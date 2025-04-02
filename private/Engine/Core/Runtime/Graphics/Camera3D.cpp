// prevent GLM experimental extension error
#define GLM_ENABLE_EXPERIMENTAL

#include <Engine/Core/Runtime/Graphics/Camera3D.hpp>

#include <glm/gtx/transform.hpp>

namespace engine::core::runtime::graphics {
    glm::mat4 Camera3D::GetProjectionMtx() {
        return m_ProjectionMtx;
    }

    glm::mat4 Camera3D::GetViewMtx() {
        return m_ViewMtx;
    }

    void Camera3D::Update(math::Vector2 viewport) {
        m_ProjectionMtx = glm::perspective(
                glm::radians(Fov),
                (float) viewport.x / (float) viewport.y,
                NearClip, FarClip);

        glm::vec3 front{
                cos(glm::radians(Rotation.x)) * cos(glm::radians(Rotation.y)),
                sin(glm::radians(Rotation.y)),
                sin(glm::radians(Rotation.x)) * cos(glm::radians(Rotation.y))
        };

        auto normalizedFront = glm::normalize(front);
        auto right = glm::normalize(glm::cross(normalizedFront, glm::vec3(0, 1, 0)));
        auto up = glm::normalize(glm::cross(right, normalizedFront));

        m_ViewMtx = glm::lookAt(Position.ToGlmVec(), Position.ToGlmVec() + front, up);
    }
}