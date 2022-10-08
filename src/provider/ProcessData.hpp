/*
 * ProcessData.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATA_HPP_
#define SRC_PROVIDER_PROCESSDATA_HPP_

#include <string>
#include <vector>
#include "ProcessState.hpp"

namespace provider
{

class ProcessData final
{
public:
    ProcessData(
        int pid,
        std::string processName,
	    common::ProcessState processState,
	    int numberOfThreads);

    int getPId();
	std::string getProcessName();
	common::ProcessState getProcessState();
	int getNumberOfThreads();

private:
	int pid_;
	std::string processName_;
	common::ProcessState processState_;
	int numberOfThreads_;
};

} // ::provider

#endif /* SRC_PROVIDER_PROCESSDATA_HPP_ */
