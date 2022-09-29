/*
 * main.cpp
 *
 *  Created on: 28 cze 2022
 *      Author: sidewin
 */

#include <iostream>
#include <filesystem>
#include <cctype>
#include <regex>

bool isProcessDirs(const std::string& path)
{
	std::regex r("[0-9]");

	return std::regex_search(path, r);
}

int main()
{
	std::cout << "### Side-Process-Manager ###" << std::endl;


	const std::filesystem::path procDir{"/proc"};

	for (auto const & entry : std::filesystem::directory_iterator{procDir})
	{
		if (entry.is_directory() && isProcessDirs(entry.path()))
		{
			std::cout << entry.path() << "\n";
		}
	}

	return 0;
}
