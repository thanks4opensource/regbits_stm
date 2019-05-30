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


#ifndef STM32F103XB_HXX
#define STM32F103XB_HXX

#include <stdint.h>

#include <regbits.hxx>



namespace stm32f103xb {

using namespace regbits;

struct Rcc {
    struct Cr {
        using              pos_t = Pos<uint32_t, Cr>;
        static constexpr   pos_t
               HSION_POS = pos_t( 0),
              HSIRDY_POS = pos_t( 1),
             HSITRIM_POS = pos_t( 3),
              HSICAL_POS = pos_t( 8),
               HSEON_POS = pos_t(16),
              HSERDY_POS = pos_t(17),
              HSEBYP_POS = pos_t(18),
               CSSON_POS = pos_t(19),
               PLLON_POS = pos_t(24),
              PLLRDY_POS = pos_t(25);

        using              bits_t = Bits<uint32_t, Cr>;
        static constexpr   bits_t
        HSION            = bits_t(1,        HSION_POS),
        HSIRDY           = bits_t(1,       HSIRDY_POS),
        HSEON            = bits_t(1,        HSEON_POS),
        HSERDY           = bits_t(1,       HSERDY_POS),
        HSEBYP           = bits_t(1,       HSEBYP_POS),
        CSSON            = bits_t(1,        CSSON_POS),
        PLLON            = bits_t(1,        PLLON_POS),
        PLLRDY           = bits_t(1,       PLLRDY_POS);

        static const uint32_t
            HSITRIM_MASK =      0x1FU,
             HSICAL_MASK =      0xFFU;

        using   mskd_t = Mskd<uint32_t, Cr>;
        using   shft_t = Shft<uint32_t, Cr>;

        REGBITS_MSKD_RANGE("Rcc::Cr",
                           HSITRIM,
                           hsitrim,
                           HSITRIM_MASK,
                           HSITRIM_POS,
                           HSITRIM_MASK);
        REGBITS_MSKD_RANGE("Rcc::Cr",
                           HSICAL,
                           hsical,
                           HSICAL_MASK,
                           HSICAL_POS,
                           HSICAL_MASK);
    };  // struct Cr
    using cr_t = Reg<uint32_t, Cr>;
          cr_t   cr;


    struct Cfgr {
        using              pos_t = Pos<uint32_t, Cfgr>;
        static constexpr   pos_t
                  SW_POS = pos_t( 0),
                 SWS_POS = pos_t( 2),
                HPRE_POS = pos_t( 4),
               PPRE1_POS = pos_t( 8),
               PPRE2_POS = pos_t(11),
              ADCPRE_POS = pos_t(14),
              PLLSRC_POS = pos_t(16),
            PLLXTPRE_POS = pos_t(17),
             PLLMULL_POS = pos_t(18),
            PLLMULL3_POS = pos_t(18),
            PLLMULL4_POS = pos_t(19),
            PLLMULL5_POS = pos_t(18),
            PLLMULL6_POS = pos_t(20),
            PLLMULL7_POS = pos_t(18),
            PLLMULL8_POS = pos_t(19),
            PLLMULL9_POS = pos_t(18),
           PLLMULL10_POS = pos_t(21),
           PLLMULL11_POS = pos_t(18),
           PLLMULL12_POS = pos_t(19),
           PLLMULL13_POS = pos_t(18),
           PLLMULL14_POS = pos_t(20),
           PLLMULL15_POS = pos_t(18),
           PLLMULL16_POS = pos_t(19),
              USBPRE_POS = pos_t(22),
                 MCO_POS = pos_t(24);

        using              bits_t = Bits<uint32_t, Cfgr>;
        static constexpr   bits_t
        PLLSRC           = bits_t(1,       PLLSRC_POS),
        PLLXTPRE         = bits_t(1,     PLLXTPRE_POS),
        PLLMULL3         = bits_t(1,     PLLMULL3_POS),
        PLLMULL4         = bits_t(1,     PLLMULL4_POS),
        PLLMULL6         = bits_t(1,     PLLMULL6_POS),
        PLLMULL10        = bits_t(1,    PLLMULL10_POS),
        USBPRE           = bits_t(1,       USBPRE_POS);

        static const uint32_t
                 SW_MASK =       0x3U,
                SWS_MASK =       0x3U,
               HPRE_MASK =       0xFU,
              PPRE1_MASK =       0x7U,
              PPRE2_MASK =       0x7U,
             ADCPRE_MASK =       0x3U,
            PLLMULL_MASK =       0xFU,
           PLLMULL5_MASK =       0x3U,
           PLLMULL7_MASK =       0x5U,
           PLLMULL8_MASK =       0x3U,
           PLLMULL9_MASK =       0x7U,
          PLLMULL11_MASK =       0x9U,
          PLLMULL12_MASK =       0x5U,
          PLLMULL13_MASK =       0xBU,
          PLLMULL14_MASK =       0x3U,
          PLLMULL15_MASK =       0xDU,
          PLLMULL16_MASK =       0x7U,
                MCO_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Cfgr>;
        static constexpr   mskd_t
        SW_HSI           = mskd_t(         SW_MASK,  0,        SW_POS),
        SW_HSE           = mskd_t(         SW_MASK,  1,        SW_POS),
        SW_PLL           = mskd_t(         SW_MASK,  2,        SW_POS),
        SWS_HSI          = mskd_t(        SWS_MASK,  0,       SWS_POS),
        SWS_HSE          = mskd_t(        SWS_MASK,  1,       SWS_POS),
        SWS_PLL          = mskd_t(        SWS_MASK,  2,       SWS_POS),

        HPRE_DIV_NONE = mskd_t(HPRE_MASK, 0b0000, HPRE_POS),
        HPRE_DIV_1    = mskd_t(HPRE_MASK, 0b0000, HPRE_POS),
        HPRE_DIV_2    = mskd_t(HPRE_MASK, 0b1000, HPRE_POS),
        HPRE_DIV_4    = mskd_t(HPRE_MASK, 0b1001, HPRE_POS),
        HPRE_DIV_8    = mskd_t(HPRE_MASK, 0b1010, HPRE_POS),
        HPRE_DIV_16   = mskd_t(HPRE_MASK, 0b1011, HPRE_POS),
        HPRE_DIV_64   = mskd_t(HPRE_MASK, 0b1100, HPRE_POS),
        HPRE_DIV_128  = mskd_t(HPRE_MASK, 0b1101, HPRE_POS),
        HPRE_DIV_256  = mskd_t(HPRE_MASK, 0b1110, HPRE_POS),
        HPRE_DIV_512  = mskd_t(HPRE_MASK, 0b1111, HPRE_POS),

        PPRE1_DIV_1   = mskd_t(PPRE1_MASK, 0b000, PPRE1_POS),
        PPRE1_DIV_2   = mskd_t(PPRE1_MASK, 0b100, PPRE1_POS),
        PPRE1_DIV_4   = mskd_t(PPRE1_MASK, 0b101, PPRE1_POS),
        PPRE1_DIV_8   = mskd_t(PPRE1_MASK, 0b110, PPRE1_POS),
        PPRE1_DIV_16  = mskd_t(PPRE1_MASK, 0b111, PPRE1_POS),

        PPRE2_DIV_1   = mskd_t(PPRE2_MASK, 0b000, PPRE2_POS),
        PPRE2_DIV_2   = mskd_t(PPRE2_MASK, 0b100, PPRE2_POS),
        PPRE2_DIV_4   = mskd_t(PPRE2_MASK, 0b101, PPRE2_POS),
        PPRE2_DIV_8   = mskd_t(PPRE2_MASK, 0b110, PPRE2_POS),
        PPRE2_DIV_16  = mskd_t(PPRE2_MASK, 0b111, PPRE2_POS),

        ADCPRE_DIV_2  = mskd_t(    ADCPRE_MASK,  0b00,       ADCPRE_POS),
        ADCPRE_DIV_4  = mskd_t(    ADCPRE_MASK,  0b01,       ADCPRE_POS),
        ADCPRE_DIV_6  = mskd_t(    ADCPRE_MASK,  0b10,       ADCPRE_POS),
        ADCPRE_DIV_8  = mskd_t(    ADCPRE_MASK,  0b11,       ADCPRE_POS),

        PLLMULL_2     = mskd_t(   PLLMULL_MASK,   0,        PLLMULL_POS),
        PLLMULL_3     = mskd_t(   PLLMULL_MASK,   1,        PLLMULL_POS),
        PLLMULL_4     = mskd_t(   PLLMULL_MASK,   2,        PLLMULL_POS),
        PLLMULL_5     = mskd_t(   PLLMULL_MASK,   3,        PLLMULL_POS),
        PLLMULL_6     = mskd_t(   PLLMULL_MASK,   4,        PLLMULL_POS),
        PLLMULL_7     = mskd_t(   PLLMULL_MASK,   5,        PLLMULL_POS),
        PLLMULL_8     = mskd_t(   PLLMULL_MASK,   6,        PLLMULL_POS),
        PLLMULL_9     = mskd_t(   PLLMULL_MASK,   7,        PLLMULL_POS),
        PLLMULL_10    = mskd_t(   PLLMULL_MASK,   8,        PLLMULL_POS),
        PLLMULL_11    = mskd_t(   PLLMULL_MASK,   9,        PLLMULL_POS),
        PLLMULL_12    = mskd_t(   PLLMULL_MASK,  10,        PLLMULL_POS),
        PLLMULL_13    = mskd_t(   PLLMULL_MASK,  11,        PLLMULL_POS),
        PLLMULL_14    = mskd_t(   PLLMULL_MASK,  12,        PLLMULL_POS),
        PLLMULL_15    = mskd_t(   PLLMULL_MASK,  13,        PLLMULL_POS),
        PLLMULL_16    = mskd_t(   PLLMULL_MASK,  14,        PLLMULL_POS),

        MCO_NONE      = mskd_t(       MCO_MASK,  0b000,         MCO_POS),
        MCO_SYSCLK    = mskd_t(       MCO_MASK,  0b100,         MCO_POS),
        MCO_HSI       = mskd_t(       MCO_MASK,  0b101,         MCO_POS),
        MCO_HSE       = mskd_t(       MCO_MASK,  0b110,         MCO_POS),
        MCO_PLL_DIV_2 = mskd_t(       MCO_MASK,  0b111,         MCO_POS);
    };  // struct Cfgr
    using cfgr_t = Reg<uint32_t, Cfgr>;
          cfgr_t   cfgr;


