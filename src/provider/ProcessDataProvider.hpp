/*
 * DataProvider.hpp
 *
 *  Created on: 29 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_
#define SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_

#include <filesystem>
#include <string>
#include <vector>
#include "ProcessData.hpp"

namespace provider
{

class ProcessDataProvider
{
public:
	std::vector<ProcessData> getProcessesData();
};

}; // ::provider

#endif /* SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_ */
