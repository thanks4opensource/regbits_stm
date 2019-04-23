regbits_stm: regbits implementations for STM MCUs
=================================================

**stm_regbits** is a work-in-progress set of [regbits](https://github.com/thanks4opensource/regbits) implementations for ST Microelectronics MCUs. [Regbits](https://github.com/thanks4opensource/regbits) provides easy to use, type-safe, compile-time verified C++ methods, operators, and constants for low-level programming of microcontroller registers with equal or better performance (code size and speed) compared to other techniques.



Contents  <a name="contents"></a>
--------
* [License](#license)
* [Usage and features](#usage_and_features)
  * [Usage](#usage)
  * [Named constants](#named_constants)
  * [Compile-time range checking](#Compile-time_range_checking)
  * [Timers](#timers)
* [Compilation](#compilation)
* [Unit tests](#unittests)
* [Future work](#future_work)



License  <a name="license"></a>
-------

regbits_stm: regbits implementations for STM MCUs

Copyright (C) 2019 Mark R. Rubin

This file is part of regbits_stm.

The regbits_stm program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

The regbits_stm program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the [GNU General Public License](LICENSE.txt) along with the regbits_stm program.  If not, see <https://www.gnu.org/licenses/gpl.html>



Usage and features <a name="usage_and_features"></a>
------------------

### Usage <a name="usage"></a>

See ["How is regbits used"](https://github.com/thanks4opensource/regbits#how_is_regbits_used) for a full set of regbits usage examples based on a fictitious microcontroller. Some examples using regbits_stm are:

        rcc->ahb1enr |= Rcc::Ahb1enr::GPIOB | Rcc::Ahb1enr::GPIOE;  // set bits

        gpiob->moder /= Gpio::Moder::OUTPUT_0 | Gpio::Moder::OUTPUT_7;  // set multiple-bit fields without affecting other bits

        gpiob->ospeedr /= Gpio::Ospeedr::HIGH_0 | Gpio::Ospeedr::EXTREME_7;

        gpiob->bsrr = Gpio::Bsrr::BS0 | Gpio::Bsrr::BS7;  // overwrite all bits

        bsctim6->cr1 = Bsctim_6_7::Cr1::OPM | Bsctim_6_7::Cr1::CEN;

Also see [blink.cxx](stm32f767xx/example/blink.cxx) for a regbits_stm implementation of the canonical embedded software demo program.




### Named constants <a name="named_constants"></a>

Regbits_stm provides meaningfully-named constants for all multiple-bit register values:

        // regbits
        gpioa->moder = Gpio::Moder::ALTFUNC_2 | Gpio::Moder::OUTPUT_5 | Gpio::Moder::ANALOG_7;

        // CMSIS Cortex-M7 Device Peripheral Access Layer Header File
        GPIOA->MODER = GPIO_MODER_MODER2_1 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER7_1;



### Compile-time range checking <a name="Compile-time_range_checking"></a>

           i2c1->cr2 = I2c::Cr2::NBYTES<255>();  // good
        // i2c2->cr2 = I2c::Cr2::NBYTES<256>();  // won't compile, value out of range

(See [here](https://github.com/thanks4opensource/regbits#ugly_indexing_syntax) for why C++ requires the above syntax.)

Note again that this compile-time checking has no run-time performance penalty, either in compiled code speed or size, and produces object code identical to:

        // CMSIS Cortex-M7 Device Peripheral Access Layer Header File
        I2C1->CR2 = 255 << I2C_CR2_NBYTES_Pos;



### Timers <a name="timers"></a>

Regbits_stm attempts to provide a consistent system for accessing the large, complex set of STM timers.

#### Compile-time check of features / register sets:

           gentim9->arr = 1500;  // good
           advtim8->arr = 1500;  // good
           advtim8->rcr = 1500;  // good
        // gentim9->rcr = 1500;  // won't compile, only advanced timers 1 and 8 have RCR register


#### Compile-time check of timer type hierarchy:

        void init_timer(Tim* const timer);

        void init_timer_10_13_14(GenTim_10_13_14* const timer);

        void init_timers()
        {
            init_timer(gentim9 );  // good
            init_timer(gentim10);  // good
            init_timer(advtim8 );  // good
            init_timer(bsctim6 );  // good

            init_timer_10_13_14(gentim13);  // good
         // init_timer_10_13_14(gentim11);  // won't compile, not timer 10, 13, or 14
        }


#### Compile-time check of timer by feature:

        void init_timer(TimDmar* const timer);

        void init_timers()
        {
            init_timer(gentim3);  // good
            init_timer(gentim5);  // good
            init_timer(advtim1);  // good
         // init_timer(gentim9);  // won't compile, only general timers 2,3,4,5 and advanced timers 1,8 have DMAR register
        }

Note once again that no run-time code is generated for these checks. Contrast with STM LL and HAL library macros and functions such as:

        IS_TIM_INSTANCE
        assert_param
        assert_failed

which either cause performance degradation if implemented, or don't perform checking if turned off. (Plus, how does an `assert_failed()` implementation in an embedded system handle an `IS_TIM_INSTANCE` error?  Display an error message?  *"An incorrect timer instance has been detected at line 387 of file turbulence_avoidance.c. The autopilot computer will now reboot. Please wait 30 to 60 seconds during which time all aircraft controls will be inoperative."*)

It is this author's opinion that it is better to handle such errors at compile time rather than at 35,000 feet. ;)



Compilation <a name="compilation"></a>
-----------

Both [Regbits](https://github.com/thanks4opensource/regbits) and this repository have only been tested with ARM GCC compilers. Unit test makefiles and build environment (see [Unit tests](#unittests) directly below), and possibly code, may need to be modified for other compilers and development environments.

All regbits code requires C++11 or higher compilation. At least with ARM GCC, optimization level `-O1` or higher is required to prevent storage from being allocated for constant values, and `-mabi=apcs-gnu` or `-mabi=atpcs` specified to force efficient passing regbits `mskd_t` parameters in registers. See the regbits repository for more  [details](https://github.com/thanks4opensource/regbits#requirements_limitations_problems).




Unit tests <a name="unittests"></a>
----------

A reasonably extensive unit test suite is included in the [regbits](https://github.com/thanks4opensource/regbits) repository. See [documentation](https://github.com/thanks4opensource/regbits#unit_test) and [code](https://github.com/thanks4opensource/regbits/tree/master/unittest).

Small sets of unit tests for specific features of the STM regbits implementations in this repository are included here, for example in the [stm32f767xx/unittest](stm32f767xx/unittest) subdirectory.

To run, `cd` to a unittest directory, and type `make` and optionally `make GOOD=-DGOOD`. Nothing will be output if all tests pass, Note that an environment variable, `GCC_ARM_ROOT`, must point to an installed development environment.



Future work <a name="future_work"></a>
-----------

This initial release of regbits_stm contains a single, incomplete, implementation, specifically for the STM32F76xx family of MCUs. At this time, [stm32f767xx.hxx](stm32f767xx/stm32f767xx.hxx) only provides access to  approximately half of the extremely complex chip's capabilities. (Each of the  peripherals that are implemented, however, should be complete.)  The author may add to this implementation, and/or provide regbits for other STM and non-STM MCUs in the future. Any help in doing so would be appreciated.
