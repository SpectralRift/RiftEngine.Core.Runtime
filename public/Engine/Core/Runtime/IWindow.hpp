#pragma once

#include <string_view>

#include <Engine/Core/Math/Vector2.hpp>
#include <Engine/Core/Runtime/Graphics/IGraphicsContext.hpp>

namespace engine::core::runtime {
    struct IWindow {
        virtual ~IWindow() = default;

        virtual bool Create() = 0;
        virtual void Destroy() = 0;

        virtual void ProcessEvents() = 0;
        virtual void* GetHandle() = 0;
        virtual graphics::IGraphicsContext* GetGraphicsContext() = 0;

        virtual void Show() = 0;
        virtual void Hide() = 0;

        virtual void SetTitle(std::string_view title) = 0;

        // ToDo: make Vector2 class
        virtual void SetPosition(const math::Vector2& position) = 0;
        virtual math::Vector2 GetPosition() = 0;

        virtual void SetSize(const math::Vector2& size) = 0;
        virtual math::Vector2 GetSize() = 0;
    };
}