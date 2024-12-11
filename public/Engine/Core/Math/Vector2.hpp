#pragma once

#include <cmath>
//#include <glm/vec2.hpp>

namespace engine::core::math {
#pragma pack(push, 1)

    /// <summary>
    /// Stores a bi-dimensional point.
    /// </summary>
    struct Vector2 {
        Vector2() : x(0), y(0) {
        }

        Vector2(const Vector2 &rhs) : x(rhs.x), y(rhs.y) {
        }

        Vector2(float x, float y) : x(x), y(y) {
        }

        float x;
        float y;

        Vector2 abs() const {
            return {::abs(x), ::abs(y)};
        }

        Vector2 &operator+=(const Vector2 &r) {
            x += r.x;
            y += r.y;

            return *this;
        }

        Vector2 &operator+=(const float &r) {
            x += r;
            y += r;

            return *this;
        }

        Vector2 &operator-=(const Vector2 &r) {
            x -= r.x;
            y -= r.y;

            return *this;
        }

        Vector2 &operator-=(const float &r) {
            x -= r;
            y -= r;

            return *this;
        }

        Vector2 &operator/=(const Vector2 &r) {
            x /= r.x;
            y /= r.y;

            return *this;
        }

        Vector2 &operator/=(const float &r) {
            x /= r;
            y /= r;

            return *this;
        }

        Vector2 &operator*=(const Vector2 &r) {
            x *= r.x;
            y *= r.y;

            return *this;
        }

        Vector2 &operator*=(const float &r) {
            x *= r;
            y *= r;

            return *this;
        }

        Vector2 operator+(const Vector2 &r) {
            x += r.x;
            y += r.y;

            return *this;
        }

        Vector2 &operator+(const float &r) {
            x += r;
            y += r;

            return *this;
        }

        Vector2 operator-(const Vector2 &r) {
            x -= r.x;
            y -= r.y;

            return *this;
        }

        Vector2 &operator-(const float &r) {
            x -= r;
            y -= r;

            return *this;
        }

        Vector2 operator/(const Vector2 &r) {
            x /= r.x;
            y /= r.y;

            return *this;
        }

        Vector2 &operator/(const float &r) {
            x /= r;
            y /= r;

            return *this;
        }

        Vector2 operator*(const Vector2 &r) {
            x *= r.x;
            y *= r.y;

            return *this;
        }

        Vector2 &operator*(const float &r) {
            x *= r;
            y *= r;

            return *this;
        }

        bool operator==(const Vector2 &r) {
            return x == r.x && y == r.y;
        }

        bool operator!=(const Vector2 &r) {
            return x != r.x || y != r.y;
        }

//        glm::vec2 to_glm_vec() {
//            return {
//                    x,
//                    y
//            };
//        }
    };

#pragma pack(pop)
}