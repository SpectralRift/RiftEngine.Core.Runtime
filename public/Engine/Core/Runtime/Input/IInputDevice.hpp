#pragma once

#include <string>

#include <Engine/Core/Math/Vector2.hpp>
#include <Engine/Core/Runtime/Input/InputConsts.hpp>

namespace engine::core::runtime::input {
    struct IInputDevice {
        virtual ~IInputDevice() = default;

        virtual bool Initialize() = 0;
        virtual void Destroy() = 0;
        virtual void Poll() = 0;

        virtual std::string GetName() const = 0;

        virtual InputDeviceType GetType() const = 0;
        virtual int GetPlayerId() = 0;
//        virtual bool GetButton(InputDeviceButton button) = 0;
    };

    struct IAxisDevice : public IInputDevice {
        virtual ~IAxisDevice() = default;

//        virtual bool HasAxis(InputDeviceAxis axis) const = 0;
//        virtual math::Vector2 GetAxis(InputDeviceAxis axis) const = 0;
    };

    struct ITouchDevice : public IInputDevice {
        virtual ~ITouchDevice() = default;

        virtual int GetMaxTouchPoints() = 0;
        virtual bool HasTouchPoint(int point) = 0;
        virtual math::Vector2 GetTouchPoint(int point) = 0;
    };
}