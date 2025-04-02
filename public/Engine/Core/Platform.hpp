#pragma once

#include <string>
#include <string_view>
#include <functional>

#include <Engine/Core/Runtime/AppHost.hpp>
#include <Engine/Core/Runtime/IWindow.hpp>
#include <Engine/Core/Runtime/IThread.hpp>
#include <Engine/Core/Runtime/IMutex.hpp>

#include <Engine/Input/IVirtualKeyboard.hpp>

namespace engine::core::Platform {
    void ShowMessageBox(std::string_view title, std::string_view message);

    std::shared_ptr<input::IVirtualKeyboard> GetVirtualKeyboard();

    std::string GetName();

    std::unique_ptr<runtime::AppHost> GetSuitableHost();

    std::unique_ptr<runtime::IWindow> CreateAppWindow();

    std::unique_ptr<runtime::IThread> CreateThread();

    std::unique_ptr<runtime::IMutex> CreateMutex();
}