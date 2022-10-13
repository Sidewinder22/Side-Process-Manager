/*
 * Window.cpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#include "Tools.hpp"
#include "Window.hpp"

namespace ui::console {

Window::Window()
	: win_(nullptr)
{
	auto [row, col] = tools::getScreenSizeXY();

	int height = row - 4;
	int width = col - 4;
	int starty = 2;
	int startx = 2;

	win_ = newwin(height, width, starty, startx);
}

Window::~Window()
{
	delwin(win_);
}

void Window::show()
{
	wborder(win_, '|', '|', '|','|','|','|','|','|');
	mvwprintw(win_, 2, 2, "New window");
	wrefresh(win_);

	wgetch(win_);
}

}  // namespace ui::console
