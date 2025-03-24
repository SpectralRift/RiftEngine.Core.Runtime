#pragma once

#include <cstddef>
#include <cstdint>

#include <string_view>

namespace engine {
    // FNV-1a Implementation

    constexpr uint32_t FNV_PRIME = 16777619u;
    constexpr uint32_t OFFSET_BASIS = 2166136261u;

    constexpr uint32_t FNVHash(const char* str, size_t size, uint32_t hash = OFFSET_BASIS) {
        if(size == 0) {
            return hash;
        }

        return FNVHash(str + 1, size - 1, (hash ^ static_cast<uint8_t>(*str)) * FNV_PRIME);
    }

    constexpr uint32_t FNVConstHash(std::string_view str) {
        return FNVHash(str.data(), str.size());
    }
}