    struct Cir {
        using              pos_t = Pos<uint32_t, Cir>;
        static constexpr   pos_t
             LSIRDYF_POS = pos_t( 0),
             LSERDYF_POS = pos_t( 1),
             HSIRDYF_POS = pos_t( 2),
             HSERDYF_POS = pos_t( 3),
             PLLRDYF_POS = pos_t( 4),
                CSSF_POS = pos_t( 7),
            LSIRDYIE_POS = pos_t( 8),
            LSERDYIE_POS = pos_t( 9),
            HSIRDYIE_POS = pos_t(10),
            HSERDYIE_POS = pos_t(11),
            PLLRDYIE_POS = pos_t(12),
             LSIRDYC_POS = pos_t(16),
             LSERDYC_POS = pos_t(17),
             HSIRDYC_POS = pos_t(18),
             HSERDYC_POS = pos_t(19),
             PLLRDYC_POS = pos_t(20),
                CSSC_POS = pos_t(23);

        using              bits_t = Bits<uint32_t, Cir>;
        static constexpr   bits_t
        LSIRDYF          = bits_t(1,      LSIRDYF_POS),
        LSERDYF          = bits_t(1,      LSERDYF_POS),
        HSIRDYF          = bits_t(1,      HSIRDYF_POS),
        HSERDYF          = bits_t(1,      HSERDYF_POS),
        PLLRDYF          = bits_t(1,      PLLRDYF_POS),
        CSSF             = bits_t(1,         CSSF_POS),
        LSIRDYIE         = bits_t(1,     LSIRDYIE_POS),
        LSERDYIE         = bits_t(1,     LSERDYIE_POS),
        HSIRDYIE         = bits_t(1,     HSIRDYIE_POS),
        HSERDYIE         = bits_t(1,     HSERDYIE_POS),
        PLLRDYIE         = bits_t(1,     PLLRDYIE_POS),
        LSIRDYC          = bits_t(1,      LSIRDYC_POS),
        LSERDYC          = bits_t(1,      LSERDYC_POS),
        HSIRDYC          = bits_t(1,      HSIRDYC_POS),
        HSERDYC          = bits_t(1,      HSERDYC_POS),
        PLLRDYC          = bits_t(1,      PLLRDYC_POS),
        CSSC             = bits_t(1,         CSSC_POS);
    };  // struct Cir
    using cir_t = Reg<uint32_t, Cir>;
          cir_t   cir;


    struct Apb2rstr {
        using              pos_t = Pos<uint32_t, Apb2rstr>;
        static constexpr   pos_t
             AFIORST_POS = pos_t( 0),
             IOPARST_POS = pos_t( 2),
             IOPBRST_POS = pos_t( 3),
             IOPCRST_POS = pos_t( 4),
             IOPDRST_POS = pos_t( 5),
             ADC1RST_POS = pos_t( 9),
             ADC2RST_POS = pos_t(10),
             TIM1RST_POS = pos_t(11),
             SPI1RST_POS = pos_t(12),
           USART1RST_POS = pos_t(14),
             IOPERST_POS = pos_t( 6);

        using              bits_t = Bits<uint32_t, Apb2rstr>;
        static constexpr   bits_t
        AFIORST          = bits_t(1,      AFIORST_POS),
        IOPARST          = bits_t(1,      IOPARST_POS),
        IOPBRST          = bits_t(1,      IOPBRST_POS),
        IOPCRST          = bits_t(1,      IOPCRST_POS),
        IOPDRST          = bits_t(1,      IOPDRST_POS),
        ADC1RST          = bits_t(1,      ADC1RST_POS),
        ADC2RST          = bits_t(1,      ADC2RST_POS),
        TIM1RST          = bits_t(1,      TIM1RST_POS),
        SPI1RST          = bits_t(1,      SPI1RST_POS),
        USART1RST        = bits_t(1,    USART1RST_POS),
        IOPERST          = bits_t(1,      IOPERST_POS);
    };  // struct Apb2rstr
    using apb2rstr_t = Reg<uint32_t, Apb2rstr>;
          apb2rstr_t   apb2rstr;


    struct Apb1rstr {
        using              pos_t = Pos<uint32_t, Apb1rstr>;
        static constexpr   pos_t
             TIM2RST_POS = pos_t( 0),
             TIM3RST_POS = pos_t( 1),
             WWDGRST_POS = pos_t(11),
           USART2RST_POS = pos_t(17),
             I2C1RST_POS = pos_t(21),
             CAN1RST_POS = pos_t(25),
              BKPRST_POS = pos_t(27),
              PWRRST_POS = pos_t(28),
             TIM4RST_POS = pos_t( 2),
             SPI2RST_POS = pos_t(14),
           USART3RST_POS = pos_t(18),
             I2C2RST_POS = pos_t(22),
              USBRST_POS = pos_t(23);

        using              bits_t = Bits<uint32_t, Apb1rstr>;
        static constexpr   bits_t
        TIM2RST          = bits_t(1,      TIM2RST_POS),
        TIM3RST          = bits_t(1,      TIM3RST_POS),
        WWDGRST          = bits_t(1,      WWDGRST_POS),
        USART2RST        = bits_t(1,    USART2RST_POS),
        I2C1RST          = bits_t(1,      I2C1RST_POS),
        CAN1RST          = bits_t(1,      CAN1RST_POS),
        BKPRST           = bits_t(1,       BKPRST_POS),
        PWRRST           = bits_t(1,       PWRRST_POS),
        TIM4RST          = bits_t(1,      TIM4RST_POS),
        SPI2RST          = bits_t(1,      SPI2RST_POS),
        USART3RST        = bits_t(1,    USART3RST_POS),
        I2C2RST          = bits_t(1,      I2C2RST_POS),
        USBRST           = bits_t(1,       USBRST_POS);
    };  // struct Apb1rstr
    using apb1rstr_t = Reg<uint32_t, Apb1rstr>;
          apb1rstr_t   apb1rstr;


    struct Ahbenr {
        using              pos_t = Pos<uint32_t, Ahbenr>;
        static constexpr   pos_t
              DMA1EN_POS = pos_t( 0),
              SRAMEN_POS = pos_t( 2),
             FLITFEN_POS = pos_t( 4),
               CRCEN_POS = pos_t( 6);

        using              bits_t = Bits<uint32_t, Ahbenr>;
        static constexpr   bits_t
        DMA1EN           = bits_t(1,       DMA1EN_POS),
        SRAMEN           = bits_t(1,       SRAMEN_POS),
        FLITFEN          = bits_t(1,      FLITFEN_POS),
        CRCEN            = bits_t(1,        CRCEN_POS);
    };  // struct Ahbenr
    using ahbenr_t = Reg<uint32_t, Ahbenr>;
          ahbenr_t   ahbenr;



    struct Apb2enr {
        using              pos_t = Pos<uint32_t, Apb2enr>;
        static constexpr   pos_t
              AFIOEN_POS = pos_t( 0),
              IOPAEN_POS = pos_t( 2),
              IOPBEN_POS = pos_t( 3),
              IOPCEN_POS = pos_t( 4),
              IOPDEN_POS = pos_t( 5),
              ADC1EN_POS = pos_t( 9),
              ADC2EN_POS = pos_t(10),
              TIM1EN_POS = pos_t(11),
              SPI1EN_POS = pos_t(12),
            USART1EN_POS = pos_t(14),
              IOPEEN_POS = pos_t( 6);

        using              bits_t = Bits<uint32_t, Apb2enr>;
        static constexpr   bits_t
        AFIOEN           = bits_t(1,       AFIOEN_POS),
        IOPAEN           = bits_t(1,       IOPAEN_POS),
        IOPBEN           = bits_t(1,       IOPBEN_POS),
        IOPCEN           = bits_t(1,       IOPCEN_POS),
        IOPDEN           = bits_t(1,       IOPDEN_POS),
        ADC1EN           = bits_t(1,       ADC1EN_POS),
        ADC2EN           = bits_t(1,       ADC2EN_POS),
        TIM1EN           = bits_t(1,       TIM1EN_POS),
        SPI1EN           = bits_t(1,       SPI1EN_POS),
        USART1EN         = bits_t(1,     USART1EN_POS),
        IOPEEN           = bits_t(1,       IOPEEN_POS);
    };  // struct Apb2enr
    using apb2enr_t = Reg<uint32_t, Apb2enr>;
          apb2enr_t   apb2enr;



    struct Apb1enr {
        using              pos_t = Pos<uint32_t, Apb1enr>;
        static constexpr   pos_t
              TIM2EN_POS = pos_t( 0),
              TIM3EN_POS = pos_t( 1),
              WWDGEN_POS = pos_t(11),
            USART2EN_POS = pos_t(17),
              I2C1EN_POS = pos_t(21),
              CAN1EN_POS = pos_t(25),
               BKPEN_POS = pos_t(27),
               PWREN_POS = pos_t(28),
              TIM4EN_POS = pos_t( 2),
              SPI2EN_POS = pos_t(14),
            USART3EN_POS = pos_t(18),
              I2C2EN_POS = pos_t(22),
               USBEN_POS = pos_t(23);

        using              bits_t = Bits<uint32_t, Apb1enr>;
        static constexpr   bits_t
        TIM2EN           = bits_t(1,       TIM2EN_POS),
        TIM3EN           = bits_t(1,       TIM3EN_POS),
        WWDGEN           = bits_t(1,       WWDGEN_POS),
        USART2EN         = bits_t(1,     USART2EN_POS),
        I2C1EN           = bits_t(1,       I2C1EN_POS),
        CAN1EN           = bits_t(1,       CAN1EN_POS),
        BKPEN            = bits_t(1,        BKPEN_POS),
        PWREN            = bits_t(1,        PWREN_POS),
        TIM4EN           = bits_t(1,       TIM4EN_POS),
        SPI2EN           = bits_t(1,       SPI2EN_POS),
        USART3EN         = bits_t(1,     USART3EN_POS),
        I2C2EN           = bits_t(1,       I2C2EN_POS),
        USBEN            = bits_t(1,        USBEN_POS);
    };  // struct Apb1enr
    using apb1enr_t = Reg<uint32_t, Apb1enr>;
          apb1enr_t   apb1enr;



    struct Bdcr {
        using              pos_t = Pos<uint32_t, Bdcr>;
        static constexpr   pos_t
               LSEON_POS = pos_t( 0),
              LSERDY_POS = pos_t( 1),
              LSEBYP_POS = pos_t( 2),
              RTCSEL_POS = pos_t( 8),
               RTCEN_POS = pos_t(15),
               BDRST_POS = pos_t(16);

        using              bits_t = Bits<uint32_t, Bdcr>;
        static constexpr   bits_t
        LSEON            = bits_t(1,        LSEON_POS),
        LSERDY           = bits_t(1,       LSERDY_POS),
        LSEBYP           = bits_t(1,       LSEBYP_POS),
        RTCEN            = bits_t(1,        RTCEN_POS);

        static const uint32_t
             RTCSEL_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Bdcr>;
        static constexpr   mskd_t

