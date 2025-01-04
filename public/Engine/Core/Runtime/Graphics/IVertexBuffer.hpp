#pragma once

#include <vector>

#include <Engine/Core/Runtime/Graphics/Vertex.hpp>

namespace engine::core::runtime::graphics {
    enum BufferUsageHint {
        BUFFER_USAGE_HINT_UNKNOWN,
        BUFFER_USAGE_HINT_STREAM,
        BUFFER_USAGE_HINT_STATIC,
        BUFFER_USAGE_HINT_DYNAMIC,
    };

    struct IVertexBuffer {
        virtual ~IVertexBuffer() = default;

        virtual bool Create() = 0;

        virtual void Destroy() = 0;

        virtual void Bind() = 0;

        virtual void Unbind() = 0;

        virtual void Draw() = 0;

        // directly uploads vertices to GPU VRAM
        virtual void Upload(const std::vector<Vertex>& data, PrimitiveType type, BufferUsageHint usage) = 0;

        virtual size_t Size() = 0;

        virtual PrimitiveType GetPrimitiveType() = 0;

        // downloads vertices from GPU VRAM
        virtual std::vector<Vertex> Download() = 0;
    };
}