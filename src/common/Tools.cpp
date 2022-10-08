/*
 * Tools.cpp
 *
 *  Created on: 8 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include <algorithm>
#include "Tools.hpp"

namespace common::tools {

void removeWhitespaces(std::string& value)
{
    value.erase(
        std::remove_if(value.begin(), value.end(), isspace),
        value.end());
}
}  // namespace common::tools