        RTCSEL_NOCLOCK   = mskd_t(     RTCSEL_MASK,  0b00,     RTCSEL_POS),
        RTCSEL_LSE       = mskd_t(     RTCSEL_MASK,  0b01,     RTCSEL_POS),
        RTCSEL_LSI       = mskd_t(     RTCSEL_MASK,  0b10,     RTCSEL_POS),
        RTCSEL_HSE       = mskd_t(     RTCSEL_MASK,  0b11,     RTCSEL_POS);
    };  // struct Bdcr
    using bdcr_t = Reg<uint32_t, Bdcr>;
          bdcr_t   bdcr;



    struct Csr {
        using              pos_t = Pos<uint32_t, Csr>;
        static constexpr   pos_t
               LSION_POS = pos_t( 0),
              LSIRDY_POS = pos_t( 1),
                RMVF_POS = pos_t(24),
             PINRSTF_POS = pos_t(26),
             PORRSTF_POS = pos_t(27),
             SFTRSTF_POS = pos_t(28),
            IWDGRSTF_POS = pos_t(29),
            WWDGRSTF_POS = pos_t(30),
            LPWRRSTF_POS = pos_t(31);

        using              bits_t = Bits<uint32_t, Csr>;
        static constexpr   bits_t
        LSION            = bits_t(1,        LSION_POS),
        LSIRDY           = bits_t(1,       LSIRDY_POS),
        RMVF             = bits_t(1,         RMVF_POS),
        PINRSTF          = bits_t(1,      PINRSTF_POS),
        PORRSTF          = bits_t(1,      PORRSTF_POS),
        SFTRSTF          = bits_t(1,      SFTRSTF_POS),
        IWDGRSTF         = bits_t(1,     IWDGRSTF_POS),
        WWDGRSTF         = bits_t(1,     WWDGRSTF_POS),
        LPWRRSTF         = bits_t(1,     LPWRRSTF_POS);
    };  // struct Csr
    using csr_t = Reg<uint32_t, Csr>;
          csr_t   csr;
};  // struct Rcc
static_assert(sizeof(Rcc) == 40, "sizeof(Rcc) != 40");


struct Gpio {
    struct Crl {
        using              pos_t = Pos<uint32_t, Crl>;
        static constexpr   pos_t
               MODE0_POS = pos_t( 0),
               MODE1_POS = pos_t( 4),
               MODE2_POS = pos_t( 8),
               MODE3_POS = pos_t(12),
               MODE4_POS = pos_t(16),
               MODE5_POS = pos_t(20),
               MODE6_POS = pos_t(24),
               MODE7_POS = pos_t(28),
                CNF0_POS = pos_t( 2),
                CNF1_POS = pos_t( 6),
                CNF2_POS = pos_t(10),
                CNF3_POS = pos_t(14),
                CNF4_POS = pos_t(18),
                CNF5_POS = pos_t(22),
                CNF6_POS = pos_t(26),
                CNF7_POS = pos_t(30);

        static const uint32_t       MASK               = 0b11,
                                    INPUT_ANALOG       = 0b00,
                                    INPUT_FLOATING     = 0b01,
                                    INPUT_PULL_UP_DOWN = 0b10,
                                    OUTPUT_PUSH_PULL   = 0b00,
                                    OUTPUT_OPEN_DRAIN  = 0b01,
                                    ALTFUNC_PUSH_PULL  = 0b10,
                                    ALTFUNC_OPEN_DRAIN = 0b11,
                                    INPUT              = 0b00,
                                    OUTPUT_10_MHZ      = 0b01,
                                    OUTPUT_2_MHZ       = 0b10,
                                    OUTPUT_50_MHZ      = 0b11;

