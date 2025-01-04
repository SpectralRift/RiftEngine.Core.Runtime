#pragma once

#include <vector>

#include <Engine/Core/Math/Vector2.hpp>

namespace engine::core::runtime::input {
    struct IInputDevice;
    struct InputEvent;

    struct InputManager {
        ~InputManager() = default;

        void Initialize();
        void Shutdown();

#ifdef SHOW_PRIVATE_API
        void PushEvent(InputEvent* ev);
#endif
//        std::vector<InputEvent*> ProcessEvents();

        std::vector<IInputDevice*> GetDevices();

        void RegisterDevice(IInputDevice *device);
        void UnregisterDevice(IInputDevice *device);

        static InputManager* Instance();
    protected:
        std::vector<IInputDevice*> m_DeviceList;
        std::vector<InputEvent*> m_Events;
    };
}