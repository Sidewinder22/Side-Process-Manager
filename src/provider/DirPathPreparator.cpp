/*
 * DirPathPreparator.cpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <regex>
#include "DirPathPreparator.hpp"

namespace provider {

std::vector<std::filesystem::path> DirPathPreparator::prepareProcDirPaths()
{
    std::vector<std::filesystem::path> results;
    const std::filesystem::path procDir{procDirName_};

    for (auto && entry : std::filesystem::directory_iterator{procDir})
    {
        if (entry.is_directory() && isProcessDir(entry.path()))
        {
            results.push_back(entry.path());
        }
    }

    return std::move(results);
}

bool DirPathPreparator::isProcessDir(const std::string& path)
{
    std::regex r(procIdRegex_);

    return std::regex_search(path, r);
}

}  // namespace provider
