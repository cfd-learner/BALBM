#ifndef __EQUILIBRIUM_HH__
#define __EQUILIBRIUM_HH__

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

namespace balbm
{

namespace d2q9
{

//! \class AbstractEqFunct
//!
//! \brief Abstract class for equilibrium distribution function
//!
//! Defines functor for calculating a local equilibrium distribution function
class AbstractEqFunct
{
public:
  virtual ~AbstractEqFunct()=0;
  inline double f const(const Lattice& lat, const AbstractMultiscaleMap& mmap,
                        const unsigned k)
    { return _f(lat, mmap, k); }
private:
  virtual double _f const(const Lattice& lat, const AbstractMultiscaleMap& mmap,
                          const unsigned k)=0;
};

//! \class IncompFlowEqFunct
//!
//! \brief Equilibrium distribution function for incompressible flow
//!
//! Defines functor for calculating a local equilibrium distribution function
//! for simulating incompressible flow
class IncompFlowEqFunct : public AbstractEqFunct
{
public:
  ~IncompFlowEqFunct() {}
private:
  double _f const(const Lattice& lat, const AbstractMultiscaleMap& mmap,
                  const unsigned k);
};

//! \class IncompFlowHLEqFunct
//!
//! \brief He and Lou equilibrium distribution function for incompressible flow
//!
//! Defines functor for calculating a local He and Lou equilibrium distribution 
//! function for simulating incompressible flow. Used for numerical stability.
class IncompFlowHLEqFunct : public AbstractEqFunct
{
public:
  ~IncompFlowHLEqFunct() {}
  IncompFlowHLEqFunct(unsigned rho_o) : _rho_o(rho_o) {}
private:
  double _rho_o;
  double _f const(const Lattice& lat, const AbstractMultiscaleMap& mmap,
                  const unsigned k);
};

} // namespace d2q9

} // namespace balbm

#endif // __EQUILIBRIUM_HH__
