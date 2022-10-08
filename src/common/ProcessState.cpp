/*
 * ProcessState.cpp
 *
 *  Created on: 8 paź 2022
 *      Author: {\_Sidewinder22_/}
 */

#include "ProcessState.hpp"

namespace common {

ProcessState convertStringToState(const std::string& stateStr)
{
   ProcessState result{ProcessState::Uknown};

   auto stateChar = stateStr.front();

   if (stateChar == 'R')
   {
       result = ProcessState::R;
   }
   else if (stateChar == 'S')
   {
       result = ProcessState::S;
   }
   else if (stateChar == 'D')
   {
       result = ProcessState::D;
   }
   else if (stateChar == 'Z')
   {
       result = ProcessState::Z;
   }
   else if (stateChar == 'T')
   {
       result = ProcessState::T;
   }
   else if (stateChar == 't')
   {
       result = ProcessState::t;
   }
   else if (stateChar == 'X')
   {
       result = ProcessState::X;
   }
   else if (stateChar == 'I')
   {
       result = ProcessState::I;
   }

   return result;
}

std::string convertStateToString(ProcessState state)
{
    std::string result("Unknown");

   if (state == ProcessState::R)
   {
       result = "R";
   }
   else if (state == ProcessState::S)
   {
       result = "S";
   }
   else if (state == ProcessState::D)
   {
       result = "D";
   }
   else if (state == ProcessState::Z)
   {
       result = "Z";
   }
   else if (state == ProcessState::T)
   {
       result = "T";
   }
   else if (state == ProcessState::t)
   {
       result = "t";
   }
   else if (state == ProcessState::X)
   {
       result = "X";
   }
   else if (state == ProcessState::I)
   {
       result = "I";
   }

   return result;
}

}  // namespace common
