/*
 * ProcessDataReader.cpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include <stdexcept>
#include "ProcessDataReader.hpp"
#include "Reader.hpp"

namespace provider {

ProcessDataReader::ProcessDataReader(
        std::vector<std::filesystem::path> procDirPaths)
    : procDirPaths_(std::move(procDirPaths))
{ }

std::vector<ProcessData> ProcessDataReader::getProcessesData()
{
    std::vector<ProcessData> results;

    for (auto && path : procDirPaths_)
    {
        auto filePath = path.string() + fileName_;

        try
        {
            auto reader = std::make_unique<Reader>(filePath);
            auto data = reader->read();

            results.push_back(data);
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << "Runtime error: " << e.what() << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid argument error: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Another exception!" << std::endl;
        }
    }

    return results;
}

}  // namespace provider
