/*
 * Window.hpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#ifndef SRC_UI_CONSOLE_WINDOW_HPP_
#define SRC_UI_CONSOLE_WINDOW_HPP_

#include <string_view>
#include <ncurses.h>
#include <panel.h>

namespace ui::console {

class Window
{
public:
	Window(int height, int width, int starty, int startx);
	~Window();

	void show(std::string_view title);

private:
	WINDOW* win_;
	PANEL* panel_;
};

}  // namespace ui::console

#endif /* SRC_UI_CONSOLE_WINDOW_HPP_ */
