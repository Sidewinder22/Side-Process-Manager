/*
 * ProcessDataReader.cpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include "ProcessDataReader.hpp"
#include "Reader.hpp"

namespace provider {

ProcessDataReader::ProcessDataReader(
        std::vector<std::filesystem::path> procDirPaths)
    : procDirPaths_(std::move(procDirPaths))
{ }

std::vector<ProcessData> ProcessDataReader::getProcessesData()
{
    for (auto && path : procDirPaths_)
    {
        std::cout << "Processing path: " << path << "\n";

        auto filePath = path.string() + fileName_;
        auto reader = std::make_unique<Reader>(filePath);
        reader->read();
    }

	return {};
}

}  // namespace provider
