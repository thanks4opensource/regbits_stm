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

*Note: Although the following describes timers in the STM32F76xxx and STM32F77xxx MCUs, most of the discussion is applicable to many if not all other ST series MCUs.*

In terms of features, the various ST timers can be regarded conceptually as falling into an approximate hierarchy, with timers further down the chain having all the capabilities of the ones above them along with new, added features of their own.

        +-- Basic Timers 6 and 7
        |
        +--+--  General Timers 9, 10, 11, 12, 13 and 14
        |  |
        |  +-----  General Timers 9 and 12
        |  |
        |  +--+--  General Timers 10, 11, 13 and 14
        |     |
        |     +-----  General Timers 10, 13 and 14
        |     |
        |     +-----  General Timer 11
        |
        +--+--  General Timers 2, 3, 4 and 5
        |  |
        |  +--+--  General Timers 2 and 5
        |  |  |
        |  |  +----- General Timer 2
        |  |  |
        |  |  +----- General Timer 5
        |  |
        |  +-----  General Timers 3 and 4
        |
        +----- Advanced Timers 1 and 8 (actually from all timers 2->7 and 9->14)

Unfortunately, the hardware implementation of this conceptual hierarchy is not easily modeled by normal C++ classes. C++ derived classes have an in-memory layout in which lower addresses are structured identically to their base class(es), with the derived class's member variables following immediately after. (Note that implementing object-oriented structures in C is done the same way.)

In ST's timer architecture, all timers, regardless of simplicity or complexity, are represented by a block of 26 consecutive 32-bit words. More complex timers have functionality controlled by more of the 26 words, while simpler timers use fewer. (Also note that whether the simpler timers ignore the unused words vs possibly exhibiting undefined or erroneous behavior is not clearly documented.)

The used vs unused words follow no particular pattern, and certainly not the C++ system of new features being added in memory following old ones. For this reason the timers have been modeled as independent C++ classes, with their hierarchy  implemented via explicit conversion methods. This allows a more complex timer to be substituted for one of it's simpler antecedents (as long as only the simpler interface is used), just as a derived class can be substituted for a base class in normal C++ class design.

