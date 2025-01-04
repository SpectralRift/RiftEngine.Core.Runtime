#pragma once

#include <vector>

#include <Engine/Core/Math/Vector2.hpp>
#include <Engine/Core/Runtime/Input/InputConsts.hpp>

namespace engine::core::runtime::input {
    struct IInputDevice;

    struct InputManager {
        ~InputManager() = default;

        void Initialize();
        void Shutdown();
        void Update();

        std::vector<IInputDevice*> GetDevices();

        void RegisterDevice(IInputDevice *device);
        void UnregisterDevice(IInputDevice *device);

//        bool GetButton(InputDeviceButton button);
//        math::Vector2 GetAxis(InputDeviceAxis axis);
    };
}