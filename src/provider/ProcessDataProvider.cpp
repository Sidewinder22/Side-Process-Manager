/*
 * ProcessDataProvider.cpp
 *
 *  Created on: 29 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include <filesystem>
#include <regex>
#include "ProcessDataProvider.hpp"

namespace provider
{

std::vector<std::string> ProcessDataProvider::getProcessesDirNames()
{
	std::vector<std::string> names;

	const std::filesystem::path procDir{procDirName};

	for (auto const & entry : std::filesystem::directory_iterator{procDir})
	{
		if (entry.is_directory() && isProcessDir(entry.path()))
		{
			names.push_back(entry.path());
		}
	}

	return std::move(names);
}

bool ProcessDataProvider::isProcessDir(const std::string& path)
{
	std::regex r("[0-9]");

	return std::regex_search(path, r);
}

} // ::provider
