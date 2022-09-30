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
	auto dirNames = provider->getProcessesDirNames();

	std::unique_ptr<ui::console::ConsoleDisplay> console;


	std::thread t(
		&ui::console::ConsoleDisplay::showProcessDirNames,
		*console,
		std::move(dirNames));

	t.join();

	return 0;
}
