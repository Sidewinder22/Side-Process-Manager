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
	void printWelcomeInfo();
	void printLogo(int row, int col);
	void printAuthor(int row, int col);
	void printScreenSize(int row, int col);

	void getAChar();

	static constexpr auto appName_ = "### Side-Process-Manager ###\n";
	static constexpr auto author_ = "{\\_Sidewinder22_/}";
	static constexpr auto screenSize_ = "Screen size: [%d x %d]";
};

}; // ::ui::console

#endif /* SRC_UI_CONSOLE_DISPLAY_HPP_ */
