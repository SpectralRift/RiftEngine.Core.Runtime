#include <Engine/Core/Runtime/App.hpp>

namespace engine::core::runtime {
    App* g_CurrentApp;

    App* App::GetActiveApp() {
        return g_CurrentApp;
    }
}