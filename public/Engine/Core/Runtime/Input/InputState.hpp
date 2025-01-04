#pragma once

#include <unordered_map>
#include <unordered_set>

#include <Engine/Core/Runtime/Input/InputConsts.hpp>
#include <Engine/Core/Math/Vector2.hpp>

namespace engine::core::runtime::input {
    struct InputState {
        std::unordered_set<InputDeviceButton> Buttons;
        std::unordered_set<InputDeviceKey> Keys;
        std::unordered_map<InputDeviceAxis, math::Vector2> Axis;
        std::unordered_map<int, math::Vector2> TouchPoints;

        bool GetButtonState(InputDeviceButton button) {
            return Buttons.contains(button);
        }

        void SetButtonState(InputDeviceButton button, bool state) {
            if (state) {
                Buttons.emplace(button);
            } else {
                Buttons.erase(button);
            }
        }

        bool GetKeyState(InputDeviceKey key) {
            return Keys.contains(key);
        }

        void SetKeyState(InputDeviceKey key, bool state) {
            if (state) {
                Keys.emplace(key);
            } else {
                Keys.erase(key);
            }
        }

        math::Vector2 GetAxis(InputDeviceAxis axis) {
            return Axis.at(axis);
        }

        void SetAxis(InputDeviceAxis axis, math::Vector2 v) {
            Axis.emplace(axis, v);
        }

        bool HasTouchPoint(int point) {
            return TouchPoints.contains(point);
        }

        math::Vector2 GetTouchPoint(int point) {
            return TouchPoints.at(point);
        }

        void SetTouchPoint(int point, math::Vector2 v) {
            TouchPoints.emplace(point, v);
        }

        void RemoveTouchPoint(int point) {
            TouchPoints.erase(point);
        }
    };
}