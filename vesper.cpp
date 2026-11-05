// C++17, Windows 11, MSVC — vesper.exe (single executable).
// combines: webview host + alpen UI (embedded) + manual-map loader (embedded DLL)
// + native hooks for: kill-roblox, auto-inject, auto-execute, FPS uncap,
//   multi-instance, RAM limit, CPU priority, game-title detection.

#include <Windows.h>
#include <TlHelp32.h>
#include <winternl.h>
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
#include <mutex>
#include <thread>
#include <chrono>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "ntdll.lib")

extern "C" NTSTATUS NTAPI NtQueryInformationProcess(
    HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass,
    PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);

// forward declarations (definitions are further down)
static std::wstring u2w(const std::string& s);
static std::string  w2u(const std::wstring& w);

using namespace Microsoft::WRL;
namespace fs = std::filesystem;

// =============================================================================
// embedded resources
// =============================================================================

static std::vector<uint8_t> load_resource(const wchar_t* name, const wchar_t* type) {
    HRSRC h = FindResourceW(nullptr, name, type);
    if (!h) return {};
    HGLOBAL g = LoadResource(nullptr, h);
    if (!g) return {};
    DWORD sz = SizeofResource(nullptr, h);
    LPVOID p = LockResource(g);
    return std::vector<uint8_t>((uint8_t*)p, (uint8_t*)p + sz);
}

// =============================================================================
// paths + process helpers
// =============================================================================

static fs::path data_root() {
    wchar_t roaming[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_APPDATA, nullptr, 0, roaming);
    fs::path p = fs::path(roaming) / L"vesper";
    fs::create_directories(p);
    fs::create_directories(p / L"workspace");
    fs::create_directories(p / L"autoexec");
    return p;
}

static std::vector<DWORD> find_all_roblox_pids() {
    std::vector<DWORD> pids;
    HANDLE s = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32W pe{ sizeof(pe) };
    if (Process32FirstW(s, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, L"RobloxPlayerBeta.exe") == 0) pids.push_back(pe.th32ProcessID);
        } while (Process32NextW(s, &pe));
    }
    CloseHandle(s);
    return pids;
}
static DWORD find_roblox_pid() {
    auto pids = find_all_roblox_pids();
    return pids.empty() ? 0 : pids.front();
}

static HMODULE remote_module(DWORD pid, const wchar_t* name) {
    HANDLE s = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    MODULEENTRY32W me{ sizeof(me) };
    HMODULE out = nullptr;
    if (Module32FirstW(s, &me)) {
        do {
            if (_wcsicmp(me.szModule, name) == 0) { out = me.hModule; break; }
        } while (Module32NextW(s, &me));
    }
    CloseHandle(s);
    return out;
}

// =============================================================================
// pipe (talks to injected DLL)
// =============================================================================

