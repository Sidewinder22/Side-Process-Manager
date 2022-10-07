/*
 * Reader.cpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <algorithm>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <utility>
#include "Reader.hpp"

namespace provider {

Reader::Reader(std::filesystem::path filePath)
    : filePath_(filePath)
{
    std::cout << "Reader, filepath: " << filePath << std::endl;

    file_.open(filePath_, std::ifstream::in);

    if (!file_.is_open())
    {
        throw std::runtime_error("Can't open file!");
    }
}

Reader::~Reader()
{
    std::cout << "Reader, closing file." << std::endl;
    if (file_.is_open())
    {
        file_.close();
    }
}

ProcessData Reader::read()
{
    std::vector<std::string> lines_;
    std::vector<std::pair<std::string, std::string>> params;

    // Load whole file to the memory and next process it.
    do
    {
        std::string buffer_;
        std::getline(file_, buffer_);


        // pair<name_of_parameter, value>

        std::vector<std::string> names = {
            "Name",
            "State",
            "Pid",
            "Threads"
        };

        for (auto && name : names)
        {
            std::regex r("^" + name + "|\n");

            if (std::regex_search(buffer_, r))
            {
                // read the value

                std::smatch valueMatch;
                std::regex r2(":|\n");

                if (std::regex_search(buffer_, valueMatch, r2))
                {

                    // remove whitespaces

                    std::string value = valueMatch.suffix();
                    value.erase(
                        std::remove_if(value.begin(), value.end(), isspace),
                        value.end());
                    params.push_back({name, value});
                }
            }
        }
    }
    while (file_.good());

    std::cout << "******************************************" << std::endl;
    for (auto && p : params)
    {
        std::cout << p.first << " | " << p.second << "\n";
    }
    std::cout << "******************************************" << std::endl;


//    auto result1 = std::find(params.begin(), params.end(),
//            [](std::pair<std::string, std::string> pair)
//        {
////            if (pair.first == std::string("Name"))
////            {
////                return true;
////            }
//            return false;
//        });
////    auto result2 = std::find(params.begin(), params.end(), "State");
////    auto result3 = std::find(params.begin(), params.end(), "Pid");
////    auto result4 = std::find(params.begin(), params.end(), "Threads");
//
//
//    if (result1 != params.end())
////        result2 != params.end() &&
////        result3 != params.end() &&
////        result4 != params.end())
//    {
//        ProcessData data(
//            std::stoi(result1->second),
////            result2->second,
//            "proc",
//            ProcessState::D,
//            1);
//        return std::move(data);
//    }
    std::cout << "[" << params[0].first << "]: " << params[0].second << std::endl;
    std::cout << "[" << params[1].first << "]: " << params[1].second << std::endl;
    std::cout << "[" << params[2].first << "]: " << params[2].second << std::endl;
    std::cout << "[" << params[3].first << "]: " << params[3].second << std::endl;


//    ProcessState state{std::stoi(params[1].second)};

    ProcessData data(
        std::stoi(params[2].second),
        params[0].second,
//        static_cast<ProcessState>(std::stoi(params[1].second)),
//        ProcessState::S,
//        ProcessState{std::stoi(params[1].second)},
        convertStrToState(params[1].second),
        std::stoi(params[3].second));


//    ProcessData data(311, "process", ProcessState::D, 1);
    return std::move(data);
}

ProcessState Reader::convertStrToState(const std::string& stateStr)
{
    std::cout << "convertStrToState, str: " << stateStr << std::endl;

   ProcessState state{ProcessState::U};

   auto stateChar = stateStr.front();

   if (stateChar == 'R')
   {
       state = ProcessState::R;
   }
   else if (stateChar == 'S')
   {
       state = ProcessState::S;
   }
   else if (stateChar == 'D')
   {
       state = ProcessState::D;
   }
   else if (stateChar == 'Z')
   {
       state = ProcessState::Z;
   }
   else if (stateChar == 'T')
   {
       state = ProcessState::T;
   }
   else if (stateChar == 't')
   {
       state = ProcessState::t;
   }
   else if (stateChar == 'X')
   {
       state = ProcessState::X;
   }
   else if (stateChar == 'I')
   {
       state = ProcessState::I;
   }

   return state;
}

//ProcessData Reader::extractProcessData(std::vector<std::string> buffer)
//{
//    static constexpr auto pidRegex = "Pid:";
//
//
//
//    ProcessData data(311, "process", ProcessState::D, 1);
//    return std::move(data);
//}

}  // namespace provider
