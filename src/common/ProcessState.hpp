/*
 * ProcessState.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_COMMON_PROCESSSTATE_HPP_
#define SRC_COMMON_PROCESSSTATE_HPP_

#include <iostream>
#include <string>

namespace common {

enum class ProcessState
{
    R,	// Running
    S,	// Sleeping in an interruptible wait
    D, 	// Waiting in uninterruptible disk sleep
    Z, 	// Zombie
    T,	// Stopped (on a signal) or (before Linux 2.6.33) trace stopped
    t,	// Tracing stop (Linux 2.6.33 onward)
    X,	// Dead (from Linux 2.6.0 onward)
    I,  // Idle

    Uknown = 128,  // Uknown
};

ProcessState convertStringToState(const std::string& stateStr);

std::string convertStateToString(ProcessState state);

}  // namespace common

#endif /* SRC_COMMON_PROCESSSTATE_HPP_ */
