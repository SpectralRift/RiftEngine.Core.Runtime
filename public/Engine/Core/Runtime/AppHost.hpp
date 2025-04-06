#pragma once

#include <memory>
#include <stdexcept>

#include <Engine/Core/Runtime/App.hpp>
#include <Engine/Core/Runtime/IWindow.hpp>

namespace engine::core::runtime {
    struct IWindow;

    struct AppHost {
        AppHost() : b_RequestedShutdown(false), m_App(nullptr), m_MainWindow(nullptr) {}

        virtual ~AppHost() = default;

        virtual bool Initialize() = 0;

        virtual void Run(std::shared_ptr<App> app) = 0;

        virtual void Shutdown() = 0;

        void RequestShutdown() { b_RequestedShutdown = true; }

        virtual std::shared_ptr<IWindow> GetMainWindow() = 0;

    protected:
        virtual void Step() = 0;

        bool b_RequestedShutdown;

        std::shared_ptr<App> m_App;
        std::shared_ptr<IWindow> m_MainWindow;
    };
}