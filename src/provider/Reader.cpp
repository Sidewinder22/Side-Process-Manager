/*
 * Reader.cpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include <stdexcept>
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
    if (file_.is_open())
    {
        file_.close();
    }
}

ProcessData Reader::read()
{
    // Load whole file to the memory and next process it.
    //do
    while (file_.good());
    {
        std::string tempBuffer_;

        std::getline(file_, tempBuffer_);

        buffer_.append(tempBuffer_);
    }// while (file_.good());

//    file_.seekg(0, std::ios::end);
//    buffer_.resize(file_.tellg());
//    file_.seekg(0);
//    file_.read(buffer_.data(), buffer_.size());

    std::cout << "File: " << buffer_ << std::endl;

    ProcessData data(311, "process", ProcessState::D, 1);
    return std::move(data);
}

}  // namespace provider
