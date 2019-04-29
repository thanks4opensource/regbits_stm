// regbits_stm: regbits implementations for STM MCUs
// Copyright (C) 2019 Mark R. Rubin
//
// This file is part of regbits_stm.
//
// The regbits_stm program is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.
//
// The regbits_stm program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// (LICENSE.txt) along with the regbits_stm program.  If not, see
// <https://www.gnu.org/licenses/gpl.html>


#include "stm32f767xx.hxx"

using namespace stm32f767xx;


void tim_type(GenTim_2_5* const tim_2_5) {}

void call_tim_type()
{
#ifdef GOOD
    tim_type(gen_tim_2);
#else
    tim_type(gen_tim_3);
#endif
}
