/*
 * DirPathPreparator.hpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_DIRPATHPREPARATOR_HPP_
#define SRC_PROVIDER_DIRPATHPREPARATOR_HPP_

#include <filesystem>
#include <vector>

namespace provider {

class DirPathPreparator
{
public:
    std::vector<std::filesystem::path> prepareProcDirPaths();

private:
    bool isProcessDir(const std::string& path);

    static constexpr auto procIdRegex_ = "[0-9]";
    static constexpr auto procDirName_ = "/proc";
};

}  // namespace provider

#endif /* SRC_PROVIDER_DIRPATHPREPARATOR_HPP_ */
