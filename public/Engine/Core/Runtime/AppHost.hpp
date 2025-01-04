#pragma once

#include <memory>
#include <stdexcept>

#include <Engine/Core/Runtime/App.hpp>
#include <Engine/Core/Runtime/IWindow.hpp>

namespace engine::core::runtime::graphics {
    struct IRenderer;
}

namespace engine::core::runtime {
    struct IWindow;

    struct AppHost {
        virtual ~AppHost() = default;

        virtual bool Initialize() = 0;

        virtual void Run(std::shared_ptr<App> app) = 0;

        virtual void Shutdown() = 0;

        virtual std::shared_ptr<IWindow> GetMainWindow() = 0;

    protected:
        virtual void HostLoop();

        std::shared_ptr<App> m_App;
        std::shared_ptr<IWindow> m_MainWindow;
        std::shared_ptr<graphics::IRenderer> m_Renderer;
    };
}