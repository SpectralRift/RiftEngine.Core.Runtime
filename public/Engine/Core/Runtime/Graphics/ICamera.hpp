#pragma once

#include <glm/glm.hpp>
#include <Engine/Core/Math/Vector2.hpp>

namespace engine::core::runtime::graphics {
    struct ICamera {
        virtual glm::mat4 GetProjectionMtx() = 0;
        virtual glm::mat4 GetViewMtx() = 0;

        virtual void Update(math::Vector2 viewport) = 0;
    };
}