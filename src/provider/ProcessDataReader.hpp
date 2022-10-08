/*
 * ProcessDataReader.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATAREADER_HPP_
#define SRC_PROVIDER_PROCESSDATAREADER_HPP_

#include <string>
#include <filesystem>
#include <vector>
#include "ProcessData.hpp"

namespace provider {

class ProcessDataReader
{
public:
    ProcessDataReader(std::vector<std::filesystem::path> procDirPaths);

	std::vector<ProcessData> getProcessesData();

private:
    std::vector<std::filesystem::path> procDirPaths_;

    static constexpr auto fileName_ = "/status";
};

}  // namespace provider

#endif /* SRC_PROVIDER_PROCESSDATAREADER_HPP_ */
