#pragma once

#include <Engine/Core/Runtime/Graphics/IGraphicsContext.hpp>
#include <Engine/Core/Runtime/Graphics/ITexture.hpp>
#include <Engine/Core/Math/Vector3.hpp>
#include <utility>

namespace engine::core::runtime::graphics {
    struct IVertexBuffer;
    struct ICamera;

    struct UIRenderItem {
        PrimitiveType m_PrimType;
        std::vector<engine::core::runtime::graphics::Vertex> m_Vertices;
        ITexture *m_Texture;
        math::Vector2 m_Scissor;
        math::Vector2 m_Size;

        explicit UIRenderItem(PrimitiveType primType, std::vector<engine::core::runtime::graphics::Vertex> m_vertices,
                              ITexture *m_texture,
                              const math::Vector2 &m_scissor, const math::Vector2 &m_size)
                : m_PrimType(primType), m_Vertices(std::move(m_vertices)), m_Texture(m_texture), m_Scissor(m_scissor), m_Size(m_size) {}

        UIRenderItem(const UIRenderItem &rhs) = default;
    };

    struct MeshRenderItem {
        IVertexBuffer *m_Buffer;
        ITexture *m_Texture;
        math::Vector3 m_Position;
        math::Vector3 m_Scale;
        math::Vector3 m_Rotation;

        explicit MeshRenderItem(IVertexBuffer *m_buffer, ITexture *m_texture, const math::Vector3 &m_position,
                                const math::Vector3 &m_scale, const math::Vector3 &m_rotation)
                : m_Buffer(m_buffer), m_Texture(m_texture), m_Position(m_position),
                  m_Scale(m_scale), m_Rotation(m_rotation) {}

        MeshRenderItem(const MeshRenderItem &rhs) = default;
    };

    struct IRenderer {
        virtual ~IRenderer() = default;

        // Initialize required objects by the renderer (i.e. shader programs)
        virtual bool Initialize(IGraphicsContext *gfxContext) = 0;

        // Destroy allocated resources for the renderer
        virtual void Destroy() = 0;

        // Begin a new frame
        virtual void BeginFrame() = 0;

        // End the frame and commit the render queue (render calls from the queue list are performed here)
        virtual void EndFrame() = 0;

        // Specify the camera to be used for this frame.
        virtual void UseCamera(ICamera* camera) = 0;

        // Submit a buffer to the renderer to be added to the queue list
        virtual void SubmitMesh(const MeshRenderItem &item) = 0;

        // Submit a buffer to the renderer to be added to the UI queue list
        virtual void SubmitUI(const UIRenderItem &item) = 0;
    };
}