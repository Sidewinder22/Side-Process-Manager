/*
 * DataProvider.hpp
 *
 *  Created on: 29 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_
#define SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_

#include <string>
#include <vector>

namespace provider
{

class ProcessDataProvider
{
public:
	std::vector<std::string> getProcessesDirNames();

private:
	bool isProcessDir(const std::string& path);
};

}; // ::provider

#endif /* SRC_PROVIDER_PROCESSDATAPROVIDER_HPP_ */
