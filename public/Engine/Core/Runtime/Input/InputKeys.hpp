#pragma once

#include <Engine/Core/Runtime/Input/InputKey.hpp>

namespace engine::core::runtime::input {
    struct InputKeys {
        static const InputKey Gamepad_A;
        static const InputKey Gamepad_B;
        static const InputKey Gamepad_X;
        static const InputKey Gamepad_Y;

        static const InputKey Gamepad_LeftStick;
        static const InputKey Gamepad_RightStick;

        static const InputKey Gamepad_LeftBumper;
        static const InputKey Gamepad_RightBumper;

        static const InputKey Gamepad_Start;

        static const InputKey Gamepad_DPad_Up;
        static const InputKey Gamepad_DPad_Down;
        static const InputKey Gamepad_DPad_Left;
        static const InputKey Gamepad_DPad_Right;
    };
}