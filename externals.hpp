#pragma once
#include <cstdint>
#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#ifndef REBASE
#define REBASE(x) (x + reinterpret_cast<uintptr_t>(GetModuleHandleA(0)))
#endif
#endif

#pragma once
#include <cstdint>

namespace UpdateCandidates {

inline constexpr uintptr_t Print = 0x1C50690;

inline constexpr uintptr_t OpcodeLookupTable = 0x71CFBA0;

inline constexpr uintptr_t Luau_LuaNil = 0x6735848;

inline constexpr uintptr_t Luau_LuaDummy = 0x67352E8;

inline constexpr uintptr_t Luau_LuauExecute = 0x26230C0;

inline constexpr uintptr_t Luau_LuaDThrow = 0x25F6560;

inline constexpr uintptr_t Luau_LuauLoad = 0x41C70F0;

inline constexpr uintptr_t Miscellaneous_Children = 0x70;

inline constexpr uintptr_t Miscellaneous_Parent = 0x60;

inline constexpr uintptr_t Miscellaneous_ScriptContextVTables[3] = {0x70271F8, 0x7027230, 0x7027240};

inline constexpr uintptr_t TaskScheduler_Pointer = 0x8C9D698;

inline constexpr uintptr_t TaskScheduler_JobsStart = 0xC8;

inline constexpr uintptr_t TaskScheduler_JobsEnd = 0xD0;

inline constexpr uintptr_t TaskScheduler_JobStride = 0x10;

inline constexpr uintptr_t Compression_ZstdDecompress = 0x2677FC0;

inline constexpr uintptr_t Signals_DisconnectConnection = 0x419A260;

inline constexpr uintptr_t Signals_GetValues = 0x4134690;

inline constexpr uintptr_t FastFlags_Registry = 0x83EBA48;

inline constexpr uintptr_t FastFlags_RegistryEnd = 0x8;

inline constexpr uintptr_t FastFlags_RegistryBuckets = 0x18;

inline constexpr uintptr_t FastFlags_RegistryMask = 0x30;

inline constexpr uintptr_t FastFlags_NodeNext = 0x8;

inline constexpr uintptr_t FastFlags_NodeKey = 0x10;

inline constexpr uintptr_t FastFlags_NodeKeyLength = 0x20;

inline constexpr uintptr_t FastFlags_NodeKeyCapacity = 0x28;

inline constexpr uintptr_t FastFlags_NodeDescriptor = 0x30;

inline constexpr uintptr_t FastFlags_DescriptorType = 0x10;

inline constexpr uintptr_t FastFlags_DescriptorStorage = 0x20;

inline constexpr uintptr_t Raknet_Receive = 0x28425A0;

inline constexpr uintptr_t Raknet_RakPeerVTable = 0x6F5F080;

inline constexpr uintptr_t Raknet_VTableEntries = 0x7C;

inline constexpr uintptr_t Reflection_HashLookup = 0x2A27430;

inline constexpr uintptr_t Reflection_GetProperty = 0x1C8E7F0;

inline constexpr uintptr_t Reflection_BitFlags = 0xAC;

inline constexpr uintptr_t Reflection_ScriptableMask = 0x10;

inline constexpr uintptr_t Reflection_HashMap = 0x1E0;

inline constexpr uintptr_t Reflection_BucketIndex = 0x1E8;

inline constexpr uintptr_t Reflection_PropertyTable = 0x1F0;

inline constexpr uintptr_t Reflection_BucketMask = 0x1F8;

inline constexpr uintptr_t Reflection_GetSet = 0xB0;

inline constexpr uintptr_t Reflection_TypeInfo = 0x70;

inline constexpr uintptr_t Reflection_TypeNumber = 0x30;

inline constexpr uintptr_t Scripts_ModuleScriptIsRobloxScript = 0x150;

inline constexpr uintptr_t Scripts_RequireBypass = 0xB50;

inline constexpr uintptr_t Identity_IdentityPointer = 0x83B6678;

inline constexpr uintptr_t Identity_GetTlsPointer = 0xC700;

inline constexpr uintptr_t Identity_GetCapabilities = 0x1C905D0;

inline constexpr uintptr_t Identity_ExtraSpaceShared = 0x18;

inline constexpr uintptr_t Identity_ExtraSpaceIdentity = 0x60;

inline constexpr uintptr_t Identity_ExtraSpaceCapabilities = 0x80;

inline constexpr uintptr_t Identity_ExtraSpaceActor = 0x40;

inline constexpr uintptr_t Identity_SharedScriptVmState = 0x28;

inline constexpr uintptr_t Identity_SharedScriptContext = 0x10;

inline constexpr uintptr_t Identity_ExtraSpaceSourcePtr = 0x88;

inline constexpr uintptr_t Identity_RobloxScriptCapability = 0x8;

inline constexpr uintptr_t Task_Spawn = 0x432E720;

inline constexpr uintptr_t Task_Delay = 0x432EAB0;

inline constexpr uintptr_t Luau_LuaO_NilObject = 0x6735848;

inline constexpr uintptr_t Luau_LuaH_DummyNode = 0x67352E8;
}