        using              mskd_t = Mskd<uint32_t, Crl>;
        static constexpr   mskd_t
        CNF0_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF0_POS),
        CNF0_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF0_POS),
        CNF0_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF0_POS),
        CNF0_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF0_POS),
        CNF0_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF0_POS),
        CNF0_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF0_POS),
        CNF0_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF0_POS),

        CNF1_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF1_POS),
        CNF1_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF1_POS),
        CNF1_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF1_POS),
        CNF1_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF1_POS),
        CNF1_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF1_POS),
        CNF1_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF1_POS),
        CNF1_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF1_POS),

        CNF2_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF2_POS),
        CNF2_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF2_POS),
        CNF2_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF2_POS),
        CNF2_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF2_POS),
        CNF2_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF2_POS),
        CNF2_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF2_POS),
        CNF2_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF2_POS),

        CNF3_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF3_POS),
        CNF3_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF3_POS),
        CNF3_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF3_POS),
        CNF3_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF3_POS),
        CNF3_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF3_POS),
        CNF3_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF3_POS),
        CNF3_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF3_POS),

        CNF4_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF4_POS),
        CNF4_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF4_POS),
        CNF4_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF4_POS),
        CNF4_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF4_POS),
        CNF4_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF4_POS),
        CNF4_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF4_POS),
        CNF4_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF4_POS),

        CNF5_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF5_POS),
        CNF5_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF5_POS),
        CNF5_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF5_POS),
        CNF5_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF5_POS),
        CNF5_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF5_POS),
        CNF5_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF5_POS),
        CNF5_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF5_POS),

        CNF6_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF6_POS),
        CNF6_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF6_POS),
        CNF6_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF6_POS),
        CNF6_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF6_POS),
        CNF6_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF6_POS),
        CNF6_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF6_POS),
        CNF6_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF6_POS),

        CNF7_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF7_POS),
        CNF7_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF7_POS),
        CNF7_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF7_POS),
        CNF7_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF7_POS),
        CNF7_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF7_POS),
        CNF7_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF7_POS),
        CNF7_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF7_POS),

        MODE0_INPUT             = mskd_t(MASK, INPUT             , MODE0_POS),
        MODE0_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE0_POS),
        MODE0_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE0_POS),
        MODE0_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE0_POS),

        MODE1_INPUT             = mskd_t(MASK, INPUT             , MODE1_POS),
        MODE1_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE1_POS),
        MODE1_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE1_POS),
        MODE1_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE1_POS),

        MODE2_INPUT             = mskd_t(MASK, INPUT             , MODE2_POS),
        MODE2_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE2_POS),
        MODE2_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE2_POS),
        MODE2_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE2_POS),

        MODE3_INPUT             = mskd_t(MASK, INPUT             , MODE3_POS),
        MODE3_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE3_POS),
        MODE3_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE3_POS),
        MODE3_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE3_POS),

        MODE4_INPUT             = mskd_t(MASK, INPUT             , MODE4_POS),
        MODE4_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE4_POS),
        MODE4_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE4_POS),
        MODE4_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE4_POS),

        MODE5_INPUT             = mskd_t(MASK, INPUT             , MODE5_POS),
        MODE5_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE5_POS),
        MODE5_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE5_POS),
        MODE5_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE5_POS),

        MODE6_INPUT             = mskd_t(MASK, INPUT             , MODE6_POS),
        MODE6_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE6_POS),
        MODE6_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE6_POS),
        MODE6_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE6_POS),

        MODE7_INPUT             = mskd_t(MASK, INPUT             , MODE7_POS),
        MODE7_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE7_POS),
        MODE7_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE7_POS),
        MODE7_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE7_POS);
    };  // struct Crl
    using crl_t = Reg<uint32_t, Crl>;
          crl_t   crl;


    struct Crh {
        using              pos_t = Pos<uint32_t, Crh>;
        static constexpr   pos_t
                MODE_POS = pos_t( 0),
               MODE8_POS = pos_t( 0),
               MODE9_POS = pos_t( 4),
              MODE10_POS = pos_t( 8),
              MODE11_POS = pos_t(12),
              MODE12_POS = pos_t(16),
              MODE13_POS = pos_t(20),
              MODE14_POS = pos_t(24),
              MODE15_POS = pos_t(28),
                 CNF_POS = pos_t( 2),
                CNF8_POS = pos_t( 2),
                CNF9_POS = pos_t( 6),
               CNF10_POS = pos_t(10),
               CNF11_POS = pos_t(14),
               CNF12_POS = pos_t(18),
               CNF13_POS = pos_t(22),
               CNF14_POS = pos_t(26),
               CNF15_POS = pos_t(30);

        static const uint32_t       MASK               = 0b11,
                                    INPUT_ANALOG       = 0b00,
                                    INPUT_FLOATING     = 0b01,
                                    INPUT_PULL_UP_DOWN = 0b10,
                                    OUTPUT_PUSH_PULL   = 0b00,
                                    OUTPUT_OPEN_DRAIN  = 0b01,
                                    ALTFUNC_PUSH_PULL  = 0b10,
                                    ALTFUNC_OPEN_DRAIN = 0b11,
                                    INPUT              = 0b00,
                                    OUTPUT_10_MHZ      = 0b01,
                                    OUTPUT_2_MHZ       = 0b10,
                                    OUTPUT_50_MHZ      = 0b11;

        using              mskd_t = Mskd<uint32_t, Crh>;
        static constexpr   mskd_t
        CNF8_INPUT_ANALOG        = mskd_t(MASK, INPUT_ANALOG      , CNF8_POS),
        CNF8_INPUT_FLOATING      = mskd_t(MASK, INPUT_FLOATING    , CNF8_POS),
        CNF8_INPUT_PULL_UP_DOWN  = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF8_POS),
        CNF8_OUTPUT_PUSH_PULL    = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF8_POS),
        CNF8_OUTPUT_OPEN_DRAIN   = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF8_POS),
        CNF8_ALTFUNC_PUSH_PULL   = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF8_POS),
        CNF8_ALTFUNC_OPEN_DRAIN  = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF8_POS),

        CNF9_INPUT_ANALOG        = mskd_t(MASK, INPUT_ANALOG      , CNF9_POS),
        CNF9_INPUT_FLOATING      = mskd_t(MASK, INPUT_FLOATING    , CNF9_POS),
        CNF9_INPUT_PULL_UP_DOWN  = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF9_POS),
        CNF9_OUTPUT_PUSH_PULL    = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF9_POS),
        CNF9_OUTPUT_OPEN_DRAIN   = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF9_POS),
        CNF9_ALTFUNC_PUSH_PULL   = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF9_POS),
        CNF9_ALTFUNC_OPEN_DRAIN  = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF9_POS),

        CNF10_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF10_POS),
        CNF10_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF10_POS),
        CNF10_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF10_POS),
        CNF10_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF10_POS),
        CNF10_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF10_POS),
        CNF10_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF10_POS),
        CNF10_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF10_POS),

        CNF11_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF11_POS),
        CNF11_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF11_POS),
        CNF11_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF11_POS),
        CNF11_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF11_POS),
        CNF11_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF11_POS),
        CNF11_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF11_POS),
        CNF11_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF11_POS),

        CNF12_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF12_POS),
        CNF12_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF12_POS),
        CNF12_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF12_POS),
        CNF12_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF12_POS),
        CNF12_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF12_POS),
        CNF12_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF12_POS),
        CNF12_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF12_POS),

        CNF13_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF13_POS),
        CNF13_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF13_POS),
        CNF13_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF13_POS),
        CNF13_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF13_POS),
        CNF13_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF13_POS),
        CNF13_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF13_POS),
        CNF13_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF13_POS),

        CNF14_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF14_POS),
        CNF14_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF14_POS),
        CNF14_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF14_POS),
        CNF14_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF14_POS),
        CNF14_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF14_POS),
        CNF14_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF14_POS),
        CNF14_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF14_POS),

        CNF15_INPUT_ANALOG       = mskd_t(MASK, INPUT_ANALOG      , CNF15_POS),
        CNF15_INPUT_FLOATING     = mskd_t(MASK, INPUT_FLOATING    , CNF15_POS),
        CNF15_INPUT_PULL_UP_DOWN = mskd_t(MASK, INPUT_PULL_UP_DOWN, CNF15_POS),
        CNF15_OUTPUT_PUSH_PULL   = mskd_t(MASK, OUTPUT_PUSH_PULL  , CNF15_POS),
        CNF15_OUTPUT_OPEN_DRAIN  = mskd_t(MASK, OUTPUT_OPEN_DRAIN , CNF15_POS),
        CNF15_ALTFUNC_PUSH_PULL  = mskd_t(MASK, ALTFUNC_PUSH_PULL , CNF15_POS),
        CNF15_ALTFUNC_OPEN_DRAIN = mskd_t(MASK, ALTFUNC_OPEN_DRAIN, CNF15_POS),

        MODE8_INPUT              = mskd_t(MASK, INPUT             , MODE8_POS),
        MODE8_OUTPUT_10_MHZ      = mskd_t(MASK, OUTPUT_10_MHZ     , MODE8_POS),
        MODE8_OUTPUT_2_MHZ       = mskd_t(MASK, OUTPUT_2_MHZ      , MODE8_POS),
        MODE8_OUTPUT_50_MHZ      = mskd_t(MASK, OUTPUT_50_MHZ     , MODE8_POS),

        MODE9_INPUT              = mskd_t(MASK, INPUT             , MODE9_POS),
        MODE9_OUTPUT_10_MHZ      = mskd_t(MASK, OUTPUT_10_MHZ     , MODE9_POS),
        MODE9_OUTPUT_2_MHZ       = mskd_t(MASK, OUTPUT_2_MHZ      , MODE9_POS),
        MODE9_OUTPUT_50_MHZ      = mskd_t(MASK, OUTPUT_50_MHZ     , MODE9_POS),

        MODE10_INPUT             = mskd_t(MASK, INPUT             , MODE10_POS),
        MODE10_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE10_POS),
        MODE10_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE10_POS),
        MODE10_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE10_POS),

        MODE11_INPUT             = mskd_t(MASK, INPUT             , MODE11_POS),
        MODE11_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE11_POS),
        MODE11_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE11_POS),
        MODE11_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE11_POS),

        MODE12_INPUT             = mskd_t(MASK, INPUT             , MODE12_POS),
        MODE12_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE12_POS),
        MODE12_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE12_POS),
        MODE12_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE12_POS),

        MODE13_INPUT             = mskd_t(MASK, INPUT             , MODE13_POS),
        MODE13_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE13_POS),
        MODE13_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE13_POS),
        MODE13_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE13_POS),

        MODE14_INPUT             = mskd_t(MASK, INPUT             , MODE14_POS),
        MODE14_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE14_POS),
        MODE14_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE14_POS),
        MODE14_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE14_POS),

        MODE15_INPUT             = mskd_t(MASK, INPUT             , MODE15_POS),
        MODE15_OUTPUT_10_MHZ     = mskd_t(MASK, OUTPUT_10_MHZ     , MODE15_POS),
        MODE15_OUTPUT_2_MHZ      = mskd_t(MASK, OUTPUT_2_MHZ      , MODE15_POS),
        MODE15_OUTPUT_50_MHZ     = mskd_t(MASK, OUTPUT_50_MHZ     , MODE15_POS);
    };  // struct Crh
    using crh_t = Reg<uint32_t, Crh>;
          crh_t   crh;


    struct Idr {
        using              pos_t = Pos<uint32_t, Idr>;
        static constexpr   pos_t
                IDR0_POS = pos_t( 0),
                IDR1_POS = pos_t( 1),
                IDR2_POS = pos_t( 2),
                IDR3_POS = pos_t( 3),
                IDR4_POS = pos_t( 4),
                IDR5_POS = pos_t( 5),
                IDR6_POS = pos_t( 6),
                IDR7_POS = pos_t( 7),
                IDR8_POS = pos_t( 8),
                IDR9_POS = pos_t( 9),
               IDR10_POS = pos_t(10),
               IDR11_POS = pos_t(11),
               IDR12_POS = pos_t(12),
               IDR13_POS = pos_t(13),
               IDR14_POS = pos_t(14),
               IDR15_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Idr>;
        static constexpr   bits_t
        IDR0             = bits_t(1,         IDR0_POS),
        IDR1             = bits_t(1,         IDR1_POS),
        IDR2             = bits_t(1,         IDR2_POS),
        IDR3             = bits_t(1,         IDR3_POS),
        IDR4             = bits_t(1,         IDR4_POS),
        IDR5             = bits_t(1,         IDR5_POS),
        IDR6             = bits_t(1,         IDR6_POS),
        IDR7             = bits_t(1,         IDR7_POS),
        IDR8             = bits_t(1,         IDR8_POS),
        IDR9             = bits_t(1,         IDR9_POS),
        IDR10            = bits_t(1,        IDR10_POS),
        IDR11            = bits_t(1,        IDR11_POS),
        IDR12            = bits_t(1,        IDR12_POS),
        IDR13            = bits_t(1,        IDR13_POS),
        IDR14            = bits_t(1,        IDR14_POS),
        IDR15            = bits_t(1,        IDR15_POS);
    };  // struct Idr
    using idr_t = Reg<uint32_t, Idr>;
          idr_t   idr;


    struct Odr {
        using              pos_t = Pos<uint32_t, Odr>;
        static constexpr   pos_t
                ODR0_POS = pos_t( 0),
                ODR1_POS = pos_t( 1),
                ODR2_POS = pos_t( 2),
                ODR3_POS = pos_t( 3),
                ODR4_POS = pos_t( 4),
                ODR5_POS = pos_t( 5),
                ODR6_POS = pos_t( 6),
                ODR7_POS = pos_t( 7),
                ODR8_POS = pos_t( 8),
                ODR9_POS = pos_t( 9),
               ODR10_POS = pos_t(10),
               ODR11_POS = pos_t(11),
               ODR12_POS = pos_t(12),
               ODR13_POS = pos_t(13),
               ODR14_POS = pos_t(14),
               ODR15_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Odr>;
        static constexpr   bits_t
        ODR0             = bits_t(1,         ODR0_POS),
        ODR1             = bits_t(1,         ODR1_POS),
        ODR2             = bits_t(1,         ODR2_POS),
        ODR3             = bits_t(1,         ODR3_POS),
        ODR4             = bits_t(1,         ODR4_POS),
        ODR5             = bits_t(1,         ODR5_POS),
        ODR6             = bits_t(1,         ODR6_POS),
        ODR7             = bits_t(1,         ODR7_POS),
        ODR8             = bits_t(1,         ODR8_POS),
        ODR9             = bits_t(1,         ODR9_POS),
        ODR10            = bits_t(1,        ODR10_POS),
        ODR11            = bits_t(1,        ODR11_POS),
        ODR12            = bits_t(1,        ODR12_POS),
        ODR13            = bits_t(1,        ODR13_POS),
        ODR14            = bits_t(1,        ODR14_POS),
        ODR15            = bits_t(1,        ODR15_POS);
    };  // struct Odr
    using odr_t = Reg<uint32_t, Odr>;
          odr_t   odr;


    struct Bsrr {
        using              pos_t = Pos<uint32_t, Bsrr>;
        static constexpr   pos_t
                 BS0_POS = pos_t( 0),
                 BS1_POS = pos_t( 1),
                 BS2_POS = pos_t( 2),
                 BS3_POS = pos_t( 3),
                 BS4_POS = pos_t( 4),
                 BS5_POS = pos_t( 5),
                 BS6_POS = pos_t( 6),
                 BS7_POS = pos_t( 7),
                 BS8_POS = pos_t( 8),
                 BS9_POS = pos_t( 9),
                BS10_POS = pos_t(10),
                BS11_POS = pos_t(11),
                BS12_POS = pos_t(12),
                BS13_POS = pos_t(13),
                BS14_POS = pos_t(14),
                BS15_POS = pos_t(15),
                 BR0_POS = pos_t(16),
                 BR1_POS = pos_t(17),
                 BR2_POS = pos_t(18),
                 BR3_POS = pos_t(19),
                 BR4_POS = pos_t(20),
                 BR5_POS = pos_t(21),
                 BR6_POS = pos_t(22),
                 BR7_POS = pos_t(23),
                 BR8_POS = pos_t(24),
                 BR9_POS = pos_t(25),
                BR10_POS = pos_t(26),
                BR11_POS = pos_t(27),
                BR12_POS = pos_t(28),
                BR13_POS = pos_t(29),
                BR14_POS = pos_t(30),
                BR15_POS = pos_t(31);

        using              bits_t = Bits<uint32_t, Bsrr>;
        static constexpr   bits_t
        BS0              = bits_t(1,          BS0_POS),
        BS1              = bits_t(1,          BS1_POS),
        BS2              = bits_t(1,          BS2_POS),
        BS3              = bits_t(1,          BS3_POS),
        BS4              = bits_t(1,          BS4_POS),
        BS5              = bits_t(1,          BS5_POS),
        BS6              = bits_t(1,          BS6_POS),
        BS7              = bits_t(1,          BS7_POS),
        BS8              = bits_t(1,          BS8_POS),
        BS9              = bits_t(1,          BS9_POS),
        BS10             = bits_t(1,         BS10_POS),
        BS11             = bits_t(1,         BS11_POS),
        BS12             = bits_t(1,         BS12_POS),
        BS13             = bits_t(1,         BS13_POS),
        BS14             = bits_t(1,         BS14_POS),
        BS15             = bits_t(1,         BS15_POS),
        BR0              = bits_t(1,          BR0_POS),
        BR1              = bits_t(1,          BR1_POS),
        BR2              = bits_t(1,          BR2_POS),
        BR3              = bits_t(1,          BR3_POS),
        BR4              = bits_t(1,          BR4_POS),
        BR5              = bits_t(1,          BR5_POS),
        BR6              = bits_t(1,          BR6_POS),
        BR7              = bits_t(1,          BR7_POS),
        BR8              = bits_t(1,          BR8_POS),
        BR9              = bits_t(1,          BR9_POS),
        BR10             = bits_t(1,         BR10_POS),
        BR11             = bits_t(1,         BR11_POS),
        BR12             = bits_t(1,         BR12_POS),
        BR13             = bits_t(1,         BR13_POS),
        BR14             = bits_t(1,         BR14_POS),
        BR15             = bits_t(1,         BR15_POS);
    };  // struct Bsrr
    using bsrr_t = Reg<uint32_t, Bsrr>;
          bsrr_t   bsrr;


    struct Brr {
        using              pos_t = Pos<uint32_t, Brr>;
        static constexpr   pos_t
                 BR0_POS = pos_t( 0),
                 BR1_POS = pos_t( 1),
                 BR2_POS = pos_t( 2),
                 BR3_POS = pos_t( 3),
                 BR4_POS = pos_t( 4),
                 BR5_POS = pos_t( 5),
                 BR6_POS = pos_t( 6),
                 BR7_POS = pos_t( 7),
                 BR8_POS = pos_t( 8),
                 BR9_POS = pos_t( 9),
                BR10_POS = pos_t(10),
                BR11_POS = pos_t(11),
                BR12_POS = pos_t(12),
                BR13_POS = pos_t(13),
                BR14_POS = pos_t(14),
                BR15_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Brr>;
        static constexpr   bits_t
        BR0              = bits_t(1,          BR0_POS),
        BR1              = bits_t(1,          BR1_POS),
        BR2              = bits_t(1,          BR2_POS),
        BR3              = bits_t(1,          BR3_POS),
        BR4              = bits_t(1,          BR4_POS),
        BR5              = bits_t(1,          BR5_POS),
        BR6              = bits_t(1,          BR6_POS),
        BR7              = bits_t(1,          BR7_POS),
        BR8              = bits_t(1,          BR8_POS),
        BR9              = bits_t(1,          BR9_POS),
        BR10             = bits_t(1,         BR10_POS),
        BR11             = bits_t(1,         BR11_POS),
        BR12             = bits_t(1,         BR12_POS),
        BR13             = bits_t(1,         BR13_POS),
        BR14             = bits_t(1,         BR14_POS),
        BR15             = bits_t(1,         BR15_POS);
    };  // struct Brr
    using brr_t = Reg<uint32_t, Brr>;
          brr_t   brr;



    struct Lckr {
        using              pos_t = Pos<uint32_t, Lckr>;
        static constexpr   pos_t
                LCK0_POS = pos_t( 0),
                LCK1_POS = pos_t( 1),
                LCK2_POS = pos_t( 2),
                LCK3_POS = pos_t( 3),
                LCK4_POS = pos_t( 4),
                LCK5_POS = pos_t( 5),
                LCK6_POS = pos_t( 6),
                LCK7_POS = pos_t( 7),
                LCK8_POS = pos_t( 8),
                LCK9_POS = pos_t( 9),
               LCK10_POS = pos_t(10),
               LCK11_POS = pos_t(11),
               LCK12_POS = pos_t(12),
               LCK13_POS = pos_t(13),
               LCK14_POS = pos_t(14),
               LCK15_POS = pos_t(15),
                LCKK_POS = pos_t(16);

        using              bits_t = Bits<uint32_t, Lckr>;
        static constexpr   bits_t
        LCK0             = bits_t(1,         LCK0_POS),
        LCK1             = bits_t(1,         LCK1_POS),
        LCK2             = bits_t(1,         LCK2_POS),
        LCK3             = bits_t(1,         LCK3_POS),
        LCK4             = bits_t(1,         LCK4_POS),
        LCK5             = bits_t(1,         LCK5_POS),
        LCK6             = bits_t(1,         LCK6_POS),
        LCK7             = bits_t(1,         LCK7_POS),
        LCK8             = bits_t(1,         LCK8_POS),
        LCK9             = bits_t(1,         LCK9_POS),
        LCK10            = bits_t(1,        LCK10_POS),
        LCK11            = bits_t(1,        LCK11_POS),
        LCK12            = bits_t(1,        LCK12_POS),
        LCK13            = bits_t(1,        LCK13_POS),
        LCK14            = bits_t(1,        LCK14_POS),
        LCK15            = bits_t(1,        LCK15_POS),
        LCKK             = bits_t(1,         LCKK_POS);
    };  // struct Lckr
    using lckr_t = Reg<uint32_t, Lckr>;
          lckr_t   lckr;
};  // struct Gpio
static_assert(sizeof(Gpio) == 28, "sizeof(Gpio) != 28");


