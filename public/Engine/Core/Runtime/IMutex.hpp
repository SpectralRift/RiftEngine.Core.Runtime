#pragma once

namespace engine::core::runtime {
    struct IMutex {
        virtual ~IMutex() = default;

        virtual void Lock() = 0;
        virtual void Unlock() = 0;
    };
}