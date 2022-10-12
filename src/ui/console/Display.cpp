/*
 * ConsoleDisplay.cpp
 *
 *  Created on: 30 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <chrono>
#include <iostream>
#include <thread>
#include <ncurses.h>

#include "Display.hpp"

namespace ui::console
{

void Display::show()
{
	initscr();
	raw();
	keypad(stdscr, true);
	noecho();

	printw("### Side-Process-Manager ###\n");
	getAChar();

	refresh();

	getch();
	endwin();
}

void Display::getAChar()
{
	printw("Type any char...\n");

	int ch = getch();
	if (ch == KEY_F(1))
	{
		printw("Key F1 pressed!");
	}
	else
	{
		printw("The pressed key is: ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
}

};	// ::ui::console
