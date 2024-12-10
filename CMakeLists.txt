cmake_minimum_required(VERSION 3.14)
project(RiftEngine_CoreRuntime VERSION 0.8.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
        RiftEngine_CoreRuntime
        private/engine/core/a.cpp
)

target_include_directories(
		RiftEngine_CoreRuntime
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private"
)

target_compile_definitions(
		RiftEngine_CoreRuntime
        PRIVATE ENGINE_BUILD_LIBRARY
)

# target_link_libraries(RiftEngine_CoreRuntime glm)