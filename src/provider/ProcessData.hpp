/*
 * ProcessData.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATA_HPP_
#define SRC_PROVIDER_PROCESSDATA_HPP_

#include <string>
#include "ProcessState.hpp"

namespace provider
{

class ProcessData
{
public:

private:
	uint pid_;
	std::string processName_;
	ProcessState processState_;
	int numberOfThreads_;
};

} // ::provider

#endif /* SRC_PROVIDER_PROCESSDATA_HPP_ */
