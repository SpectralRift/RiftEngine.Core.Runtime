#pragma once

#include <Engine/Core/Runtime/Graphics/Bitmap.hpp>

namespace engine::core::runtime::graphics {
    struct ITexture {
        virtual ~ITexture() = default;

        virtual bool Create(const Bitmap& bitmap) = 0;
        virtual void Destroy() = 0;
        virtual Bitmap Download() = 0;
        virtual math::Vector2 GetSize() = 0;

        virtual void Bind(int samplerSlot) = 0;
        virtual void Unbind() = 0;
    };
}