#pragma once

#include <string_view>
#include <memory>

#include <Engine/Core/Runtime/Graphics/IGraphicsBackend.hpp>

// forward definition for Window Interface
namespace engine::core::runtime {
    struct IWindow;
}

namespace engine::core::runtime::graphics {
    struct IGraphicsContext {
        virtual ~IGraphicsContext() = default;

        virtual bool Create() = 0;

        virtual void Destroy() = 0;

        virtual void Bind() = 0;

        virtual void Discard() = 0;

        virtual void Present() = 0;

        virtual void PreRender() {};

        virtual void PostRender() {};

        virtual IGraphicsBackend *GetBackend() = 0;

        virtual IWindow *GetOwnerWindow() = 0;
    };
}