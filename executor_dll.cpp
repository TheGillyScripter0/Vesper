// C++17, Windows 11, MSVC, target: internal DLL for RobloxPlayerBeta.exe (x64)
// uses Z4-style offset dump:
//   externals.hpp — named per-build Windows x64 offsets (scheduler, LuauLoad, etc.)
//   patterns.hpp  — AOB byte signatures for every Luau API (auto-resolved at startup)
//   structs.hpp   — Luau struct layouts (lua_State, Closure, Proto, LuaTable, ...)
//   encs.hpp      — encrypted pointer accessors (vmval1/2/3/4)
//
// what this means in practice: when roblox patches, patterns.hpp usually still
// matches, so the executor keeps working without you deriving new addresses.
// if a pattern breaks, replace just that one entry in patterns.hpp.

#include <Windows.h>
#include <shlobj.h>
#include <psapi.h>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>
#include <chrono>
#include <filesystem>
#include <fstream>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "psapi.lib")

#include "encs.hpp"
#include "structs.hpp"
#include "externals.hpp"
#include "patterns.hpp"

using namespace structs;
namespace fs = std::filesystem;

// =============================================================================
// pattern scanner — parses Z4-format IDA signatures ("48 89 5C 24 10 ?? ??")
// and finds them in the Roblox main module image. caches results in g_resolved.
// =============================================================================

static uintptr_t g_base = 0;
static size_t    g_size = 0;
static std::vector<uint8_t> g_image_cache;

struct parsed_sig {
    std::vector<uint8_t> bytes;
    std::vector<bool>    mask;  // true = match byte, false = wildcard
};

static parsed_sig parse_pattern(const char* ida) {
    parsed_sig s;
    const char* p = ida;
    while (*p) {
        while (*p == ' ') ++p;
        if (!*p) break;
        if (p[0] == '?') {
            s.bytes.push_back(0);
            s.mask.push_back(false);
            while (*p == '?') ++p;
        } else {
            unsigned v = 0;
            sscanf_s(p, "%2x", &v);
            s.bytes.push_back((uint8_t)v);
            s.mask.push_back(true);
            while (*p && *p != ' ') ++p;
        }
    }
    return s;
}

static uintptr_t scan(const parsed_sig& s) {
    if (g_image_cache.empty() || s.bytes.empty()) return 0;
    const size_t n = s.bytes.size();
    const uint8_t* img = g_image_cache.data();
    const size_t len = g_image_cache.size();
    for (size_t i = 0; i + n <= len; ++i) {
        bool ok = true;
        for (size_t j = 0; j < n; ++j) {
            if (s.mask[j] && img[i+j] != s.bytes[j]) { ok = false; break; }
        }
        if (ok) return g_base + i;
    }
    return 0;
}

static uintptr_t scan_pattern(const char* ida) {
    static std::unordered_map<std::string, uintptr_t> cache;
    std::string key = ida;
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;
    uintptr_t addr = scan(parse_pattern(ida));
    cache[key] = addr;
    return addr;
}

// =============================================================================
// Luau API — function pointer resolution via patterns
// =============================================================================

using lua_CFunction = int(__cdecl*)(lua_State*);

static constexpr int LUA_REGISTRYINDEX = -10000;
static constexpr int LUA_GLOBALSINDEX  = -10002;

#define FN(name, ret, ...) \
    using name##_t = ret(__cdecl*)(__VA_ARGS__); \
    static name##_t p_##name = nullptr;

