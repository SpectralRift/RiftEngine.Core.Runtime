#pragma once

#include <Engine/Core/Runtime/Input/InputState.hpp>
#include <Engine/Core/Runtime/Input/InputKey.hpp>

// forward declaration
struct IInputDevice;

namespace engine::core::runtime::input {
    struct InputEvent {
        InputEvent(IInputDevice* src) : SourceDevice(src) {}
        virtual ~InputEvent() = default;

        virtual InputEventType GetEventType() {
            return InputEventType::INPUT_EVENT_TYPE_UNKNOWN;
        }

        IInputDevice* SourceDevice;
    };

    struct GamepadAxisUpdateEvent : public InputEvent {
        GamepadAxisUpdateEvent(IInputDevice* src, InputDeviceAxis axis, core::math::Vector2 value) : InputEvent(src), Axis(axis), Value(value) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_GAMEPAD_AXIS_UPDATE;
        }

        InputDeviceAxis Axis;
        core::math::Vector2 Value;
    };

    struct GamepadButtonUpEvent : public InputEvent {
        GamepadButtonUpEvent(IInputDevice* src, const InputKey& btn) : InputEvent(src), Button(btn) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_GAMEPAD_BUTTON_UP;
        }

        InputKey Button;
    };

    struct GamepadButtonDownEvent : public InputEvent {
        GamepadButtonDownEvent(IInputDevice* src, const InputKey& btn) : InputEvent(src), Button(btn) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_GAMEPAD_BUTTON_DOWN;
        }

        InputKey Button;
    };

    struct MouseButtonUpEvent : public InputEvent {
        MouseButtonUpEvent(IInputDevice* src, InputDeviceButton button) : InputEvent(src), Button(button) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_KEY_UP;
        }

        InputDeviceButton Button;
    };

    struct MouseButtonDownEvent : public InputEvent {
        MouseButtonDownEvent(IInputDevice* src, InputDeviceButton button) : InputEvent(src), Button(button) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_KEY_DOWN;
        }

        InputDeviceButton Button;
    };

    struct MouseMoveEvent : public InputEvent {
        MouseMoveEvent(IInputDevice* src, math::Vector2 pos) : InputEvent(src), Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_MOVE;
        }

        math::Vector2 Position;
    };

    struct TouchStartEvent : public InputEvent {
        TouchStartEvent(IInputDevice* src, int fid, math::Vector2 pos) : InputEvent(src), FingerId(fid), Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_TOUCH_START;
        }

        int FingerId;
        math::Vector2 Position;
    };

    struct TouchDragEvent : public InputEvent {
        TouchDragEvent(IInputDevice* src, int fid, math::Vector2 pos) : InputEvent(src), FingerId(fid), Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_TOUCH_DRAG;
        }

        int FingerId;
        math::Vector2 Position;
    };

    struct TouchEndEvent : public InputEvent {
        TouchEndEvent(IInputDevice* src, int fid, math::Vector2 pos) : InputEvent(src), FingerId(fid), Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_TOUCH_END;
        }

        int FingerId;
        math::Vector2 Position;
    };

    struct TouchHoverEvent : public InputEvent {
        TouchHoverEvent(IInputDevice* src, math::Vector2 pos) : InputEvent(src), Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_TOUCH_HOVER;
        }

        math::Vector2 Position;
    };

}