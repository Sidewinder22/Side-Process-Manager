/*
 * ConsoleDisplay.cpp
 *
 *  Created on: 30 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <iostream>
#include "ConsoleDisplay.hpp"

namespace ui::console
{

void ConsoleDisplay::show()
{
	initscr();
	printw("Hello, world!");
	getch();
	endwin();
}

void ConsoleDisplay::showProcessDirNames(std::vector<std::string> dirNames)
{
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

};	// ::ui::console
