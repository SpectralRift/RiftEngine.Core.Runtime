#pragma once

#include <Engine/Core/Math/Vector2.hpp>
#include <Engine/Core/Math/Vector3.hpp>
#include <Engine/Core/Runtime/Graphics/Color.hpp>

namespace engine::core::runtime::graphics {
#pragma pack(push, 1)
    struct Vertex {
        math::Vector3 position;
        math::Vector2 uv;
        math::Vector3 normal;
        Color color;
    };
#pragma pack(pop)
}