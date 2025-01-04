#pragma once

#include <cmath>
//#include <glm/vec3.hpp>

namespace engine::core::math {
#pragma pack(push, 1)

    /// <summary>
    /// Stores a tri-dimensional point.
    /// </summary>
    struct Vector3 {
        Vector3()
                : x(0.f), y(0.f), z(0.f) {
        }

        Vector3(float x, float y, float z)
                : x(x), y(y), z(z) {
        }

        float x;
        float y;
        float z;

        Vector3 abs() const {
            return {::abs(x), ::abs(y), ::abs(z)};
        }

        Vector3 &operator+=(const Vector3 &r) {
            x += r.x;
            y += r.y;
            z += r.z;

            return *this;
        }

        Vector3 &operator+=(const float &r) {
            x += r;
            y += r;
            z += r;

            return *this;
        }

        Vector3 &operator-=(const Vector3 &r) {
            x -= r.x;
            y -= r.y;
            z -= r.z;

            return *this;
        }

        Vector3 &operator-=(const float &r) {
            x -= r;
            y -= r;
            z -= r;

            return *this;
        }

        Vector3 &operator/=(const Vector3 &r) {
            x /= r.x;
            y /= r.y;
            z /= r.z;

            return *this;
        }

        Vector3 &operator/=(const float &r) {
            x /= r;
            y /= r;
            z /= r;

            return *this;
        }

        Vector3 &operator*=(const Vector3 &r) {
            x *= r.x;
            y *= r.y;
            z *= r.z;

            return *this;
        }

        Vector3 &operator*=(const float &r) {
            x *= r;
            y *= r;
            z *= r;

            return *this;
        }

        Vector3 operator+(const Vector3 &r) {
            x += r.x;
            y += r.y;
            z += r.z;

            return *this;
        }

        Vector3 &operator+(const float &r) {
            x += r;
            y += r;
            z += r;

            return *this;
        }

        Vector3 operator-(const Vector3 &r) {
            x -= r.x;
            y -= r.y;
            z -= r.z;

            return *this;
        }

        Vector3 &operator-(const float &r) {
            x -= r;
            y -= r;
            z -= r;

            return *this;
        }

        Vector3 operator/(const Vector3 &r) {
            x /= r.x;
            y /= r.y;
            z /= r.z;

            return *this;
        }

        Vector3 &operator/(const float &r) {
            x /= r;
            y /= r;
            z /= r;

            return *this;
        }

        Vector3 operator*(const Vector3 &r) {
            x *= r.x;
            y *= r.y;
            z *= r.z;

            return *this;
        }

        Vector3 &operator*(const float &r) {
            x *= r;
            y *= r;
            z *= r;

            return *this;
        }

//        glm::vec3 ToGlmVec() {
//            return {
//                    x,
//                    y,
//                    z
//            };
//        }
    };

#pragma pack(pop)
}