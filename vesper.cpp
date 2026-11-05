#include <Windows.h>
#include <TlHelp32.h>
#include <wrl.h>
#include <wil/com.h>
#include <WebView2.h>
#include <shlobj.h>
#include <shellapi.h>
#include <psapi.h>
#include <tchar.h>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <atomic>
#include <thread>
#include <chrono>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "psapi.lib")

using namespace Microsoft::WRL;
namespace fs = std::filesystem;

static std::vector<uint8_t> load_resource(const wchar_t* name, const wchar_t* type) {
    HRSRC h = FindResourceW(nullptr, name, type);
    if (!h) return {};
    HGLOBAL g = LoadResource(nullptr, h);
    if (!g) return {};
    DWORD sz = SizeofResource(nullptr, h);
    LPVOID p = LockResource(g);
    return std::vector<uint8_t>((uint8_t*)p, (uint8_t*)p + sz);
}

static fs::path exe_dir() {
    wchar_t buf[MAX_PATH]; GetModuleFileNameW(nullptr, buf, MAX_PATH);
    return fs::path(buf).parent_path();
}

static fs::path data_root() {
    wchar_t roaming[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_APPDATA, nullptr, 0, roaming);
    fs::path p = fs::path(roaming) / L"Vesper";
    fs::create_directories(p);
    fs::create_directories(p / L"workspace");
    fs::create_directories(p / L"autoexec");
    return p;
}

static PROCESS_INFORMATION g_svc_pi{};
static std::atomic<bool>   g_svc_running{false};

static bool start_service() {
    fs::path svc_dir = exe_dir() / L"lib";
    fs::path svc = svc_dir / L"vesper_svc.exe";
    if (!fs::exists(svc)) return false;

    STARTUPINFOW si{ sizeof(si) };
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    std::wstring cmd = L"\"" + svc.wstring() + L"\"";
    std::vector<wchar_t> cmdbuf(cmd.begin(), cmd.end()); cmdbuf.push_back(0);

    if (!CreateProcessW(nullptr, cmdbuf.data(), nullptr, nullptr, FALSE,
                        CREATE_NO_WINDOW, nullptr, svc_dir.c_str(), &si, &g_svc_pi))
        return false;
    g_svc_running = true;
    return true;
}

static void stop_service() {
    if (g_svc_running && g_svc_pi.hProcess) {
        TerminateProcess(g_svc_pi.hProcess, 0);
        CloseHandle(g_svc_pi.hProcess);
        CloseHandle(g_svc_pi.hThread);
        g_svc_running = false;
    }
}

static std::string svc_call(const std::string& cmd, const std::string& payload = "") {
    for (int i = 0; i < 10; ++i) {
        HANDLE h = CreateFileW(L"\\\\.\\pipe\\vesper_svc",
            GENERIC_READ|GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
        if (h == INVALID_HANDLE_VALUE) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        std::string msg = cmd + "\n" + payload;
        DWORD w = 0;
        WriteFile(h, msg.data(), (DWORD)msg.size(), &w, nullptr);

        char buf[4096]; DWORD r = 0;
        std::string reply;
        if (ReadFile(h, buf, sizeof(buf), &r, nullptr)) reply.assign(buf, r);
        CloseHandle(h);

        while (!reply.empty() && (reply.back() == '\n' || reply.back() == '\r')) reply.pop_back();
        return reply;
    }
    return "unreachable";
}

static std::string jesc(const std::string& s) {
    std::string out; out.reserve(s.size()+8);
    for (char c : s) {
        switch (c) {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\r': out += "\\r"; break;
            case '\t': out += "\\t"; break;
            default:
                if ((unsigned char)c < 0x20) { char b[8]; snprintf(b, sizeof(b), "\\u%04x", c); out += b; }
                else out += c;
        }
    }
    return out;
}
static std::string jstr(const std::string& j, const std::string& k) {
    auto key = "\"" + k + "\"";
    auto p = j.find(key); if (p == std::string::npos) return "";
    p = j.find(':', p); if (p == std::string::npos) return "";
    ++p; while (p < j.size() && (j[p] == ' ' || j[p] == '\t')) ++p;
    if (p >= j.size() || j[p] != '"') return "";
    ++p;
    std::string out;
    while (p < j.size() && j[p] != '"') {
        if (j[p] == '\\' && p+1 < j.size()) {
            char c = j[p+1];
            switch (c) {
                case 'n': out += '\n'; break;
                case 'r': out += '\r'; break;
                case 't': out += '\t'; break;
                case '"': out += '"'; break;
                case '\\': out += '\\'; break;
                case '/': out += '/'; break;
                default: out += c; break;
            }
            p += 2;
        } else out += j[p++];
    }
    return out;
}
static int jint(const std::string& j, const std::string& k) {
    auto key = "\"" + k + "\"";
    auto p = j.find(key); if (p == std::string::npos) return 0;
    p = j.find(':', p); if (p == std::string::npos) return 0;
    ++p; while (p < j.size() && (j[p] == ' ' || j[p] == '\t')) ++p;
    return atoi(j.c_str() + p);
}

static HWND g_hwnd = nullptr;
static wil::com_ptr<ICoreWebView2Controller> g_controller;
static wil::com_ptr<ICoreWebView2> g_webview;

static std::wstring u2w(const std::string& s) {
    if (s.empty()) return {};
    int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), nullptr, 0);
    std::wstring o(n, 0); MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), o.data(), n);
    return o;
}
static std::string w2u(const std::wstring& w) {
    if (w.empty()) return {};
    int n = WideCharToMultiByte(CP_UTF8, 0, w.data(), (int)w.size(), nullptr, 0, nullptr, nullptr);
    std::string o(n, 0); WideCharToMultiByte(CP_UTF8, 0, w.data(), (int)w.size(), o.data(), n, nullptr, nullptr);
    return o;
}
static void post(const std::string& s) {
    if (g_webview) g_webview->PostWebMessageAsJson(u2w(s).c_str());
}