struct Afio {
    struct Evcr {
        using              pos_t = Pos<uint32_t, Evcr>;
        static constexpr   pos_t
                 PIN_POS = pos_t( 0),
                PORT_POS = pos_t( 4),
                EVOE_POS = pos_t( 7);

        using              bits_t = Bits<uint32_t, Evcr>;
        static constexpr   bits_t
        EVOE             = bits_t(1,         EVOE_POS);

        static const uint32_t
                PIN_MASK =       0xFU,
               PORT_MASK =       0x7U,
            PORT_PD_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Evcr>;
        using              shft_t = Shft<uint32_t, Evcr>;

        static constexpr   mskd_t
        PORT_PA          = mskd_t(PORT_MASK,     0b000,         PORT_POS),
        PORT_PB          = mskd_t(PORT_MASK,     0b001,         PORT_POS),
        PORT_PC          = mskd_t(PORT_MASK,     0b010,         PORT_POS),
        PORT_PD          = mskd_t(PORT_MASK,     0b011,         PORT_POS),
        PORT_PE          = mskd_t(PORT_MASK,     0b100,         PORT_POS);

        REGBITS_MSKD_RANGE("Afio::Evcr",
                           PIN,
                           pin,
                           PIN_MASK,
                           PIN_POS,
                           PIN_MASK);
    };  // struct Evcr
    using evcr_t = Reg<uint32_t, Evcr>;
          evcr_t   evcr;


    struct Mapr {
        using              pos_t = Pos<uint32_t, Mapr>;
        static constexpr   pos_t
          SPI1_REMAP_POS = pos_t( 0),
          I2C1_REMAP_POS = pos_t( 1),
        USART1_REMAP_POS = pos_t( 2),
        USART2_REMAP_POS = pos_t( 3),
        USART3_REMAP_POS = pos_t( 4),
          TIM1_REMAP_POS = pos_t( 6),
          TIM2_REMAP_POS = pos_t( 8),
          TIM3_REMAP_POS = pos_t(10),
          TIM4_REMAP_POS = pos_t(12),
           CAN_REMAP_POS = pos_t(13),
          PD01_REMAP_POS = pos_t(15),
             SWJ_CFG_POS = pos_t(24);

        using              bits_t = Bits<uint32_t, Mapr>;
        static constexpr   bits_t
        SPI1_REMAP       = bits_t(1,   SPI1_REMAP_POS),
        I2C1_REMAP       = bits_t(1,   I2C1_REMAP_POS),
        USART1_REMAP     = bits_t(1, USART1_REMAP_POS),
        USART2_REMAP     = bits_t(1, USART2_REMAP_POS),
        TIM4_REMAP       = bits_t(1,   TIM4_REMAP_POS);

        static const uint32_t
        USART3_REMAP_MASK =       0x3U,
         TIM1_REMAP_MASK =       0x3U,
         TIM2_REMAP_MASK =       0x3U,
         TIM3_REMAP_MASK =       0x3U,
          CAN_REMAP_MASK =       0x3U,
            SWJ_CFG_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Mapr>;
        static constexpr   mskd_t
        USART3_REMAP_NONE = mskd_t(USART3_REMAP_MASK,    0b00, USART3_REMAP_POS),
        USART3_REMAP_PB   = mskd_t(USART3_REMAP_MASK,    0b00, USART3_REMAP_POS),
        USART3_REMAP_PC   = mskd_t(USART3_REMAP_MASK,    0b01, USART3_REMAP_POS),
        USART3_REMAP_PD   = mskd_t(USART3_REMAP_MASK,    0b11, USART3_REMAP_POS),

        TIM1_REMAP_NONE  = mskd_t( TIM1_REMAP_MASK,  0b00,   TIM1_REMAP_POS),
        TIM1_REMAP_PA_B  = mskd_t( TIM1_REMAP_MASK,  0b01,   TIM1_REMAP_POS),
        TIM1_REMAP_PE    = mskd_t( TIM1_REMAP_MASK,  0b11,   TIM1_REMAP_POS),

        TIM2_REMAP_NONE  = mskd_t( TIM2_REMAP_MASK,  0b00,   TIM2_REMAP_POS),
        TIM2_REMAP_15_3  = mskd_t( TIM2_REMAP_MASK,  0b01,   TIM2_REMAP_POS),
        TIM2_REMAP_0_11  = mskd_t( TIM2_REMAP_MASK,  0b10,   TIM2_REMAP_POS),
        TIM2_REMAP_15_11 = mskd_t( TIM2_REMAP_MASK,  0b11,   TIM2_REMAP_POS),

        TIM3_REMAP_NONE  = mskd_t( TIM3_REMAP_MASK,  0b00,   TIM3_REMAP_POS),
        TIM3_REMAP_PA    = mskd_t( TIM3_REMAP_MASK,  0b00,   TIM3_REMAP_POS),
        TIM3_REMAP_PB    = mskd_t( TIM3_REMAP_MASK,  0b10,   TIM3_REMAP_POS),
        TIM3_REMAP_PC    = mskd_t( TIM3_REMAP_MASK,  0b11,   TIM3_REMAP_POS),


        CAN_REMAP_PA     = mskd_t(  CAN_REMAP_MASK,  0b00,    CAN_REMAP_POS),
        CAN_REMAP_PB     = mskd_t(  CAN_REMAP_MASK,  0b10,    CAN_REMAP_POS),
        CAN_REMAP_PD     = mskd_t(  CAN_REMAP_MASK,  0b11,    CAN_REMAP_POS),

        SWJ_CFG_FULL_SWJ  = mskd_t(   SWJ_CFG_MASK,  0b000,     SWJ_CFG_POS),
        SWJ_CFG_NO_NJTRST = mskd_t(   SWJ_CFG_MASK,  0b001,     SWJ_CFG_POS),
        SWJ_CFG_SW_DP     = mskd_t(   SWJ_CFG_MASK,  0b010,     SWJ_CFG_POS),
        SWJ_CFG_DISABLED  = mskd_t(   SWJ_CFG_MASK,  0b100,     SWJ_CFG_POS);
    };  // struct Mapr
    using mapr_t = Reg<uint32_t, Mapr>;
          mapr_t   mapr;


    static const uint32_t   EXTI_GPIOA  = 0x0,
                            EXTI_GPIOB  = 0x1,
                            EXTI_GPIOC  = 0x2,
                            EXTI_GPIOD  = 0x3,
                            EXTI_GPIOE  = 0x4,
                            EXTI_GPIOF  = 0x5,
                            EXTI_GPIOG  = 0x6,
                            EXTI_GPIOH  = 0x7,
                            EXTI_GPIOI  = 0x8,
                            EXTI_GPIOJ  = 0x9,
                            EXTI_GPIOK  = 0xa;

