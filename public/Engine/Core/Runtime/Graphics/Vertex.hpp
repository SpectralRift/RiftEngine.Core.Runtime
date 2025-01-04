#pragma once

#include <Engine/Core/Math/Vector2.hpp>
#include <Engine/Core/Math/Vector3.hpp>
#include <Engine/Core/Runtime/Graphics/Color.hpp>

namespace engine::core::runtime::graphics {
    enum PrimitiveType {
        PRIMITIVE_TYPE_UNKNOWN,
        PRIMITIVE_TYPE_TRIANGLES,
        PRIMITIVE_TYPE_POINTS,
        PRIMITIVE_TYPE_LINES
    };

#pragma pack(push, 1)
    struct Vertex {
        math::Vector3 position;
        math::Vector2 uv;
        math::Vector3 normal;
        Color color;

        Vertex() = default;

        Vertex(const math::Vector3 &position, const math::Vector2 &uv, const math::Vector3 &normal, const Color &color)
                : position(position), uv(uv), normal(normal), color(color) {}
    };
#pragma pack(pop)
}