/*
 * Tools.cpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#include "Tools.hpp"

namespace ui::console::tools {

std::pair<int, int> getScreenSizeXY()
{
	int row = 0, col = 0;
	getmaxyx(stdscr, row, col);

	return {row, col};
}

}  // namespace ui::console::tools
