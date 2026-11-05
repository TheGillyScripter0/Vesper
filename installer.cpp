#include <Windows.h>
#include <CommCtrl.h>
#include <shlobj.h>
#include <shellapi.h>
#include <shlguid.h>
#include <winhttp.h>
#include <tchar.h>
#include <cstdio>
#include <string>
#include <vector>
#include <thread>
#include <filesystem>
#include <fstream>

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "uuid.lib")
#pragma comment(linker, "/MANIFESTDEPENDENCY:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

namespace fs = std::filesystem;

// CONFIGURE these before building:
static const wchar_t* HOST        = L"github.com";
static const wchar_t* RELEASE_URL = L"/jackverwimp939-cmd/Vesper/releases/latest/download/vesper.zip";
// For GitHub Releases, the path above assumes you've published a release with vesper.zip attached.
// Alternatively point at a Cloudflare Pages / R2 bucket.

static HWND g_hwnd = nullptr;
static HWND g_progress = nullptr;
static HWND g_status = nullptr;
static HWND g_title = nullptr;

static fs::path install_dir() {
    wchar_t local[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_LOCAL_APPDATA, nullptr, 0, local);
    fs::path p = fs::path(local) / L"Vesper";
    fs::create_directories(p);
    return p;
}

static void set_status(const wchar_t* t) { if (g_status) SetWindowTextW(g_status, t); }
static void set_progress(int pct) { if (g_progress) SendMessage(g_progress, PBM_SETPOS, pct, 0); }

static bool follow_redirects_and_download(std::vector<uint8_t>& out, int start_pct, int end_pct) {
    std::wstring host = HOST;
    std::wstring path = RELEASE_URL;
    bool https = true;

    for (int redirect = 0; redirect < 10; ++redirect) {
        HINTERNET s = WinHttpOpen(L"Vesper-Setup/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, nullptr, nullptr, 0);
        if (!s) return false;
        HINTERNET c = WinHttpConnect(s, host.c_str(),
            https ? INTERNET_DEFAULT_HTTPS_PORT : INTERNET_DEFAULT_HTTP_PORT, 0);
        HINTERNET r = WinHttpOpenRequest(c, L"GET", path.c_str(), nullptr, nullptr, nullptr,
            https ? WINHTTP_FLAG_SECURE : 0);

        if (!WinHttpSendRequest(r, nullptr, 0, nullptr, 0, 0, 0) ||
            !WinHttpReceiveResponse(r, nullptr)) {
            WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);
            return false;
        }

        DWORD status = 0, statusSz = sizeof(status);
        WinHttpQueryHeaders(r, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX, &status, &statusSz, WINHTTP_NO_HEADER_INDEX);

        if (status == 301 || status == 302 || status == 307) {
            wchar_t loc[2048]{}; DWORD locSz = sizeof(loc);
            WinHttpQueryHeaders(r, WINHTTP_QUERY_LOCATION, WINHTTP_HEADER_NAME_BY_INDEX,
                loc, &locSz, WINHTTP_NO_HEADER_INDEX);
            WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);

            std::wstring url = loc;
            if (url.find(L"https://") == 0) { https = true; url = url.substr(8); }
            else if (url.find(L"http://") == 0) { https = false; url = url.substr(7); }
            auto slash = url.find(L'/');
            host = url.substr(0, slash);
            path = url.substr(slash);
            continue;
        }

        if (status != 200) {
            WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);
            return false;
        }

        DWORD total = 0, totalSz = sizeof(total);
        WinHttpQueryHeaders(r, WINHTTP_QUERY_CONTENT_LENGTH | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX, &total, &totalSz, WINHTTP_NO_HEADER_INDEX);

        for (;;) {
            DWORD avail = 0;
            if (!WinHttpQueryDataAvailable(r, &avail) || !avail) break;
            size_t before = out.size();
            out.resize(before + avail);
            DWORD read = 0;
            if (!WinHttpReadData(r, out.data() + before, avail, &read)) break;
            out.resize(before + read);
            if (total) {
                int pct = start_pct + (int)((double)(end_pct - start_pct) * out.size() / total);
                set_progress(pct);
            }
        }
        WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);
        return !out.empty();
    }
    return false;
}

#include <comdef.h>
#include <Shldisp.h>

static bool extract_zip(const fs::path& zip, const fs::path& dest) {
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    IShellDispatch* shell = nullptr;
    if (FAILED(CoCreateInstance(CLSID_Shell, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&shell))))
        return false;

    VARIANT vSrc, vDst;
    VariantInit(&vSrc); VariantInit(&vDst);
    vSrc.vt = VT_BSTR; vSrc.bstrVal = SysAllocString(zip.c_str());
    vDst.vt = VT_BSTR; vDst.bstrVal = SysAllocString(dest.c_str());

    Folder* src = nullptr;
    Folder* dst = nullptr;
    shell->NameSpace(vSrc, &src);
    shell->NameSpace(vDst, &dst);

    bool ok = false;
    if (src && dst) {
        FolderItems* items = nullptr;
        if (SUCCEEDED(src->Items(&items))) {
            VARIANT vOpts; VariantInit(&vOpts);
            vOpts.vt = VT_I4; vOpts.lVal = FOF_NO_UI | FOF_NOCONFIRMATION;
            VARIANT vItems; VariantInit(&vItems);
            vItems.vt = VT_DISPATCH; vItems.pdispVal = items;
            ok = SUCCEEDED(dst->CopyHere(vItems, vOpts));
            items->Release();
        }
    }

    if (src) src->Release();
    if (dst) dst->Release();
    SysFreeString(vSrc.bstrVal); SysFreeString(vDst.bstrVal);
    shell->Release();
    CoUninitialize();
    return ok;
}

