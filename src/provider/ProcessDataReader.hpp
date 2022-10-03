/*
 * ProcessDataReader.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATAREADER_HPP_
#define SRC_PROVIDER_PROCESSDATAREADER_HPP_

#include <string>
#include <vector>

namespace provider {

class ProcessDataReader
{
public:
	std::vector<std::string> getStatusData();
};

}  // namespace provider

#endif /* SRC_PROVIDER_PROCESSDATAREADER_HPP_ */
