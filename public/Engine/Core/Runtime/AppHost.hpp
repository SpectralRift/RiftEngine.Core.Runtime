#pragma once

#include <memory>
#include <stdexcept>

#include <Engine/Core/Runtime/App.hpp>
#include <Engine/Core/Runtime/IWindow.hpp>

namespace engine::core::runtime {
    struct AppHost {
        virtual ~AppHost() = default;

        virtual bool Initialize() = 0;

        virtual void Run(std::unique_ptr<App> app) = 0;

        virtual void Shutdown() = 0;

        virtual std::unique_ptr<IWindow> GetMainWindow() = 0;
    };
}