#pragma once

#include <cstdint>
#include <vector>
#include <cmath>

namespace engine::core::runtime::graphics {
#pragma pack(push, 1)
    /// <summary>
    /// Stores a quad-dimensional packed color (ARGB color).
    /// </summary>
    struct Color {
        Color()
                : r(0), g(0), b(0), a(0) {
        }

        Color(const Color& rhs)
                : r(rhs.r), g(rhs.g), b(rhs.b), a(rhs.a) {
        }

        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
                : r(r), g(g), b(b), a(a) {
        }

        uint8_t a;
        uint8_t r;
        uint8_t g;
        uint8_t b;

        Color& operator+=(const Color& r) {
            this->r += r.r;
            this->g += r.g;
            this->b += r.b;
            this->a += r.a;

            return *this;
        }


        Color& operator+=(const uint8_t& r) {
            this->r += r;
            this->g += r;
            this->b += r;
            this->a += r;

            return *this;
        }


        Color& operator-=(const Color& r) {
            this->r -= r.r;
            this->g -= r.g;
            this->b -= r.b;
            this->a -= r.a;

            return *this;
        }


        Color& operator-=(const uint8_t& r) {
            this->r -= r;
            this->g -= r;
            this->b -= r;
            this->a -= r;

            return *this;
        }


        Color& operator/=(const Color& r) {
            this->r /= r.r;
            this->g /= r.g;
            this->b /= r.b;
            this->a /= r.a;

            return *this;
        }


        Color& operator/=(const uint8_t& r) {
            this->r /= r;
            this->g /= r;
            this->b /= r;
            this->a /= r;

            return *this;
        }


        Color& operator*=(const Color& r) {
            this->r *= r.r;
            this->g *= r.g;
            this->b *= r.b;
            this->a *= r.a;

            return *this;
        }


        Color& operator*=(const uint8_t& r) {
            this->r *= r;
            this->g *= r;
            this->b *= r;
            this->a *= r;

            return *this;
        }


        Color operator+(const Color& r) {
            this->r += r.r;
            this->g += r.g;
            this->b += r.b;
            this->a += r.a;

            return *this;
        }


        Color& operator+(const uint8_t& r) {
            this->r += r;
            this->g += r;
            this->b += r;
            this->a += r;

            return *this;
        }


        Color operator-(const Color& r) {
            this->r -= r.r;
            this->g -= r.g;
            this->b -= r.b;
            this->a -= r.a;

            return *this;
        }


        Color& operator-(const uint8_t& r) {
            this->r -= r;
            this->g -= r;
            this->b -= r;
            this->a -= r;

            return *this;
        }


        Color operator/(const Color& r) {
            this->r /= r.r;
            this->g /= r.g;
            this->b /= r.b;
            this->a /= r.a;

            return *this;
        }


        Color& operator/(const uint8_t& r) {
            this->r /= r;
            this->g /= r;
            this->b /= r;
            this->a /= r;

            return *this;
        }


        Color operator*(const Color& r) {
            this->r *= r.r;
            this->g *= r.g;
            this->b *= r.b;
            this->a *= r.a;

            return *this;
        }


        Color& operator*(const uint8_t& r) {
            this->r *= r;
            this->g *= r;
            this->b *= r;
            this->a *= r;

            return *this;
        }
    };
#pragma pack(pop)

    namespace colors {
        static Color black(0, 0, 0);
        static Color white(255, 255, 255);

        static Color red(255, 0, 0);
        static Color green(0, 255, 0);
        static Color blue(0, 0, 255);

        static Color yellow(255, 255, 0);
    } // namespace colors
}