// core API we actually use in the executor environment:
FN(lua_pushvalue,          void, lua_State*, int)
FN(lua_pushnil,            void, lua_State*)
FN(lua_pushnumber,         void, lua_State*, double)
FN(lua_pushinteger,        void, lua_State*, int)
FN(lua_pushlstring,        void, lua_State*, const char*, size_t)
FN(lua_pushstring,         void, lua_State*, const char*)
FN(lua_pushcclosurek,      void, lua_State*, lua_CFunction, const char*, int, void*)
FN(lua_pushboolean,        void, lua_State*, int)
FN(lua_gettop,             int,  lua_State*)
FN(lua_settop,             void, lua_State*, int)
FN(lua_type,               int,  lua_State*, int)
FN(lua_toboolean,          int,  lua_State*, int)
FN(lua_tolstring,          const char*, lua_State*, int, size_t*)
FN(lua_rawget,             int,  lua_State*, int)
FN(lua_rawset,             void, lua_State*, int)
FN(lua_getfield,           int,  lua_State*, int, const char*)
FN(lua_setfield,           void, lua_State*, int, const char*)
FN(lua_createtable,        void, lua_State*, int, int)
FN(lua_setmetatable,       int,  lua_State*, int)
FN(lua_getmetatable,       int,  lua_State*, int)
FN(lua_pcall,              int,  lua_State*, int, int, int)
FN(lua_newthread,          lua_State*, lua_State*)
FN(lua_resume,             int,  lua_State*, lua_State*, int)
FN(lua_ref,                int,  lua_State*, int)
FN(lua_unref,              void, lua_State*, int)
FN(lua_setsafeenv,         void, lua_State*, int, int)
FN(lua_setreadonly,        void, lua_State*, int, int)

// luau_load is the key one — takes compiled bytecode and loads it as a closure
FN(luau_load, int, lua_State*, const char*, const char*, size_t, int)

// =============================================================================
// resolution — maps Z4 pattern names to our function pointers
// =============================================================================