    struct Exticr1 {
        using            pos_t = Pos<uint32_t, Exticr1>;
        static constexpr pos_t
           EXTI0_POS = pos_t( 0),
           EXTI1_POS = pos_t( 4),
           EXTI2_POS = pos_t( 8),
           EXTI3_POS = pos_t(12);

        static const uint32_t
              EXTI0_MASK =       0xFU,
              EXTI1_MASK =       0xFU,
              EXTI2_MASK =       0xFU,
              EXTI3_MASK =       0xFU;

        using            mskd_t = Mskd<uint32_t, Exticr1>;
        using            shft_t = Shft<uint32_t, Exticr1>;

        REGBITS_MSKD_RANGE("Afio::Exti0",
                           EXTI0,
                           exti0,
                           EXTI0_MASK,
                           EXTI0_POS,
                           EXTI0_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti1",
                           EXTI1,
                           exti1,
                           EXTI1_MASK,
                           EXTI1_POS,
                           EXTI1_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti2",
                           EXTI2,
                           exti2,
                           EXTI2_MASK,
                           EXTI2_POS,
                           EXTI2_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti3",
                           EXTI3,
                           exti3,
                           EXTI3_MASK,
                           EXTI3_POS,
                           EXTI3_MASK);
    };  // struct Exticr1
    using exticr1_t = Reg<uint32_t, Exticr1>;
          exticr1_t   exticr1;


    struct Exticr2 {
        using            pos_t = Pos<uint32_t, Exticr2>;
        static constexpr pos_t
           EXTI4_POS = pos_t( 0),
           EXTI5_POS = pos_t( 4),
           EXTI6_POS = pos_t( 8),
           EXTI7_POS = pos_t(12);

        static const uint32_t
              EXTI4_MASK =       0xFU,
              EXTI5_MASK =       0xFU,
              EXTI6_MASK =       0xFU,
              EXTI7_MASK =       0xFU;

        using            mskd_t = Mskd<uint32_t, Exticr2>;
        using            shft_t = Shft<uint32_t, Exticr2>;

        REGBITS_MSKD_RANGE("Afio::Exti4",
                           EXTI4,
                           exti4,
                           EXTI4_MASK,
                           EXTI4_POS,
                           EXTI4_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti5",
                           EXTI5,
                           exti5,
                           EXTI5_MASK,
                           EXTI5_POS,
                           EXTI5_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti6",
                           EXTI6,
                           exti6,
                           EXTI6_MASK,
                           EXTI6_POS,
                           EXTI6_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti7",
                           EXTI7,
                           exti7,
                           EXTI7_MASK,
                           EXTI7_POS,
                           EXTI7_MASK);
    };  // struct Exticr2
    using exticr2_t = Reg<uint32_t, Exticr2>;
          exticr2_t   exticr2;


    struct Exticr3 {
        using            pos_t = Pos<uint32_t, Exticr3>;
        static constexpr pos_t
            EXTI8_POS = pos_t( 0),
            EXTI9_POS = pos_t( 4),
           EXTI10_POS = pos_t( 8),
           EXTI11_POS = pos_t(12);

        static const uint32_t
               EXTI8_MASK =      0xFU,
               EXTI9_MASK =      0xFU,
              EXTI10_MASK =      0xFU,
              EXTI11_MASK =      0xFU;

        using            mskd_t = Mskd<uint32_t, Exticr3>;
        using            shft_t = Shft<uint32_t, Exticr3>;

        REGBITS_MSKD_RANGE("Afio::Exti8",
                           EXTI8,
                           exti8,
                           EXTI8_MASK,
                           EXTI8_POS,
                           EXTI8_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti9",
                           EXTI9,
                           exti9,
                           EXTI9_MASK,
                           EXTI9_POS,
                           EXTI9_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti10",
                           EXTI10,
                           exti10,
                           EXTI10_MASK,
                           EXTI10_POS,
                           EXTI10_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti11",
                           EXTI11,
                           exti11,
                           EXTI11_MASK,
                           EXTI11_POS,
                           EXTI11_MASK);
    };  // struct Exticr3
    using exticr3_t = Reg<uint32_t, Exticr3>;
          exticr3_t   exticr3;


    struct Exticr4 {
        using            pos_t = Pos<uint32_t, Exticr4>;
        static constexpr pos_t
           EXTI12_POS = pos_t( 0),
           EXTI13_POS = pos_t( 4),
           EXTI14_POS = pos_t( 8),
           EXTI15_POS = pos_t(12);

        static const uint32_t
              EXTI12_MASK =      0xFU,
              EXTI13_MASK =      0xFU,
              EXTI14_MASK =      0xFU,
              EXTI15_MASK =      0xFU;

        using            mskd_t = Mskd<uint32_t, Exticr4>;
        using            shft_t = Shft<uint32_t, Exticr4>;

        REGBITS_MSKD_RANGE("Afio::Exti12",
                           EXTI12,
                           exti12,
                           EXTI12_MASK,
                           EXTI12_POS,
                           EXTI12_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti13",
                           EXTI13,
                           exti13,
                           EXTI13_MASK,
                           EXTI13_POS,
                           EXTI13_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti14",
                           EXTI14,
                           exti14,
                           EXTI14_MASK,
                           EXTI14_POS,
                           EXTI14_MASK);
        REGBITS_MSKD_RANGE("Afio::Exti15",
                           EXTI15,
                           exti15,
                           EXTI15_MASK,
                           EXTI15_POS,
                           EXTI15_MASK);
    };  // struct Exticr4
    using exticr4_t = Reg<uint32_t, Exticr4>;
          exticr4_t   exticr4;

    private:
    uint32_t    _reserved0,
                _undefined_mapr2;
};  // struct Afio
static_assert(sizeof(Afio) == 32, "sizeof(Afio) != 32");


struct Exti {
    struct Imr {
        using              pos_t = Pos<uint32_t, Imr>;
        static constexpr   pos_t
                 MR0_POS = pos_t( 0),
                 MR1_POS = pos_t( 1),
                 MR2_POS = pos_t( 2),
                 MR3_POS = pos_t( 3),
                 MR4_POS = pos_t( 4),
                 MR5_POS = pos_t( 5),
                 MR6_POS = pos_t( 6),
                 MR7_POS = pos_t( 7),
                 MR8_POS = pos_t( 8),
                 MR9_POS = pos_t( 9),
                MR10_POS = pos_t(10),
                MR11_POS = pos_t(11),
                MR12_POS = pos_t(12),
                MR13_POS = pos_t(13),
                MR14_POS = pos_t(14),
                MR15_POS = pos_t(15),
                MR16_POS = pos_t(16),
                MR17_POS = pos_t(17),
                MR18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Imr>;
        static constexpr   bits_t
        MR0              = bits_t(1,          MR0_POS),
        MR1              = bits_t(1,          MR1_POS),
        MR2              = bits_t(1,          MR2_POS),
        MR3              = bits_t(1,          MR3_POS),
        MR4              = bits_t(1,          MR4_POS),
        MR5              = bits_t(1,          MR5_POS),
        MR6              = bits_t(1,          MR6_POS),
        MR7              = bits_t(1,          MR7_POS),
        MR8              = bits_t(1,          MR8_POS),
        MR9              = bits_t(1,          MR9_POS),
        MR10             = bits_t(1,         MR10_POS),
        MR11             = bits_t(1,         MR11_POS),
        MR12             = bits_t(1,         MR12_POS),
        MR13             = bits_t(1,         MR13_POS),
        MR14             = bits_t(1,         MR14_POS),
        MR15             = bits_t(1,         MR15_POS),
        MR16             = bits_t(1,         MR16_POS),
        MR17             = bits_t(1,         MR17_POS),
        MR18             = bits_t(1,         MR18_POS);
    };  // struct Imr
    using imr_t = Reg<uint32_t, Imr>;
          imr_t   imr;


    struct Emr {
        using              pos_t = Pos<uint32_t, Emr>;
        static constexpr   pos_t
                 MR0_POS = pos_t( 0),
                 MR1_POS = pos_t( 1),
                 MR2_POS = pos_t( 2),
                 MR3_POS = pos_t( 3),
                 MR4_POS = pos_t( 4),
                 MR5_POS = pos_t( 5),
                 MR6_POS = pos_t( 6),
                 MR7_POS = pos_t( 7),
                 MR8_POS = pos_t( 8),
                 MR9_POS = pos_t( 9),
                MR10_POS = pos_t(10),
                MR11_POS = pos_t(11),
                MR12_POS = pos_t(12),
                MR13_POS = pos_t(13),
                MR14_POS = pos_t(14),
                MR15_POS = pos_t(15),
                MR16_POS = pos_t(16),
                MR17_POS = pos_t(17),
                MR18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Emr>;
        static constexpr   bits_t
        MR0              = bits_t(1,          MR0_POS),
        MR1              = bits_t(1,          MR1_POS),
        MR2              = bits_t(1,          MR2_POS),
        MR3              = bits_t(1,          MR3_POS),
        MR4              = bits_t(1,          MR4_POS),
        MR5              = bits_t(1,          MR5_POS),
        MR6              = bits_t(1,          MR6_POS),
        MR7              = bits_t(1,          MR7_POS),
        MR8              = bits_t(1,          MR8_POS),
        MR9              = bits_t(1,          MR9_POS),
        MR10             = bits_t(1,         MR10_POS),
        MR11             = bits_t(1,         MR11_POS),
        MR12             = bits_t(1,         MR12_POS),
        MR13             = bits_t(1,         MR13_POS),
        MR14             = bits_t(1,         MR14_POS),
        MR15             = bits_t(1,         MR15_POS),
        MR16             = bits_t(1,         MR16_POS),
        MR17             = bits_t(1,         MR17_POS),
        MR18             = bits_t(1,         MR18_POS);
    };  // struct Emr
    using emr_t = Reg<uint32_t, Emr>;
          emr_t   emr;


