/*
 * Reader.hpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_READER_HPP_
#define SRC_PROVIDER_READER_HPP_

#include <array>
#include <filesystem>
#include <fstream>
#include <string>
#include "ProcessData.hpp"

namespace provider {

class Reader
{
public:
    Reader(std::filesystem::path filePath);
    ~Reader();

    ProcessData read();

private:
    static constexpr auto valueRegex = ":|\n";
    // C++20
    static constexpr std::array<std::string, 4> names_ {
        "Name",
        "State",
        "Pid",
        "Threads"
    };

    void readParams();
    ProcessData constructProcessData();

    std::vector<std::pair<std::string, std::string>> params_;
    std::string filePath_;
    std::ifstream file_;
};

}  // namespace provider

#endif /* SRC_PROVIDER_READER_HPP_ */
