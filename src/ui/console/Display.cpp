/*
 * ConsoleDisplay.cpp
 *
 *  Created on: 30 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <chrono>
#include <cstring>
#include <thread>
#include <ncurses.h>

#include "Display.hpp"

namespace ui::console
{

void Display::show()
{
	// Initialize ncurses features
	initscr();
	raw();
	keypad(stdscr, true);
	noecho();

	int row, col;
	getmaxyx(stdscr, row, col);

	printLogo(row, col);
	printScreenSize(row, col);

//	getAChar();
	refresh();

	getch();
	endwin();
}

void Display::printLogo(int row, int col)
{
	attron(A_BOLD);
	mvprintw(row/2, (col - std::strlen(appName_))/2, appName_);
	attroff(A_BOLD);
}

void Display::printScreenSize(int row, int col)
{
	int screenSizeLength = std::strlen(screenSize_);
	if (col >= screenSizeLength)
	{
		mvprintw(2, col - screenSizeLength -2, screenSize_, row, col);
	}
}

void Display::getAChar()
{
	move(0, 0);
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
