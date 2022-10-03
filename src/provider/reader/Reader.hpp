/*
 * Reader.hpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_READER_READER_HPP_
#define SRC_PROVIDER_READER_READER_HPP_

#include <string>
#include "IReader.hpp"

namespace provider::reader {

class Reader
	: public IReader
{
public:
    Reader(const std::string& fileName);
    ~Reader() override;

private:
    std::string fileName_;
};

}  // namespace provider::reader

#endif /* SRC_PROVIDER_READER_READER_HPP_ */
