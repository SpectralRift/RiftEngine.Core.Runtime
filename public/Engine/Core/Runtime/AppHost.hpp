#pragma once

#include <memory>
#include <stdexcept>

#include <Engine/Core/Runtime/App.hpp>

namespace engine::core::runtime {
    struct AppHost {
        virtual ~AppHost() = default;

        virtual bool Initialize() = 0;

        virtual void Run(std::unique_ptr<App> app) = 0;

        virtual void Shutdown() = 0;

        virtual void* GetMainWindow() = 0;
        virtual void* GetSecondaryWindow() = 0;
    };
}