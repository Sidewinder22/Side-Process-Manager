/*
 * Layout.cpp
 *
 *  Created on: 14 paź 2022
 *      Author: sidewin
 */

#include <cmath>
#include "Tools.hpp"
#include "Layout.hpp"

namespace ui::console {

void Layout::createLayout()
{
	auto [row, col] = tools::getScreenSizeXY();

	int columns = std::floor(col / 2);

	int height = row - 2;
	int width = columns - 2;

	int leftStartY = 2;
	int leftStartX = 2;
	int rightStartY = 2;
	int rightStartX = width + 1;

	leftWindow_ = std::make_unique<Window>(height, width, leftStartY, leftStartX);
	rightWindow_ = std::make_unique<Window>(height, width, rightStartY, rightStartX);

	leftWindow_->show(leftWinName_);
	rightWindow_->show(rightWinName_);

	update_panels();
	doupdate();
}

}  // namespace ui::console
