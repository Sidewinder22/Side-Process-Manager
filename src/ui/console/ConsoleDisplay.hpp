/*
 * ConsoleDisplay.hpp
 *
 *  Created on: 30 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_UI_CONSOLE_CONSOLEDISPLAY_HPP_
#define SRC_UI_CONSOLE_CONSOLEDISPLAY_HPP_

#include <string>
#include <vector>

namespace ui::console
{

class ConsoleDisplay
{
public:
	void showProcessDirNames(std::vector<std::string> dirNames);
};

}; // ::ui::console

#endif /* SRC_UI_CONSOLE_CONSOLEDISPLAY_HPP_ */
