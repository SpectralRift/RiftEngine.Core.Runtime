#include <Engine/Core/Runtime/BasicAppHost.hpp>
#include <Engine/Core/Runtime/Graphics/IRenderer.hpp>
#include <Engine/Core/Platform.hpp>
#include <Engine/Runtime/Logger.hpp>
#include <Engine/Input/InputManager.hpp>

using namespace engine;

namespace engine::core::runtime {
    // refer to the global app instance which is used by App::GetActiveApp() method
    extern App *g_CurrentApp;

    static engine::runtime::Logger g_LoggerBasicAppHost("BasicAppHost");

    bool BasicAppHost::Initialize() {
        g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Initializing desktop host...");

        m_MainWindow = Platform::CreateAppWindow();

        if (!m_MainWindow || !m_MainWindow->Create()) {
            g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_ERROR, "Failed to create the main application window.");

            Platform::ShowMessageBox(
                    "SpectralRift Engine Error",
                    "This application has encountered a critical error while attempting to create the application m_MainWindowdow.\n\n"
                    "This failure indicates that the platform-specific environment required to render the application is incompatible with the current system setup.\n\n"
                    "Please check out SpectralRift's documentation for more information."
            );

            return false;
        }

        m_MainWindow->SetSize({1024, 768});
        m_MainWindow->SetTitle("SpectralRift Player (" + engine::core::Platform::GetName() + " with " +
                               m_MainWindow->GetGraphicsContext()->GetBackend()->GetName() + ")");

        g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_INFO, "Desktop host initialized.");

        return true;
    }

    void BasicAppHost::Run(std::shared_ptr<App> app) {
        g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Preparing to run the app...");

        if (!app) {
            g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_ERROR, "Failed to run the app instance provided to the host as the instance is NULL.");
            Platform::ShowMessageBox("SR1 Engine Error",
                                     "Failed to run the app instance provided to the host as the instance is NULL.");
            goto LBL_SHUTDOWN;
        }

        // move app ownership and set the global app instance
        m_App = std::move(app);
        m_MainWindow->GetGraphicsContext()->Bind();

        if (!m_App->Initialize()) {
            g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_ERROR, "Failed to initialize the application.");
            Platform::ShowMessageBox("SR1 Engine Error", "Failed to initialize the application.");
            goto LBL_SHUTDOWN;
        }

        g_CurrentApp = m_App.get();

        b_RequestedShutdown = false;
        m_MainWindow->Show();

        g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Entering app loop.");

        while (m_MainWindow->IsValid() && !b_RequestedShutdown) {
            Step();
        }

        LBL_SHUTDOWN:
        Shutdown();
    }

    void BasicAppHost::Step() {
        m_MainWindow->ProcessEvents();
        input::InputManager::Instance()->ProcessEvents();

        m_MainWindow->GetGraphicsContext()->Bind();

        m_MainWindow->GetGraphicsContext()->GetBackend()->DisableFeatures(
                engine::core::runtime::graphics::BackendFeature::BACKEND_FEATURE_SCISSOR_TEST);
        m_MainWindow->GetGraphicsContext()->GetBackend()->SetViewport({0.f, 0.f}, m_MainWindow->GetSize());
        m_MainWindow->GetGraphicsContext()->GetBackend()->Clear(engine::core::runtime::graphics::colors::black);

        m_MainWindow->GetGraphicsContext()->PreRender();

        m_App->Update(1.f / 60.f);
        m_App->Render(1.f / 60.f);

        m_MainWindow->GetGraphicsContext()->PostRender();
        m_MainWindow->GetGraphicsContext()->Present();
    };

    void BasicAppHost::Shutdown() {
        g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Shutting down the desktop host...");

        if (m_App) {
            g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Shutting down the application...");
            m_App->Shutdown();
            m_App = nullptr;
        }

        if (m_MainWindow) {
            g_LoggerBasicAppHost.Log(engine::runtime::LOG_LEVEL_DEBUG, "Destroying the main application window...");
            m_MainWindow->Hide();
            m_MainWindow->Destroy();

            m_MainWindow = nullptr;
        }

        if (g_CurrentApp) {
            g_CurrentApp = nullptr;
        }
    }

    std::shared_ptr<IWindow> BasicAppHost::GetMainWindow() {
        return m_MainWindow;
    }
}