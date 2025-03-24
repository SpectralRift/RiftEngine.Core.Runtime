#include <Engine/Core/Runtime/App.hpp>
#include <Engine/Core/Runtime/App_Internal.hpp>

namespace engine::core::runtime {
    App* g_CurrentApp;

    App* App::GetCurrentApp() {
        return g_CurrentApp;
    }
}