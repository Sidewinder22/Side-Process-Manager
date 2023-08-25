/*
 * main.cpp
 *
 *  Created on: 28 cze 2022
 *      Author: sidewin
 */

#include <iostream>
#include "ProcessDataProvider.hpp"
#include "ProcessState.hpp"
#include "ui/console/Display.hpp"

int main()
{


	std::unique_ptr<provider::ProcessDataProvider> provider;
	auto data = provider->getProcessesData();

//	std::unique_ptr<ui::console::Display> console;

//	console->show();

    std::cout
        << "|  PID  |  "
        << "|  NAME  |  "
        << "|  STATE  |  "
        << "|  THREADS  |\n";

    for( auto&& d: data)
    {
        std::cout
            << "| " << d.getPId()
            << " | " << common::convertStateToString(d.getProcessState())
            << " | " << d.getNumberOfThreads()
            << " | " << d.getProcessName() << " |\n";
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
