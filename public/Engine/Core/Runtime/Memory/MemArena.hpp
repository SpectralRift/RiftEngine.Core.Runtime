#pragma once

#include <cstdlib>

namespace engine::core::runtime::memory {
    struct MemArena {
        MemArena() {
            m_Arena = nullptr;
            m_ArenaSize = 0;
            m_ArenaCapacity = 0;
        }

        ~MemArena() {
            if (m_Arena) {
                Free();
            }
        }

        MemArena(MemArena &&rhs) noexcept {
            m_Arena = rhs.m_Arena;
            m_ArenaSize = rhs.m_ArenaSize;
            m_ArenaCapacity = rhs.m_ArenaCapacity;
        }

        bool Create(size_t size);
        bool Resize(size_t size);
        bool Free();

        void *Alloc(size_t size);
    private:
        void *m_Arena;
        size_t m_ArenaSize;
        size_t m_ArenaCapacity;
    };
}