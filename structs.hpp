#pragma once
#include <cstddef>
#include <cstdint>
#include "encs.hpp"

namespace structs {
union GCObject;
struct Closure;
struct LuaNode;
struct lua_Debug;
struct RobloxExtraSpace;
struct FeedbackVectorSlot;
union Value {
    GCObject* gc;
    void* p;
    double n;
    int b;
    int64_t l;
    float v[2];
};
struct CallInfo;
struct Closure;
struct LuaTable;
struct Proto;
struct RobloxExtraSpace;
struct Shared;
struct TString;
struct TValue;
struct Udata;
struct global_State;
struct lua_Page;
struct lua_State;
struct LocVar;
struct Shared;
struct lua_Page;

namespace abi {
template<size_t Size> struct alignas(8) storage { std::byte bytes[Size]; };
template<class T> struct shared_ptr { T* pointer; void* control; T* get() const noexcept { return pointer; } };
template<class T> using weak_ptr = shared_ptr<T>;
}
using Instruction = uint32_t;
using lua_CFunction = int (*)(lua_State*);
using lua_Continuation = int (*)(lua_State*, int);
using lua_Alloc = void* (*)(void*, void*, size_t, size_t);
using lua_CageAlloc = void* (*)(void*, void*, size_t, size_t, int);
using lua_UserdataMark = void (*)(lua_State*, void*);
using lua_EmbedderMark = void (*)(lua_State*, int);
using lua_EmbedderGc = void (*)(lua_State*, lua_EmbedderMark);
using registryfree_t = uint32_t;
struct alignas(8) UpVal { std::byte storage[40]; };
struct alignas(8) GCStats { std::byte storage[184]; };
struct alignas(8) GCMetrics { std::byte storage[472]; };
struct alignas(8) lua_ExecutionCallbacks { std::byte storage[72]; };
struct alignas(8) lua_UdataDirectAccessData { std::byte storage[72]; };
inline constexpr size_t LUA_T_COUNT = 14;
inline constexpr size_t LUA_UTAG_LIMIT = 128;
inline constexpr size_t UTAG_INTERNAL_LIMIT = 130;
inline constexpr size_t TM_N = 21;

struct Proto {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    uint8_t padding_3[0x5];
    PROTO_LINEINFO_ENC<unsigned char*> lineinfo;
    PROTO_UPVALUES_ENC<TString**> upvalues;
    uint8_t padding_18[0x28];
    PROTO_TYPEINFO_ENC<unsigned char*> typeinfo;
    uint8_t padding_48[0x10];
    Proto** p;
    PROTO_LOCVARS_ENC<struct LocVar*> locvars;
    uint8_t padding_68[0x8];
    PROTO_USERDATA_ENC<uint64_t*> userdata;
    PROTO_ABSLINEINFO_ENC<int*> abslineinfo;
    TValue* k;
    unsigned int* code;
    PROTO_DEBUGINSN_ENC<unsigned char*> debuginsn;
    int sizeupvalues;
    uint8_t padding_9c[0x4];
    int sizelocvars;
    uint8_t padding_a4[0x8];
    int sizep;
    int sizek;
    int sizetypeinfo;
    int sizecode;
    int sizelineinfo;
    struct FeedbackVectorSlot* feedbackvec;
    int feedbackvecsize;
    uint8_t padding_cc[0x1c];
};

struct lua_State {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    uint8_t status;
    uint8_t padding_4[0x1];
    bool singlestep;
    uint8_t padding_6[0x2];
    unsigned short nCcalls;
    unsigned short baseCcalls;
    unsigned int cachedslot;
    CallInfo* end_ci;
    CallInfo* base_ci;
    struct RobloxExtraSpace* userdata;
    uint8_t padding_28[0x8];
    CallInfo* ci;
    global_State* global;
    TValue* stack;
    TValue* top;
    TValue* base;
    uint8_t padding_58[0x18];
    LSTATE_STACKSIZE_ENC<int> stacksize;
    int size_ci;
    UpVal* openupval;
    uint8_t padding_80[0x8];
};

struct RobloxExtraSpace {
    RobloxExtraSpace* next;
    void* _container;
    RobloxExtraSpace* prev;
    abi::shared_ptr<Shared> shared;
    uint8_t padding_28[0x8];
    abi::weak_ptr<void const> InstanceDefiningCapabilities;
    abi::weak_ptr<uintptr_t> actor;
    uint8_t padding_50[0x8];
    void* flyweightPtr;
    abi::storage<16> identity;
    void* scriptContext;
    uint8_t padding_78[0x8];
    uint64_t capabilities;
    abi::weak_ptr<uintptr_t> script;
    uint8_t padding_98[0x20];
};

struct TValue {
    Value value;
    int32_t extra;
    int32_t tt;
};

struct alignas(16) global_State {
    uint8_t padding_0[0x10];
    GCObject* gray;
    GCObject* weak;
    uint8_t padding_20[0x8];
    lua_Alloc frealloc;
    void* ud;
    uint8_t padding_38[0x1];
    unsigned char gcstate;
    uint8_t padding_3a[0x2];
    int gcgoal;
    int gcstepsize;
    int gcstepmul;
    size_t GCthreshold;
    size_t totalbytes;
    uint8_t padding_58[0x18];
    lua_State* mainthread;
    UpVal uvhead;
    uint8_t padding_a0[0x568];
    TValue pseudotemp;
    TValue registry;
    registryfree_t registryfree;
    uint8_t padding_62c[0xc];
    uint64_t rngstate;
    uint8_t padding_640[0x3208];
    size_t memcatbytes[256];
    void (*udatagc[128])(struct lua_State*, void*);
    lua_UserdataMark udatamark[LUA_UTAG_LIMIT];
    LuaTable* udatamt[LUA_UTAG_LIMIT];
    TValue weakregistry;
    int weakregistryfree;
    int weakregistrytop;
    lua_EmbedderGc embeddergc;
    TString* lightuserdataname[128];
    uint8_t padding_5068[0x420];
    uint64_t ptrenckeynew[8];
    bool ptrencactive;
    uint8_t padding_54c9[0x2a7];
};

struct Udata {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    unsigned char tag;
    int len;
    UDATA_META_ENC<struct LuaTable*> metatable;
    char data[1];
    uint8_t padding_11[0x7];
};

struct Closure {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    unsigned char isC;
    unsigned char nupvalues;
    uint8_t padding_5[0x3];
    GCObject* gclist;
    LuaTable* env;
    union {
        struct {
            Proto* p;
            TValue uprefs[1];
            uint8_t padding_18[0x10];
        } l;
        struct {
            lua_CFunction f;
            CLOSURE_CONT_ENC<lua_Continuation> cont;
            TString* debugname;
            TValue upvals[1];
        } c;
    };
};

struct CallInfo {
    Proto* p;
    TValue* func;
    TValue* base;
    uint8_t padding_18[0x8];
    union {
        int errfunc;
        const Instruction* savedpc;
    };
    int nresults;
    unsigned int flags;
};

struct TString {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    uint8_t padding_3[0x1];
    uint16_t atomflag;
    int16_t atom;
    TString* next;
    TSTRING_HASH_ENC<unsigned int> hash;
    unsigned int len;
    char data[1];
    uint8_t padding_19[0x7];
};

struct Shared {
    abi::storage<16> allThreads;
    void* scriptContext;
    void* engineContext;
    void* needToFree;
    void* scriptVmState;
    int threadCount;
    uint8_t padding_34[0x4];
};

struct lua_Page {
    lua_Page* listprev;
    uint8_t padding_8[0x40];
};

struct LuaTable {
    uint8_t padding_0[0x2];
    uint8_t memcat;
    uint8_t tmcache;
    uint8_t lsizenode;
    uint8_t readonly;
    uint8_t padding_6[0x1];
    uint8_t nodemask8;
    int sizearray;
    union {
        int aboundary;
        int lastfree;
    };
    LuaTable* metatable;
    LuaNode* node;
    GCObject* gclist;
    TValue* array;
};
}
