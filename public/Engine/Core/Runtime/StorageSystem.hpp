#pragma once

#include <string>

namespace engine::core::runtime {
    struct StorageSystem {
        static std::string ReadFileString(std::string_view path);
    };
}
