/*
 * Reader.cpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include <regex>
#include <stdexcept>
#include <utility>
#include "ProcessState.hpp"
#include "Tools.hpp"
#include "Reader.hpp"

namespace provider {

Reader::Reader(std::filesystem::path filePath)
    : filePath_(filePath)
    , names_({
             "Name",
             "State",
             "Pid",
             "Threads"
         })
{
    file_.open(filePath_, std::ifstream::in);

    if (!file_.is_open())
    {
        throw std::runtime_error("Can't open file!");
    }
}

Reader::~Reader()
{
    if (file_.is_open())
    {
        file_.close();
    }
}

ProcessData Reader::read()
{
    readParams();
    return {constructProcessData()};
}

ProcessData Reader::constructProcessData()
{
    int pid;
    std::string name;
    common::ProcessState state;
    int threads;

    for (auto && p : params_)
    {
        if (p.first == names_[0])       // Name
        {
            name = p.second;
        }
        else if (p.first == names_[1])  // State
        {
            state = common::convertStringToState(p.second);
        }
        else if (p.first == names_[2])  // Pid
        {
            pid = std::stoi(p.second);
        }
        else if (p.first == names_[3])  // Threads
        {
            threads = std::stoi(p.second);
        }
    }

    return {pid, name, state, threads};
}

/***
 * Read one line from file, check if it contains desired value
 * if true put it to the vector
 * if not, read the next value
 */
void Reader::readParams()
{
    do
    {
        std::string line;
        std::getline(file_, line);

        for (auto && name : names_)
        {
            std::regex r("^" + name + "|\n");

            if (std::regex_search(line, r))
            {
                std::smatch valueMatch;
                std::regex r2(valueRegex);

                if (std::regex_search(line, valueMatch, r2))
                {
                    std::string value = valueMatch.suffix();
                    common::tools::removeWhitespaces(value);

                    params_.push_back({name, value});
                }
            }
        }
    }
    while (file_.good());
}

}  // namespace provider
