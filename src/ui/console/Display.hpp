/*
 * ConsoleDisplay.hpp
 *
 *  Created on: 30 wrz 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_UI_CONSOLE_DISPLAY_HPP_
#define SRC_UI_CONSOLE_DISPLAY_HPP_

#include <string>
#include <vector>

namespace ui::console
{

class Display
{
public:
	void show();

private:
	void getAChar();
};

}; // ::ui::console

#endif /* SRC_UI_CONSOLE_DISPLAY_HPP_ */
