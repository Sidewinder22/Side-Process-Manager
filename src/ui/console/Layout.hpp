/*
 * Layout.hpp
 *
 *  Created on: 14 paź 2022
 *      Author: sidewin
 */

#ifndef SRC_UI_CONSOLE_LAYOUT_HPP_
#define SRC_UI_CONSOLE_LAYOUT_HPP_

#include <memory>
#include "Window.hpp"

namespace ui::console {

class Layout
{
public:
	void createLayout();

private:
	std::unique_ptr<Window> leftWindow_;
	std::unique_ptr<Window> rightWindow_;

	static constexpr auto leftWinName_ = "Left Window";
	static constexpr auto rightWinName_ = "Right Window";
};

}  // namespace ui::console

#endif /* SRC_UI_CONSOLE_LAYOUT_HPP_ */