static bool pipe_attached() {
    if (WaitNamedPipeW(L"\\\\.\\pipe\\vesper_exec", 0)) return true;
    return GetLastError() == ERROR_SEM_TIMEOUT;
}
static std::string pipe_exec(const std::string& src) {
    HANDLE h = CreateFileW(L"\\\\.\\pipe\\vesper_exec", GENERIC_READ|GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    if (h == INVALID_HANDLE_VALUE) return "pipe-unavailable";
    DWORD mode = PIPE_READMODE_MESSAGE;
    SetNamedPipeHandleState(h, &mode, nullptr, nullptr);
    DWORD w = 0;
    WriteFile(h, src.data(), (DWORD)src.size(), &w, nullptr);
    char buf[256]; DWORD r = 0;
    ReadFile(h, buf, sizeof(buf), &r, nullptr);
    CloseHandle(h);
    return std::string(buf, r);
}

// =============================================================================
// settings — pushed from UI via setPerformance
// =============================================================================

struct Settings {
    std::atomic<bool> autoinject{false};
    std::atomic<bool> autoexec{false};
    std::atomic<bool> fpsuncap{false};
    std::atomic<int>  fpstarget{240};
    std::atomic<bool> multi{false};
    std::atomic<int>  ramlimit{0};         // MB
    std::string       cpupriority = "normal";
    std::atomic<bool> rejoin{false};
    std::atomic<bool> antiafk{false};
    std::atomic<bool> discord{false};
    std::mutex        m;
} g_settings;

// =============================================================================
// manual-map injector (unchanged core)
// =============================================================================

struct map_context {
    HMODULE (WINAPI* LoadLibraryA)(LPCSTR);
    FARPROC (WINAPI* GetProcAddress)(HMODULE, LPCSTR);
    uintptr_t image_base;
    IMAGE_NT_HEADERS* nt;
    uintptr_t entry_rva;
};

static DWORD __stdcall loader_stub(map_context* ctx) {
    IMAGE_NT_HEADERS* nt = ctx->nt;
    uintptr_t base = ctx->image_base;
    auto imp_dir = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (imp_dir->Size) {
        auto imp = (IMAGE_IMPORT_DESCRIPTOR*)(base + imp_dir->VirtualAddress);
        while (imp->Name) {
            const char* dll = (const char*)(base + imp->Name);
            HMODULE mod = ctx->LoadLibraryA(dll);
            auto oft = (IMAGE_THUNK_DATA*)(base + (imp->OriginalFirstThunk ? imp->OriginalFirstThunk : imp->FirstThunk));
            auto ft  = (IMAGE_THUNK_DATA*)(base + imp->FirstThunk);
            while (oft->u1.AddressOfData) {
                FARPROC fn;
                if (oft->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
                    fn = ctx->GetProcAddress(mod, (LPCSTR)(oft->u1.Ordinal & 0xFFFF));
                else {
                    auto ibn = (IMAGE_IMPORT_BY_NAME*)(base + oft->u1.AddressOfData);
                    fn = ctx->GetProcAddress(mod, ibn->Name);
                }
                ft->u1.Function = (ULONGLONG)fn;
                ++oft; ++ft;
            }
            ++imp;
        }
    }
    using dllmain_t = BOOL(WINAPI*)(HMODULE, DWORD, LPVOID);
    auto dllmain = (dllmain_t)(base + ctx->entry_rva);
    dllmain((HMODULE)base, DLL_PROCESS_ATTACH, nullptr);
    return 0;
}

static bool hijack_thread(DWORD pid, uintptr_t entry, uintptr_t arg) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 te{ sizeof(te) };
    bool ok = false;
    if (Thread32First(snap, &te)) {
        do {
            if (te.th32OwnerProcessID != pid) continue;
            HANDLE th = OpenThread(THREAD_GET_CONTEXT|THREAD_SET_CONTEXT|THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
            if (!th) continue;
            SuspendThread(th);
            CONTEXT c{}; c.ContextFlags = CONTEXT_FULL;
            if (GetThreadContext(th, &c)) {
                c.Rcx = arg; c.Rip = entry;
                SetThreadContext(th, &c);
                ok = true;
            }
            ResumeThread(th);
            CloseHandle(th);
            if (ok) break;
        } while (Thread32Next(snap, &te));
    }
    CloseHandle(snap);
    return ok;
}

static std::string do_inject() {
    if (pipe_attached()) return "already attached";
    auto dll_image = load_resource(L"EXECUTOR_DLL", RT_RCDATA);
    if (dll_image.empty()) return "embedded DLL resource missing";

    DWORD pid = find_roblox_pid();
    if (!pid) return "RobloxPlayerBeta.exe not running";

    HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!proc) return "OpenProcess failed (run as administrator)";

    auto dos = (IMAGE_DOS_HEADER*)dll_image.data();
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) { CloseHandle(proc); return "bad DLL image"; }
    auto nt = (IMAGE_NT_HEADERS*)(dll_image.data() + dos->e_lfanew);

    SIZE_T size = nt->OptionalHeader.SizeOfImage;
    LPVOID remote = VirtualAllocEx(proc, nullptr, size, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!remote) { CloseHandle(proc); return "VirtualAllocEx failed"; }

    WriteProcessMemory(proc, remote, dll_image.data(), nt->OptionalHeader.SizeOfHeaders, nullptr);
    auto sec = IMAGE_FIRST_SECTION(nt);
    for (uint32_t i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++sec) {
        if (!sec->SizeOfRawData) continue;
        WriteProcessMemory(proc, (uint8_t*)remote + sec->VirtualAddress,
            dll_image.data() + sec->PointerToRawData, sec->SizeOfRawData, nullptr);
    }

    uintptr_t delta = (uintptr_t)remote - nt->OptionalHeader.ImageBase;
    if (delta) {
        auto rd = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
        if (rd->Size) {
            std::vector<uint8_t> patched(size);
            ReadProcessMemory(proc, remote, patched.data(), size, nullptr);
            auto reloc = (IMAGE_BASE_RELOCATION*)(patched.data() + rd->VirtualAddress);
            auto end   = (IMAGE_BASE_RELOCATION*)((uint8_t*)reloc + rd->Size);
            while (reloc < end && reloc->VirtualAddress) {
                uint32_t count = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / 2;
                auto entries = (uint16_t*)(reloc + 1);
                for (uint32_t i = 0; i < count; ++i) {
                    if ((entries[i] >> 12) == IMAGE_REL_BASED_DIR64) {
                        auto p = (uintptr_t*)(patched.data() + reloc->VirtualAddress + (entries[i] & 0xFFF));
                        *p += delta;
                    }
                }
                reloc = (IMAGE_BASE_RELOCATION*)((uint8_t*)reloc + reloc->SizeOfBlock);
            }
            WriteProcessMemory(proc, remote, patched.data(), size, nullptr);
        }
    }

    HMODULE k32_local = GetModuleHandleW(L"kernel32.dll");
    HMODULE k32_remote = remote_module(pid, L"kernel32.dll");
    if (!k32_remote) { CloseHandle(proc); return "kernel32 resolution failed"; }
    uintptr_t k32_delta = (uintptr_t)k32_remote - (uintptr_t)k32_local;

    map_context ctx{};
    ctx.LoadLibraryA = (decltype(ctx.LoadLibraryA))((uintptr_t)GetProcAddress(k32_local, "LoadLibraryA") + k32_delta);
    ctx.GetProcAddress = (decltype(ctx.GetProcAddress))((uintptr_t)GetProcAddress(k32_local, "GetProcAddress") + k32_delta);
    ctx.image_base = (uintptr_t)remote;
    ctx.nt = (IMAGE_NT_HEADERS*)((uintptr_t)remote + dos->e_lfanew);
    ctx.entry_rva = nt->OptionalHeader.AddressOfEntryPoint;

    LPVOID ctx_remote = VirtualAllocEx(proc, nullptr, sizeof(ctx), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    WriteProcessMemory(proc, ctx_remote, &ctx, sizeof(ctx), nullptr);

    LPVOID stub_remote = VirtualAllocEx(proc, nullptr, 0x400, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(proc, stub_remote, (void*)loader_stub, 0x400, nullptr);

    bool ok = hijack_thread(pid, (uintptr_t)stub_remote, (uintptr_t)ctx_remote);
    CloseHandle(proc);
    if (!ok) return "thread hijack failed";

    for (int i = 0; i < 30; ++i) {
        if (pipe_attached()) return "";
        Sleep(100);
    }
    return "mapped but pipe never opened (offsets probably stale)";
}

// =============================================================================
// EARLY BIRD — launch Roblox suspended, kill TLS callbacks, inject before Hyperion
// =============================================================================

static std::wstring find_roblox_exe_path() {
    wchar_t local[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_LOCAL_APPDATA, nullptr, 0, local);
    fs::path versions = fs::path(local) / L"Roblox" / L"Versions";
    if (!fs::exists(versions)) return L"";
    fs::path newest;
    fs::file_time_type newest_time{};
    for (auto& e : fs::directory_iterator(versions)) {
        fs::path exe = e.path() / L"RobloxPlayerBeta.exe";
        if (fs::exists(exe)) {
            auto t = fs::last_write_time(exe);
            if (newest.empty() || t > newest_time) { newest = exe; newest_time = t; }
        }
    }
    return newest.empty() ? L"" : newest.wstring();
}

static std::string early_bird_launch(const std::string& launch_args) {
    std::wstring rpath = find_roblox_exe_path();
    if (rpath.empty()) return "Roblox not installed (install it + launch it once first so it downloads)";

    auto dll_image = load_resource(L"EXECUTOR_DLL", RT_RCDATA);
    if (dll_image.empty()) return "embedded DLL resource missing";

    // Build command line. If launch_args is a roblox-player:// URL, pass it as arg.
    std::wstring cmdline = L"\"" + rpath + L"\"";
    if (!launch_args.empty()) { cmdline += L" "; cmdline += u2w(launch_args); }

    STARTUPINFOW si{ sizeof(si) };
    PROCESS_INFORMATION pi{};
    std::vector<wchar_t> cmdbuf(cmdline.begin(), cmdline.end());
    cmdbuf.push_back(0);

    // Launch SUSPENDED — main thread paused before any user-mode code runs
    if (!CreateProcessW(nullptr, cmdbuf.data(), nullptr, nullptr, FALSE,
                        CREATE_SUSPENDED, nullptr, nullptr, &si, &pi))
        return "CreateProcess failed (" + std::to_string(GetLastError()) + ")";

    // --- KILL TLS CALLBACKS before Roblox runs ANY code ---
    // Hyperion initializes via a TLS callback. Nulling the callback array in Roblox's
    // PE header means Hyperion's callback never fires and it never installs its hooks.
    PROCESS_BASIC_INFORMATION pbi{};
    ULONG rlen = 0;
    NTSTATUS st = NtQueryInformationProcess(pi.hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), &rlen);
    if (st < 0) {
        TerminateProcess(pi.hProcess, 1);
        CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
        return "NtQueryInformationProcess failed";
    }

    // winternl.h's PEB struct doesn't expose ImageBaseAddress — read it directly at offset 0x10
    void* image_base_ptr = nullptr;
    ReadProcessMemory(pi.hProcess, (char*)pbi.PebBaseAddress + 0x10, &image_base_ptr, sizeof(image_base_ptr), nullptr);
    uintptr_t rbx_base = (uintptr_t)image_base_ptr;

    IMAGE_DOS_HEADER rdos{};
    ReadProcessMemory(pi.hProcess, (void*)rbx_base, &rdos, sizeof(rdos), nullptr);
    IMAGE_NT_HEADERS rnt{};
    ReadProcessMemory(pi.hProcess, (void*)(rbx_base + rdos.e_lfanew), &rnt, sizeof(rnt), nullptr);

    bool tls_killed = false;
    auto& tls_dd = rnt.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS];
    if (tls_dd.VirtualAddress && tls_dd.Size) {
        IMAGE_TLS_DIRECTORY64 tls{};
        ReadProcessMemory(pi.hProcess, (void*)(rbx_base + tls_dd.VirtualAddress), &tls, sizeof(tls), nullptr);
        if (tls.AddressOfCallBacks) {
            uintptr_t zero = 0;
            DWORD oldp;
            VirtualProtectEx(pi.hProcess, (void*)tls.AddressOfCallBacks, 8, PAGE_READWRITE, &oldp);
            WriteProcessMemory(pi.hProcess, (void*)tls.AddressOfCallBacks, &zero, sizeof(zero), nullptr);
            VirtualProtectEx(pi.hProcess, (void*)tls.AddressOfCallBacks, 8, oldp, &oldp);
            tls_killed = true;
        }
    }

    // --- Manual-map our DLL into the suspended Roblox ---
    auto dos = (IMAGE_DOS_HEADER*)dll_image.data();
    auto nt = (IMAGE_NT_HEADERS*)(dll_image.data() + dos->e_lfanew);
    SIZE_T size = nt->OptionalHeader.SizeOfImage;
    LPVOID remote = VirtualAllocEx(pi.hProcess, nullptr, size, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!remote) {
        TerminateProcess(pi.hProcess, 1);
        CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
        return "VirtualAllocEx failed";
    }

    WriteProcessMemory(pi.hProcess, remote, dll_image.data(), nt->OptionalHeader.SizeOfHeaders, nullptr);
    auto sec = IMAGE_FIRST_SECTION(nt);
    for (uint32_t i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++sec) {
        if (!sec->SizeOfRawData) continue;
        WriteProcessMemory(pi.hProcess, (uint8_t*)remote + sec->VirtualAddress,
            dll_image.data() + sec->PointerToRawData, sec->SizeOfRawData, nullptr);
    }

    uintptr_t delta = (uintptr_t)remote - nt->OptionalHeader.ImageBase;
    if (delta) {
        auto rd = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
        if (rd->Size) {
            std::vector<uint8_t> patched(size);
            ReadProcessMemory(pi.hProcess, remote, patched.data(), size, nullptr);
            auto reloc = (IMAGE_BASE_RELOCATION*)(patched.data() + rd->VirtualAddress);
            auto end = (IMAGE_BASE_RELOCATION*)((uint8_t*)reloc + rd->Size);
            while (reloc < end && reloc->VirtualAddress) {
                uint32_t count = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / 2;
                auto entries = (uint16_t*)(reloc + 1);
                for (uint32_t j = 0; j < count; ++j) {
                    if ((entries[j] >> 12) == IMAGE_REL_BASED_DIR64) {
                        auto p = (uintptr_t*)(patched.data() + reloc->VirtualAddress + (entries[j] & 0xFFF));
                        *p += delta;
                    }
                }
                reloc = (IMAGE_BASE_RELOCATION*)((uint8_t*)reloc + reloc->SizeOfBlock);
            }
            WriteProcessMemory(pi.hProcess, remote, patched.data(), size, nullptr);
        }
    }

    HMODULE k32_local = GetModuleHandleW(L"kernel32.dll");
    HMODULE k32_remote = remote_module(pi.dwProcessId, L"kernel32.dll");
    if (!k32_remote) {
        TerminateProcess(pi.hProcess, 1);
        CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
        return "kernel32 not mapped yet in suspended Roblox";
    }
    uintptr_t k32_delta = (uintptr_t)k32_remote - (uintptr_t)k32_local;

    map_context ctx{};
    ctx.LoadLibraryA = (decltype(ctx.LoadLibraryA))((uintptr_t)GetProcAddress(k32_local, "LoadLibraryA") + k32_delta);
    ctx.GetProcAddress = (decltype(ctx.GetProcAddress))((uintptr_t)GetProcAddress(k32_local, "GetProcAddress") + k32_delta);
    ctx.image_base = (uintptr_t)remote;
    ctx.nt = (IMAGE_NT_HEADERS*)((uintptr_t)remote + dos->e_lfanew);
    ctx.entry_rva = nt->OptionalHeader.AddressOfEntryPoint;

    LPVOID ctx_remote = VirtualAllocEx(pi.hProcess, nullptr, sizeof(ctx), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    WriteProcessMemory(pi.hProcess, ctx_remote, &ctx, sizeof(ctx), nullptr);

    LPVOID stub_remote = VirtualAllocEx(pi.hProcess, nullptr, 0x400, MEM_COMMIT|MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(pi.hProcess, stub_remote, (void*)loader_stub, 0x400, nullptr);

    // --- Queue APC: fires when ntdll hits NtTestAlert during thread init ---
    // this runs our loader stub before Roblox's entry point. combined with
    // nulled TLS callbacks, Hyperion never initializes.
    QueueUserAPC((PAPCFUNC)stub_remote, pi.hThread, (ULONG_PTR)ctx_remote);

    ResumeThread(pi.hThread);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    // wait for pipe to come up
    for (int i = 0; i < 100; ++i) {
        if (pipe_attached()) return "";
        Sleep(100);
    }
    return tls_killed ? "launched (TLS killed), DLL may not have fired" : "launched but TLS not killed";
}

// =============================================================================
// NATIVE FEATURES — the new stuff
// =============================================================================

// ---- kill all roblox ----
static bool kill_all_roblox() {
    auto pids = find_all_roblox_pids();
    bool any = false;
    for (DWORD pid : pids) {
        HANDLE p = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
        if (p) { TerminateProcess(p, 1); CloseHandle(p); any = true; }
    }
    return any;
}

// ---- multi-instance: kill the Roblox singleton mutex ----
// Roblox creates a mutex named "ROBLOX_singletonMutex". closing a handle to it
// from another process lets a second Roblox launch past its "already running" check.
static void unlock_multi_instance() {
    HANDLE m = CreateMutexW(nullptr, FALSE, L"ROBLOX_singletonMutex");
    // we intentionally LEAK the handle — keeping it open means the mutex
    // exists, but Roblox's check for "it's held by someone else" fails, which
    // is what the trick relies on. CloseHandle(m) would undo it.
    if (m) SetHandleInformation(m, HANDLE_FLAG_INHERIT, 0);
}

// ---- CPU priority ----
static void apply_cpu_priority(const std::string& level) {
    DWORD cls = NORMAL_PRIORITY_CLASS;
    if (level == "above") cls = ABOVE_NORMAL_PRIORITY_CLASS;
    else if (level == "high") cls = HIGH_PRIORITY_CLASS;
    else if (level == "low") cls = BELOW_NORMAL_PRIORITY_CLASS;
    for (DWORD pid : find_all_roblox_pids()) {
        HANDLE p = OpenProcess(PROCESS_SET_INFORMATION, FALSE, pid);
        if (p) { SetPriorityClass(p, cls); CloseHandle(p); }
    }
}

// ---- RAM soft-limit (SetProcessWorkingSetSize) ----
// not a hard cap — Windows can exceed it under pressure — but tells the OS
// to trim the working set when it grows past this. soft-caps effective memory.
static void apply_ram_limit(int mb) {
    if (mb <= 0) return;
    SIZE_T target = (SIZE_T)mb * 1024 * 1024;
    for (DWORD pid : find_all_roblox_pids()) {
        HANDLE p = OpenProcess(PROCESS_SET_QUOTA | PROCESS_QUERY_INFORMATION, FALSE, pid);
        if (p) {
            SetProcessWorkingSetSize(p, target / 2, target);
            CloseHandle(p);
        }
    }
}

// ---- FPS uncap via ClientAppSettings.json ----
// Roblox reads this file from %LOCALAPPDATA%\Roblox\Versions\<ver>\ClientSettings\
// writing the FFlag `DFIntTaskSchedulerTargetFps` sets the frame cap.
// takes effect on the next Roblox launch.
static void write_fps_uncap(bool enable, int fps) {
    wchar_t local[MAX_PATH];
    SHGetFolderPathW(nullptr, CSIDL_LOCAL_APPDATA, nullptr, 0, local);
    fs::path versions = fs::path(local) / L"Roblox" / L"Versions";
    if (!fs::exists(versions)) return;

    // apply to every installed Roblox version folder (handles bloxstrap too)
    for (auto& e : fs::directory_iterator(versions)) {
        if (!e.is_directory()) continue;
        fs::path cs = e.path() / L"ClientSettings";
        fs::create_directories(cs);
        fs::path cfg = cs / L"ClientAppSettings.json";

        std::string content = "{\n";
        if (enable) {
            int target = fps > 0 ? fps : 9999;
            content += "  \"DFIntTaskSchedulerTargetFps\": " + std::to_string(target) + ",\n";
            content += "  \"FFlagTaskSchedulerLimitTargetFpsTo2402\": \"False\",\n";
            content += "  \"DFFlagTaskSchedulerBlockingIO\": \"False\"\n";
        }
        content += "}\n";
        std::ofstream f(cfg);
        if (f) f << content;
    }
}

// ---- game title detection (from Roblox's main window) ----
struct FindWindowData { DWORD pid; HWND found; };
static BOOL CALLBACK enum_win_cb(HWND h, LPARAM lp) {
    auto* d = (FindWindowData*)lp;
    DWORD pid = 0; GetWindowThreadProcessId(h, &pid);
    if (pid == d->pid && IsWindowVisible(h)) {
        wchar_t cls[64]{};
        GetClassNameW(h, cls, 64);
        if (wcscmp(cls, L"WINDOWSCLIENT") == 0 || wcscmp(cls, L"ROBLOX") == 0 || GetWindow(h, GW_OWNER) == nullptr) {
            d->found = h;
            return FALSE;
        }
    }
    return TRUE;
}
static std::string get_roblox_game_title() {
    DWORD pid = find_roblox_pid();
    if (!pid) return "";
    FindWindowData d{ pid, nullptr };
    EnumWindows(enum_win_cb, (LPARAM)&d);
    if (!d.found) return "";
    wchar_t title[256]{};
    GetWindowTextW(d.found, title, 256);
    // convert to utf8
    char buf[512]{};
    WideCharToMultiByte(CP_UTF8, 0, title, -1, buf, 512, nullptr, nullptr);
    std::string s = buf;
    // strip "Roblox" prefix if present
    auto p = s.find(" - ");
    if (p != std::string::npos) s = s.substr(p + 3);
    if (s == "Roblox") s = "";
    return s;
}

// ---- auto-execute all files in /autoexec/ via the pipe ----
static void run_autoexec_folder() {
    fs::path dir = data_root() / L"autoexec";
    if (!fs::exists(dir)) return;
    for (auto& e : fs::directory_iterator(dir)) {
        if (!e.is_regular_file()) continue;
        std::ifstream f(e.path(), std::ios::binary);
        if (!f) continue;
        std::string src((std::istreambuf_iterator<char>(f)), {});
        if (!src.empty()) pipe_exec(src);
    }
}

// ---- background worker: auto-inject + auto-exec + ram/cpu reapply ----
static std::atomic<bool> g_worker_run{true};
static std::atomic<DWORD> g_last_roblox_pid{0};

static void background_worker() {
    while (g_worker_run) {
        DWORD cur_pid = find_roblox_pid();
        DWORD last = g_last_roblox_pid.load();

        // Roblox just appeared? auto-inject if enabled
        if (cur_pid && cur_pid != last) {
            g_last_roblox_pid = cur_pid;
            // give Roblox a sec to settle before injecting
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (g_settings.autoinject && !pipe_attached()) {
                std::string err = do_inject();
                if (err.empty() && g_settings.autoexec) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    run_autoexec_folder();
                }
            }
        }
        // Roblox exited?
        if (!cur_pid) g_last_roblox_pid = 0;

        // keep CPU priority / RAM limit applied (new Roblox instances need re-apply)
        if (cur_pid) {
            apply_cpu_priority(g_settings.cpupriority);
            if (g_settings.ramlimit > 0) apply_ram_limit(g_settings.ramlimit);
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

// =============================================================================
// JSON helpers (unchanged)
// =============================================================================

static std::string json_escape(const std::string& s) {
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
static std::string get_str(const std::string& j, const std::string& k) {
    auto key = "\"" + k + "\"";
    auto p = j.find(key);
    if (p == std::string::npos) return "";
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
static int get_int(const std::string& j, const std::string& k) {
    auto key = "\"" + k + "\"";
    auto p = j.find(key);
    if (p == std::string::npos) return 0;
    p = j.find(':', p); if (p == std::string::npos) return 0;
    ++p; while (p < j.size() && (j[p] == ' ' || j[p] == '\t')) ++p;
    return atoi(j.c_str() + p);
}
static bool get_bool(const std::string& j, const std::string& k) {
    auto key = "\"" + k + "\"";
    auto p = j.find(key);
    if (p == std::string::npos) return false;
    p = j.find(':', p); if (p == std::string::npos) return false;
    ++p; while (p < j.size() && (j[p] == ' ' || j[p] == '\t')) ++p;
    return j.compare(p, 4, "true") == 0;
}

// =============================================================================
// webview wiring
// =============================================================================

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
static void post_reply(const std::string& s) {
    if (g_webview) g_webview->PostWebMessageAsJson(u2w(s).c_str());
}

static void handle_message(const std::string& msg) {
    int id = get_int(msg, "id");
    std::string op = get_str(msg, "op");

    auto reply = [&](const std::string& body){
        char idbuf[32]; snprintf(idbuf, sizeof(idbuf), "%d", id);
        std::string full = "{\"id\":"; full += idbuf; full += ","; full += body; full += "}";
        post_reply(full);
    };

    if (op == "inject") {
        std::thread([id, reply]() {
            std::string err = do_inject();
            char idbuf[32]; snprintf(idbuf, sizeof(idbuf), "%d", id);
            if (err.empty()) {
                post_reply(std::string("{\"id\":") + idbuf + ",\"ok\":true}");
                if (g_settings.autoexec) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    run_autoexec_folder();
                }
            } else {
                post_reply(std::string("{\"id\":") + idbuf + ",\"ok\":false,\"reason\":\"" + json_escape(err) + "\"}");
            }
        }).detach();
        return;
    }
    if (op == "launchRoblox") {
        std::string args = get_str(msg, "args");
        std::thread([id, args]() {
            std::string err = early_bird_launch(args);
            char idbuf[32]; snprintf(idbuf, sizeof(idbuf), "%d", id);
            if (err.empty()) {
                post_reply(std::string("{\"id\":") + idbuf + ",\"ok\":true,\"method\":\"early-bird\"}");
                if (g_settings.autoexec) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    run_autoexec_folder();
                }
            } else {
                post_reply(std::string("{\"id\":") + idbuf + ",\"ok\":false,\"reason\":\"" + json_escape(err) + "\"}");
            }
        }).detach();
        return;
    }
    if (op == "exec") {
        std::string src = get_str(msg, "source");
        if (!pipe_attached()) { reply("\"ok\":false,\"reason\":\"not-attached\""); return; }
        std::string res = pipe_exec(src);
        reply("\"ok\":true,\"result\":\"" + json_escape(res) + "\"");
        return;
    }
    if (op == "isAttached") {
        std::string game = get_roblox_game_title();
        std::string body = std::string("\"ok\":true,\"attached\":") + (pipe_attached() ? "true" : "false");
        if (!game.empty()) body += ",\"game\":\"" + json_escape(game) + "\"";
        reply(body);
        return;
    }
    if (op == "killRoblox") {
        bool ok = kill_all_roblox();
        reply(std::string("\"ok\":") + (ok ? "true" : "false"));
        return;
    }
    if (op == "setPerformance") {
        g_settings.autoinject = get_bool(msg, "autoinject");
        g_settings.autoexec   = get_bool(msg, "autoexec");
        g_settings.fpsuncap   = get_bool(msg, "fpsuncap");
        g_settings.fpstarget  = get_int(msg, "fpstarget");
        g_settings.multi      = get_bool(msg, "multi");
        g_settings.ramlimit   = get_int(msg, "ramlimit");
        g_settings.rejoin     = get_bool(msg, "rejoin");
        g_settings.antiafk    = get_bool(msg, "antiafk");
        g_settings.discord    = get_bool(msg, "discord");
        {
            std::lock_guard<std::mutex> lk(g_settings.m);
            g_settings.cpupriority = get_str(msg, "cpupriority");
        }

        // apply the ones that need immediate action
        write_fps_uncap(g_settings.fpsuncap, g_settings.fpstarget);
        if (g_settings.multi) unlock_multi_instance();
        apply_cpu_priority(g_settings.cpupriority);
        if (g_settings.ramlimit > 0) apply_ram_limit(g_settings.ramlimit);

        reply("\"ok\":true");
        return;
    }
    if (op == "listFiles") {
        auto list = [](const fs::path& dir){
            std::string out = "["; bool first = true;
            if (fs::exists(dir)) for (auto& e : fs::directory_iterator(dir)) {
                if (!e.is_regular_file()) continue;
                if (!first) out += ",";
                out += "\"" + json_escape(e.path().filename().string()) + "\""; first = false;
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
        std::string folder = get_str(msg, "folder");
        std::string name   = get_str(msg, "name");
        fs::path p = data_root() / u2w(folder) / u2w(name);
        std::ifstream f(p, std::ios::binary);
        if (!f) { reply("\"ok\":false,\"reason\":\"not-found\""); return; }
        std::string s((std::istreambuf_iterator<char>(f)), {});
        reply("\"ok\":true,\"content\":\"" + json_escape(s) + "\"");
        return;
    }
    if (op == "saveFile") {
        std::string name = get_str(msg, "name");
        std::string content = get_str(msg, "content");
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

    reply("\"ok\":false,\"reason\":\"unknown-op\"");
}

static LRESULT CALLBACK wndproc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_SIZE:
            if (g_controller) { RECT r; GetClientRect(h, &r); g_controller->put_Bounds(r); }
            return 0;
        case WM_DESTROY:
            g_worker_run = false;
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
                                            handle_message(w2u(raw.get()));
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
        (HBRUSH)(COLOR_WINDOW+1), nullptr, L"vesper_main", nullptr };
    RegisterClassExW(&wc);
    g_hwnd = CreateWindowExW(0, wc.lpszClassName, L"Vesper",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 820,
        nullptr, nullptr, hinst, nullptr);

    if (!init_webview()) {
        MessageBoxW(nullptr,
            L"WebView2 Runtime isn't installed.\n\nGet it from:\nhttps://developer.microsoft.com/microsoft-edge/webview2/",
            L"Vesper", MB_OK|MB_ICONERROR);
        return 1;
    }

    // start the background worker (handles auto-inject, auto-exec, periodic reapply)
    std::thread(background_worker).detach();

    ShowWindow(g_hwnd, nShow);
    UpdateWindow(g_hwnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg); DispatchMessage(&msg);
    }

    g_worker_run = false;
    g_controller.reset();
    g_webview.reset();
    CoUninitialize();
    return 0;
}
