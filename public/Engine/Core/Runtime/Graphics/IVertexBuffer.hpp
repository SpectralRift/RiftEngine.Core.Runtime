#pragma once

#include <Engine\Core\Runtime\Graphics\Vertex.hpp>

namespace engine::core::runtime::graphics {
    struct IVertexBuffer {
        virtual ~IVertexBuffer() = default;

        virtual bool Create() = 0;

        virtual void Destroy() = 0;

        virtual void Bind() = 0;

        virtual void Unbind() = 0;

        virtual void Upload(Vertex *data, size_t size) = 0;

        virtual size_t Size() = 0;

        virtual void Download(Vertex *output) = 0;
    };
}