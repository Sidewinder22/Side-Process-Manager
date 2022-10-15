/*
 * Window.cpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#include "Tools.hpp"
#include "Window.hpp"

namespace ui::console {

Window::Window(int height, int width, int starty, int startx)
	: win_(nullptr)
{
	win_ = newwin(height, width, starty, startx);
	panel_ = new_panel(win_);
}

Window::~Window()
{
	delwin(win_);
}

void Window::show(std::string_view title)
{
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wborder(win_, '|', '|', '-', '-', '+', '+', '+', '+');

	mvwprintw(win_, 2, 2, title.data());
	wrefresh(win_);
}

}  // namespace ui::console
