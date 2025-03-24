#include <Engine/Core/Runtime/StorageSystem.hpp>

#include <fstream>
#include <sstream>

namespace engine::core::runtime {
    std::string StorageSystem::ReadFileString(std::string_view path) {
        std::ifstream inFile;
        std::stringstream str;

#ifdef WIN32
        auto prefix = std::string{"DataRaw"};
#endif
#ifdef __SWITCH__
        auto prefix = std::string{"romfs:"};
#endif

        printf("StorageSystem: Reading file %s\n", (prefix + "/" + std::string{path}).c_str());

        inFile.open(prefix + "/" + std::string{path});

        if (!inFile) {
            return {};
        }

        str << inFile.rdbuf();

        return str.str();
    }
}
