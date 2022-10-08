/*
 * main.cpp
 *
 *  Created on: 28 cze 2022
 *      Author: sidewin
 */

#include <iostream>
#include <thread>
#include "ProcessDataProvider.hpp"
#include "ConsoleDisplay.hpp"

int main()
{
	std::cout << "### Side-Process-Manager ###" << std::endl;

	std::cout << "Hardware threads: "
		<< std::thread::hardware_concurrency() << "\n";

	std::unique_ptr<provider::ProcessDataProvider> provider;
	auto data = provider->getProcessesData();

	std::unique_ptr<ui::console::ConsoleDisplay> console;

//	data.push_back({3113, "name", provider::ProcessState::S, 6});

    std::cout
        << "|  PID  |  "
        << "|  NAME  |  "
        << "|  STATE  |  "
        << "|  THREADS  |\n";

	for( auto&& d: data)
	{
	    std::cout
	        << "|\t" << d.getProcessName()
	        << "\t|\t" << d.getPId()
	        << "\t|\t" << static_cast<int>(d.getProcessState())
	        << "\t|\t" << d.getNumberOfThreads() << "\t|\n";
	}

	/*
	std::thread t(
		&ui::console::ConsoleDisplay::showProcessDirNames,
		*console,
//		std::move(dirNames));
		std::move(processesData));

	t.join();
		*/

	return 0;
}
