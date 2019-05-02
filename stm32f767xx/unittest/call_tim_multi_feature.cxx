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

union RequiredTimerTypes {
    TimCr2*     tim_cr2;
    TimCcr1*    tim_ccr1;
    TimDmar*    tim_dmar;
};


void tim_feature(
RequiredTimerTypes  timer)
{
    timer.tim_cr2 ->cr2  |= TimCr2::Cr2::TI1S;
    timer.tim_ccr1->ccr1  = 0x1234;
    timer.tim_dmar->dmar /= TimDmar::Dmar::DMAB<0x789>();
}


void call_tim_multi_feature()
{
    RequiredTimerTypes  timer;
#ifdef GOOD
    timer.tim_cr2  = gen_tim_5->tim_cr2 ();
    timer.tim_ccr1 = gen_tim_5->tim_ccr1();
    timer.tim_dmar = gen_tim_5->tim_dmar();
    tim_feature(timer);

    timer.tim_cr2  = adv_tim_8->tim_cr2 ();
    timer.tim_ccr1 = adv_tim_8->tim_ccr1();
    timer.tim_dmar = adv_tim_8->tim_dmar();
    tim_feature(timer);
#else
    timer.tim_cr2  = gen_tim_9->tim_cr2 ();
    timer.tim_ccr1 = gen_tim_9->tim_ccr1();
    timer.tim_dmar = gen_tim_9->tim_dmar();
    tim_feature(timer);
#endif
}