The downside of this implementation is that client code is more verbose and less intuitive than it would be otherwise, but there is an advantage when dealing with multiple features (see [below](#timer_multiple_features)).

Finally, note that the explicit hierarchy conversions could be implemented via C++ user-defined cast operators, but the resulting client code would then be even more verbose and less intuitive:

        // current implementation
        //
        // use as direct hierarchy parent
        func(gen_tim_2->gen_tim_2_5());
        // direct conversion to 2nd-level parent
        func(gen_tim_2->gen_tim_2_3_4_5());
        // chained conversion to 2nd-level parent
        func(gen_tim_2->gen_tim_2_5()->gen_tim_2_3_4_5());

        // alternate, user-defined cast implementation
        //
        // use as direct hierarchy parent -- is not dereference operator
        func(*gen_tim_2);
        // explicit conversion to direct hierarchy parent
        func(static_cast<GenTim_2_5*>(gen_tim_2));
        // direct conversion to 2nd-level parent
        func(static_cast<GenTim_2_3_4_5*>(gen_tim_2));
        // chained conversion to 2nd-level parent
        func(static_cast<GenTim_2_3_4_5*>(*static_cast<GenTim_2_5*>(gen_tim_2)));

Examples of current implementation usage follow ...


#### Compile-time check of timer features / register sets

        gen_tim_9->arr = 1500;  // good
        adv_tim_8->arr = 1500;  // good
        adv_tim_8->rcr = 1500;  // good
        // won't compile, only advanced timers 1 and 8 have RCR register
        // gen_tim_9->rcr = 1500;


#### Compile-time check of timer type

        void func(GenTim_5* const timer);

        void funcs()
        {
            func(gen_tim_5);  // good
         // func(gen_tim_2);  // won't compile: not general timer 5
        }


#### Compile-time check of timer type hierarchy

        void func(Tim* const timer);
        void func(GenTim_10_13_14* const timer);
        void func(GenTim_10_11_13_14* const timer);

        void funcs()
        {
            // call func(Tim*)
            func(gen_tim_9 ->tim());  // good
            func(gen_tim_10->tim());  // good
            func(adv_tim_8 ->tim());  // good
            func(bsc_tim_6 ->tim());  // good

            // good, calls func(GenTim_10_13_14*) because is type of gen_tim_13
            func(gen_tim_13);
            // good, calls func(GenTim_10_11_13_14*)
            func(gen_tim_11->gen_tim_10_11_13_14());

            // won't compile: gen_tim_11 is type GenTim_11*, no matching func()
            // func(gen_tim_11);

            // won't compile: can't convert gen_tim_9 to GenTim_10_11_13_14*
            // func(gen_tim_9->gen_tim_10_11_13_14());
        }


#### Compile-time check of timer by feature

        void func(TimDmar* const timer);

        void funcs()
        {
            func(gen_tim_3->tim_dmar());  // good
            func(gen_tim_5->tim_dmar());  // good
            func(adv_tim_1->tim_dmar());  // good
            // won't compile, only general timers 2,3,4,5 and advanced timers 1,8 have DMAR register
            // func(gen_tim_9->tim_dmar());
        }


#### Compile-time check of timer by multiple features <a name="timer_multiple_features"></a>

In the following example, note:  

1. Calls to func() will compile and execute even if fewer than all three of the union's elements are set. However, unless all three are used as intended, an incorrect timer could be passed causing unexpected runtime behavior at minimum, if not complete failure (as would also occur if zero elements were set).

2. Compiler optimization will remove the second and third of the three union element assignments (as the object code for all three is identical) resulting in no code inefficiency compared to a non-typesafe C implementation.

        union Features {
            volatile TimCr2*   tim_cr2;
            volatile TimCcr1*  tim_ccr1;
            volatile TimDmar*  tim_dmar;
        };

        void func(
        Features    timer)
        {
            timer.tim_cr2 ->cr2  |= TimCr2::Cr2::TI1S;
            timer.tim_ccr1->ccr1  = 0x1234;
            timer.tim_dmar->dmar /= TimDmar::Dmar::DMAB<0x789>();
        }

        void funcs()
        {
            Features    timer;

            // good: general timer 5 has CR2, CCR1, and DMAR registers
            timer.tim_cr2  = gen_tim_5->tim_cr2 ();
            timer.tim_ccr1 = gen_tim_5->tim_ccr1();
            timer.tim_dmar = gen_tim_5->tim_dmar();
            func(timer);

            // good: advanced timer 8 has CR2, CCR1, and DMAR registers
            timer.tim_cr2  = adv_tim_8->tim_cr2 ();
            timer.tim_ccr1 = adv_tim_8->tim_ccr1();
            timer.tim_dmar = adv_tim_8->tim_dmar();
            func(timer);

            timer.tim_cr2  = bsc_tim_6->tim_cr2 ();
            // won't compile: basic timers 6 and 7 don't have CCR1 register
            // timer.tim_ccr1 = bsc_tim_6->tim_ccr1();  
            // won't compile: basic timers 6 and 7 don't have DMAR register
            // timer.tim_dmar = bsc_tim_6->tim_dmar();
            func(timer);

            // won't compile: basic timers 9 and 12 don't have CR2 register
            // timer.tim_cr2  = gen_tim_9->tim_cr2 ();
            timer.tim_ccr1 = gen_tim_9->tim_ccr1();
            // won't compile: basic timers 9 and 12 don't have DMAR register
            // timer.tim_dmar = gen_tim_9->tim_dmar();
            func(timer);
        #endif
        }


#### Comparison with C implementations

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

Small sets of unit tests for specific features of the STM regbits implementations in this repository are included here, for example in the [stm32f103xb/unittest](stm32f103xb/unittest) and [stm32f767xx/unittest](stm32f767xx/unittest) subdirectories.

To run, `cd` to a unittest directory, and type `make` and optionally `make GOOD=-DGOOD`. Nothing will be output if all tests pass, Note that an environment variable, `GCC_ARM_ROOT`, must point to an installed development environment.



Future work <a name="future_work"></a>
-----------

This initial release of regbits_stm contains two incomplete implementations, one each for the STM32F103xx and STM32F76xx families of MCUs. At this time, [stm32f103xb.hxx](stm32f103xb/stm32f103xb.hxx) and [stm32f767xx.hxx](stm32f767xx/stm32f767xx.hxx) only provides access to  approximately half of the chip's capabilities. (Each of the peripherals that are implemented, however, should be complete.)  The author may add to these implementations, and/or provide regbits for other STM and non-STM MCUs in the future. Any help in doing so would be appreciated.
