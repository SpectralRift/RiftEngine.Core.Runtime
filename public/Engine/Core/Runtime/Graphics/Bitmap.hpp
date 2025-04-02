#pragma once

#include <Engine/Core/Runtime/Graphics/Color.hpp>
#include <Engine/Core/Math/Vector2.hpp>

namespace engine::core::runtime::graphics {
    struct Bitmap {
        Bitmap() = default;

        Bitmap(std::vector<Color> data, math::Vector2 size)
                : m_Data{std::move(data)}, m_Size{size} {}

        Bitmap(const Bitmap &rhs)
                : m_Data{rhs.m_Data}, m_Size{rhs.m_Size} {}

        Bitmap &operator=(const Bitmap &rhs) {
            m_Data = rhs.m_Data;
            m_Size = rhs.m_Size;
            return *this;
        }

        const std::vector<Color> & GetPixels() const {
            return m_Data;
        }

        void SetPixels(std::vector<Color> data) {
            m_Data = std::move(data);
        }

        math::Vector2 Size() const {
            return m_Size;
        }

        void SetSize(math::Vector2 size) {
            m_Size = size;
        }

    protected:
        math::Vector2 m_Size;
        std::vector<Color> m_Data;
    };
}