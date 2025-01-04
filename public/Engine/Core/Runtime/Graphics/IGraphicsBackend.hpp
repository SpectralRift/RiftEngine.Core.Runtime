#pragma once

#include <string>
#include <memory>

#include <Engine/Core/Runtime/Graphics/Color.hpp>
#include <Engine/Core/Math/Vector2.hpp>

#include <Engine/Core/Runtime/Graphics/IVertexBuffer.hpp>
#include <Engine/Core/Runtime/Graphics/IShader.hpp>
#include <Engine/Core/Runtime/Graphics/ITexture.hpp>
#include <Engine/Core/Runtime/Graphics/IShaderProgram.hpp>

namespace engine::core::runtime::graphics {
    enum BackendFeature {
        BACKEND_FEATURE_UNKNOWN,
        BACKEND_FEATURE_SCISSOR_TEST = 1 << 0,
        BACKEND_FEATURE_ALPHA_BLENDING = 1 << 1
    };

    struct IGraphicsBackend {
        virtual ~IGraphicsBackend() = default;

        virtual bool Initialize() = 0;

        virtual void Shutdown() = 0;

        virtual std::string GetName() const = 0;

        virtual std::string GetIdentifier() const = 0;

        virtual void SetViewport(math::Vector2 pos, math::Vector2 size) = 0;

        virtual void SetScissor(math::Vector2 start, math::Vector2 size) = 0;

        virtual void EnableFeatures(BackendFeature featuresMask) = 0;

        virtual void DisableFeatures(BackendFeature featuresMask) = 0;

        virtual BackendFeature GetActiveFeatures() = 0;

        virtual void Clear(graphics::Color color) = 0;

        virtual std::unique_ptr<IVertexBuffer> CreateVertexBuffer() = 0;

        virtual std::unique_ptr<IShader> CreateShader() = 0;

        virtual std::unique_ptr<IShaderProgram> CreateShaderProgram() = 0;

        virtual std::unique_ptr<ITexture> CreateTexture() = 0;
    };
}