    struct Rtsr {
        using              pos_t = Pos<uint32_t, Rtsr>;
        static constexpr   pos_t
                 TR0_POS = pos_t( 0),
                 TR1_POS = pos_t( 1),
                 TR2_POS = pos_t( 2),
                 TR3_POS = pos_t( 3),
                 TR4_POS = pos_t( 4),
                 TR5_POS = pos_t( 5),
                 TR6_POS = pos_t( 6),
                 TR7_POS = pos_t( 7),
                 TR8_POS = pos_t( 8),
                 TR9_POS = pos_t( 9),
                TR10_POS = pos_t(10),
                TR11_POS = pos_t(11),
                TR12_POS = pos_t(12),
                TR13_POS = pos_t(13),
                TR14_POS = pos_t(14),
                TR15_POS = pos_t(15),
                TR16_POS = pos_t(16),
                TR17_POS = pos_t(17),
                TR18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Rtsr>;
        static constexpr   bits_t
        TR0              = bits_t(1,          TR0_POS),
        TR1              = bits_t(1,          TR1_POS),
        TR2              = bits_t(1,          TR2_POS),
        TR3              = bits_t(1,          TR3_POS),
        TR4              = bits_t(1,          TR4_POS),
        TR5              = bits_t(1,          TR5_POS),
        TR6              = bits_t(1,          TR6_POS),
        TR7              = bits_t(1,          TR7_POS),
        TR8              = bits_t(1,          TR8_POS),
        TR9              = bits_t(1,          TR9_POS),
        TR10             = bits_t(1,         TR10_POS),
        TR11             = bits_t(1,         TR11_POS),
        TR12             = bits_t(1,         TR12_POS),
        TR13             = bits_t(1,         TR13_POS),
        TR14             = bits_t(1,         TR14_POS),
        TR15             = bits_t(1,         TR15_POS),
        TR16             = bits_t(1,         TR16_POS),
        TR17             = bits_t(1,         TR17_POS),
        TR18             = bits_t(1,         TR18_POS);
    };  // struct Rtsr
    using rtsr_t = Reg<uint32_t, Rtsr>;
          rtsr_t   rtsr;


    struct Ftsr {
        using              pos_t = Pos<uint32_t, Ftsr>;
        static constexpr   pos_t
                 TR0_POS = pos_t( 0),
                 TR1_POS = pos_t( 1),
                 TR2_POS = pos_t( 2),
                 TR3_POS = pos_t( 3),
                 TR4_POS = pos_t( 4),
                 TR5_POS = pos_t( 5),
                 TR6_POS = pos_t( 6),
                 TR7_POS = pos_t( 7),
                 TR8_POS = pos_t( 8),
                 TR9_POS = pos_t( 9),
                TR10_POS = pos_t(10),
                TR11_POS = pos_t(11),
                TR12_POS = pos_t(12),
                TR13_POS = pos_t(13),
                TR14_POS = pos_t(14),
                TR15_POS = pos_t(15),
                TR16_POS = pos_t(16),
                TR17_POS = pos_t(17),
                TR18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Ftsr>;
        static constexpr   bits_t
        TR0              = bits_t(1,          TR0_POS),
        TR1              = bits_t(1,          TR1_POS),
        TR2              = bits_t(1,          TR2_POS),
        TR3              = bits_t(1,          TR3_POS),
        TR4              = bits_t(1,          TR4_POS),
        TR5              = bits_t(1,          TR5_POS),
        TR6              = bits_t(1,          TR6_POS),
        TR7              = bits_t(1,          TR7_POS),
        TR8              = bits_t(1,          TR8_POS),
        TR9              = bits_t(1,          TR9_POS),
        TR10             = bits_t(1,         TR10_POS),
        TR11             = bits_t(1,         TR11_POS),
        TR12             = bits_t(1,         TR12_POS),
        TR13             = bits_t(1,         TR13_POS),
        TR14             = bits_t(1,         TR14_POS),
        TR15             = bits_t(1,         TR15_POS),
        TR16             = bits_t(1,         TR16_POS),
        TR17             = bits_t(1,         TR17_POS),
        TR18             = bits_t(1,         TR18_POS);
    };  // struct Ftsr
    using ftsr_t = Reg<uint32_t, Ftsr>;
          ftsr_t   ftsr;


    struct Swier {
        using              pos_t = Pos<uint32_t, Swier>;
        static constexpr   pos_t
              SWIER0_POS = pos_t( 0),
              SWIER1_POS = pos_t( 1),
              SWIER2_POS = pos_t( 2),
              SWIER3_POS = pos_t( 3),
              SWIER4_POS = pos_t( 4),
              SWIER5_POS = pos_t( 5),
              SWIER6_POS = pos_t( 6),
              SWIER7_POS = pos_t( 7),
              SWIER8_POS = pos_t( 8),
              SWIER9_POS = pos_t( 9),
             SWIER10_POS = pos_t(10),
             SWIER11_POS = pos_t(11),
             SWIER12_POS = pos_t(12),
             SWIER13_POS = pos_t(13),
             SWIER14_POS = pos_t(14),
             SWIER15_POS = pos_t(15),
             SWIER16_POS = pos_t(16),
             SWIER17_POS = pos_t(17),
             SWIER18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Swier>;
        static constexpr   bits_t
        SWIER0           = bits_t(1,       SWIER0_POS),
        SWIER1           = bits_t(1,       SWIER1_POS),
        SWIER2           = bits_t(1,       SWIER2_POS),
        SWIER3           = bits_t(1,       SWIER3_POS),
        SWIER4           = bits_t(1,       SWIER4_POS),
        SWIER5           = bits_t(1,       SWIER5_POS),
        SWIER6           = bits_t(1,       SWIER6_POS),
        SWIER7           = bits_t(1,       SWIER7_POS),
        SWIER8           = bits_t(1,       SWIER8_POS),
        SWIER9           = bits_t(1,       SWIER9_POS),
        SWIER10          = bits_t(1,      SWIER10_POS),
        SWIER11          = bits_t(1,      SWIER11_POS),
        SWIER12          = bits_t(1,      SWIER12_POS),
        SWIER13          = bits_t(1,      SWIER13_POS),
        SWIER14          = bits_t(1,      SWIER14_POS),
        SWIER15          = bits_t(1,      SWIER15_POS),
        SWIER16          = bits_t(1,      SWIER16_POS),
        SWIER17          = bits_t(1,      SWIER17_POS),
        SWIER18          = bits_t(1,      SWIER18_POS);
    };  // struct Swier
    using swier_t = Reg<uint32_t, Swier>;
          swier_t   swier;


    struct Pr {
        using              pos_t = Pos<uint32_t, Pr>;
        static constexpr   pos_t
                 PR0_POS = pos_t( 0),
                 PR1_POS = pos_t( 1),
                 PR2_POS = pos_t( 2),
                 PR3_POS = pos_t( 3),
                 PR4_POS = pos_t( 4),
                 PR5_POS = pos_t( 5),
                 PR6_POS = pos_t( 6),
                 PR7_POS = pos_t( 7),
                 PR8_POS = pos_t( 8),
                 PR9_POS = pos_t( 9),
                PR10_POS = pos_t(10),
                PR11_POS = pos_t(11),
                PR12_POS = pos_t(12),
                PR13_POS = pos_t(13),
                PR14_POS = pos_t(14),
                PR15_POS = pos_t(15),
                PR16_POS = pos_t(16),
                PR17_POS = pos_t(17),
                PR18_POS = pos_t(18);

        using              bits_t = Bits<uint32_t, Pr>;
        static constexpr   bits_t
        PR0              = bits_t(1,          PR0_POS),
        PR1              = bits_t(1,          PR1_POS),
        PR2              = bits_t(1,          PR2_POS),
        PR3              = bits_t(1,          PR3_POS),
        PR4              = bits_t(1,          PR4_POS),
        PR5              = bits_t(1,          PR5_POS),
        PR6              = bits_t(1,          PR6_POS),
        PR7              = bits_t(1,          PR7_POS),
        PR8              = bits_t(1,          PR8_POS),
        PR9              = bits_t(1,          PR9_POS),
        PR10             = bits_t(1,         PR10_POS),
        PR11             = bits_t(1,         PR11_POS),
        PR12             = bits_t(1,         PR12_POS),
        PR13             = bits_t(1,         PR13_POS),
        PR14             = bits_t(1,         PR14_POS),
        PR15             = bits_t(1,         PR15_POS),
        PR16             = bits_t(1,         PR16_POS),
        PR17             = bits_t(1,         PR17_POS),
        PR18             = bits_t(1,         PR18_POS);
    };  // struct Pr
    using pr_t = Reg<uint32_t, Pr>;
          pr_t   pr;
};  // struct Exti
static_assert(sizeof(Exti) == 24, "sizeof(Exti) != 24");


// timers
//


// timer types
//

// check to include private stm32f103xb_tim.hxx from here
#define STM32F103XB_TIM_HXX_INCLUDE

struct Tim
{
#include "stm32f103xb_tim.hxx"
};
static_assert(sizeof(Tim) == 84, "sizeof(Tim) != 84");


// timers classes
//

struct AdvTim_1
{
#define STM32F103XB_ADV_TIM_1
#include "stm32f103xb_tim.hxx"
#undef STM32F103XB_ADV_TIM_1
};  // struct AdvTim_1
static_assert(sizeof(AdvTim_1) == 84, "sizeof(AdvTim_1) != 84");

struct GenTim_2_3_4
{
#define STM32F103XB_GEN_TIM_2_3_4
#include "stm32f103xb_tim.hxx"
#undef STM32F103XB_GEN_TIM_2_3_4
};  // struct GenTim_2_3_4
static_assert(sizeof(GenTim_2_3_4) == 84, "sizeof(GenTim_2_3_4) != 84");

#undef STM32F103XB_TIM_HXX_INCLUDE



struct Spi {
    struct Cr1 {
        using              pos_t = Pos<uint32_t, Cr1>;
        static constexpr   pos_t
                CPHA_POS = pos_t( 0),
                CPOL_POS = pos_t( 1),
                MSTR_POS = pos_t( 2),
                  BR_POS = pos_t( 3),
                 SPE_POS = pos_t( 6),
            LSBFIRST_POS = pos_t( 7),
                 SSI_POS = pos_t( 8),
                 SSM_POS = pos_t( 9),
              RXONLY_POS = pos_t(10),
                 DFF_POS = pos_t(11),
             CRCNEXT_POS = pos_t(12),
               CRCEN_POS = pos_t(13),
              BIDIOE_POS = pos_t(14),
            BIDIMODE_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Cr1>;
        static constexpr   bits_t
        CPHA             = bits_t(1,         CPHA_POS),
        CPOL             = bits_t(1,         CPOL_POS),
        MSTR             = bits_t(1,         MSTR_POS),
        SPE              = bits_t(1,          SPE_POS),
        LSBFIRST         = bits_t(1,     LSBFIRST_POS),
        SSI              = bits_t(1,          SSI_POS),
        SSM              = bits_t(1,          SSM_POS),
        RXONLY           = bits_t(1,       RXONLY_POS),
        DFF              = bits_t(1,          DFF_POS),
        CRCNEXT          = bits_t(1,      CRCNEXT_POS),
        CRCEN            = bits_t(1,        CRCEN_POS),
        BIDIOE           = bits_t(1,       BIDIOE_POS),
        BIDIMODE         = bits_t(1,     BIDIMODE_POS);

