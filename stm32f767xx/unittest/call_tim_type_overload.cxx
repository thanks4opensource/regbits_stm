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


__attribute__((noinline)) void tim_type(
Tim* const      tim)
{
    tim->arr = 100;
}


__attribute__((noinline)) void tim_type(
GenTim_2_3_4_5* const   tim_2_3_4_5)
{
    tim_2_3_4_5->ccer |= GenTim_2_3_4_5::Ccer::CC2E;
}


__attribute__((noinline)) void tim_type(
GenTim_2_5* const   tim_2_5)
{
    tim_2_5->ccr4 = 0xfffff;
}


__attribute__((noinline)) void tim_type(
GenTim_3_4* const   tim_3_4)
{
    tim_3_4->ccr1 = 0x1234;
}



__attribute__((noinline)) void tim_type(
GenTim_2* const tim_2)
{
    tim_2->ccr4 = 0xfffff;
}



void call_tim_type_overload()
{
#ifdef GOOD
    tim_type(gen_tim_2);
    tim_type(gen_tim_2->gen_tim_2_5());
    tim_type(gen_tim_2->gen_tim_2_3_4_5());
    tim_type(gen_tim_2->tim());
    tim_type(gen_tim_3);
#else
    tim_type(gen_tim_3->gen_tim_2_5());
#endif
}
