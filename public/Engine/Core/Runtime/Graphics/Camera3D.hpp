#pragma once

#include <Engine/Core/Math/Vector3.hpp>
#include <Engine/Core/Runtime/Graphics/ICamera.hpp>

namespace engine::core::runtime::graphics {
    struct Camera3D : public ICamera {
        glm::mat4 GetProjectionMtx() override;
        glm::mat4 GetViewMtx() override;

        void Update(math::Vector2 viewport) override;

        float Fov{45.f};
        float NearClip{0.1f};
        float FarClip{2000.0f};

        math::Vector3 Position{0.f, 0.f, 0.f};

        // yaw, pitch
        math::Vector2 Rotation{-90.f, 0.f};
    protected:
        glm::mat4 m_ProjectionMtx{1.0f};
        glm::mat4 m_ViewMtx{1.0f};
    };
}