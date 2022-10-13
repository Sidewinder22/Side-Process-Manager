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

using namespace std::chrono_literals;

void Display::show()
{
	initscr(); 				// Start curses mode
	raw();
	keypad(stdscr, true);	// For using F-keys
	noecho();
	cbreak(); 				// Line buffering disabled
	start_color();

	printWelcomeInfo();

	int row = 0, col = 0;
	getmaxyx(stdscr, row, col);

	WINDOW* win;
	int startx = 0, starty = 0, width = 0, height = 0;

	height = row - 4;
	width = col - 4;
	starty = 2;
	startx = 2;

	win = newwin(height, width, starty, startx);

	wborder(win, '|', '|', '|','|','|','|','|','|');
	mvwprintw(win, 2, 2, "New window");
	wrefresh(win);

	wgetch(win);

	getch();
	delwin(win);
	endwin();
}

void Display::printWelcomeInfo()
{
	int row = 0, col = 0;
	getmaxyx(stdscr, row, col);

	printLogo(row, col);
	printAuthor(row, col);
	printScreenSize(row, col);

	refresh();

	std::this_thread::sleep_for(2000ms);

	clear();
}

void Display::printLogo(int row, int col)
{
	attron(A_BOLD);
	mvprintw(row/2, (col - std::strlen(appName_))/2, appName_);
	attroff(A_BOLD);
}

void Display::printAuthor(int row, int col)
{
	attron(A_DIM);
	mvprintw((row/2) + 1, (col - std::strlen(author_))/2, author_);
	attroff(A_DIM);
}

void Display::printScreenSize(int row, int col)
{
	int screenSizeLength = std::strlen(screenSize_);
	if (col >= screenSizeLength)
	{
		attron(A_DIM);
		mvprintw(2, col - screenSizeLength -2, screenSize_, row, col);
		attroff(A_DIM);
	}
}

void Display::getChar()
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
