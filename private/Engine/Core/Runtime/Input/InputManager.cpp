#define SHOW_PRIVATE_API

#include <Engine/Core/Runtime/Input/InputManager.hpp>
#include <Engine/Core/Runtime/Input/IInputDevice.hpp>
#include <Engine/Core/Runtime/Input/InputEvent.hpp>

#include <Engine/Core/Platform.hpp>

#include <Engine/Runtime/Logger.hpp>

namespace engine::core::runtime::input {
    static InputManager* g_InputManager;
    static engine::runtime::Logger g_LoggerInputManager("InputManager");

    InputManager::InputManager() : b_IsInit{false}, m_Thread{nullptr} {}

    InputManager* InputManager::Instance() {
        if(!g_InputManager) {
            g_InputManager = new InputManager();
        }

        return g_InputManager;
    }

    std::vector<IInputDevice*> InputManager::GetDevices() {
        return m_DeviceList;
    }

    void InputManager::Initialize() {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Initializing input manager...");
        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Creating input thread...");
        m_Thread = Platform::CreateThread();

        if(!m_Thread) {
            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_ERROR, "Failed to create input thread!");
            return;
        }

        m_Thread->SetName("Input Management Thread");
        m_Thread->SetTaskFunc(&InputManager::ProcessTask, this);
        m_Thread->Start();
        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Created input thread!");
        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_INFO, "Initialized input manager!");

        b_IsInit = true;
    }

    void InputManager::Shutdown() {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        b_IsInit = false;

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Shutting down the input manager...");

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Destroying device resources...");
        for(auto device : m_DeviceList) {
            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Destroying resources for '%s'", device->GetName().c_str());
            device->Destroy();
        }

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_INFO, "Destroyed device resources!");
        m_DeviceList.clear();
    }

    void InputManager::ProcessEvents() {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        for(auto ev : m_Events) {
//            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Processing event of type %i", ev->GetEventType());

            for(const auto& handler : m_EventHandlers[ev->GetEventType()]) {
                handler(ev);
            }
        }

        if(!m_Events.empty()) {
            m_Events.clear();
        }
    }

    void InputManager::ProcessTask() {
        while(m_Thread->IsRunning() || b_IsInit) {
            // poll device inputs
            std::lock_guard<std::mutex> lock(mtx_InputProc);

            for(auto d: m_DeviceList) {
                d->Poll();
            }
        }
    }

//    void InputManager::Poll() {
//        for(auto device : m_DeviceList) {
//            device->Poll();
//        }
//    }

    void InputManager::RegisterDevice(IInputDevice *device) {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_INFO, "Registering device '%s' type %i", device->GetName().c_str(), device->GetType());
        m_DeviceList.emplace_back(device);
    }

    void InputManager::UnregisterDevice(IInputDevice *device) {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Unregistering device '%s' type %i", device->GetName().c_str(), device->GetType());

        // look for device in our list
        auto it = std::find(m_DeviceList.begin(), m_DeviceList.end(), device);

        if (it != m_DeviceList.end()) {
            m_DeviceList.erase(it);
            device->Destroy();
            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_INFO, "Device '%s' was destroyed successfully!", device->GetName().c_str());
        } else {
            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_ERROR, "Device '%s' was not registered in the first place!", device->GetName().c_str());
        }
    }

//    bool InputManager::GetButton(InputDeviceButton button) {
//        for(auto device : m_DeviceList) {
//            if(device->GetButton(button)) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    math::Vector2 InputManager::GetAxis(InputDeviceAxis axis) {
//        for(auto device : m_DeviceList) {
//            auto axisDevice = dynamic_cast<engine::core::runtime::input::IAxisDevice*>(device);
//
//            if (axisDevice && axisDevice->HasAxis(axis)) {
//                return axisDevice->GetAxis(axis);
//            }
//        }
//
//        return {0.f, 0.f};
//    }

    void InputManager::PushEvent(InputEvent* ev) {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        if(b_IsInit) {
            m_Events.emplace_back(ev);
//            g_LoggerInputManager.Log(engine::runtime::LOG_LEVEL_DEBUG, "Pushed new event of type %i to the queue!", ev->GetEventType());
        }
    }

    void InputManager::RegisterEventHandler(InputEventType eventType, std::function<void(InputEvent*)> handler) {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        m_EventHandlers[eventType].push_back(std::move(handler));
    }

    void InputManager::UnregisterEventHandler(InputEventType eventType, std::function<void(InputEvent*)> handler) {
        std::lock_guard<std::mutex> lock(mtx_InputProc);

        auto it = m_EventHandlers.find(eventType);
        if (it != m_EventHandlers.end()) {
            auto& handlers = it->second;
            handlers.erase(
                    std::remove_if(handlers.begin(), handlers.end(),
                                   [&handler](const std::function<void(InputEvent*)>& existingHandler) {
                                       return existingHandler.target_type() == handler.target_type() &&
                                              existingHandler.target<void(InputEvent*)>() == handler.target<void(InputEvent*)>();
                                   }),
                    handlers.end()
            );

            if (handlers.empty()) {
                m_EventHandlers.erase(it);
            }
        }
    }
}