#pragma once

#include <Engine/Core/Runtime/AppHost.hpp>

namespace engine::core::runtime {
    struct DesktopHost : public AppHost {
        virtual ~DesktopHost() = default;

        bool Initialize();

        void Run(std::shared_ptr<App> app);

        void Shutdown();

        std::shared_ptr<IWindow> GetMainWindow();
    protected:
        std::shared_ptr<IWindow> m_MainWindow;
    };
}