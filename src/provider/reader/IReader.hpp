/*
 * IReader.hpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_READER_IREADER_HPP_
#define SRC_PROVIDER_READER_IREADER_HPP_

namespace provider::reader {

class IReader
{
public:
	virtual ~IReader() = default;

	template <typename T>
	T readValue(const std::string& name)
	{

	}
};

}  // namespace provider::reader

#endif /* SRC_PROVIDER_READER_IREADER_HPP_ */
