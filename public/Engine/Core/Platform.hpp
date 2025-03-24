#pragma once

#include <string>
#include <string_view>

#include <Engine/Core/Runtime/AppHost.hpp>
#include <Engine/Core/Runtime/IWindow.hpp>
#include <Engine/Core/Runtime/IThread.hpp>

namespace engine::core::Platform {
    void Init();

    void PreEngineInit();

    void Shutdown();

    void ShowMessageBox(std::string_view title, std::string_view message);

    std::string GetName();

    std::unique_ptr<runtime::AppHost> GetSuitableHost();

    std::unique_ptr<runtime::IWindow> CreateAppWindow();

    std::unique_ptr<runtime::IThread> CreateThread();
}