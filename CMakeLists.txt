cmake_minimum_required(VERSION 3.14)
project(RiftEngine_Core_Runtime VERSION 0.8.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/glm)

add_library(
		RiftEngine_Core_Runtime
#        private/Engine/Core/Runtime/Memory/MemArena_Standard.cpp
        private/Engine/Core/Runtime/StorageSystem.cpp
        private/Engine/Core/Runtime/App.cpp
        private/Engine/Core/Runtime/AppHost.cpp
        private/Engine/Core/Runtime/Graphics/Camera3D.cpp
)

target_include_directories(
		RiftEngine_Core_Runtime
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private"
)

target_compile_definitions(
		RiftEngine_Core_Runtime
        PRIVATE ENGINE_BUILD_LIBRARY
)

target_link_libraries(RiftEngine_Core_Runtime glm::glm Rift_Runtime_Logging)