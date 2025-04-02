/**
 * Standard Implementation for MemArena. Part of the SpectralRift Engine Core Runtime.
 *
 * @author r0neko
 *
 * @see MemArena.hpp
*/

#include <Engine/Core/Runtime/Memory/MemArena.hpp>

#include <cstdio>
#include <stdexcept>

#include <Windows.h>

namespace engine::core::runtime::memory {
    void* MemArenaAlloc(size_t size) {
        // ToDo: implement platform specific stuff
        return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    bool MemArenaFree(void* ptr) {
        // ToDo: implement platform specific stuff
        return VirtualFree(ptr, 0, MEM_RELEASE);
    }

    bool MemArena::Create(size_t size) {
        printf("MemArena: Creating arena of size %zu\n", size);

        if (size == 0) {
            printf("MemArena: Size must be greater than 0!\n");
            return false;
        }

        if (m_Arena) {
            printf("MemArena: Memory already allocated. Free the arena before allocating again.\n");
            return false;
        }

        m_Arena = MemArenaAlloc(size);

        if (!m_Arena) {
            printf("MemArena: Failed to allocate memory!\n");
            return false;
        }

        m_ArenaCapacity = size;
        m_ArenaSize = 0;

        printf("MemArena: Allocated arena of size %zu\n", size);

        return true;
    }

    bool MemArena::Resize(size_t size) {
        if (!m_Arena) {
            printf("MemArena: No memory allocated. Call Alloc before resizing.\n");
            return false;
        }

        if (m_ArenaCapacity <= size) {
            printf("MemArena: No need to realloc; already big enough.\n");
            return true;
        }

        printf("MemArena: Reallocating arena of size %zu\n", size);

        void* newArena = MemArenaAlloc(size);

        if (!newArena) {
            printf("MemArena: Failed to allocate memory!\n");
            return false;
        }

        memcpy(newArena, m_Arena, m_ArenaSize);
        MemArenaFree(m_Arena);

        m_Arena = newArena;
        m_ArenaCapacity = size;

        printf("MemArena: Reallocated arena of size %zu\n", size);

        return true;
    }

    bool MemArena::Free() {
        if (m_Arena) {
            // ToDo: implement platform specific stuff
            if (!MemArenaFree(m_Arena)) {
                printf("MemArena: Failed to free memory arena!\n");
                return false;
            }

            m_Arena = nullptr;
            m_ArenaSize = 0;
            m_ArenaCapacity = 0;
        }

        return true;
    }

    void *MemArena::Alloc(size_t size) {
        if (!m_Arena) {
            printf("MemArena: No memory allocated. Call Alloc before writing.\n");
            return nullptr;
        }

        if (m_ArenaSize + size > m_ArenaCapacity) {
            printf("MemArena: Capacity overflow! Resizing arena...\n");

            if (!Resize(m_ArenaSize + (size * 2))) {
                printf("MemArena: Failed to resize arena!\n");
                return nullptr;
            }
        }

        m_ArenaSize += size;

        return (char*) m_Arena + (m_ArenaSize - size);
    }

}