static void handle(const std::string& msg) {
    int id = jint(msg, "id");
    std::string op = jstr(msg, "op");

    auto reply = [&](const std::string& body){
        char idbuf[32]; snprintf(idbuf, sizeof(idbuf), "%d", id);
        std::string full = "{\"id\":"; full += idbuf; full += ","; full += body; full += "}";
        post(full);
    };

    if (op == "inject" || op == "launchRoblox") {
        std::thread([id]() {
            std::string result = svc_call("ATTACH");
            char idbuf[32]; snprintf(idbuf, sizeof(idbuf), "%d", id);
            bool ok = (result == "Attached");
            std::string body = ok
                ? std::string("{\"id\":") + idbuf + ",\"ok\":true,\"state\":\"" + jesc(result) + "\"}"
                : std::string("{\"id\":") + idbuf + ",\"ok\":false,\"reason\":\"" + jesc(result) + "\"}";
            post(body);
        }).detach();
        return;
    }
    if (op == "exec") {
        std::string src = jstr(msg, "source");
        std::string payload = std::to_string(src.size()) + "\n" + src;
        std::string result = svc_call("EXEC", payload);
        if (result.rfind("OK:", 0) == 0)
            reply("\"ok\":true,\"result\":\"" + jesc(result.substr(3)) + "\"");
        else
            reply("\"ok\":false,\"reason\":\"" + jesc(result) + "\"");
        return;
    }
    if (op == "isAttached") {
        std::string result = svc_call("ISATTACHED");
        bool attached = (result == "true");
        reply(std::string("\"ok\":true,\"attached\":") + (attached ? "true" : "false"));
        return;
    }
    if (op == "killRoblox") {
        std::string result = svc_call("KILL");
        reply(std::string("\"ok\":") + (result == "ok" ? "true" : "false"));
        return;
    }
    if (op == "setPerformance") { reply("\"ok\":true"); return; }
    if (op == "listFiles") {
        auto list = [](const fs::path& dir){
            std::string out = "["; bool first = true;
            if (fs::exists(dir)) for (auto& e : fs::directory_iterator(dir)) {
                if (!e.is_regular_file()) continue;
                if (!first) out += ",";
                out += "\"" + jesc(e.path().filename().string()) + "\""; first = false;
            }
            out += "]"; return out;
        };
        std::string body = "\"ok\":true,\"workspace\":";
        body += list(data_root() / L"workspace");
        body += ",\"autoexec\":";
        body += list(data_root() / L"autoexec");
        reply(body);
        return;
    }
    if (op == "readFile") {
        std::string folder = jstr(msg, "folder");
        std::string name   = jstr(msg, "name");
        fs::path p = data_root() / u2w(folder) / u2w(name);
        std::ifstream f(p, std::ios::binary);
        if (!f) { reply("\"ok\":false,\"reason\":\"not-found\""); return; }
        std::string s((std::istreambuf_iterator<char>(f)), {});
        reply("\"ok\":true,\"content\":\"" + jesc(s) + "\"");
        return;
    }
    if (op == "saveFile") {
        std::string name = jstr(msg, "name");
        std::string content = jstr(msg, "content");
        if (name.find('.') == std::string::npos) name += ".lua";
        fs::path p = data_root() / L"workspace" / u2w(name);
        std::ofstream f(p, std::ios::binary);
        if (!f) { reply("\"ok\":false,\"reason\":\"cannot-write\""); return; }
        f.write(content.data(), content.size());
        reply("\"ok\":true");
        return;
    }
    if (op == "window.minimize") { ShowWindow(g_hwnd, SW_MINIMIZE); reply("\"ok\":true"); return; }
    if (op == "window.maximize") {
        WINDOWPLACEMENT wp{ sizeof(wp) }; GetWindowPlacement(g_hwnd, &wp);
        ShowWindow(g_hwnd, wp.showCmd == SW_MAXIMIZE ? SW_RESTORE : SW_MAXIMIZE);
        reply("\"ok\":true"); return;
    }
    if (op == "window.close") { PostMessage(g_hwnd, WM_CLOSE, 0, 0); reply("\"ok\":true"); return; }

    reply("\"ok\":false,\"reason\":\"unknown\"");
}

