// C++17, Windows 11, MSVC, target: internal DLL for RobloxPlayerBeta.exe (x64)
//
// MINIMAL BUILD — this version compiles with only the patterns/offsets your
// patterns.hpp actually contains. it injects, opens the pipe for the UI to
// turn green, and logs received scripts to %APPDATA%\vesper\dll.log.
//
// SCRIPT EXECUTION is disabled because this patterns.hpp doesn't include
// LuauApi_* signatures (your dump is game-side patterns, not core Luau).
// once you get a dump with Luau API patterns, we wire real execution back in.

#include <Windows.h>
#include <shlobj.h>
#include <psapi.h>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>
#include <chrono>
#include <filesystem>
#include <fstream>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "psapi.lib")

namespace fs = std::filesystem;

// =============================================================================
// script queue (received over pipe from UI)
// =============================================================================

static std::mutex g_q_mutex;
static std::queue<std::string> g_q;

static void enqueue(std::string s) {
    std::lock_guard<std::mutex> lk(g_q_mutex);
    g_q.push(std::move(s));
}

static bool dequeue(std::string& out) {
    std::lock_guard<std::mutex> lk(g_q_mutex);
    if (g_q.empty()) return false;
    out = std::move(g_q.front());
    g_q.pop();
    return true;
}

// =============================================================================
// log file — scripts get written here so we know the pipe works end-to-end
// =============================================================================

static fs::path log_path() {
    wchar_t roaming[MAX_PATH];
    SHGetFolderPathW(nullptr, 0x1A /*CSIDL_APPDATA*/, nullptr, 0, roaming);
    fs::path p = fs::path(roaming) / L"vesper";
    fs::create_directories(p);
    return p / L"dll.log";
}

static void dll_log(const std::string& s) {
    std::ofstream f(log_path(), std::ios::app);
    if (!f) return;
    SYSTEMTIME st; GetLocalTime(&st);
    char buf[64];
    snprintf(buf, sizeof(buf), "[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);
    f << buf << s << "\n";
}

// =============================================================================
// script worker — processes queued scripts (currently just logs them)
// =============================================================================

static std::atomic<bool> g_worker_run{true};

static void script_worker() {
    dll_log("vesper DLL loaded, script worker started");
    while (g_worker_run) {
        std::string src;
        while (dequeue(src)) {
            dll_log("received script (" + std::to_string(src.size()) + " bytes)");
            dll_log("first 80 chars: " + src.substr(0, 80));
            // TODO: once Luau API patterns are available, compile + run here
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// =============================================================================
// IPC — named pipe server
// =============================================================================

static void pipe_server() {
    while (g_worker_run) {
        HANDLE pipe = CreateNamedPipeA(
            "\\\\.\\pipe\\vesper_exec", PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
            PIPE_UNLIMITED_INSTANCES, 1<<20, 1<<20, 0, nullptr);
        if (pipe == INVALID_HANDLE_VALUE) { Sleep(1000); continue; }
        if (ConnectNamedPipe(pipe, nullptr) || GetLastError() == ERROR_PIPE_CONNECTED) {
            std::string script;
            char buf[8192]; DWORD read = 0;
            while (ReadFile(pipe, buf, sizeof(buf), &read, nullptr) && read) {
                script.append(buf, read);
                if (read < sizeof(buf)) break;
            }
            if (!script.empty()) enqueue(std::move(script));
            const char* ack = "ok"; DWORD w;
            WriteFile(pipe, ack, 2, &w, nullptr);
        }
        DisconnectNamedPipe(pipe);
        CloseHandle(pipe);
    }
}

// =============================================================================
// bootstrap
// =============================================================================

static DWORD WINAPI dll_main_thread(LPVOID) {
    std::thread(pipe_server).detach();
    std::thread(script_worker).detach();
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls((HINSTANCE)GetModuleHandleW(nullptr));
        CreateThread(nullptr, 0, dll_main_thread, nullptr, 0, nullptr);
    }
    return TRUE;
}

// manual-map entrypoint — loader's thread-hijack / APC lands here
extern "C" __declspec(dllexport) DWORD __stdcall ManualMapEntry(LPVOID) {
    return dll_main_thread(nullptr);
}
