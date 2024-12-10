#pragma once

namespace engine::core::runtime::input {
    enum class InputType {
        INPUT_TYPE_UNKNOWN,
        INPUT_TYPE_KEYBOARD,
        INPUT_TYPE_MOUSE,
        INPUT_TYPE_TOUCH,
        INPUT_TYPE_GAMEPAD,
    };

    enum class InputEventType {
        INPUT_EVENT_TYPE_UNKNOWN,

        // Keyboard Events
        INPUT_EVENT_TYPE_KEY_UP,
        INPUT_EVENT_TYPE_KEY_DOWN,

        // Mouse Events
        INPUT_EVENT_TYPE_MOUSE_KEY_UP,
        INPUT_EVENT_TYPE_MOUSE_KEY_DOWN,
        INPUT_EVENT_TYPE_MOUSE_MOVE,

        // Touch Events
        INPUT_EVENT_TYPE_TOUCH_START,
        INPUT_EVENT_TYPE_TOUCH_HOVER,
        INPUT_EVENT_TYPE_TOUCH_DRAG,
        INPUT_EVENT_TYPE_TOUCH_END,

        // Gamepad Events
        INPUT_EVENT_TYPE_GAMEPAD_BUTTON_UP,
        INPUT_EVENT_TYPE_GAMEPAD_BUTTON_DOWN,
        INPUT_EVENT_TYPE_GAMEPAD_AXIS_MOVE
    };

    enum class InputKey {
        INPUT_KEY_UNKNOWN,
        INPUT_KEY_SPACE,
        INPUT_KEY_UP,
        INPUT_KEY_DOWN,
        INPUT_KEY_LEFT,
        INPUT_KEY_RIGHT,
    };
}
