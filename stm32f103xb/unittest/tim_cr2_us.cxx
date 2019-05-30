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


#include "stm32f103xb.hxx"

using namespace stm32f103xb;


void tim_cr2_mms()
{
#ifdef GOOD
    adv_tim_1 ->cr2 = AdvTim_1    ::Cr2::CCUS      ;
    gen_tim_3 ->cr2 = GenTim_2_3_4::Cr2::MMS_ENABLE;
#else
    gen_tim_3 ->cr2 = GenTim_2_3_4::Cr2::CCUS      ;
#endif
}
