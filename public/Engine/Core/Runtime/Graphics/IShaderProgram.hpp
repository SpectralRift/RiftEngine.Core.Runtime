#pragma once

#include <glm/glm.hpp>

#include <string>
#include <memory>

namespace engine::core::runtime::graphics {
    struct IShader;

    struct IShaderProgram {
        virtual ~IShaderProgram() = default;

        virtual bool Link() = 0;

        virtual void Destroy() = 0;

        virtual void Bind() = 0;

        virtual void Unbind() = 0;

        virtual void AddShader(std::unique_ptr<IShader> shader) = 0;

        virtual void SetUniformMat4(std::string_view name, const glm::mat4 &mat) = 0;

        virtual void SetUniformI(std::string_view name, int val) = 0;

        virtual std::string GetLinkLog() = 0;

        virtual bool IsLinked() = 0;
    };
}