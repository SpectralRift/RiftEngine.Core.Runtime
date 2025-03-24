#pragma once

#include <string>
#include <string_view>

namespace engine::core::runtime::input {
    struct InputKey {
        InputKey(std::string_view name, std::string_view displayName) : m_Name(name), m_DisplayName(displayName) {}
        InputKey(const InputKey& other) = default;

        std::string GetName() const { return m_Name; }
        std::string GetDisplayName() const { return m_DisplayName; }
    protected:
        std::string m_Name;
        std::string m_DisplayName;
    };
}