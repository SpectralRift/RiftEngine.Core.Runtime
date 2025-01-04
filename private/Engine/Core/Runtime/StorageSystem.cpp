#include <Engine/Core/Runtime/StorageSystem.hpp>

#include <fstream>
#include <sstream>

namespace engine::core::runtime {
    std::string StorageSystem::ReadFileString(std::string_view path) {
        std::ifstream inFile;
        std::stringstream str;

        inFile.open("DataRaw/" + std::string{path});

        if (!inFile) {
            return {};
        }

        str << inFile.rdbuf();

        return str.str();
    }
}
