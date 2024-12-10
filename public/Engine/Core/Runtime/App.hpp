#pragma once

namespace engine::core::runtime {
    struct AppHost;

    struct App {
        App(AppHost &host) : host(host) {}
        virtual ~App() = default;

        virtual bool Initialize() {
            return false;
        }

        virtual void Update(float deltaTime) {}

        virtual void Render() {}

        virtual void Shutdown() {}

    protected:
        AppHost &host;
    };
}
