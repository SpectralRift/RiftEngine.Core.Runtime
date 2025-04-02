#pragma once

#include <string>
#include <span>

namespace engine::core::runtime::graphics {
    enum ShaderType {
        SHADER_TYPE_UNKNOWN,
        SHADER_TYPE_VERTEX,
        SHADER_TYPE_FRAGMENT
    };

    enum ShaderCapsFlags : unsigned char {
        SHADER_CAPS_NONE = 0,
        SHADER_CAPS_ALLOW_PROVIDE_COMPILED = 1 << 0,
        SHADER_CAPS_ALLOW_GET_SOURCE = 1 << 0,
    };

    struct IShader {
        virtual ~IShader() = default;

        virtual bool Compile() = 0;

        virtual void Destroy() = 0;

        virtual void SetSource(std::string_view source, ShaderType type) = 0;

        virtual bool UseCompiledShader(const std::span<unsigned char>& data, core::runtime::graphics::ShaderType type) = 0;

        virtual ShaderCapsFlags GetImplCapabilities() const = 0;

        virtual std::span<unsigned char> GetCompiledShader() = 0;

        virtual std::string GetSource() = 0;

        virtual std::string GetCompileLog() = 0;

        virtual bool IsCompiled() = 0;
    };
}