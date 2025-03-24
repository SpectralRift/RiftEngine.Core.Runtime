#pragma once

#include <vector>
#include <mutex>
#include <functional>

#include <Engine/Core/Runtime/Input/InputConsts.hpp>
#include <Engine/Core/Runtime/IThread.hpp>
#include <Engine/Core/Math/Vector2.hpp>

namespace engine::core::runtime::input {
    struct IInputDevice;
    struct InputEvent;

    struct InputManager {
        InputManager();
        ~InputManager() = default;

        void Initialize();
        void Shutdown();

        void ProcessEvents();

#ifdef SHOW_PRIVATE_API
        // make sure that certain related to pushing APIs are not exposed to everyone. we wouldn't want anyone to push fake input data, would we?
        void PushEvent(InputEvent* ev);
#endif

        std::vector<IInputDevice*> GetDevices();

        void RegisterDevice(IInputDevice *device);
        void UnregisterDevice(IInputDevice *device);

        void RegisterEventHandler(InputEventType eventType, std::function<void(InputEvent*)> handler);
        void UnregisterEventHandler(InputEventType eventType, std::function<void(InputEvent*)> handler);

        static InputManager* Instance();
    protected:
        void ProcessTask();

        std::mutex mtx_InputProc;
        std::vector<IInputDevice*> m_DeviceList;
        std::vector<InputEvent*> m_Events;
        std::unique_ptr<IThread> m_Thread;
        std::unordered_map<InputEventType, std::vector<std::function<void(InputEvent*)>>> m_EventHandlers;

        bool b_IsInit;
    };
}