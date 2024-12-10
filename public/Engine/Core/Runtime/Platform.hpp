#pragma once

#include <string>
#include <string_view>

#include <Engine/Core/Runtime/AppHost.hpp>

namespace engine::core::Platform {
    void Init();

    void Shutdown();

    void ShowMessageBox(std::string_view title, std::string_view message);

    std::string GetName();

    std::unique_ptr<AppHost> GetSuitableHost();
}