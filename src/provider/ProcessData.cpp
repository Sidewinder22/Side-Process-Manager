/*
 * ProcessData.cpp
 *
 *  Created on: 3 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include "ProcessData.hpp"

namespace provider {

ProcessData::ProcessData(
        int pid,
        std::string processName,
	    ProcessState processState,
	    int numberOfThreads)
	: pid_(pid)
	, processName_(processName)
	, processState_(processState)
	, numberOfThreads_(numberOfThreads)
	{ }

int ProcessData::getPId()
{
    return pid_;
}

std::string ProcessData::getProcessName()
{
    return processName_;
}

ProcessState ProcessData::getProcessState()
{
    return processState_;
}

int ProcessData::getNumberOfThreads()
{
    return numberOfThreads_;
}

}  // namespace provider
