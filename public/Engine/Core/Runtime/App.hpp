#pragma once

#include <memory>

namespace engine::core::runtime {
    struct AppHost;

    struct App {
        App(AppHost* host) : m_Host(host) {}

        virtual ~App() = default;

        virtual bool Initialize() {
            return false;
        }

        virtual void Update(float deltaTime) {}

        virtual void Render(float deltaTime) {}

        virtual void Shutdown() {}

        AppHost* GetHost() { return m_Host; }

        static App *GetActiveApp();

    protected:
        AppHost* m_Host;
    };
}
