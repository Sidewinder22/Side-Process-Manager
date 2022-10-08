/*
 * ProcessState.hpp
 *
 *  Created on: 2 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#ifndef SRC_PROVIDER_PROCESSSTATE_HPP_
#define SRC_PROVIDER_PROCESSSTATE_HPP_

namespace provider {

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

    U = 128,  // Uknown
};

}  // namespace provider

#endif /* SRC_PROVIDER_PROCESSSTATE_HPP_ */
