#pragma once
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

namespace provisioner::platform::curseforge
{
    struct CurseforgeManifestModLoader
    {
        std::string id;
        bool primary = false;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CurseforgeManifestModLoader, id, primary)

    struct CurseforgeManifestMinecraftInfo
    {
        std::string version;
        std::vector<CurseforgeManifestModLoader> modLoaders;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CurseforgeManifestMinecraftInfo, version, modLoaders)

    struct CurseforgeManifestRequirement
    {
        int projectID = 0;
        int64_t fileID = 0;
        bool required = false;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CurseforgeManifestRequirement, projectID, fileID, required)

    struct CurseforgeManifestData
    {
        CurseforgeManifestMinecraftInfo minecraft;
        std::string manifestType = "minecraftModpack";
        int manifestVersion = 1;
        std::string name;
        std::string version;
        std::string author;
        std::vector<CurseforgeManifestRequirement> files;
        std::string overrides = "overrides";
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CurseforgeManifestData, minecraft, manifestType, manifestVersion, name, version, author, files, overrides)
}
