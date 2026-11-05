#pragma once
#include <cstdint>
#include <cstring>
#include <type_traits>

namespace enc {
template<class T, unsigned Operation, class = std::enable_if_t<
    (std::is_pointer_v<T> || std::is_integral_v<T> || std::is_floating_point_v<T>) &&
    (sizeof(T) == 4 || sizeof(T) == 8) && Operation >= 1 && Operation <= 4>>
class value {
    using bits_type = std::conditional_t<sizeof(T) == 4, std::uint32_t, std::uint64_t>;
    bits_type storage;

public:
    value() = default;
    value(const value&) = delete;
    value& operator=(const value&) = delete;

    T get_at(std::uintptr_t original_slot) const noexcept {
        bits_type stored;
        std::memcpy(&stored, &storage, sizeof(stored));
        const auto address = static_cast<bits_type>(original_slot);
        bits_type decoded;
        if constexpr (Operation == 1) decoded = static_cast<bits_type>(stored - address);
        else if constexpr (Operation == 2) decoded = static_cast<bits_type>(address - stored);
        else if constexpr (Operation == 3) decoded = static_cast<bits_type>(address ^ stored);
        else decoded = static_cast<bits_type>(address + stored);
        if constexpr (std::is_pointer_v<T>) return reinterpret_cast<T>(static_cast<std::uintptr_t>(decoded));
        else {
            T result;
            std::memcpy(&result, &decoded, sizeof(result));
            return result;
        }
    }

    void set_at(T decoded, std::uintptr_t original_slot) noexcept {
        bits_type bits;
        if constexpr (std::is_pointer_v<T>) bits = static_cast<bits_type>(reinterpret_cast<std::uintptr_t>(decoded));
        else std::memcpy(&bits, &decoded, sizeof(bits));
        const auto address = static_cast<bits_type>(original_slot);
        bits_type stored;
        if constexpr (Operation == 1) stored = static_cast<bits_type>(bits + address);
        else if constexpr (Operation == 2) stored = static_cast<bits_type>(address - bits);
        else if constexpr (Operation == 3) stored = static_cast<bits_type>(address ^ bits);
        else stored = static_cast<bits_type>(bits - address);
        std::memcpy(&storage, &stored, sizeof(stored));
    }

    T get() const noexcept { return get_at(reinterpret_cast<std::uintptr_t>(this)); }
    void set(T decoded) noexcept { set_at(decoded, reinterpret_cast<std::uintptr_t>(this)); }
    operator T() const noexcept { return get(); }
    value& operator=(T decoded) noexcept { set(decoded); return *this; }
};

template<class T> using vmval1 = value<T, 1>;
template<class T> using vmval2 = value<T, 2>;
template<class T> using vmval3 = value<T, 3>;
template<class T> using vmval4 = value<T, 4>;
}

namespace structs {
using enc::vmval1;
using enc::vmval2;
using enc::vmval3;
using enc::vmval4;
}

#define CLOSURE_CONT_ENC vmval3
#define LSTATE_STACKSIZE_ENC vmval2
#define PROTO_ABSLINEINFO_ENC vmval4
#define PROTO_DEBUGINSN_ENC vmval3
#define PROTO_LINEINFO_ENC vmval3
#define PROTO_LOCVARS_ENC vmval3
#define PROTO_TYPEINFO_ENC vmval2
#define PROTO_UPVALUES_ENC vmval4
#define PROTO_USERDATA_ENC vmval1
#define TSTRING_HASH_ENC vmval2
#define UDATA_META_ENC vmval2
