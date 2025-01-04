#define SHOW_PRIVATE_API

#include <Engine/Core/Runtime/Input/InputManager.hpp>
#include <Engine/Core/Runtime/Input/IInputDevice.hpp>
#include <Engine/Core/Runtime/Input/InputEvent.hpp>

namespace engine::core::runtime::input {
    static InputManager* g_InputManager;

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

    }

    void InputManager::Shutdown() {
        printf("InputManager: Shutting down the input manager...\n");

        printf("InputManager: Destroying device resources...\n");
        for(auto device : m_DeviceList) {
            printf("InputManager: Destroying resources for '%s'\n", device->GetName().c_str());
            device->Destroy();
        }

        printf("InputManager: Destroyed device resources!\n");
        m_DeviceList.clear();
    }

//    void InputManager::Poll() {
//        for(auto device : m_DeviceList) {
//            device->Poll();
//        }
//    }

    void InputManager::RegisterDevice(IInputDevice *device) {
        printf("InputManager: Registering device '%s' type %i\n", device->GetName().c_str(), device->GetType());
        m_DeviceList.emplace_back(device);
    }

    void InputManager::UnregisterDevice(IInputDevice *device) {
        printf("InputManager: Unregistering device '%s' type %i\n", device->GetName().c_str(), device->GetType());

        // look for device in our list
        auto it = std::find(m_DeviceList.begin(), m_DeviceList.end(), device);

        if (it != m_DeviceList.end()) {
            m_DeviceList.erase(it);
            device->Destroy();
            printf("InputManager: Device '%s' was destroyed successfully!\n", device->GetName().c_str());
        } else {
            printf("InputManager: Device '%s' was not registered in the first place!\n", device->GetName().c_str());
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
        m_Events.emplace_back(ev);
        printf("InputManager: NEW EVENT %i\n", ev->GetEventType());
    }
}