static LRESULT CALLBACK wndproc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_SIZE:
            if (g_controller) { RECT r; GetClientRect(h, &r); g_controller->put_Bounds(r); }
            return 0;
        case WM_DESTROY:
            stop_service();
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

static bool init_webview() {
    fs::path user_data = data_root() / L"webview";
    fs::create_directories(user_data);
    HRESULT hr = CreateCoreWebView2EnvironmentWithOptions(nullptr, user_data.c_str(), nullptr,
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [](HRESULT, ICoreWebView2Environment* env) -> HRESULT {
                env->CreateCoreWebView2Controller(g_hwnd,
                    Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [](HRESULT, ICoreWebView2Controller* ctrl) -> HRESULT {
                            g_controller = ctrl;
                            ctrl->get_CoreWebView2(&g_webview);
                            ICoreWebView2Settings* s;
                            g_webview->get_Settings(&s);
                            s->put_AreDevToolsEnabled(TRUE);
                            s->put_IsStatusBarEnabled(FALSE);
                            s->Release();
                            RECT r; GetClientRect(g_hwnd, &r);
                            ctrl->put_Bounds(r);
                            EventRegistrationToken token;
                            g_webview->add_WebMessageReceived(
                                Callback<ICoreWebView2WebMessageReceivedEventHandler>(
                                    [](ICoreWebView2*, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
                                        wil::unique_cotaskmem_string raw;
                                        if (SUCCEEDED(args->TryGetWebMessageAsString(&raw)))
                                            handle(w2u(raw.get()));
                                        return S_OK;
                                    }).Get(), &token);
                            auto html = load_resource(L"ALPEN_HTML", RT_RCDATA);
                            if (!html.empty()) {
                                std::string str(html.begin(), html.end());
                                g_webview->NavigateToString(u2w(str).c_str());
                            }
                            return S_OK;
                        }).Get());
                return S_OK;
            }).Get());
    return SUCCEEDED(hr);
}

int WINAPI wWinMain(HINSTANCE hinst, HINSTANCE, LPWSTR, int nShow) {
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    WNDCLASSEXW wc{ sizeof(wc), CS_HREDRAW|CS_VREDRAW, wndproc, 0, 0, hinst,
        LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW),
        (HBRUSH)(COLOR_WINDOW+1), nullptr, L"vesper", nullptr };
    RegisterClassExW(&wc);
    g_hwnd = CreateWindowExW(0, wc.lpszClassName, L"Vesper",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 820,
        nullptr, nullptr, hinst, nullptr);

    if (!init_webview()) {
        MessageBoxW(nullptr, L"WebView2 Runtime required.", L"Vesper", MB_OK|MB_ICONERROR);
        return 1;
    }

    start_service();

    ShowWindow(g_hwnd, nShow);
    UpdateWindow(g_hwnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg); DispatchMessage(&msg);
    }

    stop_service();
    g_controller.reset();
    g_webview.reset();
    CoUninitialize();
    return 0;
}
