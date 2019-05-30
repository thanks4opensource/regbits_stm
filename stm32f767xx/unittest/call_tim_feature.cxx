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


void tim_feature(
volatile TimCcmr1_1_2_3_4_5_8_9_12* const   tim_ccmr1_1_2_3_4_5_8_9_12)
{
       tim_ccmr1_1_2_3_4_5_8_9_12->ccmr1
    /= TimCcmr1_1_2_3_4_5_8_9_12::Ccmr1::CC2S_IN_IC2_TI2;
}


void call_tim_feature()
{
#ifdef GOOD
    tim_feature(gen_tim_9->tim_ccmr1_1_2_3_4_5_8_9_12());
#else
    tim_feature(gen_tim_10->tim_ccmr1_1_2_3_4_5_8_9_12());
#endif
}
