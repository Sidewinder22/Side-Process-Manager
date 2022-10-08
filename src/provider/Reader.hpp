/*
 * Reader.hpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_READER_HPP_
#define SRC_PROVIDER_READER_HPP_

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "ProcessData.hpp"

namespace provider {

class Reader
{
public:
    Reader(std::filesystem::path filePath);
    ~Reader();

    ProcessData read();

private:
    std::string filePath_;
    std::ifstream file_;
};

}  // namespace provider

#endif /* SRC_PROVIDER_READER_HPP_ */
