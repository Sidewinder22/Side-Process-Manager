/*
 * main.cpp
 *
 *  Created on: 28 cze 2022
 *      Author: sidewin
 */

#include <iostream>
#include <thread>
#include "ProcessDataProvider.hpp"

void showProcessDirNames()
{
	std::unique_ptr<provider::ProcessDataProvider> provider;

	auto dirNames = provider->getProcessesDirNames();

	int i = 4;
	for (auto && name: dirNames)
	{
		std::cout << name << "\t";
		if (++i % 4 == 0)
		{
			std::cout << "\n";
		}
	}
}

int main()
{
	std::cout << "### Side-Process-Manager ###" << std::endl;

	std::thread t(showProcessDirNames);
	t.join();

	return 0;
}
