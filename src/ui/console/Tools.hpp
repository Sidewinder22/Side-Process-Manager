/*
 * Tools.hpp
 *
 *  Created on: 13 paź 2022
 *      Author: sidewin
 */

#ifndef SRC_UI_CONSOLE_TOOLS_HPP_
#define SRC_UI_CONSOLE_TOOLS_HPP_

#include <utility>
#include <ncurses.h>

namespace ui::console::tools {

std::pair<int, int> getScreenSizeXY();

}  // namespace ui::console::tools

#endif /* SRC_UI_CONSOLE_TOOLS_HPP_ */
