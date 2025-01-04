#pragma once

#include <Engine/Core/Runtime/Input/InputState.hpp>

namespace engine::core::runtime::input {
    struct InputEvent {
        virtual ~InputEvent() = default;

        virtual InputEventType GetEventType() {
            return InputEventType::INPUT_EVENT_TYPE_UNKNOWN;
        }
    };

    struct MouseButtonUpEvent : public InputEvent {
        MouseButtonUpEvent(InputDeviceButton button) : Button(button) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_KEY_UP;
        }

        InputDeviceButton Button;
    };

    struct MouseButtonDownEvent : public InputEvent {
        MouseButtonDownEvent(InputDeviceButton button) : Button(button) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_KEY_DOWN;
        }

        InputDeviceButton Button;
    };

    struct MouseMoveEvent : public InputEvent {
        MouseMoveEvent(math::Vector2 pos) : Position(pos) {}

        InputEventType GetEventType() override {
            return InputEventType::INPUT_EVENT_TYPE_MOUSE_MOVE;
        }

        math::Vector2 Position;
    };
}