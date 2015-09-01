// Complex flow simulator using lattice Boltzmann method
// Copyright (C) 2015 Matthew Grasinger
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// A copy of the GNU General Public License is at the root directory of
// this program.  If not, see <http://www.gnu.org/licenses/>

#ifndef BALBM_CONFIG_HH
#define BALBM_CONFIG_HH

//#define NDEBUG

//! Define this to use runtime bounds checking when streaming 
//#define BALBM_CHECK_BOUNDSstream_ING

//! Define this to disable bounds checking within armadillo
//#define ARMA_NO_DEBUG

namespace balbm
{
  constexpr std::string VERSION("0.0.1");
}

#endif // BALBM_CONFIG_HH 
