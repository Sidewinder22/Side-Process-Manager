/*
 * Window.hpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#ifndef SRC_UI_CONSOLE_WINDOW_HPP_
#define SRC_UI_CONSOLE_WINDOW_HPP_

#include <ncurses.h>

namespace ui::console {

class Window
{
public:
	Window();
	~Window();

	void show();

private:
	WINDOW* win_;
};

}  // namespace ui::console

#endif /* SRC_UI_CONSOLE_WINDOW_HPP_ */