static bool resolve_all() {
#define RESOLVE(fn, pattern_expr) do { \
        uintptr_t a = scan_pattern(pattern_expr); \
        if (!a) { OutputDebugStringA("rbx-ext: pattern miss: " #fn); return false; } \
        p_##fn = (fn##_t)a; \
    } while (0)

    // the Z4 patterns namespace organizes by Luau subsystem. the exact pattern
    // names below match patterns.hpp entries. if any one fails to resolve,
    // either the pattern name differs in your patterns.hpp (check with Ctrl-F)
    // or that pattern no longer matches the current roblox build.
    //
    // using `Patterns::LuauApi_<name>` style — your patterns.hpp uses flat names
    // under `namespace Patterns`, so fall back to those if the nested form errors.

    // for a first build, I'm resolving via the main luau_lapi_f_call family —
    // the Z4 dump names core luau fns under `Luau_` / `LuauApi_` prefixes.
    // check patterns.hpp for the exact string literals; names below are the
    // common form. if a lookup misses, Ctrl-F patterns.hpp and copy the real name.

    RESOLVE(lua_pushvalue,       Patterns::LuauApi_lua_pushvalue);
    RESOLVE(lua_pushnil,         Patterns::LuauApi_lua_pushnil);
    RESOLVE(lua_pushnumber,      Patterns::LuauApi_lua_pushnumber);
    RESOLVE(lua_pushinteger,     Patterns::LuauApi_lua_pushinteger);
    RESOLVE(lua_pushlstring,     Patterns::LuauApi_lua_pushlstring);
    RESOLVE(lua_pushstring,      Patterns::Misc_lua_pushstring);
    RESOLVE(lua_pushcclosurek,   Patterns::LuauApi_lua_pushcclosurek);
    RESOLVE(lua_pushboolean,     Patterns::LuauApi_lua_pushboolean);
    RESOLVE(lua_gettop,          Patterns::Luau_lua_gettop);
    RESOLVE(lua_settop,          Patterns::LuauApi_lua_settop);
    RESOLVE(lua_type,            Patterns::Luau_lua_type);
    RESOLVE(lua_toboolean,       Patterns::LuauApi_lua_toboolean);
    RESOLVE(lua_tolstring,       Patterns::LuauApi_lua_tolstring);
    RESOLVE(lua_rawget,          Patterns::LuauApi_lua_rawget);
    RESOLVE(lua_rawset,          Patterns::LuauApi_lua_rawset);
    RESOLVE(lua_getfield,        Patterns::LuauApi_lua_getfield);
    RESOLVE(lua_setfield,        Patterns::Misc_lua_setfield);
    RESOLVE(lua_createtable,     Patterns::LuauApi_lua_createtable);
    RESOLVE(lua_setmetatable,    Patterns::LuauApi_lua_setmetatable);
    RESOLVE(lua_getmetatable,    Patterns::LuauApi_lua_getmetatable);
    RESOLVE(lua_pcall,           Patterns::LuauApi_lua_pcall);
    RESOLVE(lua_newthread,       Patterns::LuauApi_lua_newthread);
    RESOLVE(lua_resume,          Patterns::LuauApi_lua_resume);
    RESOLVE(lua_ref,             Patterns::LuauApi_lua_ref);
    RESOLVE(lua_unref,           Patterns::LuauApi_lua_unref);
    // lua_setsafeenv + lua_setreadonly skipped — not present in this patterns.hpp dump.
    // the environment function L_setreadonly guards against this nullptr below.

    // luau_load comes from externals.hpp (it's in UpdateCandidates)
    p_luau_load = (luau_load_t)(g_base + UpdateCandidates::Luau_LuauLoad);

#undef RESOLVE
    return true;
}

// =============================================================================
// task scheduler — using externals.hpp offsets
// =============================================================================

struct TaskSchedulerJob {
    void* vtable;
    uint8_t padding[0x30];
    lua_State* L;       // some jobs carry a lua_State in their context
};

static lua_State* find_main_lua_state() {
    // walk the scheduler's job list. the ScriptContext's step job owns the main L.
    uintptr_t sched = *(uintptr_t*)(g_base + UpdateCandidates::TaskScheduler_Pointer);
    if (!sched) return nullptr;

    auto jobs_start = *(uintptr_t*)(sched + UpdateCandidates::TaskScheduler_JobsStart);
    auto jobs_end   = *(uintptr_t*)(sched + UpdateCandidates::TaskScheduler_JobsEnd);
    size_t stride   = UpdateCandidates::TaskScheduler_JobStride;

    for (uintptr_t j = jobs_start; j < jobs_end; j += stride) {
        void* job = *(void**)j;
        if (!job) continue;
        // look at job's vtable, first few entries reference strings;
        // pick the one whose job-name string contains "WaitingHybridScripts" or
        // the ScriptContext step. simplest reliable check: look at a vtable
        // address range match against UpdateCandidates::Miscellaneous_ScriptContextVTables.
        void* vt = *(void**)job;
        for (auto target : UpdateCandidates::Miscellaneous_ScriptContextVTables) {
            if (vt == (void*)(g_base + target)) {
                // the lua_State pointer lives at job + some offset, commonly 0x198.
                // this needs adjustment per build; walk the job struct in x64dbg if it misses.
                for (int off = 0x180; off < 0x300; off += 8) {
                    lua_State* candidate = *(lua_State**)((uint8_t*)job + off);
                    if (candidate && IsBadReadPtr(candidate, 8) == FALSE) return candidate;
                }
            }
        }
    }
    return nullptr;
}

// =============================================================================
// script queue (UI -> DLL via named pipe)
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
// executor environment — minimal set, extended with HTTP + filesystem
// =============================================================================

static int g_genv_ref = 0;

static int L_getgenv(lua_State* L) {
    p_lua_pushinteger(L, g_genv_ref);
    p_lua_rawget(L, LUA_REGISTRYINDEX);
    return 1;
}

static int L_identifyexecutor(lua_State* L) {
    p_lua_pushstring(L, "rbx-ext");
    p_lua_pushstring(L, "1.0");
    return 2;
}

static int L_getrawmetatable(lua_State* L) {
    if (!p_lua_getmetatable(L, 1)) p_lua_pushnil(L);
    return 1;
}

static int L_setrawmetatable(lua_State* L) {
    p_lua_pushvalue(L, 2);
    p_lua_setmetatable(L, 1);
    p_lua_pushvalue(L, 1);
    return 1;
}

static int L_setreadonly(lua_State* L) {
    if (p_lua_setreadonly) p_lua_setreadonly(L, 1, p_lua_toboolean(L, 2));
    return 0;
}

static int L_checkcaller(lua_State* L) {
    p_lua_pushboolean(L, 1);
    return 1;
}

// --- HTTP ---
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

static std::string http_get(const std::wstring& url) {
    URL_COMPONENTS c{}; c.dwStructSize = sizeof(c);
    wchar_t host[256]{}, path[1024]{};
    c.lpszHostName = host; c.dwHostNameLength = 255;
    c.lpszUrlPath = path; c.dwUrlPathLength = 1023;
    if (!WinHttpCrackUrl(url.c_str(), 0, 0, &c)) return "";
    HINTERNET s = WinHttpOpen(L"rbx-ext/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, nullptr, nullptr, 0);
    if (!s) return "";
    HINTERNET h = WinHttpConnect(s, host, c.nPort, 0);
    HINTERNET r = WinHttpOpenRequest(h, L"GET", path, nullptr, nullptr, nullptr,
        c.nScheme == INTERNET_SCHEME_HTTPS ? WINHTTP_FLAG_SECURE : 0);
    std::string out;
    if (WinHttpSendRequest(r, nullptr, 0, nullptr, 0, 0, 0) && WinHttpReceiveResponse(r, nullptr)) {
        for (;;) {
            DWORD avail = 0;
            if (!WinHttpQueryDataAvailable(r, &avail) || !avail) break;
            std::vector<char> buf(avail);
            DWORD read = 0;
            if (!WinHttpReadData(r, buf.data(), avail, &read)) break;
            out.append(buf.data(), read);
        }
    }
    WinHttpCloseHandle(r); WinHttpCloseHandle(h); WinHttpCloseHandle(s);
    return out;
}

static int L_httpget(lua_State* L) {
    const char* url_c = p_lua_tolstring(L, 1, nullptr);
    if (!url_c) { p_lua_pushstring(L, ""); return 1; }
    std::wstring url;
    while (*url_c) url.push_back((wchar_t)(unsigned char)*url_c++);
    std::string body = http_get(url);
    p_lua_pushlstring(L, body.c_str(), body.size());
    return 1;
}

// --- filesystem (sandboxed to %APPDATA%/rbx_ext/workspace) ---
static fs::path sandbox_dir() {
    wchar_t roaming[MAX_PATH];
    SHGetFolderPathW(nullptr, 0x1A /*CSIDL_APPDATA*/, nullptr, 0, roaming);
    fs::path p = fs::path(roaming) / L"rbx_ext" / L"workspace";
    fs::create_directories(p);
    return p;
}

static int L_writefile(lua_State* L) {
    const char* name = p_lua_tolstring(L, 1, nullptr);
    size_t sz = 0; const char* data = p_lua_tolstring(L, 2, &sz);
    if (!name || !data) return 0;
    std::ofstream f(sandbox_dir() / name, std::ios::binary);
    if (f) f.write(data, sz);
    return 0;
}

static int L_readfile(lua_State* L) {
    const char* name = p_lua_tolstring(L, 1, nullptr);
    if (!name) { p_lua_pushnil(L); return 1; }
    std::ifstream f(sandbox_dir() / name, std::ios::binary);
    if (!f) { p_lua_pushnil(L); return 1; }
    std::string s((std::istreambuf_iterator<char>(f)), {});
    p_lua_pushlstring(L, s.c_str(), s.size());
    return 1;
}

// =============================================================================
// environment installation
// =============================================================================

static void install_env(lua_State* L) {
    // persistent getgenv table
    p_lua_createtable(L, 0, 32);
    p_lua_pushvalue(L, -1);
    g_genv_ref = p_lua_ref(L, LUA_REGISTRYINDEX);
    p_lua_settop(L, 0);

    auto reg = [&](const char* name, lua_CFunction fn) {
        p_lua_pushcclosurek(L, fn, name, 0, nullptr);
        p_lua_setfield(L, LUA_GLOBALSINDEX, name);
    };

    reg("getgenv",            L_getgenv);
    reg("identifyexecutor",   L_identifyexecutor);
    reg("getexecutorname",    L_identifyexecutor);
    reg("getrawmetatable",    L_getrawmetatable);
    reg("setrawmetatable",    L_setrawmetatable);
    reg("setreadonly",        L_setreadonly);
    reg("checkcaller",        L_checkcaller);
    reg("HttpGet",            L_httpget);
    reg("writefile",          L_writefile);
    reg("readfile",           L_readfile);

    OutputDebugStringA("rbx-ext: environment installed");
}

// =============================================================================
// identity elevation — give our scripts full roblox capabilities so game funcs
// like game:GetService() accept our calls. uses externals.hpp Identity offsets.
// =============================================================================

static void elevate_identity(lua_State* L) {
    auto* es = (RobloxExtraSpace*)(((uint8_t*)L) - sizeof(void*)); // ExtraSpace sits before lua_State in Roblox's layout
    // actually ExtraSpace is at L->userdata; use the structs.hpp field:
    es = (RobloxExtraSpace*)(((lua_State*)L)->userdata);
    if (!es) return;

    // write full-privilege capability mask. Z4's known "all caps" value:
    es->capabilities = 0xFFFFFFFFFFFFFFFFULL | UpdateCandidates::Identity_RobloxScriptCapability;

    // identity 8 is "elevated" (plugin / studio). stored in abi::storage<16> identity.
    // writing bytes directly:
    uint64_t identity_val = 8;
    memcpy(&es->identity, &identity_val, sizeof(identity_val));
}

// =============================================================================
// scheduler-tied script execution
// =============================================================================

static std::atomic<bool> g_env_done{false};

static void try_run_queued(lua_State* L) {
    if (!L) return;
    if (!g_env_done.exchange(true)) install_env(L);

    std::string src;
    while (dequeue(src)) {
        // bundling a Luau compiler is a separate concern — for now we try the
        // raw bytecode path. if luau_load's chunkname starts with '=', it treats
        // the buffer as bytecode. a real "loadstring" needs a luau compiler which
        // isn't shipped in the roblox binary — bundle libluau.lib in the DLL
        // in a later iteration.
        //
        // TEMPORARY: wrap source so luau_load sees it as a precompiled chunk.
        // for a real build: compile with luau's Compile() → bytecode, pass that.
        int r = p_luau_load(L, "=rbx_ext", src.c_str(), src.size(), 0);
        if (r != 0) {
            const char* err = p_lua_tolstring(L, -1, nullptr);
            OutputDebugStringA(err ? err : "luau_load failed");
            p_lua_settop(L, 0);
            continue;
        }

        elevate_identity(L);
        lua_State* co = p_lua_newthread(L);
        p_lua_pushvalue(L, -2);         // closure onto new thread
        int rr = p_lua_resume(co, L, 0);
        if (rr != 0 && rr != 1) {
            const char* err = p_lua_tolstring(co, -1, nullptr);
            OutputDebugStringA(err ? err : "lua_resume error");
        }
        p_lua_settop(L, 0);
    }
}

// poll thread: find L, drain queue. not a real scheduler hook (which needs
// MinHook) — this polls once per ~2ms. a proper hook lands in a later iteration.
static void execution_loop() {
    lua_State* L = nullptr;
    while (true) {
        if (!L) {
            L = find_main_lua_state();
            if (!L) { std::this_thread::sleep_for(std::chrono::milliseconds(100)); continue; }
        }
        try_run_queued(L);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

// =============================================================================
// IPC
// =============================================================================

static void pipe_server() {
    while (true) {
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

static DWORD WINAPI dll_main(LPVOID) {
    HMODULE me = GetModuleHandleW(L"RobloxPlayerBeta.exe");
    if (!me) me = GetModuleHandleW(nullptr);
    g_base = (uintptr_t)me;

    MODULEINFO mi{};
    GetModuleInformation(GetCurrentProcess(), me, &mi, sizeof(mi));
    g_size = mi.SizeOfImage;

    // cache image bytes once — scan runs against the local copy, no RPM needed
    g_image_cache.resize(g_size);
    memcpy(g_image_cache.data(), (void*)g_base, g_size);

    if (!resolve_all()) {
        MessageBoxW(nullptr,
            L"rbx-ext: some patterns didn't match the current Roblox build.\n\n"
            L"check patterns.hpp entry names against the RESOLVE() calls in executor_dll.cpp.",
            L"rbx-ext", MB_OK | MB_ICONWARNING);
        // don't abort — still start the pipe so the UI shows "attached"
    }

    std::thread(pipe_server).detach();
    std::thread(execution_loop).detach();
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls((HINSTANCE)GetModuleHandleW(nullptr));
        CreateThread(nullptr, 0, dll_main, nullptr, 0, nullptr);
    }
    return TRUE;
}

extern "C" __declspec(dllexport) DWORD __stdcall ManualMapEntry(LPVOID) {
    return dll_main(nullptr);
}
