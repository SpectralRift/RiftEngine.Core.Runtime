#include <Engine/Core/Runtime/App_Internal.hpp>
#include <Engine/Core/Runtime/AppHost.hpp>
#include <Engine/Core/Runtime/Graphics/IRenderer.hpp>
#include <Engine/Core/Platform.hpp>

namespace engine::core::runtime {
    bool AppHost::Initialize() {
        m_MainWindow = engine::core::Platform::CreateAppWindow();

        if (!m_MainWindow || !m_MainWindow->Create()) {
            engine::core::Platform::ShowMessageBox(
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

        return true;
    }

    void AppHost::Run(std::shared_ptr<App> app) {
        // move app ownership and set the global app instance
        m_App = std::move(app);
        g_CurrentApp = m_App.get();

        m_App->Initialize();

        m_MainWindow->Show();
        m_MainWindow->GetGraphicsContext()->Bind();

        while(m_MainWindow->IsValid()) {
            HostLoop();
        }

        Shutdown();
    }

    void AppHost::HostLoop() {
        m_MainWindow->ProcessEvents();

        m_MainWindow->GetGraphicsContext()->Bind();
        
        m_MainWindow->GetGraphicsContext()->GetBackend()->DisableFeatures(engine::core::runtime::graphics::BackendFeature::BACKEND_FEATURE_SCISSOR_TEST);
        m_MainWindow->GetGraphicsContext()->GetBackend()->SetViewport({0.f, 0.f}, m_MainWindow->GetSize());
        m_MainWindow->GetGraphicsContext()->GetBackend()->Clear(engine::core::runtime::graphics::colors::black);
        
        m_MainWindow->GetGraphicsContext()->PreRender();
        
        m_Renderer->BeginFrame();

        m_Renderer->EndFrame();

        m_MainWindow->GetGraphicsContext()->PostRender();
        m_MainWindow->GetGraphicsContext()->Present();
    };

    void AppHost::Shutdown() {

    }

    std::shared_ptr<IWindow> AppHost::GetMainWindow() {
        return m_MainWindow;
    }
}