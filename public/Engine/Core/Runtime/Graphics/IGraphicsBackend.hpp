#pragma once

#include <string>
#include <memory>

#include <Engine\Core\Runtime\Graphics\Color.hpp>
#include <Engine\Core\Math\Vector2.hpp>

namespace engine::core::runtime::graphics {
    struct IGraphicsBackend {
        virtual ~IGraphicsBackend() = default;

        virtual bool Initialize() = 0;

        virtual void Shutdown() = 0;

        virtual std::string GetName() const = 0;

        virtual std::string GetIdentifier() const = 0;

        virtual void SetViewport(const math::Vector2 &pos, const math::Vector2 &size) = 0;

        virtual void SetScissor(const math::Vector2 &start, const math::Vector2 &size) = 0;

        virtual void Clear(const graphics::Color &color) = 0;
    };
}