static bool make_shortcut(const fs::path& target, const fs::path& link_path) {
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    IShellLinkW* link = nullptr;
    if (FAILED(CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link)))) {
        CoUninitialize(); return false;
    }
    link->SetPath(target.c_str());
    link->SetWorkingDirectory(target.parent_path().c_str());
    link->SetDescription(L"Vesper");
    link->SetIconLocation(target.c_str(), 0);

    IPersistFile* pf = nullptr;
    link->QueryInterface(IID_PPV_ARGS(&pf));
    bool ok = pf && SUCCEEDED(pf->Save(link_path.c_str(), TRUE));
    if (pf) pf->Release();
    link->Release();
    CoUninitialize();
    return ok;
}

static void install_flow() {
    fs::path dir = install_dir();

    set_status(L"Downloading Vesper...");
    set_progress(5);
    std::vector<uint8_t> pkg;
    if (!follow_redirects_and_download(pkg, 5, 80)) {
        MessageBoxW(g_hwnd, L"Download failed. Check your internet connection.", L"Vesper", MB_OK|MB_ICONERROR);
        PostMessage(g_hwnd, WM_CLOSE, 0, 0); return;
    }

    set_status(L"Extracting...");
    set_progress(85);
    fs::path zip_path = dir / L"vesper.zip";
    { std::ofstream f(zip_path, std::ios::binary); f.write((const char*)pkg.data(), pkg.size()); }

    // clean out any old install first (except our own download)
    for (auto& e : fs::directory_iterator(dir)) {
        if (e.path() == zip_path) continue;
        std::error_code ec;
        fs::remove_all(e.path(), ec);
    }

    if (!extract_zip(zip_path, dir)) {
        MessageBoxW(g_hwnd, L"Extraction failed.", L"Vesper", MB_OK|MB_ICONERROR);
        PostMessage(g_hwnd, WM_CLOSE, 0, 0); return;
    }
    fs::remove(zip_path);

    set_status(L"Creating shortcuts...");
    set_progress(92);
    fs::path exe = dir / L"vesper.exe";

    wchar_t desktop[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_DESKTOP, nullptr, 0, desktop);
    make_shortcut(exe, fs::path(desktop) / L"Vesper.lnk");

    wchar_t start[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_PROGRAMS, nullptr, 0, start);
    fs::path start_folder = fs::path(start) / L"Vesper";
    fs::create_directories(start_folder);
    make_shortcut(exe, start_folder / L"Vesper.lnk");

    set_status(L"Done!");
    set_progress(100);
    Sleep(600);

    ShellExecuteW(nullptr, L"open", exe.c_str(), nullptr, dir.c_str(), SW_SHOW);
    PostMessage(g_hwnd, WM_CLOSE, 0, 0);
}

static LRESULT CALLBACK wndproc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_CTLCOLORSTATIC: {
            HDC dc = (HDC)w;
            SetTextColor(dc, RGB(240, 232, 232));
            SetBkColor(dc, RGB(14, 14, 16));
            static HBRUSH b = CreateSolidBrush(RGB(14, 14, 16));
            return (LRESULT)b;
        }
        case WM_ERASEBKGND: {
            RECT r; GetClientRect(h, &r);
            HBRUSH b = CreateSolidBrush(RGB(14, 14, 16));
            FillRect((HDC)w, &r, b);
            DeleteObject(b);
            return 1;
        }
        case WM_DESTROY: PostQuitMessage(0); return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

int WINAPI wWinMain(HINSTANCE hinst, HINSTANCE, LPWSTR, int) {
    INITCOMMONCONTROLSEX icc{ sizeof(icc), ICC_PROGRESS_CLASS };
    InitCommonControlsEx(&icc);

    HICON ico = (HICON)LoadImageW(hinst, MAKEINTRESOURCEW(1), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);

    WNDCLASSEXW wc{ sizeof(wc), 0, wndproc, 0, 0, hinst,
        ico ? ico : LoadIcon(nullptr, IDI_APPLICATION),
        LoadCursor(nullptr, IDC_ARROW),
        nullptr, nullptr, L"vesper_setup", nullptr };
    RegisterClassExW(&wc);
    g_hwnd = CreateWindowExW(0, wc.lpszClassName, L"Vesper Setup",
        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 240, nullptr, nullptr, hinst, nullptr);

    HFONT title_font = CreateFontW(32, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");
    HFONT body_font = CreateFontW(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");

    g_title = CreateWindowW(L"STATIC", L"V E S P E R", WS_CHILD|WS_VISIBLE|SS_CENTER,
        0, 30, 500, 36, g_hwnd, nullptr, hinst, nullptr);
    SendMessage(g_title, WM_SETFONT, (WPARAM)title_font, 0);

    g_status = CreateWindowW(L"STATIC", L"Preparing...", WS_CHILD|WS_VISIBLE|SS_CENTER,
        20, 100, 460, 20, g_hwnd, nullptr, hinst, nullptr);
    SendMessage(g_status, WM_SETFONT, (WPARAM)body_font, 0);

    g_progress = CreateWindowExW(0, PROGRESS_CLASS, nullptr,
        WS_CHILD|WS_VISIBLE|PBS_SMOOTH,
        40, 130, 420, 18, g_hwnd, nullptr, hinst, nullptr);
    SendMessage(g_progress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
    SendMessage(g_progress, PBM_SETBARCOLOR, 0, RGB(214, 52, 71));
    SendMessage(g_progress, PBM_SETBKCOLOR, 0, RGB(42, 21, 24));

    ShowWindow(g_hwnd, SW_SHOW);
    UpdateWindow(g_hwnd);

    std::thread(install_flow).detach();

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg); DispatchMessage(&msg);
    }
    return 0;
}
