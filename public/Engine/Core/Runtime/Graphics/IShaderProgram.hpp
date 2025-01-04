#pragma once

#include <glm/glm.hpp>

#include <string>

namespace engine::core::runtime::graphics {
    struct IShader;

    struct IShaderProgram {
        virtual ~IShaderProgram() = default;

        virtual bool Link() = 0;

        virtual void Destroy() = 0;

        virtual void Bind() = 0;

        virtual void Unbind() = 0;

        virtual void AddShader(IShader* shader) = 0;

        virtual void SetUniformMat4(std::string_view name, const glm::mat4 &mat) = 0;

        virtual std::string GetLinkLog() = 0;

        virtual bool IsLinked() = 0;
    };
}