        static const uint32_t
                 BR_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Cr1>;
        static constexpr   mskd_t
        BR_DIV_2         = mskd_t(         BR_MASK,  0b000,          BR_POS),
        BR_DIV_4         = mskd_t(         BR_MASK,  0b001,          BR_POS),
        BR_DIV_8         = mskd_t(         BR_MASK,  0b010,          BR_POS),
        BR_DIV_16        = mskd_t(         BR_MASK,  0b011,          BR_POS),
        BR_DIV_32        = mskd_t(         BR_MASK,  0b100,          BR_POS),
        BR_DIV_64        = mskd_t(         BR_MASK,  0b101,          BR_POS),
        BR_DIV_128       = mskd_t(         BR_MASK,  0b110,          BR_POS),
        BR_DIV_256       = mskd_t(         BR_MASK,  0b111,          BR_POS);
    };  // struct Cr1
    using cr1_t = Reg<uint32_t, Cr1>;
          cr1_t   cr1;


    struct Cr2 {
        using              pos_t = Pos<uint32_t, Cr2>;
        static constexpr   pos_t
             RXDMAEN_POS = pos_t( 0),
             TXDMAEN_POS = pos_t( 1),
                SSOE_POS = pos_t( 2),
               ERRIE_POS = pos_t( 5),
              RXNEIE_POS = pos_t( 6),
               TXEIE_POS = pos_t( 7);

        using              bits_t = Bits<uint32_t, Cr2>;
        static constexpr   bits_t
        RXDMAEN          = bits_t(1,      RXDMAEN_POS),
        TXDMAEN          = bits_t(1,      TXDMAEN_POS),
        SSOE             = bits_t(1,         SSOE_POS),
        ERRIE            = bits_t(1,        ERRIE_POS),
        RXNEIE           = bits_t(1,       RXNEIE_POS),
        TXEIE            = bits_t(1,        TXEIE_POS);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;


    struct Sr {
        using              pos_t = Pos<uint32_t, Sr>;
        static constexpr   pos_t
                RXNE_POS = pos_t( 0),
                 TXE_POS = pos_t( 1),
              CHSIDE_POS = pos_t( 2),
                 UDR_POS = pos_t( 3),
              CRCERR_POS = pos_t( 4),
                MODF_POS = pos_t( 5),
                 OVR_POS = pos_t( 6),
                 BSY_POS = pos_t( 7);

        using              bits_t = Bits<uint32_t, Sr>;
        static constexpr   bits_t
        RXNE             = bits_t(1,         RXNE_POS),
        TXE              = bits_t(1,          TXE_POS),
        CHSIDE           = bits_t(1,       CHSIDE_POS),
        UDR              = bits_t(1,          UDR_POS),
        CRCERR           = bits_t(1,       CRCERR_POS),
        MODF             = bits_t(1,         MODF_POS),
        OVR              = bits_t(1,          OVR_POS),
        BSY              = bits_t(1,          BSY_POS);
    };  // struct Sr
    using sr_t = Reg<uint32_t, Sr>;
          sr_t   sr;


                uint16_t    dr;
    private:    uint16_t    _dr_high_bits;   public:


                uint16_t    crcpr;
    private:    uint16_t    _crcpr_high_bits;    public:


                uint16_t    rxcrcr;
    private:    uint16_t    _rxcrcr_high_bits;   public:


                uint16_t    txcrcr;
    private:    uint16_t    _txcrcr_high_bits;   public:


    struct I2scfgr {
        using              pos_t = Pos<uint32_t, I2scfgr>;
        static constexpr   pos_t
              I2SMOD_POS = pos_t(11);

        using              bits_t = Bits<uint32_t, I2scfgr>;
        static constexpr   bits_t
        I2SMOD           = bits_t(1,       I2SMOD_POS);
    };  // struct I2scfgr
    using i2scfgr_t = Reg<uint32_t, I2scfgr>;
          i2scfgr_t   i2scfgr;
};  // struct Spi
static_assert(sizeof(Spi) == 32, "sizeof(Spi) != 32");


struct ElecSig {
                uint16_t    flash_size;
    private:    uint16_t    _flash_size_high_bits;   public:

    private:    uint32_t    _unused;    public:

                uint16_t    u_id_15_0,
                            u_id_31_16;
                uint32_t    u_id_62_32,
                            u_id_95_64;
};  // struct ElecSig
static_assert(sizeof(ElecSig) == 20, "sizeof(ElecSig) != 20");


struct DbgMcu {
    struct Idcode {
        using              pos_t = Pos<uint32_t, Idcode>;
        static constexpr   pos_t
              DEV_ID_POS = pos_t( 0),
              REV_ID_POS = pos_t(16);

        static const uint32_t
             DEV_ID_MASK =     0xFFFU,
             REV_ID_MASK =    0xFFFFU;

        using   mskd_t = Mskd<uint32_t, Idcode>;
        using   shft_t = Shft<uint32_t, Idcode>;

        REGBITS_MSKD_RANGE("DbgMcu::Idcode",
                           DEV_ID,
                           dev_id,
                           DEV_ID_MASK,
                           DEV_ID_POS,
                           DEV_ID_MASK);
        REGBITS_MSKD_RANGE("DbgMcu::Idcode",
                           REV_ID,
                           rev_id,
                           REV_ID_MASK,
                           REV_ID_POS,
                           REV_ID_MASK);
    };  // struct Idcode
    using idcode_t = Reg<uint32_t, Idcode>;
          idcode_t   idcode;
};  // struct DbgMcu
static_assert(sizeof(DbgMcu) == 4, "sizeof(DbgMcu) != 4");


static const uint32_t   PERIPH_BASE         = 0x40000000U;

static const uint32_t   APB1PERIPH_BASE     = PERIPH_BASE              ,
                        APB2PERIPH_BASE     = PERIPH_BASE + 0x00010000U,
                        AHBPERIPH_BASE      = PERIPH_BASE + 0x00020000U;

// APB1 peripherals
static const uint32_t   TIM2_BASE           = APB1PERIPH_BASE + 0x00000000U,
                        TIM3_BASE           = APB1PERIPH_BASE + 0x00000400U,
                        TIM4_BASE           = APB1PERIPH_BASE + 0x00000800U,
                        RTC_BASE            = APB1PERIPH_BASE + 0x00002800U,
                        WWDG_BASE           = APB1PERIPH_BASE + 0x00002C00U,
                        IWDG_BASE           = APB1PERIPH_BASE + 0x00003000U,
                        SPI2_BASE           = APB1PERIPH_BASE + 0x00003800U,
                        USART2_BASE         = APB1PERIPH_BASE + 0x00004400U,
                        USART3_BASE         = APB1PERIPH_BASE + 0x00004800U,
                        I2C1_BASE           = APB1PERIPH_BASE + 0x00005400U,
                        I2C2_BASE           = APB1PERIPH_BASE + 0x00005800U,
                        CAN1_BASE           = APB1PERIPH_BASE + 0x00006400U,
                        BKP_BASE            = APB1PERIPH_BASE + 0x00006C00U,
                        PWR_BASE            = APB1PERIPH_BASE + 0x00007000U;

// APB2 peripherals
static const uint32_t   AFIO_BASE           = APB2PERIPH_BASE + 0x00000000U,
                        EXTI_BASE           = APB2PERIPH_BASE + 0x00000400U,
                        GPIOA_BASE          = APB2PERIPH_BASE + 0x00000800U,
                        GPIOB_BASE          = APB2PERIPH_BASE + 0x00000C00U,
                        GPIOC_BASE          = APB2PERIPH_BASE + 0x00001000U,
                        GPIOD_BASE          = APB2PERIPH_BASE + 0x00001400U,
                        GPIOE_BASE          = APB2PERIPH_BASE + 0x00001800U,
                        ADC1_BASE           = APB2PERIPH_BASE + 0x00002400U,
                        ADC2_BASE           = APB2PERIPH_BASE + 0x00002800U,
                        TIM1_BASE           = APB2PERIPH_BASE + 0x00002C00U,
                        SPI1_BASE           = APB2PERIPH_BASE + 0x00003000U,
                        USART1_BASE         = APB2PERIPH_BASE + 0x00003800U;

// AHB peripherals
static const uint32_t   DMA1_BASE           = AHBPERIPH_BASE + 0x00000000U,
                        DMA1_Channel1_BASE  = AHBPERIPH_BASE + 0x00000008U,
                        DMA1_Channel2_BASE  = AHBPERIPH_BASE + 0x0000001CU,
                        DMA1_Channel3_BASE  = AHBPERIPH_BASE + 0x00000030U,
                        DMA1_Channel4_BASE  = AHBPERIPH_BASE + 0x00000044U,
                        DMA1_Channel5_BASE  = AHBPERIPH_BASE + 0x00000058U,
                        DMA1_Channel6_BASE  = AHBPERIPH_BASE + 0x0000006CU,
                        DMA1_Channel7_BASE  = AHBPERIPH_BASE + 0x00000080U,
                        RCC_BASE            = AHBPERIPH_BASE + 0x00001000U,
                        CRC_BASE            = AHBPERIPH_BASE + 0x00003000U;

static const uint32_t   ELEC_SIG_BASE       = 0x1FFFF7E0;

static const uint32_t   DBGMCU_BASE         = 0xE0042000U;


#define STM32F103XB_PERIPH(TYPE, PERIPH, BASE)      \
    static volatile TYPE* const                     \
    PERIPH = reinterpret_cast<volatile TYPE*>(BASE)

STM32F103XB_PERIPH( Rcc,                rcc,            RCC_BASE        );

STM32F103XB_PERIPH( Gpio,               gpioa,          GPIOA_BASE      );
STM32F103XB_PERIPH( Gpio,               gpiob,          GPIOB_BASE      );
STM32F103XB_PERIPH( Gpio,               gpioc,          GPIOC_BASE      );
STM32F103XB_PERIPH( Gpio,               gpiod,          GPIOD_BASE      );
STM32F103XB_PERIPH( Gpio,               gpioe,          GPIOE_BASE      );

STM32F103XB_PERIPH( Exti,               exti,           EXTI_BASE       );

STM32F103XB_PERIPH( AdvTim_1,           adv_tim_1,      TIM1_BASE       );

STM32F103XB_PERIPH( GenTim_2_3_4,       gen_tim_2,      TIM2_BASE       );
STM32F103XB_PERIPH( GenTim_2_3_4,       gen_tim_3,      TIM3_BASE       );
STM32F103XB_PERIPH( GenTim_2_3_4,       gen_tim_4,      TIM3_BASE       );

STM32F103XB_PERIPH( Spi,                spi1,           SPI1_BASE       );

STM32F103XB_PERIPH( ElecSig,            elec_sig,       ELEC_SIG_BASE   );

STM32F103XB_PERIPH( DbgMcu,             dbg_mcu,        DBGMCU_BASE     );

#undef STM32F103XB_PERIPH

}  // namespace stm32f103xb

#endif  // #ifndef STM32F103XB_HXX
