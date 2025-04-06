#pragma once

#include <Engine/Core/Runtime/AppHost.hpp>

namespace engine::core::runtime {
    struct BasicAppHost : public AppHost {
        virtual ~BasicAppHost() = default;

        virtual bool Initialize() override;

        virtual void Run(std::shared_ptr<App> app) override;

        virtual void Shutdown() override;

        virtual std::shared_ptr<IWindow> GetMainWindow() override;

    protected:
        virtual void Step() override;
    };
}