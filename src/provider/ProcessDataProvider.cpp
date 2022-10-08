/*
 * ProcessDataProvider.cpp
 *
 *  Created on: 29 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#include "DirPathPreparator.hpp"
#include "ProcessDataReader.hpp"
#include "ProcessDataProvider.hpp"

namespace provider
{

std::vector<ProcessData> ProcessDataProvider::getProcessesData()
{
    auto pathPreparator = std::make_unique<DirPathPreparator>();

    auto reader = std::make_unique<ProcessDataReader>(
        pathPreparator->prepareProcDirPaths());

    return reader->getProcessesData();
}

} // ::provider
