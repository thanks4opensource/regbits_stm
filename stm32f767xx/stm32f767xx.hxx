// regbits_stm: regbits implementations for STM MCUs
// Copyright (C) 2019,2020 Mark R. Rubin
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
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// (LICENSE.txt) along with the regbits_stm program. If not, see
// <https://www.gnu.org/licenses/gpl.html>


#ifndef STM32F767XX_HXX
#define STM32F767XX_HXX

#include <stdint.h>

#include <regbits.hxx>


#if REGBITS_MAJOR_VERSION == 1
#if REGBITS_MINOR_VERSION  < 0
#warning REGBITS_MINOR_VERSION >= 0 with required REGBITS_MAJOR_VERSION == 1
#endif
#else
#error REGBITS_MAJOR_VERSION != 1
#endif

#define STM32F767XX_MAJOR_VERSION   1
#define STM32F767XX_MINOR_VERSION   2
#define STM32F767XX_MICRO_VERSION   0



namespace stm32f767xx {

using namespace regbits;

struct Rcc {
    struct Cr {
        using            pos_t = Pos<uint32_t, Cr>;
        static constexpr pos_t      HSION_POS     = pos_t( 0),
                                    HSIRDY_POS    = pos_t( 1),
                                    HSITRIM_POS   = pos_t( 3),
                                    HSICAL_POS    = pos_t( 8),
                                    HSEON_POS     = pos_t(16),
                                    HSERDY_POS    = pos_t(17),
                                    HSEBYP_POS    = pos_t(18),
                                    CSSON_POS     = pos_t(19),
                                    PLLON_POS     = pos_t(24),
                                    PLLRDY_POS    = pos_t(25),
                                    PLLI2SON_POS  = pos_t(26),
                                    PLLI2SRDY_POS = pos_t(27),
                                    PLLSAION_POS  = pos_t(28),
                                    PLLSAIRDY_POS = pos_t(29);

        using            bits_t = Bits<uint32_t, Cr>;
        static constexpr bits_t     HSION     = bits_t(1, HSION_POS    ),
                                    HSIRDY    = bits_t(1, HSIRDY_POS   ),
                                    HSEON     = bits_t(1, HSEON_POS    ),
                                    HSERDY    = bits_t(1, HSERDY_POS   ),
                                    HSEBYP    = bits_t(1, HSEBYP_POS   ),
                                    CSSON     = bits_t(1, CSSON_POS    ),
                                    PLLON     = bits_t(1, PLLON_POS    ),
                                    PLLRDY    = bits_t(1, PLLRDY_POS   ),
                                    PLLI2SON  = bits_t(1, PLLI2SON_POS ),
                                    PLLI2SRDY = bits_t(1, PLLI2SRDY_POS),
                                    PLLSAION  = bits_t(1, PLLSAION_POS ),
                                    PLLSAIRDY = bits_t(1, PLLSAIRDY_POS);

        static const uint32_t   HSITRIM_MASK    = 0x1f,
                                HSICAL_MASK     = 0xff;

        using mskd_t = Mskd<uint32_t, Cr>;
        using shft_t = Shft<uint32_t, Cr>;

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


    struct Pllcfgr {
        using            pos_t = Pos<uint32_t, Pllcfgr>;
        static constexpr pos_t      PLLM_POS        = pos_t( 0),
                                    PLLN_POS        = pos_t( 6),
                                    PLLP_POS        = pos_t(16),
                                    PLLSRC_POS      = pos_t(22),
                                    PLLSRC_HSE_POS  = pos_t(22),
                                    PLLQ_POS        = pos_t(24),
                                    PLLR_POS        = pos_t(28);

        using            bits_t = Bits<uint32_t, Pllcfgr>;
        static constexpr bits_t     PLLSRC          = bits_t(1, PLLSRC_POS  );

        static const uint32_t       PLLM_MASK = 0b000111111,
                                    PLLN_MASK = 0b111111111,
                                    PLLP_MASK = 0b000000011,
                                    PLLQ_MASK = 0b000001111,
                                    PLLR_MASK = 0b000000111;
        static const uint32_t       PLLN_MAX  = 432;

        using mskd_t = Mskd<uint32_t, Pllcfgr>;
        using shft_t = Shft<uint32_t, Pllcfgr>;

        REGBITS_MSKD_RANGE("Rcc::Pllcfgr",
                           PLLM,
                           pllm,
                           PLLM_MASK,
                           PLLM_POS,
                           PLLM_MASK);
        REGBITS_MSKD_RANGE("Rcc::Pllcfgr",
                           PLLN,
                           plln,
                           PLLN_MASK,
                           PLLN_POS,
                           PLLN_MAX);

        static constexpr mskd_t PLLP_2   = mskd_t(PLLP_MASK, 0b00, PLLP_POS),
                                PLLP_4   = mskd_t(PLLP_MASK, 0b01, PLLP_POS),
                                PLLP_6   = mskd_t(PLLP_MASK, 0b10, PLLP_POS),
                                PLLP_8   = mskd_t(PLLP_MASK, 0b11, PLLP_POS),
                            //  PLLQ 0 and 1 illegal values
                                PLLQ_2   = mskd_t(PLLQ_MASK,     2, PLLQ_POS),
                                PLLQ_3   = mskd_t(PLLQ_MASK,     3, PLLQ_POS),
                                PLLQ_4   = mskd_t(PLLQ_MASK,     4, PLLQ_POS),
                                PLLQ_5   = mskd_t(PLLQ_MASK,     5, PLLQ_POS),
                                PLLQ_6   = mskd_t(PLLQ_MASK,     6, PLLQ_POS),
                                PLLQ_7   = mskd_t(PLLQ_MASK,     7, PLLQ_POS),
                                PLLQ_8   = mskd_t(PLLQ_MASK,     8, PLLQ_POS),
                                PLLQ_9   = mskd_t(PLLQ_MASK,     9, PLLQ_POS),
                                PLLQ_10  = mskd_t(PLLQ_MASK, 10, PLLQ_POS   ),
                                PLLQ_11  = mskd_t(PLLQ_MASK, 11, PLLQ_POS   ),
                                PLLQ_12  = mskd_t(PLLQ_MASK, 12, PLLQ_POS   ),
                                PLLQ_13  = mskd_t(PLLQ_MASK, 13, PLLQ_POS   ),
                                PLLQ_14  = mskd_t(PLLQ_MASK, 14, PLLQ_POS   ),
                                PLLQ_15  = mskd_t(PLLQ_MASK, 15, PLLQ_POS   ),
                            //  PLLR 0 and 1 illegal values
                                PLLR_2   = mskd_t(PLLR_MASK,     2, PLLR_POS),
                                PLLR_3   = mskd_t(PLLR_MASK,     3, PLLR_POS),
                                PLLR_4   = mskd_t(PLLR_MASK,     4, PLLR_POS),
                                PLLR_5   = mskd_t(PLLR_MASK,     5, PLLR_POS),
                                PLLR_6   = mskd_t(PLLR_MASK,     6, PLLR_POS),
                                PLLR_7   = mskd_t(PLLR_MASK,     7, PLLR_POS);
    };  // struct Pllcfgr
    using pllcfgr_t = Reg<uint32_t, Pllcfgr>;
          pllcfgr_t   pllcfgr;


    struct Cfgr {
        using            pos_t = Pos<uint32_t, Cfgr>;
        static constexpr pos_t  SW_POS      = pos_t( 0),
                                SWS_POS     = pos_t( 2),
                                HPRE_POS    = pos_t( 4),
                                PPRE1_POS   = pos_t(10),
                                PPRE2_POS   = pos_t(13),
                                RTCPRE_POS  = pos_t(16),
                                MCO1_POS    = pos_t(21),
                                I2SSRC_POS  = pos_t(23),
                                MCO1PRE_POS = pos_t(24),
                                MCO2PRE_POS = pos_t(27),
                                MCO2_POS    = pos_t(30);

        static const uint32_t   SW_MASK       = 0x3    ,
                                SWS_MASK      = 0x3    ,
                                HPRE_MASK     = 0b1111 ,
                                PPRE1_MASK    = 0b111  ,
                                PPRE2_MASK    = 0b111  ,
                                RTCPRE_MASK   = 0b11111,
                                I2SSRC_MASK   = 1      ,
                                MCO1_MASK     = 0b11   ,
                                MCO1PRE_MASK  = 0b111  ,
                                MCO2PRE_MASK  = 0b111  ;

        using            mskd_t = Mskd<uint32_t, Cfgr>;
        static constexpr mskd_t
        SW_HSI        = mskd_t(SW_MASK, 0x0, SW_POS),
        SW_HSE        = mskd_t(SW_MASK, 0x1, SW_POS),
        SW_PLL        = mskd_t(SW_MASK, 0x2, SW_POS),

        SWS_HSI       = mskd_t(SWS_MASK, 0x0, SWS_POS),
        SWS_HSE       = mskd_t(SWS_MASK, 0x1, SWS_POS),
        SWS_PLL       = mskd_t(SWS_MASK, 0x2, SWS_POS),

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

        RTCPRE_NONE_0 = mskd_t(RTCPRE_MASK,  0, RTCPRE_POS),
        RTCPRE_NONE_1 = mskd_t(RTCPRE_MASK,  1, RTCPRE_POS),
        RTCPRE_DIV_2  = mskd_t(RTCPRE_MASK,  2, RTCPRE_POS),
        RTCPRE_DIV_3  = mskd_t(RTCPRE_MASK,  3, RTCPRE_POS),
        RTCPRE_DIV_4  = mskd_t(RTCPRE_MASK,  4, RTCPRE_POS),
        RTCPRE_DIV_5  = mskd_t(RTCPRE_MASK,  5, RTCPRE_POS),
        RTCPRE_DIV_6  = mskd_t(RTCPRE_MASK,  6, RTCPRE_POS),
        RTCPRE_DIV_7  = mskd_t(RTCPRE_MASK,  7, RTCPRE_POS),
        RTCPRE_DIV_8  = mskd_t(RTCPRE_MASK,  8, RTCPRE_POS),
        RTCPRE_DIV_9  = mskd_t(RTCPRE_MASK,  9, RTCPRE_POS),
        RTCPRE_DIV_10 = mskd_t(RTCPRE_MASK, 10, RTCPRE_POS),
        RTCPRE_DIV_11 = mskd_t(RTCPRE_MASK, 11, RTCPRE_POS),
        RTCPRE_DIV_12 = mskd_t(RTCPRE_MASK, 12, RTCPRE_POS),
        RTCPRE_DIV_13 = mskd_t(RTCPRE_MASK, 13, RTCPRE_POS),
        RTCPRE_DIV_14 = mskd_t(RTCPRE_MASK, 14, RTCPRE_POS),
        RTCPRE_DIV_15 = mskd_t(RTCPRE_MASK, 15, RTCPRE_POS),
        RTCPRE_DIV_16 = mskd_t(RTCPRE_MASK, 16, RTCPRE_POS),
        RTCPRE_DIV_17 = mskd_t(RTCPRE_MASK, 17, RTCPRE_POS),
        RTCPRE_DIV_18 = mskd_t(RTCPRE_MASK, 18, RTCPRE_POS),
        RTCPRE_DIV_19 = mskd_t(RTCPRE_MASK, 19, RTCPRE_POS),
        RTCPRE_DIV_20 = mskd_t(RTCPRE_MASK, 20, RTCPRE_POS),
        RTCPRE_DIV_21 = mskd_t(RTCPRE_MASK, 21, RTCPRE_POS),
        RTCPRE_DIV_22 = mskd_t(RTCPRE_MASK, 22, RTCPRE_POS),
        RTCPRE_DIV_23 = mskd_t(RTCPRE_MASK, 23, RTCPRE_POS),
        RTCPRE_DIV_24 = mskd_t(RTCPRE_MASK, 24, RTCPRE_POS),
        RTCPRE_DIV_25 = mskd_t(RTCPRE_MASK, 25, RTCPRE_POS),
        RTCPRE_DIV_26 = mskd_t(RTCPRE_MASK, 26, RTCPRE_POS),
        RTCPRE_DIV_27 = mskd_t(RTCPRE_MASK, 27, RTCPRE_POS),
        RTCPRE_DIV_28 = mskd_t(RTCPRE_MASK, 28, RTCPRE_POS),
        RTCPRE_DIV_29 = mskd_t(RTCPRE_MASK, 29, RTCPRE_POS),
        RTCPRE_DIV_30 = mskd_t(RTCPRE_MASK, 30, RTCPRE_POS),
        RTCPRE_DIV_31 = mskd_t(RTCPRE_MASK, 31, RTCPRE_POS),

        I2SSRC_PLL = mskd_t(I2SSRC_MASK, 0, I2SSRC_POS),
        I2SSRC_EXT = mskd_t(I2SSRC_MASK, 1, I2SSRC_POS),

        MCO1_HSI      = mskd_t(MCO1_MASK, 0b00, MCO1_POS),
        MCO1_LSE      = mskd_t(MCO1_MASK, 0b01, MCO1_POS),
        MCO1_HSE      = mskd_t(MCO1_MASK, 0b10, MCO1_POS),
        MCO1_PLL      = mskd_t(MCO1_MASK, 0b11, MCO1_POS),

        MCO1PRE_DIV_1 = mskd_t(MCO1PRE_MASK, 0b000, MCO1PRE_POS),
        MCO1PRE_DIV_2 = mskd_t(MCO1PRE_MASK, 0b100, MCO1PRE_POS),
        MCO1PRE_DIV_3 = mskd_t(MCO1PRE_MASK, 0b101, MCO1PRE_POS),
        MCO1PRE_DIV_4 = mskd_t(MCO1PRE_MASK, 0b110, MCO1PRE_POS),
        MCO1PRE_DIV_5 = mskd_t(MCO1PRE_MASK, 0b111, MCO1PRE_POS),

        MCO2PRE_DIV_1 = mskd_t(MCO2PRE_MASK, 0b000, MCO2PRE_POS),
        MCO2PRE_DIV_2 = mskd_t(MCO2PRE_MASK, 0b100, MCO2PRE_POS),
        MCO2PRE_DIV_3 = mskd_t(MCO2PRE_MASK, 0b101, MCO2PRE_POS),
        MCO2PRE_DIV_4 = mskd_t(MCO2PRE_MASK, 0b110, MCO2PRE_POS),
        MCO2PRE_DIV_5 = mskd_t(MCO2PRE_MASK, 0b111, MCO2PRE_POS);
    };  // struct Cfgr
    using cfgr_t = Reg<uint32_t, Cfgr>;
          cfgr_t   cfgr;


    struct Cir {
        using            pos_t = Pos<uint32_t, Cir>;
        static constexpr pos_t  LSIRDYF_POS     = pos_t( 0),
                                LSERDYF_POS     = pos_t( 1),
                                HSIRDYF_POS     = pos_t( 2),
                                HSERDYF_POS     = pos_t( 3),
                                PLLRDYF_POS     = pos_t( 4),
                                PLLI2SRDYF_POS  = pos_t( 5),
                                PLLSAIRDYF_POS  = pos_t( 6),
                                CSSF_POS        = pos_t( 7),
                                LSIRDYIE_POS    = pos_t( 8),
                                LSERDYIE_POS    = pos_t( 9),
                                HSIRDYIE_POS    = pos_t(10),
                                HSERDYIE_POS    = pos_t(11),
                                PLLRDYIE_POS    = pos_t(12),
                                PLLI2SRDYIE_POS = pos_t(13),
                                PLLSAIRDYIE_POS = pos_t(14),
                                LSIRDYC_POS     = pos_t(16),
                                LSERDYC_POS     = pos_t(17),
                                HSIRDYC_POS     = pos_t(18),
                                HSERDYC_POS     = pos_t(19),
                                PLLRDYC_POS     = pos_t(20),
                                PLLI2SRDYC_POS  = pos_t(21),
                                PLLSAIRDYC_POS  = pos_t(22),
                                CSSC_POS        = pos_t(23);

        using            bits_t = Bits<uint32_t, Cir>;
        static constexpr bits_t LSIRDYF         = bits_t(1, LSIRDYF_POS    ),
                                LSERDYF         = bits_t(1, LSERDYF_POS    ),
                                HSIRDYF         = bits_t(1, HSIRDYF_POS    ),
                                HSERDYF         = bits_t(1, HSERDYF_POS    ),
                                PLLRDYF         = bits_t(1, PLLRDYF_POS    ),
                                PLLI2SRDYF      = bits_t(1, PLLI2SRDYF_POS ),
                                PLLSAIRDYF      = bits_t(1, PLLSAIRDYF_POS ),
                                CSSF            = bits_t(1, CSSF_POS       ),
                                LSIRDYIE        = bits_t(1, LSIRDYIE_POS   ),
                                LSERDYIE        = bits_t(1, LSERDYIE_POS   ),
                                HSIRDYIE        = bits_t(1, HSIRDYIE_POS   ),
                                HSERDYIE        = bits_t(1, HSERDYIE_POS   ),
                                PLLRDYIE        = bits_t(1, PLLRDYIE_POS   ),
                                PLLI2SRDYIE     = bits_t(1, PLLI2SRDYIE_POS),
                                PLLSAIRDYIE     = bits_t(1, PLLSAIRDYIE_POS),
                                LSIRDYC         = bits_t(1, LSIRDYC_POS    ),
                                LSERDYC         = bits_t(1, LSERDYC_POS    ),
                                HSIRDYC         = bits_t(1, HSIRDYC_POS    ),
                                HSERDYC         = bits_t(1, HSERDYC_POS    ),
                                PLLRDYC         = bits_t(1, PLLRDYC_POS    ),
                                PLLI2SRDYC      = bits_t(1, PLLI2SRDYC_POS ),
                                PLLSAIRDYC      = bits_t(1, PLLSAIRDYC_POS ),
                                CSSC            = bits_t(1, CSSC_POS       );
    };  // struct Cir
    using cir_t = Reg<uint32_t, Cir>;
          cir_t   cir;


    struct Ahb1rstr {
        using            pos_t = Pos<uint32_t, Ahb1rstr>;
        static constexpr pos_t      GPIOA_POS   = pos_t( 0),
                                    GPIOB_POS   = pos_t( 1),
                                    GPIOC_POS   = pos_t( 2),
                                    GPIOD_POS   = pos_t( 3),
                                    GPIOE_POS   = pos_t( 4),
                                    GPIOF_POS   = pos_t( 5),
                                    GPIOG_POS   = pos_t( 6),
                                    GPIOH_POS   = pos_t( 7),
                                    GPIOI_POS   = pos_t( 8),
                                    GPIOJ_POS   = pos_t( 9),
                                    GPIOK_POS   = pos_t(10),
                                    CRC_POS     = pos_t(12),
                                    DMA1_POS    = pos_t(21),
                                    DMA2_POS    = pos_t(22),
                                    DMA2D_POS   = pos_t(23),
                                    ETHMAC_POS  = pos_t(25),
                                    OTGH_POS    = pos_t(29);

        using            bits_t = Bits<uint32_t, Ahb1rstr>;
        static constexpr bits_t     GPIOA   = bits_t(1, GPIOA_POS   ),
                                    GPIOB   = bits_t(1, GPIOB_POS   ),
                                    GPIOC   = bits_t(1, GPIOC_POS   ),
                                    GPIOD   = bits_t(1, GPIOD_POS   ),
                                    GPIOE   = bits_t(1, GPIOE_POS   ),
                                    GPIOF   = bits_t(1, GPIOF_POS   ),
                                    GPIOG   = bits_t(1, GPIOG_POS   ),
                                    GPIOH   = bits_t(1, GPIOH_POS   ),
                                    GPIOI   = bits_t(1, GPIOI_POS   ),
                                    GPIOJ   = bits_t(1, GPIOJ_POS   ),
                                    GPIOK   = bits_t(1, GPIOK_POS   ),
                                    CRC     = bits_t(1, CRC_POS     ),
                                    DMA1    = bits_t(1, DMA1_POS    ),
                                    DMA2    = bits_t(1, DMA2_POS    ),
                                    DMA2D   = bits_t(1, DMA2D_POS   ),
                                    ETHMAC  = bits_t(1, ETHMAC_POS  ),
                                    OTGH    = bits_t(1, OTGH_POS    );
    };  // struct Ahb1rstr
    using ahb1rstr_t = Reg<uint32_t, Ahb1rstr>;
          ahb1rstr_t   ahb1rstr;


    struct Ahb2rstr {
        using            pos_t = Pos<uint32_t, Ahb2rstr>;
        static constexpr pos_t      DCMIRST_POS     = pos_t(0),
                                    JPEGRST_POS     = pos_t(1),
                                    RNGRST_POS      = pos_t(6),
                                    OTGFSRST_POS    = pos_t(7);

        using            bits_t = Bits<uint32_t, Ahb2rstr>;
        static constexpr bits_t     DCMIRST         = bits_t(1, DCMIRST_POS ),
                                    JPEGRST         = bits_t(1, JPEGRST_POS ),
                                    RNGRST          = bits_t(1, RNGRST_POS  ),
                                    OTGFSRST        = bits_t(1, OTGFSRST_POS);
    };  // struct Ahb2rstr
    using ahb2rstr_t = Reg<uint32_t, Ahb2rstr>;
          ahb2rstr_t   ahb2rstr;


    struct Ahb3rstr {
        using            pos_t    = Pos<uint32_t, Ahb3rstr>;
        static constexpr pos_t      FMCRST_POS      = pos_t(0),
                                    QSPIRST_POS     = pos_t(1);

        using            bits_t   = Bits<uint32_t, Ahb3rstr>;
        static constexpr bits_t     FMCRST          = bits_t(1, FMCRST_POS  ),
                                    QSPIRST         = bits_t(1, QSPIRST_POS );
    };  // struct Ahb3rstr
    using ahb3rstr_t = Reg<uint32_t, Ahb3rstr>;
          ahb3rstr_t   ahb3rstr;


    private: uint32_t   _reserved0;  public:


    struct Apb1rstr {
        using            pos_t = Pos<uint32_t, Apb1rstr>;
        static constexpr pos_t      TIM2_POS        = pos_t( 0),
                                    TIM3_POS        = pos_t( 1),
                                    TIM4_POS        = pos_t( 2),
                                    TIM5_POS        = pos_t( 3),
                                    TIM6_POS        = pos_t( 4),
                                    TIM7_POS        = pos_t( 5),
                                    TIM12_POS       = pos_t( 6),
                                    TIM13_POS       = pos_t( 7),
                                    TIM14_POS       = pos_t( 8),
                                    LPTIM1_POS      = pos_t( 9),
                                    WWDG_POS        = pos_t(11),
                                    CAN3_POS        = pos_t(13),
                                    SPI2_POS        = pos_t(14),
                                    SPI3_POS        = pos_t(15),
                                    SPDIFRX_POS     = pos_t(16),
                                    USART2_POS      = pos_t(17),
                                    USART3_POS      = pos_t(18),
                                    UART4_POS       = pos_t(19),
                                    UART5_POS       = pos_t(20),
                                    I2C1_POS        = pos_t(21),
                                    I2C2_POS        = pos_t(22),
                                    I2C3_POS        = pos_t(23),
                                    I2C4_POS        = pos_t(24),
                                    CAN1_POS        = pos_t(25),
                                    CAN2_POS        = pos_t(26),
                                    CEC_POS         = pos_t(27),
                                    PWR_POS         = pos_t(28),
                                    DAC_POS         = pos_t(29),
                                    UART7_POS       = pos_t(30),
                                    UART8_POS       = pos_t(31);

        using            bits_t = Bits<uint32_t, Apb1rstr>;
        static constexpr bits_t     TIM2            = bits_t(1, TIM2_POS    ),
                                    TIM3            = bits_t(1, TIM3_POS    ),
                                    TIM4            = bits_t(1, TIM4_POS    ),
                                    TIM5            = bits_t(1, TIM5_POS    ),
                                    TIM6            = bits_t(1, TIM6_POS    ),
                                    TIM7            = bits_t(1, TIM7_POS    ),
                                    TIM12           = bits_t(1, TIM12_POS   ),
                                    TIM13           = bits_t(1, TIM13_POS   ),
                                    TIM14           = bits_t(1, TIM14_POS   ),
                                    LPTIM1          = bits_t(1, LPTIM1_POS  ),
                                    WWDG            = bits_t(1, WWDG_POS    ),
                                    CAN3            = bits_t(1, CAN3_POS    ),
                                    SPI2            = bits_t(1, SPI2_POS    ),
                                    SPI3            = bits_t(1, SPI3_POS    ),
                                    SPDIFRX         = bits_t(1, SPDIFRX_POS ),
                                    USART2          = bits_t(1, USART2_POS  ),
                                    USART3          = bits_t(1, USART3_POS  ),
                                    UART4           = bits_t(1, UART4_POS   ),
                                    UART5           = bits_t(1, UART5_POS   ),
                                    I2C1            = bits_t(1, I2C1_POS    ),
                                    I2C2            = bits_t(1, I2C2_POS    ),
                                    I2C3            = bits_t(1, I2C3_POS    ),
                                    I2C4            = bits_t(1, I2C4_POS    ),
                                    CAN1            = bits_t(1, CAN1_POS    ),
                                    CAN2            = bits_t(1, CAN2_POS    ),
                                    CEC             = bits_t(1, CEC_POS     ),
                                    PWR             = bits_t(1, PWR_POS     ),
                                    DAC             = bits_t(1, DAC_POS     ),
                                    UART7           = bits_t(1, UART7_POS   ),
                                    UART8           = bits_t(1, UART8_POS   );
    };  // struct Apb1rstr
    using apb1rstr_t = Reg<uint32_t, Apb1rstr>;
          apb1rstr_t   apb1rstr;


    struct Apb2rstr {
        using            pos_t = Pos<uint32_t, Apb2rstr>;
        static constexpr pos_t      TIM1_POS        = pos_t( 0),
                                    TIM8_POS        = pos_t( 1),
                                    USART1_POS      = pos_t( 4),
                                    USART6_POS      = pos_t( 5),
                                    SDMMC2_POS      = pos_t( 7),
                                    ADC_POS         = pos_t( 8),
                                    SDMMC1_POS      = pos_t(11),
                                    SPI1_POS        = pos_t(12),
                                    SPI4_POS        = pos_t(13),
                                    SYSCFG_POS      = pos_t(14),
                                    TIM9_POS        = pos_t(16),
                                    TIM10_POS       = pos_t(17),
                                    TIM11_POS       = pos_t(18),
                                    SPI5_POS        = pos_t(20),
                                    SPI6_POS        = pos_t(21),
                                    SAI1_POS        = pos_t(22),
                                    SAI2_POS        = pos_t(23),
                                    LTDC_POS        = pos_t(26),
                                    DFSDM1_POS      = pos_t(29),
                                    MDIO_POS        = pos_t(30);

        using            bits_t = Bits<uint32_t, Apb2rstr>;
        static constexpr bits_t     TIM1            = bits_t(1, TIM1_POS    ),
                                    TIM8            = bits_t(1, TIM8_POS    ),
                                    USART1          = bits_t(1, USART1_POS  ),
                                    USART6          = bits_t(1, USART6_POS  ),
                                    SDMMC2          = bits_t(1, SDMMC2_POS  ),
                                    ADC             = bits_t(1, ADC_POS     ),
                                    SDMMC1          = bits_t(1, SDMMC1_POS  ),
                                    SPI1            = bits_t(1, SPI1_POS    ),
                                    SPI4            = bits_t(1, SPI4_POS    ),
                                    SYSCFG          = bits_t(1, SYSCFG_POS  ),
                                    TIM9            = bits_t(1, TIM9_POS    ),
                                    TIM10           = bits_t(1, TIM10_POS   ),
                                    TIM11           = bits_t(1, TIM11_POS   ),
                                    SPI5            = bits_t(1, SPI5_POS    ),
                                    SPI6            = bits_t(1, SPI6_POS    ),
                                    SAI1            = bits_t(1, SAI1_POS    ),
                                    SAI2            = bits_t(1, SAI2_POS    ),
                                    LTDC            = bits_t(1, LTDC_POS    ),
                                    DFSDM1          = bits_t(1, DFSDM1_POS  ),
                                    MDIO            = bits_t(1, MDIO_POS    );
    };  // struct Apb2rstr
    using apb2rstr_t = Reg<uint32_t, Apb2rstr>;
          apb2rstr_t   apb2rstr;


    private: uint32_t   _reserved1[2];  public:


    struct Ahb1enr {
        using            pos_t = Pos<uint32_t, Ahb1enr>;
        static constexpr pos_t      GPIOA_POS       = pos_t( 0),
                                    GPIOB_POS       = pos_t( 1),
                                    GPIOC_POS       = pos_t( 2),
                                    GPIOD_POS       = pos_t( 3),
                                    GPIOE_POS       = pos_t( 4),
                                    GPIOF_POS       = pos_t( 5),
                                    GPIOG_POS       = pos_t( 6),
                                    GPIOH_POS       = pos_t( 7),
                                    GPIOI_POS       = pos_t( 8),
                                    GPIOJ_POS       = pos_t( 9),
                                    GPIOK_POS       = pos_t(10),
                                    CRC_POS         = pos_t(12),
                                    BKPSRAM_POS     = pos_t(18),
                                    DTCMRAM_POS     = pos_t(20),
                                    DMA1_POS        = pos_t(21),
                                    DMA2_POS        = pos_t(22),
                                    DMA2D_POS       = pos_t(23),
                                    ETHMAC_POS      = pos_t(25),
                                    ETHMACTX_POS    = pos_t(26),
                                    ETHMACRX_POS    = pos_t(27),
                                    ETHMACPTP_POS   = pos_t(28),
                                    OTGHS_POS       = pos_t(29),
                                    OTGHSULPI_POS   = pos_t(30);

        using            bits_t = Bits<uint32_t, Ahb1enr>;
        static constexpr bits_t     GPIOA           = bits_t(1, GPIOA_POS    ),
                                    GPIOB           = bits_t(1, GPIOB_POS    ),
                                    GPIOC           = bits_t(1, GPIOC_POS    ),
                                    GPIOD           = bits_t(1, GPIOD_POS    ),
                                    GPIOE           = bits_t(1, GPIOE_POS    ),
                                    GPIOF           = bits_t(1, GPIOF_POS    ),
                                    GPIOG           = bits_t(1, GPIOG_POS    ),
                                    GPIOH           = bits_t(1, GPIOH_POS    ),
                                    GPIOI           = bits_t(1, GPIOI_POS    ),
                                    GPIOJ           = bits_t(1, GPIOJ_POS    ),
                                    GPIOK           = bits_t(1, GPIOK_POS    ),
                                    CRC             = bits_t(1, CRC_POS      ),
                                    BKPSRAM         = bits_t(1, BKPSRAM_POS  ),
                                    DTCMRAM         = bits_t(1, DTCMRAM_POS  ),
                                    DMA1            = bits_t(1, DMA1_POS     ),
                                    DMA2            = bits_t(1, DMA2_POS     ),
                                    DMA2D           = bits_t(1, DMA2D_POS    ),
                                    ETHMAC          = bits_t(1, ETHMAC_POS   ),
                                    ETHMACTX        = bits_t(1, ETHMACTX_POS ),
                                    ETHMACRX        = bits_t(1, ETHMACRX_POS ),
                                    ETHMACPTP       = bits_t(1, ETHMACPTP_POS),
                                    OTGHS           = bits_t(1, OTGHS_POS    ),
                                    OTGHSULPI       = bits_t(1, OTGHSULPI_POS);
    };  // struct Ahb1enr
    using ahb1enr_t = Reg<uint32_t, Ahb1enr>;
          ahb1enr_t   ahb1enr;


    struct Ahb2enr {
        using            pos_t = Pos<uint32_t, Ahb2enr>;
        static constexpr pos_t      DCMI_POS        = pos_t(0),
                                    JPEG_POS        = pos_t(1),
                                    RNG_POS         = pos_t(6),
                                    OTGFS_POS       = pos_t(7);

        using            bits_t = Bits<uint32_t, Ahb2enr>;
        static constexpr bits_t     DCMI            = bits_t(1, DCMI_POS    ),
                                    JPEG            = bits_t(1, JPEG_POS    ),
                                    RNG             = bits_t(1, RNG_POS     ),
                                    OTGFS           = bits_t(1, OTGFS_POS   );
    };  // struct Ahb2enr
    using ahb2enr_t = Reg<uint32_t, Ahb2enr>;
          ahb2enr_t   ahb2enr;


    struct Ahb3enr {
        using            pos_t = Pos<uint32_t, Ahb3enr>;
        static constexpr pos_t      FMC_POS         = pos_t(0),
                                    QSPI_POS        = pos_t(1);

        using            bits_t = Bits<uint32_t, Ahb3enr>;
        static constexpr bits_t     FMC             = bits_t(1, FMC_POS     ),
                                    QSPI            = bits_t(1, QSPI_POS    );
    };  // struct Ahb3enr
    using ahb3enr_t = Reg<uint32_t, Ahb3enr>;
          ahb3enr_t   ahb3enr;


    private: uint32_t   _reserved2;  public:


    struct Apb1enr {
        using            pos_t = Pos<uint32_t, Apb1enr>;
        static constexpr pos_t      TIM2_POS        = pos_t( 0),
                                    TIM3_POS        = pos_t( 1),
                                    TIM4_POS        = pos_t( 2),
                                    TIM5_POS        = pos_t( 3),
                                    TIM6_POS        = pos_t( 4),
                                    TIM7_POS        = pos_t( 5),
                                    TIM12_POS       = pos_t( 6),
                                    TIM13_POS       = pos_t( 7),
                                    TIM14_POS       = pos_t( 8),
                                    LPTIM1_POS      = pos_t( 9),
                                    RTC_POS         = pos_t(10),
                                    WWDG_POS        = pos_t(11),
                                    CAN3_POS        = pos_t(13),
                                    SPI2_POS        = pos_t(14),
                                    SPI3_POS        = pos_t(15),
                                    SPDIFRX_POS     = pos_t(16),
                                    USART2_POS      = pos_t(17),
                                    USART3_POS      = pos_t(18),
                                    UART4_POS       = pos_t(19),
                                    UART5_POS       = pos_t(20),
                                    I2C1_POS        = pos_t(21),
                                    I2C2_POS        = pos_t(22),
                                    I2C3_POS        = pos_t(23),
                                    I2C4_POS        = pos_t(24),
                                    CAN1_POS        = pos_t(25),
                                    CAN2_POS        = pos_t(26),
                                    CEC_POS         = pos_t(27),
                                    PWR_POS         = pos_t(28),
                                    DAC_POS         = pos_t(29),
                                    UART7_POS       = pos_t(30),
                                    UART8_POS       = pos_t(31);

        using            bits_t = Bits<uint32_t, Apb1enr>;
        static constexpr bits_t     TIM2            = bits_t(1, TIM2_POS    ),
                                    TIM3            = bits_t(1, TIM3_POS    ),
                                    TIM4            = bits_t(1, TIM4_POS    ),
                                    TIM5            = bits_t(1, TIM5_POS    ),
                                    TIM6            = bits_t(1, TIM6_POS    ),
                                    TIM7            = bits_t(1, TIM7_POS    ),
                                    TIM12           = bits_t(1, TIM12_POS   ),
                                    TIM13           = bits_t(1, TIM13_POS   ),
                                    TIM14           = bits_t(1, TIM14_POS   ),
                                    LPTIM1          = bits_t(1, LPTIM1_POS  ),
                                    RTC             = bits_t(1, RTC_POS     ),
                                    WWDG            = bits_t(1, WWDG_POS    ),
                                    CAN3            = bits_t(1, CAN3_POS    ),
                                    SPI2            = bits_t(1, SPI2_POS    ),
                                    SPI3            = bits_t(1, SPI3_POS    ),
                                    SPDIFRX         = bits_t(1, SPDIFRX_POS ),
                                    USART2          = bits_t(1, USART2_POS  ),
                                    USART3          = bits_t(1, USART3_POS  ),
                                    UART4           = bits_t(1, UART4_POS   ),
                                    UART5           = bits_t(1, UART5_POS   ),
                                    I2C1            = bits_t(1, I2C1_POS    ),
                                    I2C2            = bits_t(1, I2C2_POS    ),
                                    I2C3            = bits_t(1, I2C3_POS    ),
                                    I2C4            = bits_t(1, I2C4_POS    ),
                                    CAN1            = bits_t(1, CAN1_POS    ),
                                    CAN2            = bits_t(1, CAN2_POS    ),
                                    CEC             = bits_t(1, CEC_POS     ),
                                    PWR             = bits_t(1, PWR_POS     ),
                                    DAC             = bits_t(1, DAC_POS     ),
                                    UART7           = bits_t(1, UART7_POS   ),
                                    UART8           = bits_t(1, UART8_POS   );
    };  // struct Apb1enr
    using apb1enr_t = Reg<uint32_t, Apb1enr>;
          apb1enr_t   apb1enr;


    struct Apb2enr {
        using            pos_t = Pos<uint32_t, Apb2enr>;
        static constexpr pos_t      TIM1_POS        = pos_t( 0),
                                    TIM8_POS        = pos_t( 1),
                                    USART1_POS      = pos_t( 4),
                                    USART6_POS      = pos_t( 5),
                                    SDMMC2_POS      = pos_t( 7),
                                    ADC1_POS        = pos_t( 8),
                                    ADC2_POS        = pos_t( 9),
                                    ADC3_POS        = pos_t(10),
                                    SDMMC1_POS      = pos_t(11),
                                    SPI1_POS        = pos_t(12),
                                    SPI4_POS        = pos_t(13),
                                    SYSCFG_POS      = pos_t(14),
                                    TIM9_POS        = pos_t(16),
                                    TIM10_POS       = pos_t(17),
                                    TIM11_POS       = pos_t(18),
                                    SPI5_POS        = pos_t(20),
                                    SPI6_POS        = pos_t(21),
                                    SAI1_POS        = pos_t(22),
                                    SAI2_POS        = pos_t(23),
                                    LTDC_POS        = pos_t(26),
                                    DFSDM1_POS      = pos_t(29),
                                    MDIO_POS        = pos_t(30);

        using            bits_t = Bits<uint32_t, Apb2enr>;
        static constexpr bits_t     TIM1            = bits_t(1, TIM1_POS    ),
                                    TIM8            = bits_t(1, TIM8_POS    ),
                                    USART1          = bits_t(1, USART1_POS  ),
                                    USART6          = bits_t(1, USART6_POS  ),
                                    SDMMC2          = bits_t(1, SDMMC2_POS  ),
                                    ADC1            = bits_t(1, ADC1_POS    ),
                                    ADC2            = bits_t(1, ADC2_POS    ),
                                    ADC3            = bits_t(1, ADC3_POS    ),
                                    SDMMC1          = bits_t(1, SDMMC1_POS  ),
                                    SPI1            = bits_t(1, SPI1_POS    ),
                                    SPI4            = bits_t(1, SPI4_POS    ),
                                    SYSCFG          = bits_t(1, SYSCFG_POS  ),
                                    TIM9            = bits_t(1, TIM9_POS    ),
                                    TIM10           = bits_t(1, TIM10_POS   ),
                                    TIM11           = bits_t(1, TIM11_POS   ),
                                    SPI5            = bits_t(1, SPI5_POS    ),
                                    SPI6            = bits_t(1, SPI6_POS    ),
                                    SAI1            = bits_t(1, SAI1_POS    ),
                                    SAI2            = bits_t(1, SAI2_POS    ),
                                    LTDC            = bits_t(1, LTDC_POS    ),
                                    DFSDM1          = bits_t(1, DFSDM1_POS  ),
                                    MDIO            = bits_t(1, MDIO_POS    );
    };  // struct Apb2enr
    using apb2enr_t = Reg<uint32_t, Apb2enr>;
          apb2enr_t   apb2enr;


    private: uint32_t   _reserved3[2];  public:


    struct Ahb1lpenr {
        using            pos_t = Pos<uint32_t, Ahb1lpenr>;
        static constexpr pos_t      GPIOALP_POS     = pos_t( 0),
                                    GPIOBLP_POS     = pos_t( 1),
                                    GPIOCLP_POS     = pos_t( 2),
                                    GPIODLP_POS     = pos_t( 3),
                                    GPIOELP_POS     = pos_t( 4),
                                    GPIOFLP_POS     = pos_t( 5),
                                    GPIOGLP_POS     = pos_t( 6),
                                    GPIOHLP_POS     = pos_t( 7),
                                    GPIOILP_POS     = pos_t( 8),
                                    GPIOJLP_POS     = pos_t( 9),
                                    GPIOKLP_POS     = pos_t(10),
                                    CRCLP_POS       = pos_t(12),
                                    AXILP_POS       = pos_t(13),
                                    FLITFLP_POS     = pos_t(15),
                                    SRAM1LP_POS     = pos_t(16),
                                    SRAM2LP_POS     = pos_t(17),
                                    BKPSRAMLP_POS   = pos_t(18),
                                    DTCMLP_POS      = pos_t(20),
                                    DMA1LP_POS      = pos_t(21),
                                    DMA2LP_POS      = pos_t(22),
                                    DMA2DLP_POS     = pos_t(23),
                                    ETHMACLP_POS    = pos_t(25),
                                    ETHMACTXLP_POS  = pos_t(26),
                                    ETHMACRXLP_POS  = pos_t(27),
                                    ETHMACPTPLP_POS = pos_t(28),
                                    OTGHSLP_POS     = pos_t(29),
                                    OTGHSULPILP_POS = pos_t(30);

        using            bits_t = Bits<uint32_t, Ahb1lpenr>;
        static constexpr bits_t     GPIOALP         = bits_t(1, GPIOALP_POS    ),
                                    GPIOBLP         = bits_t(1, GPIOBLP_POS    ),
                                    GPIOCLP         = bits_t(1, GPIOCLP_POS    ),
                                    GPIODLP         = bits_t(1, GPIODLP_POS    ),
                                    GPIOELP         = bits_t(1, GPIOELP_POS    ),
                                    GPIOFLP         = bits_t(1, GPIOFLP_POS    ),
                                    GPIOGLP         = bits_t(1, GPIOGLP_POS    ),
                                    GPIOHLP         = bits_t(1, GPIOHLP_POS    ),
                                    GPIOILP         = bits_t(1, GPIOILP_POS    ),
                                    GPIOJLP         = bits_t(1, GPIOJLP_POS    ),
                                    GPIOKLP         = bits_t(1, GPIOKLP_POS    ),
                                    CRCLP           = bits_t(1, CRCLP_POS      ),
                                    AXILP           = bits_t(1, AXILP_POS      ),
                                    FLITFLP         = bits_t(1, FLITFLP_POS    ),
                                    SRAM1LP         = bits_t(1, SRAM1LP_POS    ),
                                    SRAM2LP         = bits_t(1, SRAM2LP_POS    ),
                                    BKPSRAMLP       = bits_t(1, BKPSRAMLP_POS  ),
                                    DTCMLP          = bits_t(1, DTCMLP_POS     ),
                                    DMA1LP          = bits_t(1, DMA1LP_POS     ),
                                    DMA2LP          = bits_t(1, DMA2LP_POS     ),
                                    DMA2DLP         = bits_t(1, DMA2DLP_POS    ),
                                    ETHMACLP        = bits_t(1, ETHMACLP_POS   ),
                                    ETHMACTXLP      = bits_t(1, ETHMACTXLP_POS ),
                                    ETHMACRXLP      = bits_t(1, ETHMACRXLP_POS ),
                                    ETHMACPTPLP     = bits_t(1, ETHMACPTPLP_POS),
                                    OTGHSLP         = bits_t(1, OTGHSLP_POS    ),
                                    OTGHSULPILP     = bits_t(1, OTGHSULPILP_POS);
    };  // struct Ahb1lpenr
    using ahb1lpenr_t = Reg<uint32_t, Ahb1lpenr>;
          ahb1lpenr_t   ahb1lpenr;


    struct Ahb2lpenr {
        using            pos_t = Pos<uint32_t, Ahb2lpenr>;
        static constexpr pos_t      DCMILP_POS      = pos_t(0),
                                    JPEGLP_POS      = pos_t(1),
                                    RNGLP_POS       = pos_t(6),
                                    OTGFSLP_POS     = pos_t(7);

        using            bits_t = Bits<uint32_t, Ahb2lpenr>;
        static constexpr bits_t     DCMILP          = bits_t(1, DCMILP_POS  ),
                                    JPEGLP          = bits_t(1, JPEGLP_POS  ),
                                    RNGLP           = bits_t(1, RNGLP_POS   ),
                                    OTGFSLP         = bits_t(1, OTGFSLP_POS );
    };  // struct Ahb2lpenr
    using ahb2lpenr_t = Reg<uint32_t, Ahb2lpenr>;
          ahb2lpenr_t   ahb2lpenr;


    struct Ahb3lpenr {
        using            pos_t = Pos<uint32_t, Ahb3lpenr>;
        static constexpr pos_t       FMCLPEN_POS = pos_t( 0),
                                    QSPILPEN_POS = pos_t( 1);

        using            bits_t = Bits<uint32_t, Ahb3lpenr>;
        static constexpr bits_t     FMCLPEN  = bits_t(1,  FMCLPEN_POS),
                                    QSPILPEN = bits_t(1, QSPILPEN_POS);
    };  // struct Ahb3lpenr
    using Ahb3lpenr_t = Reg<uint32_t, Ahb3lpenr>;
          Ahb3lpenr_t   Ahb3lpenr;


    private: uint32_t   _reserved4;  public:


    struct Apb1lpenr {
        using            pos_t = Pos<uint32_t, Apb1lpenr>;
        static constexpr pos_t  FMCLP_POS       = pos_t( 0),
                                QSPILP_POS      = pos_t( 1),
                                TIM2LP_POS      = pos_t( 0),
                                TIM3LP_POS      = pos_t( 1),
                                TIM4LP_POS      = pos_t( 2),
                                TIM5LP_POS      = pos_t( 3),
                                TIM6LP_POS      = pos_t( 4),
                                TIM7LP_POS      = pos_t( 5),
                                TIM12LP_POS     = pos_t( 6),
                                TIM13LP_POS     = pos_t( 7),
                                TIM14LP_POS     = pos_t( 8),
                                LPTIM1LP_POS    = pos_t( 9),
                                RTCLP_POS       = pos_t(10),
                                WWDGLP_POS      = pos_t(11),
                                CAN3LP_POS      = pos_t(13),
                                SPI2LP_POS      = pos_t(14),
                                SPI3LP_POS      = pos_t(15),
                                SPDIFRXLP_POS   = pos_t(16),
                                USART2LP_POS    = pos_t(17),
                                USART3LP_POS    = pos_t(18),
                                UART4LP_POS     = pos_t(19),
                                UART5LP_POS     = pos_t(20),
                                I2C1LP_POS      = pos_t(21),
                                I2C2LP_POS      = pos_t(22),
                                I2C3LP_POS      = pos_t(23),
                                I2C4LP_POS      = pos_t(24),
                                CAN1LP_POS      = pos_t(25),
                                CAN2LP_POS      = pos_t(26),
                                CECLP_POS       = pos_t(27),
                                PWRLP_POS       = pos_t(28),
                                DACLP_POS       = pos_t(29),
                                UART7LP_POS     = pos_t(30),
                                UART8LP_POS     = pos_t(31);

        using            bits_t = Bits<uint32_t, Apb1lpenr>;
        static constexpr bits_t FMCLP           = bits_t(1, FMCLP_POS   ),
                                QSPILP          = bits_t(1, QSPILP_POS  ),
                                TIM2LP          = bits_t(1, TIM2LP_POS  ),
                                TIM3LP          = bits_t(1, TIM3LP_POS  ),
                                TIM4LP          = bits_t(1, TIM4LP_POS  ),
                                TIM5LP          = bits_t(1, TIM5LP_POS  ),
                                TIM6LP          = bits_t(1, TIM6LP_POS  ),
                                TIM7LP          = bits_t(1, TIM7LP_POS  ),
                                TIM12LP         = bits_t(1, TIM12LP_POS ),
                                TIM13LP         = bits_t(1, TIM13LP_POS ),
                                TIM14LP         = bits_t(1, TIM14LP_POS ),
                                LPTIM1LP        = bits_t(1, LPTIM1LP_POS),
                                RTCLP           = bits_t(1, RTCLP_POS   ),
                                WWDGLP          = bits_t(1, WWDGLP_POS  ),
                                CAN3LP          = bits_t(1, CAN3LP_POS  ),
                                SPI2LP          = bits_t(1, SPI2LP_POS  ),
                                SPI3LP          = bits_t(1, SPI3LP_POS  ),
                                SPDIFRXLP       = bits_t(1, SPDIFRXLP_POS),
                                USART2LP        = bits_t(1, USART2LP_POS),
                                USART3LP        = bits_t(1, USART3LP_POS),
                                UART4LP         = bits_t(1, UART4LP_POS ),
                                UART5LP         = bits_t(1, UART5LP_POS ),
                                I2C1LP          = bits_t(1, I2C1LP_POS  ),
                                I2C2LP          = bits_t(1, I2C2LP_POS  ),
                                I2C3LP          = bits_t(1, I2C3LP_POS  ),
                                I2C4LP          = bits_t(1, I2C4LP_POS  ),
                                CAN1LP          = bits_t(1, CAN1LP_POS  ),
                                CAN2LP          = bits_t(1, CAN2LP_POS  ),
                                CECLP           = bits_t(1, CECLP_POS   ),
                                PWRLP           = bits_t(1, PWRLP_POS   ),
                                DACLP           = bits_t(1, DACLP_POS   ),
                                UART7LP         = bits_t(1, UART7LP_POS ),
                                UART8LP         = bits_t(1, UART8LP_POS );
    };  // struct Apb1lpenr
    using apb1lpenr_t = Reg<uint32_t, Apb1lpenr>;
          apb1lpenr_t   apb1lpenr;

    struct Apb2lpenr {
        using            pos_t = Pos<uint32_t, Apb2lpenr>;
        static constexpr pos_t      TIM1LP_POS      = pos_t( 0),
                                    TIM8LP_POS      = pos_t( 1),
                                    USART1LP_POS    = pos_t( 4),
                                    USART6LP_POS    = pos_t( 5),
                                    SDMMC2LP_POS    = pos_t( 7),
                                    ADC1LP_POS      = pos_t( 8),
                                    ADC2LP_POS      = pos_t( 9),
                                    ADC3LP_POS      = pos_t(10),
                                    SDMMC1LP_POS    = pos_t(11),
                                    SPI1LP_POS      = pos_t(12),
                                    SPI4LP_POS      = pos_t(13),
                                    SYSCFGLP_POS    = pos_t(14),
                                    TIM9LP_POS      = pos_t(16),
                                    TIM10LP_POS     = pos_t(17),
                                    TIM11LP_POS     = pos_t(18),
                                    SPI5LP_POS      = pos_t(20),
                                    SPI6LP_POS      = pos_t(21),
                                    SAI1LP_POS      = pos_t(22),
                                    SAI2LP_POS      = pos_t(23),
                                    LTDCLP_POS      = pos_t(26),
                                    DFSDM1LP_POS    = pos_t(29),
                                    MDIOLP_POS      = pos_t(30);

        using            bits_t = Bits<uint32_t, Apb2lpenr>;
        static constexpr bits_t     TIM1LP          = bits_t(1, TIM1LP_POS  ),
                                    TIM8LP          = bits_t(1, TIM8LP_POS  ),
                                    USART1LP        = bits_t(1, USART1LP_POS),
                                    USART6LP        = bits_t(1, USART6LP_POS),
                                    SDMMC2LP        = bits_t(1, SDMMC2LP_POS),
                                    ADC1LP          = bits_t(1, ADC1LP_POS  ),
                                    ADC2LP          = bits_t(1, ADC2LP_POS  ),
                                    ADC3LP          = bits_t(1, ADC3LP_POS  ),
                                    SDMMC1LP        = bits_t(1, SDMMC1LP_POS),
                                    SPI1LP          = bits_t(1, SPI1LP_POS  ),
                                    SPI4LP          = bits_t(1, SPI4LP_POS  ),
                                    SYSCFGLP        = bits_t(1, SYSCFGLP_POS),
                                    TIM9LP          = bits_t(1, TIM9LP_POS  ),
                                    TIM10LP         = bits_t(1, TIM10LP_POS ),
                                    TIM11LP         = bits_t(1, TIM11LP_POS ),
                                    SPI5LP          = bits_t(1, SPI5LP_POS  ),
                                    SPI6LP          = bits_t(1, SPI6LP_POS  ),
                                    SAI1LP          = bits_t(1, SAI1LP_POS  ),
                                    SAI2LP          = bits_t(1, SAI2LP_POS  ),
                                    LTDCLP          = bits_t(1, LTDCLP_POS  ),
                                    DFSDM1LP        = bits_t(1, DFSDM1LP_POS),
                                    MDIOLP          = bits_t(1, MDIOLP_POS  );
    };  // struct Apb2lpenr
    using apb2lpenr_t = Reg<uint32_t, Apb2lpenr>;
          apb2lpenr_t   apb2lpenr;


    private: uint32_t   _reserved5[2];  public:


    struct Bdcr {
        using            pos_t = Pos<uint32_t, Bdcr>;
        static constexpr pos_t      LSEON_POS       = pos_t( 0),
                                    LSERDY_POS      = pos_t( 1),
                                    LSEBYP_POS      = pos_t( 2),
                                    LSEDRV_POS      = pos_t( 3),
                                    RTCSEL_POS      = pos_t( 8),
                                    RTC_POS         = pos_t(15),
                                    BD_POS          = pos_t(16);

        using            bits_t = Bits<uint32_t, Bdcr>;
        static constexpr bits_t     LSEON           = bits_t(1, LSEON_POS   ),
                                    LSERDY          = bits_t(1, LSERDY_POS  ),
                                    LSEBYP          = bits_t(1, LSEBYP_POS  ),
                                    RTC             = bits_t(1, RTC_POS     ),
                                    BD              = bits_t(1, BD_POS      );

        static const uint32_t   LSEDRV_MASK     = 0b11,
                                RTCSEL_MASK     = 0b11;

        using            mskd_t = Mskd<uint32_t, Bdcr>;
        static constexpr mskd_t
            LSEDRV_LOW   = mskd_t(LSEDRV_MASK, 0b00, LSEDRV_POS),
            LSEDRV_MEDHI = mskd_t(LSEDRV_MASK, 0b01, LSEDRV_POS),
            LSEDRV_MEDLO = mskd_t(LSEDRV_MASK, 0b10, LSEDRV_POS),
            LSEDRV_HIGH  = mskd_t(LSEDRV_MASK, 0b11, LSEDRV_POS),
            RTCSEL_NONE  = mskd_t(RTCSEL_MASK, 0b00, RTCSEL_POS),
            RTCSEL_LSE   = mskd_t(RTCSEL_MASK, 0b01, RTCSEL_POS),
            RTCSEL_LSI   = mskd_t(RTCSEL_MASK, 0b10, RTCSEL_POS),
            RTCSEL_HSE   = mskd_t(RTCSEL_MASK, 0b11, RTCSEL_POS);
    };  // struct Bdcr
    using bdcr_t = Reg<uint32_t, Bdcr>;
          bdcr_t   bdcr;


    struct Csr {
        using            pos_t = Pos<uint32_t, Csr>;
        static constexpr pos_t      LSION_POS       = pos_t( 0),
                                    LSIRDY_POS      = pos_t( 1),
                                    RMVF_POS        = pos_t(24),
                                    BORRSTF_POS     = pos_t(25),
                                    PINRSTF_POS     = pos_t(26),
                                    PORRSTF_POS     = pos_t(27),
                                    SFTRSTF_POS     = pos_t(28),
                                    IWDGRSTF_POS    = pos_t(29),
                                    WWDGRSTF_POS    = pos_t(30),
                                    LPWRRSTF_POS    = pos_t(31);

        using            bits_t = Bits<uint32_t, Csr>;
        static constexpr bits_t     LSION           = bits_t(1, LSION_POS   ),
                                    LSIRDY          = bits_t(1, LSIRDY_POS  ),
                                    RMVF            = bits_t(1, RMVF_POS    ),
                                    BORRSTF         = bits_t(1, BORRSTF_POS ),
                                    PINRSTF         = bits_t(1, PINRSTF_POS ),
                                    PORRSTF         = bits_t(1, PORRSTF_POS ),
                                    SFTRSTF         = bits_t(1, SFTRSTF_POS ),
                                    IWDGRSTF        = bits_t(1, IWDGRSTF_POS),
                                    WWDGRSTF        = bits_t(1, WWDGRSTF_POS),
                                    LPWRRSTF        = bits_t(1, LPWRRSTF_POS);
    };  // struct Csr
    using csr_t = Reg<uint32_t, Csr>;
          csr_t   csr;


    private: uint32_t   _reserved6[2];  public:


    struct Sscgr {
        using            pos_t = Pos<uint32_t, Sscgr>;
        static constexpr pos_t      MODPER_POS      = pos_t( 0),
                                    INCSTEP_POS     = pos_t(13),
                                    SPREADSEL_POS   = pos_t(30),
                                    SSCG_POS        = pos_t(31);

        using            bits_t = Bits<uint32_t, Sscgr>;
        static constexpr bits_t     SPREADSEL       = bits_t(1, SPREADSEL_POS),
                                    SSCG            = bits_t(1, SSCG_POS    );

        static const uint32_t   MODPER_MASK  = 0b000111111111111,
                                INCSTEP_MASK = 0b111111111111111;

        using        mskd_t = Mskd<uint32_t, Sscgr>;
        using        shft_t = Shft<uint32_t, Sscgr>;

        REGBITS_MSKD_RANGE("Rcc::Sscgr",
                           MODPER,
                           modper,
                           MODPER_MASK,
                           MODPER_POS,
                           MODPER_MASK);
        REGBITS_MSKD_RANGE("Rcc::Sscgr",
                           INCSTEP,
                           incstep,
                           INCSTEP_MASK,
                           INCSTEP_POS,
                           INCSTEP_MASK);
    };  // struct Sscgr
    using sscgr_t = Reg<uint32_t, Sscgr>;
          sscgr_t   sscgr;


    struct Plli2scfgr {
        using            pos_t = Pos<uint32_t, Plli2scfgr>;
        static constexpr pos_t      PLLI2SN_POS     = pos_t( 6),
                                    PLLI2SP_POS     = pos_t(16),
                                    PLLI2SQ_POS     = pos_t(24),
                                    PLLI2SR_POS     = pos_t(28);

        static const uint32_t       PLLI2SN_MASK = 0b111111111,
                                    PLLI2SP_MASK = 0b000000011,
                                    PLLI2SQ_MASK = 0b000001111,
                                    PLLI2SR_MASK = 0b000000111;
        static const uint32_t       PLLI2SN_MAX  = 432        ;

        using        mskd_t = Mskd<uint32_t, Plli2scfgr>;
        using        shft_t = Shft<uint32_t, Plli2scfgr>;

        REGBITS_MSKD_RANGE("Rcc::Plli2scfgr",
                           PLLI2SN,
                           plli2sn,
                           PLLI2SN_MASK,
                           PLLI2SN_POS,
                           PLLI2SN_MAX);

        static constexpr mskd_t
            PLLI2SP_2 = mskd_t(PLLI2SP_MASK, 0b00, PLLI2SP_POS),
            PLLI2SP_4 = mskd_t(PLLI2SP_MASK, 0b01, PLLI2SP_POS),
            PLLI2SP_6 = mskd_t(PLLI2SP_MASK, 0b10, PLLI2SP_POS),
            PLLI2SP_8 = mskd_t(PLLI2SP_MASK, 0b11, PLLI2SP_POS),
         // PLLI2SQ 0 and 1 illegal values
            PLLI2SQ_2 = mskd_t(PLLI2SQ_MASK,    2, PLLI2SQ_POS),
            PLLI2SQ_3 = mskd_t(PLLI2SQ_MASK,    3, PLLI2SQ_POS),
            PLLI2SQ_4 = mskd_t(PLLI2SQ_MASK,    4, PLLI2SQ_POS),
            PLLI2SQ_5 = mskd_t(PLLI2SQ_MASK,    5, PLLI2SQ_POS),
            PLLI2SQ_6 = mskd_t(PLLI2SQ_MASK,    6, PLLI2SQ_POS),
            PLLI2SQ_7 = mskd_t(PLLI2SQ_MASK,    7, PLLI2SQ_POS),
            PLLI2SQ_8 = mskd_t(PLLI2SQ_MASK,    8, PLLI2SQ_POS),
            PLLI2SQ_9 = mskd_t(PLLI2SQ_MASK,    9, PLLI2SQ_POS),
            PLLI2SQ_10 = mskd_t(PLLI2SQ_MASK,  10, PLLI2SQ_POS),
            PLLI2SQ_11 = mskd_t(PLLI2SQ_MASK,  11, PLLI2SQ_POS),
            PLLI2SQ_12 = mskd_t(PLLI2SQ_MASK,  12, PLLI2SQ_POS),
            PLLI2SQ_13 = mskd_t(PLLI2SQ_MASK,  13, PLLI2SQ_POS),
            PLLI2SQ_14 = mskd_t(PLLI2SQ_MASK,  14, PLLI2SQ_POS),
            PLLI2SQ_15 = mskd_t(PLLI2SQ_MASK,  15, PLLI2SQ_POS),
         // PLLI2SR 0 and 1 illegal values
            PLLI2SR_2 = mskd_t(PLLI2SR_MASK,    2, PLLI2SR_POS),
            PLLI2SR_3 = mskd_t(PLLI2SR_MASK,    3, PLLI2SR_POS),
            PLLI2SR_4 = mskd_t(PLLI2SR_MASK,    4, PLLI2SR_POS),
            PLLI2SR_5 = mskd_t(PLLI2SR_MASK,    5, PLLI2SR_POS),
            PLLI2SR_6 = mskd_t(PLLI2SR_MASK,    6, PLLI2SR_POS),
            PLLI2SR_7 = mskd_t(PLLI2SR_MASK,    7, PLLI2SR_POS);
    };  // struct Plli2scfgr
    using plli2scfgr_t = Reg<uint32_t, Plli2scfgr>;
          plli2scfgr_t   plli2scfgr;


    struct Pllsaicfgr {
        using            pos_t = Pos<uint32_t, Pllsaicfgr>;
        static constexpr pos_t      PLLSAIN_POS     = pos_t( 6),
                                    PLLSAIP_POS     = pos_t(16),
                                    PLLSAIQ_POS     = pos_t(24),
                                    PLLSAIR_POS     = pos_t(28);

        static const uint32_t       PLLSAIN_MASK = 0b111111111,
                                    PLLSAIP_MASK = 0b000000011,
                                    PLLSAIQ_MASK = 0b000001111,
                                    PLLSAIR_MASK = 0b000000111;
        static const uint32_t       PLLSAIN_MAX  = 432        ;

        using        mskd_t = Mskd<uint32_t, Pllsaicfgr>;
        using        shft_t = Shft<uint32_t, Pllsaicfgr>;

        REGBITS_MSKD_RANGE("Rcc::Pllsaicfgr",
                           PLLSAIN,
                           pllsain,
                           PLLSAIN_MASK,
                           PLLSAIN_POS,
                           PLLSAIN_MAX);

        static constexpr mskd_t
            PLLSAIP_2 = mskd_t(PLLSAIP_MASK, 0b00, PLLSAIP_POS),
            PLLSAIP_4 = mskd_t(PLLSAIP_MASK, 0b01, PLLSAIP_POS),
            PLLSAIP_6 = mskd_t(PLLSAIP_MASK, 0b10, PLLSAIP_POS),
            PLLSAIP_8 = mskd_t(PLLSAIP_MASK, 0b11, PLLSAIP_POS),
         // PLLSAIQ 0 and 1 illegal values
            PLLSAIQ_2 = mskd_t(PLLSAIQ_MASK,    2, PLLSAIQ_POS),
            PLLSAIQ_3 = mskd_t(PLLSAIQ_MASK,    3, PLLSAIQ_POS),
            PLLSAIQ_4 = mskd_t(PLLSAIQ_MASK,    4, PLLSAIQ_POS),
            PLLSAIQ_5 = mskd_t(PLLSAIQ_MASK,    5, PLLSAIQ_POS),
            PLLSAIQ_6 = mskd_t(PLLSAIQ_MASK,    6, PLLSAIQ_POS),
            PLLSAIQ_7 = mskd_t(PLLSAIQ_MASK,    7, PLLSAIQ_POS),
            PLLSAIQ_8 = mskd_t(PLLSAIQ_MASK,    8, PLLSAIQ_POS),
            PLLSAIQ_9 = mskd_t(PLLSAIQ_MASK,    9, PLLSAIQ_POS),
            PLLSAIQ_10 = mskd_t(PLLSAIQ_MASK,  10, PLLSAIQ_POS),
            PLLSAIQ_11 = mskd_t(PLLSAIQ_MASK,  11, PLLSAIQ_POS),
            PLLSAIQ_12 = mskd_t(PLLSAIQ_MASK,  12, PLLSAIQ_POS),
            PLLSAIQ_13 = mskd_t(PLLSAIQ_MASK,  13, PLLSAIQ_POS),
            PLLSAIQ_14 = mskd_t(PLLSAIQ_MASK,  14, PLLSAIQ_POS),
            PLLSAIQ_15 = mskd_t(PLLSAIQ_MASK,  15, PLLSAIQ_POS),
         // PLLSAIR 0 and 1 illegal values
            PLLSAIR_2 = mskd_t(PLLSAIR_MASK,    2, PLLSAIR_POS),
            PLLSAIR_3 = mskd_t(PLLSAIR_MASK,    3, PLLSAIR_POS),
            PLLSAIR_4 = mskd_t(PLLSAIR_MASK,    4, PLLSAIR_POS),
            PLLSAIR_5 = mskd_t(PLLSAIR_MASK,    5, PLLSAIR_POS),
            PLLSAIR_6 = mskd_t(PLLSAIR_MASK,    6, PLLSAIR_POS),
            PLLSAIR_7 = mskd_t(PLLSAIR_MASK,    7, PLLSAIR_POS);
    };  // struct Pllsaicfgr
    using pllsaicfgr_t = Reg<uint32_t, Pllsaicfgr>;
          pllsaicfgr_t   pllsaicfgr;


    struct Dckcfgr1 {
        using            pos_t = Pos<uint32_t, Dckcfgr1>;
        static constexpr pos_t      PLLI2SDIVQ_POS  = pos_t( 0),
                                    PLLSAIDIVQ_POS  = pos_t( 8),
                                    PLLSAIDIVR_POS  = pos_t(16),
                                    SAI1SEL_POS     = pos_t(20),
                                    SAI2SEL_POS     = pos_t(22),
                                    TIMPRE_POS      = pos_t(24),
                                    DFSDM1SEL_POS   = pos_t(25),
                                    ADFSDM1SEL_POS  = pos_t(26);

        using            bits_t = Bits<uint32_t, Dckcfgr1>;
        static constexpr bits_t     TIMPRE          = bits_t(1, TIMPRE_POS  ),
                                    DFSDM1SEL       = bits_t(1, DFSDM1SEL_POS),
                                    ADFSDM1SEL      = bits_t(1, ADFSDM1SEL_POS);


        static const uint32_t       PLLI2SDIVQ_MASK = 0b11111,
                                    PLLSAIDIVQ_MASK = 0b11111,
                                    PLLSAIDIVR_MASK = 0b00011,
                                    SAI1SEL_MASK    = 0b00011,
                                    SAI2SEL_MASK    = 0b00011;

        using        mskd_t = Mskd<uint32_t, Dckcfgr1>;
        using        shft_t = Shft<uint32_t, Dckcfgr1>;

        static constexpr mskd_t
            PLLSAIDIVR_2    = mskd_t(PLLSAIDIVR_MASK, 0b00, PLLSAIDIVR_POS),
            PLLSAIDIVR_4    = mskd_t(PLLSAIDIVR_MASK, 0b01, PLLSAIDIVR_POS),
            PLLSAIDIVR_8    = mskd_t(PLLSAIDIVR_MASK, 0b10, PLLSAIDIVR_POS),
            PLLSAIDIVR_16   = mskd_t(PLLSAIDIVR_MASK, 0b11, PLLSAIDIVR_POS),
            SAI1SEL_PLLSAI  = mskd_t(SAI1SEL_MASK,    0b00, SAI1SEL_POS   ),
            SAI1SEL_PLLI2S  = mskd_t(SAI1SEL_MASK,    0b01, SAI1SEL_POS   ),
            SAI1SEL_ALT     = mskd_t(SAI1SEL_MASK,    0b10, SAI1SEL_POS   ),
            SAI1SEL_HSI_HSE = mskd_t(SAI1SEL_MASK,    0b11, SAI1SEL_POS   ),
            SAI2SEL_PLLSAI  = mskd_t(SAI2SEL_MASK,    0b00, SAI2SEL_POS   ),
            SAI2SEL_PLLI2S  = mskd_t(SAI2SEL_MASK,    0b01, SAI2SEL_POS   ),
            SAI2SEL_ALT     = mskd_t(SAI2SEL_MASK,    0b10, SAI2SEL_POS   ),
            SAI2SEL_HSI_HSE = mskd_t(SAI2SEL_MASK,    0b11, SAI2SEL_POS   );

#if 0
        REGBITS_MSKD_RANGE("Rcc::Dckcfgr1",
                           PLLI2SDIV,
                           plli2sdiv,
                           PLLI2SDIVQ_MASK,
                           PLLI2SDIVQ_POS,
                           PLLI2SDIVQ_MASK);

        REGBITS_MSKD_RANGE("Rcc::Dckcfgr1",
                           PSLSAIDIVQ,
                           pslsaidivq,
                           PLLSAIDIVQ_MASK,
                           PLLSAIDIVQ_POS,
                           PLLSAIDIVQ_MASK);
#endif
    };  // struct Dckcfgr1
    using dckcfgr1_t = Reg<uint32_t, Dckcfgr1>;
          dckcfgr1_t   dckcfgr1;


    struct Dckcfgr2 {
        using            pos_t = Pos<uint32_t, Dckcfgr2>;
        static constexpr pos_t      USART1SEL_POS   = pos_t( 0),
                                    USART2SEL_POS   = pos_t( 2),
                                    USART3SEL_POS   = pos_t( 4),
                                    UART4SEL_POS    = pos_t( 6),
                                    UART5SEL_POS    = pos_t( 8),
                                    USART6SEL_POS   = pos_t(10),
                                    UART7SEL_POS    = pos_t(12),
                                    UART8SEL_POS    = pos_t(14),
                                    I2C1SEL_POS     = pos_t(16),
                                    I2C2SEL_POS     = pos_t(18),
                                    I2C3SEL_POS     = pos_t(20),
                                    I2C4SEL_POS     = pos_t(22),
                                    LPTIM1SEL_POS   = pos_t(24),
                                    CECSEL_POS      = pos_t(26),
                                    CK48MSEL_POS    = pos_t(27),
                                    SDMMC1SEL_POS   = pos_t(28),
                                    SDMMC2SEL_POS   = pos_t(29);

        using            bits_t = Bits<uint32_t, Dckcfgr2>;
        static constexpr bits_t     CECSEL          = bits_t(1, CECSEL_POS  ),
                                    CK48MSEL        = bits_t(1, CK48MSEL_POS),
                                    SDMMC1SEL       = bits_t(1, SDMMC1SEL_POS),
                                    SDMMC2SEL       = bits_t(1, SDMMC2SEL_POS);

        static const uint32_t       USART1SEL_MASK = 0b11,
                                    USART2SEL_MASK = 0b11,
                                    USART3SEL_MASK = 0b11,
                                    UART4SEL_MASK  = 0b11,
                                    UART5SEL_MASK  = 0b11,
                                    USART6SEL_MASK = 0b11,
                                    UART7SEL_MASK  = 0b11,
                                    UART8SEL_MASK  = 0b11,
                                    I2C1SEL_MASK   = 0b11,
                                    I2C2SEL_MASK   = 0b11,
                                    I2C3SEL_MASK   = 0b11,
                                    I2C4SEL_MASK   = 0b11,
                                    LPTIM1SEL_MASK = 0b11;

        using            mskd_t = Mskd<uint32_t, Dckcfgr2>;
        static constexpr mskd_t
            USART1SEL_APB1 = mskd_t(USART1SEL_MASK, 0b00, USART1SEL_POS),
            USART1SEL_SYS  = mskd_t(USART1SEL_MASK, 0b01, USART1SEL_POS),
            USART1SEL_HSI  = mskd_t(USART1SEL_MASK, 0b10, USART1SEL_POS),
            USART1SEL_LSE  = mskd_t(USART1SEL_MASK, 0b11, USART1SEL_POS),
            USART2SEL_APB1 = mskd_t(USART2SEL_MASK, 0b00, USART2SEL_POS),
            USART2SEL_SYS  = mskd_t(USART2SEL_MASK, 0b01, USART2SEL_POS),
            USART2SEL_HSI  = mskd_t(USART2SEL_MASK, 0b10, USART2SEL_POS),
            USART2SEL_LSE  = mskd_t(USART2SEL_MASK, 0b11, USART2SEL_POS),
            USART3SEL_APB1 = mskd_t(USART3SEL_MASK, 0b00, USART3SEL_POS),
            USART3SEL_SYS  = mskd_t(USART3SEL_MASK, 0b01, USART3SEL_POS),
            USART3SEL_HSI  = mskd_t(USART3SEL_MASK, 0b10, USART3SEL_POS),
            USART3SEL_LSE  = mskd_t(USART3SEL_MASK, 0b11, USART3SEL_POS),
            UART4SEL_APB1  = mskd_t(UART4SEL_MASK,  0b00, UART4SEL_POS ),
            UART4SEL_SYS   = mskd_t(UART4SEL_MASK,  0b01, UART4SEL_POS ),
            UART4SEL_HSI   = mskd_t(UART4SEL_MASK,  0b10, UART4SEL_POS ),
            UART4SEL_LSE   = mskd_t(UART4SEL_MASK,  0b11, UART4SEL_POS ),
            UART5SEL_APB1  = mskd_t(UART5SEL_MASK,  0b00, UART5SEL_POS ),
            UART5SEL_SYS   = mskd_t(UART5SEL_MASK,  0b01, UART5SEL_POS ),
            UART5SEL_HSI   = mskd_t(UART5SEL_MASK,  0b10, UART5SEL_POS ),
            UART5SEL_LSE   = mskd_t(UART5SEL_MASK,  0b11, UART5SEL_POS ),
            USART6SEL_APB1 = mskd_t(USART6SEL_MASK, 0b00, USART6SEL_POS),
            USART6SEL_SYS  = mskd_t(USART6SEL_MASK, 0b01, USART6SEL_POS),
            USART6SEL_HSI  = mskd_t(USART6SEL_MASK, 0b10, USART6SEL_POS),
            USART6SEL_LSE  = mskd_t(USART6SEL_MASK, 0b11, USART6SEL_POS),
            UART7SEL_APB1  = mskd_t(UART7SEL_MASK,  0b00, UART7SEL_POS ),
            UART7SEL_SYS   = mskd_t(UART7SEL_MASK,  0b01, UART7SEL_POS ),
            UART7SEL_HSI   = mskd_t(UART7SEL_MASK,  0b10, UART7SEL_POS ),
            UART7SEL_LSE   = mskd_t(UART7SEL_MASK,  0b11, UART7SEL_POS ),
            UART8SEL_APB1  = mskd_t(UART8SEL_MASK,  0b00, UART8SEL_POS ),
            UART8SEL_SYS   = mskd_t(UART8SEL_MASK,  0b01, UART8SEL_POS ),
            UART8SEL_HSI   = mskd_t(UART8SEL_MASK,  0b10, UART8SEL_POS ),
            UART8SEL_LSE   = mskd_t(UART8SEL_MASK,  0b11, UART8SEL_POS ),
            I2C1SEL_APB1   = mskd_t(I2C1SEL_MASK,   0b00, I2C1SEL_POS  ),
            I2C1SEL_SYS    = mskd_t(I2C1SEL_MASK,   0b01, I2C1SEL_POS  ),
            I2C1SEL_HSI    = mskd_t(I2C1SEL_MASK,   0b10, I2C1SEL_POS  ),
            I2C2SEL_APB1   = mskd_t(I2C2SEL_MASK,   0b00, I2C2SEL_POS  ),
            I2C2SEL_SYS    = mskd_t(I2C2SEL_MASK,   0b01, I2C2SEL_POS  ),
            I2C2SEL_HSI    = mskd_t(I2C2SEL_MASK,   0b10, I2C2SEL_POS  ),
            I2C3SEL_APB1   = mskd_t(I2C3SEL_MASK,   0b00, I2C3SEL_POS  ),
            I2C3SEL_SYS    = mskd_t(I2C3SEL_MASK,   0b01, I2C3SEL_POS  ),
            I2C3SEL_HSI    = mskd_t(I2C3SEL_MASK,   0b10, I2C3SEL_POS  ),
            I2C4SEL_APB1   = mskd_t(I2C4SEL_MASK,   0b00, I2C4SEL_POS  ),
            I2C4SEL_SYS    = mskd_t(I2C4SEL_MASK,   0b01, I2C4SEL_POS  ),
            I2C4SEL_HSI    = mskd_t(I2C4SEL_MASK,   0b10, I2C4SEL_POS  ),
            LPTIM1SEL_APB1 = mskd_t(LPTIM1SEL_MASK, 0b00, LPTIM1SEL_POS),
            LPTIM1SEL_SYS  = mskd_t(LPTIM1SEL_MASK, 0b01, LPTIM1SEL_POS),
            LPTIM1SEL_HSI  = mskd_t(LPTIM1SEL_MASK, 0b10, LPTIM1SEL_POS),
            LPTIM1SEL_LSE  = mskd_t(LPTIM1SEL_MASK, 0b11, LPTIM1SEL_POS);
    };  // struct Dckcfgr2
    using dckcfgr2_t = Reg<uint32_t, Dckcfgr2>;
          dckcfgr2_t   dckcfgr2;

};  // struct Rcc
static_assert(sizeof(Rcc) == 148, "sizeof(Rcc) != 148");



struct Gpio {
    struct Moder {
        using            pos_t = Pos<uint32_t, Moder>;
        static constexpr pos_t      POS_0  = pos_t( 0),
                                    POS_1  = pos_t( 2),
                                    POS_2  = pos_t( 4),
                                    POS_3  = pos_t( 6),
                                    POS_4  = pos_t( 8),
                                    POS_5  = pos_t(10),
                                    POS_6  = pos_t(12),
                                    POS_7  = pos_t(14),
                                    POS_8  = pos_t(16),
                                    POS_9  = pos_t(18),
                                    POS_10 = pos_t(20),
                                    POS_11 = pos_t(22),
                                    POS_12 = pos_t(24),
                                    POS_13 = pos_t(26),
                                    POS_14 = pos_t(28),
                                    POS_15 = pos_t(30);

        static const uint32_t       MASK    = 0x3,
                                    INPUT   = 0x0,
                                    OUTPUT  = 0x1,
                                    ALTFUNC = 0x2,
                                    ANALOG  = 0x3;

        using mskd_t = Mskd<uint32_t, Moder>;

        static constexpr mskd_t
                           INPUT_0 = mskd_t(MASK, INPUT ,  POS_0 ),
                          OUTPUT_0 = mskd_t(MASK, OUTPUT , POS_0 ),
                         ALTFUNC_0 = mskd_t(MASK, ALTFUNC, POS_0 ),
                          ANALOG_0 = mskd_t(MASK, ANALOG , POS_0 ),
                           INPUT_1 = mskd_t(MASK, INPUT ,  POS_1 ),
                          OUTPUT_1 = mskd_t(MASK, OUTPUT , POS_1 ),
                         ALTFUNC_1 = mskd_t(MASK, ALTFUNC, POS_1 ),
                          ANALOG_1 = mskd_t(MASK, ANALOG , POS_1 ),
                           INPUT_2 = mskd_t(MASK, INPUT ,  POS_2 ),
                          OUTPUT_2 = mskd_t(MASK, OUTPUT , POS_2 ),
                         ALTFUNC_2 = mskd_t(MASK, ALTFUNC, POS_2 ),
                          ANALOG_2 = mskd_t(MASK, ANALOG , POS_2 ),
                           INPUT_3 = mskd_t(MASK, INPUT ,  POS_3 ),
                          OUTPUT_3 = mskd_t(MASK, OUTPUT , POS_3 ),
                         ALTFUNC_3 = mskd_t(MASK, ALTFUNC, POS_3 ),
                          ANALOG_3 = mskd_t(MASK, ANALOG , POS_3 ),
                           INPUT_4 = mskd_t(MASK, INPUT ,  POS_4 ),
                          OUTPUT_4 = mskd_t(MASK, OUTPUT , POS_4 ),
                         ALTFUNC_4 = mskd_t(MASK, ALTFUNC, POS_4 ),
                          ANALOG_4 = mskd_t(MASK, ANALOG , POS_4 ),
                           INPUT_5 = mskd_t(MASK, INPUT ,  POS_5 ),
                          OUTPUT_5 = mskd_t(MASK, OUTPUT , POS_5 ),
                         ALTFUNC_5 = mskd_t(MASK, ALTFUNC, POS_5 ),
                          ANALOG_5 = mskd_t(MASK, ANALOG , POS_5 ),
                           INPUT_6 = mskd_t(MASK, INPUT ,  POS_6 ),
                          OUTPUT_6 = mskd_t(MASK, OUTPUT , POS_6 ),
                         ALTFUNC_6 = mskd_t(MASK, ALTFUNC, POS_6 ),
                          ANALOG_6 = mskd_t(MASK, ANALOG , POS_6 ),
                           INPUT_7 = mskd_t(MASK, INPUT ,  POS_7 ),
                          OUTPUT_7 = mskd_t(MASK, OUTPUT , POS_7 ),
                         ALTFUNC_7 = mskd_t(MASK, ALTFUNC, POS_7 ),
                          ANALOG_7 = mskd_t(MASK, ANALOG , POS_7 ),
                           INPUT_8 = mskd_t(MASK, INPUT ,  POS_8 ),
                          OUTPUT_8 = mskd_t(MASK, OUTPUT , POS_8 ),
                         ALTFUNC_8 = mskd_t(MASK, ALTFUNC, POS_8 ),
                          ANALOG_8 = mskd_t(MASK, ANALOG , POS_8 ),
                           INPUT_9 = mskd_t(MASK, INPUT ,  POS_9 ),
                          OUTPUT_9 = mskd_t(MASK, OUTPUT , POS_9 ),
                         ALTFUNC_9 = mskd_t(MASK, ALTFUNC, POS_9 ),
                          ANALOG_9 = mskd_t(MASK, ANALOG , POS_9 ),
                          INPUT_10 = mskd_t(MASK, INPUT ,  POS_10),
                         OUTPUT_10 = mskd_t(MASK, OUTPUT , POS_10),
                        ALTFUNC_10 = mskd_t(MASK, ALTFUNC, POS_10),
                         ANALOG_10 = mskd_t(MASK, ANALOG , POS_10),
                          INPUT_11 = mskd_t(MASK, INPUT ,  POS_11),
                         OUTPUT_11 = mskd_t(MASK, OUTPUT , POS_11),
                        ALTFUNC_11 = mskd_t(MASK, ALTFUNC, POS_11),
                         ANALOG_11 = mskd_t(MASK, ANALOG , POS_11),
                          INPUT_12 = mskd_t(MASK, INPUT ,  POS_12),
                         OUTPUT_12 = mskd_t(MASK, OUTPUT , POS_12),
                        ALTFUNC_12 = mskd_t(MASK, ALTFUNC, POS_12),
                         ANALOG_12 = mskd_t(MASK, ANALOG , POS_12),
                          INPUT_13 = mskd_t(MASK, INPUT ,  POS_13),
                         OUTPUT_13 = mskd_t(MASK, OUTPUT , POS_13),
                        ALTFUNC_13 = mskd_t(MASK, ALTFUNC, POS_13),
                         ANALOG_13 = mskd_t(MASK, ANALOG , POS_13),
                          INPUT_14 = mskd_t(MASK, INPUT ,  POS_14),
                         OUTPUT_14 = mskd_t(MASK, OUTPUT , POS_14),
                        ALTFUNC_14 = mskd_t(MASK, ALTFUNC, POS_14),
                         ANALOG_14 = mskd_t(MASK, ANALOG , POS_14),
                          INPUT_15 = mskd_t(MASK, INPUT ,  POS_15),
                         OUTPUT_15 = mskd_t(MASK, OUTPUT , POS_15),
                        ALTFUNC_15 = mskd_t(MASK, ALTFUNC, POS_15),
                         ANALOG_15 = mskd_t(MASK, ANALOG , POS_15);
    };  // struct Moder
    using moder_t = Reg<uint32_t, Moder>;
          moder_t   moder;


    struct Otyper {
        using            pos_t = Pos<uint32_t, Otyper>;
        static constexpr pos_t      POS_0  = pos_t( 0),
                                    POS_1  = pos_t( 1),
                                    POS_2  = pos_t( 2),
                                    POS_3  = pos_t( 3),
                                    POS_4  = pos_t( 4),
                                    POS_5  = pos_t( 5),
                                    POS_6  = pos_t( 6),
                                    POS_7  = pos_t( 7),
                                    POS_8  = pos_t( 8),
                                    POS_9  = pos_t( 9),
                                    POS_10 = pos_t(10),
                                    POS_11 = pos_t(11),
                                    POS_12 = pos_t(12),
                                    POS_13 = pos_t(13),
                                    POS_14 = pos_t(14),
                                    POS_15 = pos_t(15);

        using            bits_t = Bits<uint32_t, Otyper>;
        static constexpr bits_t     OPEN_DRAIN_0  = bits_t(1, POS_0     ),
                                    OPEN_DRAIN_1  = bits_t(1, POS_1     ),
                                    OPEN_DRAIN_2  = bits_t(1, POS_2     ),
                                    OPEN_DRAIN_3  = bits_t(1, POS_3     ),
                                    OPEN_DRAIN_4  = bits_t(1, POS_4     ),
                                    OPEN_DRAIN_5  = bits_t(1, POS_5     ),
                                    OPEN_DRAIN_6  = bits_t(1, POS_6     ),
                                    OPEN_DRAIN_7  = bits_t(1, POS_7     ),
                                    OPEN_DRAIN_8  = bits_t(1, POS_8     ),
                                    OPEN_DRAIN_9  = bits_t(1, POS_9     ),
                                    OPEN_DRAIN_10 = bits_t(1, POS_10    ),
                                    OPEN_DRAIN_11 = bits_t(1, POS_11    ),
                                    OPEN_DRAIN_12 = bits_t(1, POS_12    ),
                                    OPEN_DRAIN_13 = bits_t(1, POS_13    ),
                                    OPEN_DRAIN_14 = bits_t(1, POS_14    ),
                                    OPEN_DRAIN_15 = bits_t(1, POS_15    );

        using            mskd_t = Mskd<uint32_t, Otyper>;
        static constexpr mskd_t     PUSH_PULL_0   = mskd_t(1, 0, POS_0 ),
                                    PUSH_PULL_1   = mskd_t(1, 0, POS_1 ),
                                    PUSH_PULL_2   = mskd_t(1, 0, POS_2 ),
                                    PUSH_PULL_3   = mskd_t(1, 0, POS_3 ),
                                    PUSH_PULL_4   = mskd_t(1, 0, POS_4 ),
                                    PUSH_PULL_5   = mskd_t(1, 0, POS_5 ),
                                    PUSH_PULL_6   = mskd_t(1, 0, POS_6 ),
                                    PUSH_PULL_7   = mskd_t(1, 0, POS_7 ),
                                    PUSH_PULL_8   = mskd_t(1, 0, POS_8 ),
                                    PUSH_PULL_9   = mskd_t(1, 0, POS_9 ),
                                    PUSH_PULL_10  = mskd_t(1, 0, POS_10),
                                    PUSH_PULL_11  = mskd_t(1, 0, POS_11),
                                    PUSH_PULL_12  = mskd_t(1, 0, POS_12),
                                    PUSH_PULL_13  = mskd_t(1, 0, POS_13),
                                    PUSH_PULL_14  = mskd_t(1, 0, POS_14),
                                    PUSH_PULL_15  = mskd_t(1, 0, POS_15);

        REGBITS_BITS_RANGE("Gpio::Otyper",
                           PORT,
                           port,
                           uint32_t);
    };  // struct Otyper
    using otyper_t = Reg<uint32_t, Otyper>;
          otyper_t   otyper;


    struct Ospeedr {
        using            pos_t = Pos<uint32_t, Ospeedr>;
        static constexpr pos_t      POS_0  = pos_t( 0),
                                    POS_1  = pos_t( 2),
                                    POS_2  = pos_t( 4),
                                    POS_3  = pos_t( 6),
                                    POS_4  = pos_t( 8),
                                    POS_5  = pos_t(10),
                                    POS_6  = pos_t(12),
                                    POS_7  = pos_t(14),
                                    POS_8  = pos_t(16),
                                    POS_9  = pos_t(18),
                                    POS_10 = pos_t(20),
                                    POS_11 = pos_t(22),
                                    POS_12 = pos_t(24),
                                    POS_13 = pos_t(26),
                                    POS_14 = pos_t(28),
                                    POS_15 = pos_t(30);

        static const uint32_t       MASK    = 0x3,
                                    LOW     = 0x0,
                                    MEDIUM  = 0x1,
                                    HIGH    = 0x2,
                                    EXTREME = 0x3;

        using            mskd_t = Mskd<uint32_t, Ospeedr>;
        static constexpr mskd_t
                   LOW_0 = mskd_t(MASK, LOW  , POS_0 ),
                MEDIUM_0 = mskd_t(MASK, MEDIUM , POS_0 ),
                  HIGH_0 = mskd_t(MASK, HIGH     , POS_0 ),
               EXTREME_0 = mskd_t(MASK, EXTREME, POS_0 ),
                   LOW_1 = mskd_t(MASK, LOW  , POS_1 ),
                MEDIUM_1 = mskd_t(MASK, MEDIUM , POS_1 ),
                  HIGH_1 = mskd_t(MASK, HIGH     , POS_1 ),
               EXTREME_1 = mskd_t(MASK, EXTREME, POS_1 ),
                   LOW_2 = mskd_t(MASK, LOW  , POS_2 ),
                MEDIUM_2 = mskd_t(MASK, MEDIUM , POS_2 ),
                  HIGH_2 = mskd_t(MASK, HIGH     , POS_2 ),
               EXTREME_2 = mskd_t(MASK, EXTREME, POS_2 ),
                   LOW_3 = mskd_t(MASK, LOW  , POS_3 ),
                MEDIUM_3 = mskd_t(MASK, MEDIUM , POS_3 ),
                  HIGH_3 = mskd_t(MASK, HIGH     , POS_3 ),
               EXTREME_3 = mskd_t(MASK, EXTREME, POS_3 ),
                   LOW_4 = mskd_t(MASK, LOW  , POS_4 ),
                MEDIUM_4 = mskd_t(MASK, MEDIUM , POS_4 ),
                  HIGH_4 = mskd_t(MASK, HIGH     , POS_4 ),
               EXTREME_4 = mskd_t(MASK, EXTREME, POS_4 ),
                   LOW_5 = mskd_t(MASK, LOW  , POS_5 ),
                MEDIUM_5 = mskd_t(MASK, MEDIUM , POS_5 ),
                  HIGH_5 = mskd_t(MASK, HIGH     , POS_5 ),
               EXTREME_5 = mskd_t(MASK, EXTREME, POS_5 ),
                   LOW_6 = mskd_t(MASK, LOW  , POS_6 ),
                MEDIUM_6 = mskd_t(MASK, MEDIUM , POS_6 ),
                  HIGH_6 = mskd_t(MASK, HIGH     , POS_6 ),
               EXTREME_6 = mskd_t(MASK, EXTREME, POS_6 ),
                   LOW_7 = mskd_t(MASK, LOW  , POS_7 ),
                MEDIUM_7 = mskd_t(MASK, MEDIUM , POS_7 ),
                  HIGH_7 = mskd_t(MASK, HIGH     , POS_7 ),
               EXTREME_7 = mskd_t(MASK, EXTREME, POS_7 ),
                   LOW_8 = mskd_t(MASK, LOW  , POS_8 ),
                MEDIUM_8 = mskd_t(MASK, MEDIUM , POS_8 ),
                  HIGH_8 = mskd_t(MASK, HIGH     , POS_8 ),
               EXTREME_8 = mskd_t(MASK, EXTREME, POS_8 ),
                   LOW_9 = mskd_t(MASK, LOW  , POS_9 ),
                MEDIUM_9 = mskd_t(MASK, MEDIUM , POS_9 ),
                  HIGH_9 = mskd_t(MASK, HIGH     , POS_9 ),
               EXTREME_9 = mskd_t(MASK, EXTREME, POS_9 ),
                  LOW_10 = mskd_t(MASK, LOW  , POS_10),
               MEDIUM_10 = mskd_t(MASK, MEDIUM , POS_10),
                 HIGH_10 = mskd_t(MASK, HIGH     , POS_10),
              EXTREME_10 = mskd_t(MASK, EXTREME, POS_10),
                  LOW_11 = mskd_t(MASK, LOW  , POS_11),
               MEDIUM_11 = mskd_t(MASK, MEDIUM , POS_11),
                 HIGH_11 = mskd_t(MASK, HIGH     , POS_11),
              EXTREME_11 = mskd_t(MASK, EXTREME, POS_11),
                  LOW_12 = mskd_t(MASK, LOW  , POS_12),
               MEDIUM_12 = mskd_t(MASK, MEDIUM , POS_12),
                 HIGH_12 = mskd_t(MASK, HIGH     , POS_12),
              EXTREME_12 = mskd_t(MASK, EXTREME, POS_12),
                  LOW_13 = mskd_t(MASK, LOW  , POS_13),
               MEDIUM_13 = mskd_t(MASK, MEDIUM , POS_13),
                 HIGH_13 = mskd_t(MASK, HIGH     , POS_13),
              EXTREME_13 = mskd_t(MASK, EXTREME, POS_13),
                  LOW_14 = mskd_t(MASK, LOW  , POS_14),
               MEDIUM_14 = mskd_t(MASK, MEDIUM , POS_14),
                 HIGH_14 = mskd_t(MASK, HIGH     , POS_14),
              EXTREME_14 = mskd_t(MASK, EXTREME, POS_14),
                  LOW_15 = mskd_t(MASK, LOW  , POS_15),
               MEDIUM_15 = mskd_t(MASK, MEDIUM , POS_15),
                 HIGH_15 = mskd_t(MASK, HIGH     , POS_15),
              EXTREME_15 = mskd_t(MASK, EXTREME, POS_15);
    };  // struct Ospeedr
    using ospeedr_t = Reg<uint32_t, Ospeedr>;
          ospeedr_t   ospeedr;


    struct Pupdr {
        using            pos_t = Pos<uint32_t, Pupdr>;
        static constexpr pos_t
              PUPDR0_POS = pos_t( 0),
              PUPDR1_POS = pos_t( 2),
              PUPDR2_POS = pos_t( 4),
              PUPDR3_POS = pos_t( 6),
              PUPDR4_POS = pos_t( 8),
              PUPDR5_POS = pos_t(10),
              PUPDR6_POS = pos_t(12),
              PUPDR7_POS = pos_t(14),
              PUPDR8_POS = pos_t(16),
              PUPDR9_POS = pos_t(18),
             PUPDR10_POS = pos_t(20),
             PUPDR11_POS = pos_t(22),
             PUPDR12_POS = pos_t(24),
             PUPDR13_POS = pos_t(26),
             PUPDR14_POS = pos_t(28),
             PUPDR15_POS = pos_t(30);

        static const uint32_t
                 PUPDR0_MASK =       0x3U,
                 PUPDR1_MASK =       0x3U,
                 PUPDR2_MASK =       0x3U,
                 PUPDR3_MASK =       0x3U,
                 PUPDR4_MASK =       0x3U,
                 PUPDR5_MASK =       0x3U,
                 PUPDR6_MASK =       0x3U,
                 PUPDR7_MASK =       0x3U,
                 PUPDR8_MASK =       0x3U,
                 PUPDR9_MASK =       0x3U,
                PUPDR10_MASK =       0x3U,
                PUPDR11_MASK =       0x3U,
                PUPDR12_MASK =       0x3U,
                PUPDR13_MASK =       0x3U,
                PUPDR14_MASK =       0x3U,
                PUPDR15_MASK =       0x3U;

        using            mskd_t = Mskd<uint32_t, Pupdr>;
        static constexpr mskd_t
        PUPDR0_PULL_NONE     = mskd_t(PUPDR0_MASK,  0b00,  PUPDR0_POS),
        PUPDR0_PULL_UP       = mskd_t(PUPDR0_MASK,  0b01,  PUPDR0_POS),
        PUPDR0_PULL_DOWN     = mskd_t(PUPDR0_MASK,  0b10,  PUPDR0_POS),
        PUPDR1_PULL_NONE     = mskd_t(PUPDR1_MASK,  0b00,  PUPDR1_POS),
        PUPDR1_PULL_UP       = mskd_t(PUPDR1_MASK,  0b01,  PUPDR1_POS),
        PUPDR1_PULL_DOWN     = mskd_t(PUPDR1_MASK,  0b10,  PUPDR1_POS),
        PUPDR2_PULL_NONE     = mskd_t(PUPDR2_MASK,  0b00,  PUPDR2_POS),
        PUPDR2_PULL_UP       = mskd_t(PUPDR2_MASK,  0b01,  PUPDR2_POS),
        PUPDR2_PULL_DOWN     = mskd_t(PUPDR2_MASK,  0b10,  PUPDR2_POS),
        PUPDR3_PULL_NONE     = mskd_t(PUPDR3_MASK,  0b00,  PUPDR3_POS),
        PUPDR3_PULL_UP       = mskd_t(PUPDR3_MASK,  0b01,  PUPDR3_POS),
        PUPDR3_PULL_DOWN     = mskd_t(PUPDR3_MASK,  0b10,  PUPDR3_POS),
        PUPDR4_PULL_NONE     = mskd_t(PUPDR4_MASK,  0b00,  PUPDR4_POS),
        PUPDR4_PULL_UP       = mskd_t(PUPDR4_MASK,  0b01,  PUPDR4_POS),
        PUPDR4_PULL_DOWN     = mskd_t(PUPDR4_MASK,  0b10,  PUPDR4_POS),
        PUPDR5_PULL_NONE     = mskd_t(PUPDR5_MASK,  0b00,  PUPDR5_POS),
        PUPDR5_PULL_UP       = mskd_t(PUPDR5_MASK,  0b01,  PUPDR5_POS),
        PUPDR5_PULL_DOWN     = mskd_t(PUPDR5_MASK,  0b10,  PUPDR5_POS),
        PUPDR6_PULL_NONE     = mskd_t(PUPDR6_MASK,  0b00,  PUPDR6_POS),
        PUPDR6_PULL_UP       = mskd_t(PUPDR6_MASK,  0b01,  PUPDR6_POS),
        PUPDR6_PULL_DOWN     = mskd_t(PUPDR6_MASK,  0b10,  PUPDR6_POS),
        PUPDR7_PULL_NONE     = mskd_t(PUPDR7_MASK,  0b00,  PUPDR7_POS),
        PUPDR7_PULL_UP       = mskd_t(PUPDR7_MASK,  0b01,  PUPDR7_POS),
        PUPDR7_PULL_DOWN     = mskd_t(PUPDR7_MASK,  0b10,  PUPDR7_POS),
        PUPDR8_PULL_NONE     = mskd_t(PUPDR8_MASK,  0b00,  PUPDR8_POS),
        PUPDR8_PULL_UP       = mskd_t(PUPDR8_MASK,  0b01,  PUPDR8_POS),
        PUPDR8_PULL_DOWN     = mskd_t(PUPDR8_MASK,  0b10,  PUPDR8_POS),
        PUPDR9_PULL_NONE     = mskd_t(PUPDR9_MASK,  0b00,  PUPDR9_POS),
        PUPDR9_PULL_UP       = mskd_t(PUPDR9_MASK,  0b01,  PUPDR9_POS),
        PUPDR9_PULL_DOWN     = mskd_t(PUPDR9_MASK,  0b10,  PUPDR9_POS),
        PUPDR10_PULL_NONE    = mskd_t(PUPDR10_MASK, 0b00, PUPDR10_POS),
        PUPDR10_PULL_UP      = mskd_t(PUPDR10_MASK, 0b01, PUPDR10_POS),
        PUPDR10_PULL_DOWN    = mskd_t(PUPDR10_MASK, 0b10, PUPDR10_POS),
        PUPDR11_PULL_NONE    = mskd_t(PUPDR11_MASK, 0b00, PUPDR11_POS),
        PUPDR11_PULL_UP      = mskd_t(PUPDR11_MASK, 0b01, PUPDR11_POS),
        PUPDR11_PULL_DOWN    = mskd_t(PUPDR11_MASK, 0b10, PUPDR11_POS),
        PUPDR12_PULL_NONE    = mskd_t(PUPDR12_MASK, 0b00, PUPDR12_POS),
        PUPDR12_PULL_UP      = mskd_t(PUPDR12_MASK, 0b01, PUPDR12_POS),
        PUPDR12_PULL_DOWN    = mskd_t(PUPDR12_MASK, 0b10, PUPDR12_POS),
        PUPDR13_PULL_NONE    = mskd_t(PUPDR13_MASK, 0b00, PUPDR13_POS),
        PUPDR13_PULL_UP      = mskd_t(PUPDR13_MASK, 0b01, PUPDR13_POS),
        PUPDR13_PULL_DOWN    = mskd_t(PUPDR13_MASK, 0b10, PUPDR13_POS),
        PUPDR14_PULL_NONE    = mskd_t(PUPDR14_MASK, 0b00, PUPDR14_POS),
        PUPDR14_PULL_UP      = mskd_t(PUPDR14_MASK, 0b01, PUPDR14_POS),
        PUPDR14_PULL_DOWN    = mskd_t(PUPDR14_MASK, 0b10, PUPDR14_POS),
        PUPDR15_PULL_NONE    = mskd_t(PUPDR15_MASK, 0b00, PUPDR15_POS),
        PUPDR15_PULL_UP      = mskd_t(PUPDR15_MASK, 0b01, PUPDR15_POS),
        PUPDR15_PULL_DOWN    = mskd_t(PUPDR15_MASK, 0b10, PUPDR15_POS);
    };  // struct Pupdr
    using pupdr_t = Reg<uint32_t, Pupdr>;
          pupdr_t   pupdr;


    struct Idr {
        using            pos_t = Pos<uint32_t, Idr>;
        static constexpr pos_t
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

        using            bits_t = Bits<uint32_t, Idr>;
        static constexpr bits_t
           IDR0 = bits_t(1,   IDR0_POS),
           IDR1 = bits_t(1,   IDR1_POS),
           IDR2 = bits_t(1,   IDR2_POS),
           IDR3 = bits_t(1,   IDR3_POS),
           IDR4 = bits_t(1,   IDR4_POS),
           IDR5 = bits_t(1,   IDR5_POS),
           IDR6 = bits_t(1,   IDR6_POS),
           IDR7 = bits_t(1,   IDR7_POS),
           IDR8 = bits_t(1,   IDR8_POS),
           IDR9 = bits_t(1,   IDR9_POS),
          IDR10 = bits_t(1,  IDR10_POS),
          IDR11 = bits_t(1,  IDR11_POS),
          IDR12 = bits_t(1,  IDR12_POS),
          IDR13 = bits_t(1,  IDR13_POS),
          IDR14 = bits_t(1,  IDR14_POS),
          IDR15 = bits_t(1,  IDR15_POS);

        REGBITS_BITS_RANGE("Gpio::Idr",
                           PORT,
                           port,
                           uint32_t);
    };  // struct Idr
    using idr_t = Reg<uint32_t, Idr>;
          idr_t   idr;


    struct Odr {
        using            pos_t = Pos<uint32_t, Odr>;
        static constexpr pos_t
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

        using            bits_t = Bits<uint32_t, Odr>;
        static constexpr bits_t
           ODR0 = bits_t(1,   ODR0_POS),
           ODR1 = bits_t(1,   ODR1_POS),
           ODR2 = bits_t(1,   ODR2_POS),
           ODR3 = bits_t(1,   ODR3_POS),
           ODR4 = bits_t(1,   ODR4_POS),
           ODR5 = bits_t(1,   ODR5_POS),
           ODR6 = bits_t(1,   ODR6_POS),
           ODR7 = bits_t(1,   ODR7_POS),
           ODR8 = bits_t(1,   ODR8_POS),
           ODR9 = bits_t(1,   ODR9_POS),
          ODR10 = bits_t(1,  ODR10_POS),
          ODR11 = bits_t(1,  ODR11_POS),
          ODR12 = bits_t(1,  ODR12_POS),
          ODR13 = bits_t(1,  ODR13_POS),
          ODR14 = bits_t(1,  ODR14_POS),
          ODR15 = bits_t(1,  ODR15_POS);

        REGBITS_BITS_RANGE("Gpio::Odr",
                           PORT,
                           port,
                           uint32_t);
    };  // struct Odr
    using odr_t = Reg<uint32_t, Odr>;
          odr_t   odr;


    struct Bsrr {
        using            pos_t = Pos<uint32_t, Bsrr>;
        static constexpr pos_t
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

        using            bits_t = Bits<uint32_t, Bsrr>;
        static constexpr bits_t
           BS0 = bits_t(1,   BS0_POS),
           BS1 = bits_t(1,   BS1_POS),
           BS2 = bits_t(1,   BS2_POS),
           BS3 = bits_t(1,   BS3_POS),
           BS4 = bits_t(1,   BS4_POS),
           BS5 = bits_t(1,   BS5_POS),
           BS6 = bits_t(1,   BS6_POS),
           BS7 = bits_t(1,   BS7_POS),
           BS8 = bits_t(1,   BS8_POS),
           BS9 = bits_t(1,   BS9_POS),
          BS10 = bits_t(1,  BS10_POS),
          BS11 = bits_t(1,  BS11_POS),
          BS12 = bits_t(1,  BS12_POS),
          BS13 = bits_t(1,  BS13_POS),
          BS14 = bits_t(1,  BS14_POS),
          BS15 = bits_t(1,  BS15_POS),
           BR0 = bits_t(1,   BR0_POS),
           BR1 = bits_t(1,   BR1_POS),
           BR2 = bits_t(1,   BR2_POS),
           BR3 = bits_t(1,   BR3_POS),
           BR4 = bits_t(1,   BR4_POS),
           BR5 = bits_t(1,   BR5_POS),
           BR6 = bits_t(1,   BR6_POS),
           BR7 = bits_t(1,   BR7_POS),
           BR8 = bits_t(1,   BR8_POS),
           BR9 = bits_t(1,   BR9_POS),
          BR10 = bits_t(1,  BR10_POS),
          BR11 = bits_t(1,  BR11_POS),
          BR12 = bits_t(1,  BR12_POS),
          BR13 = bits_t(1,  BR13_POS),
          BR14 = bits_t(1,  BR14_POS),
          BR15 = bits_t(1,  BR15_POS);
    };  // struct Bsrr
    using bsrr_t = Reg<uint32_t, Bsrr>;
          bsrr_t   bsrr;


    struct Lckr {
        using            pos_t = Pos<uint32_t, Lckr>;
        static constexpr pos_t
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
          LCK15_POS = pos_t(15);

        using            bits_t = Bits<uint32_t, Lckr>;
        static constexpr bits_t
           LCK0 = bits_t(1,   LCK0_POS),
           LCK1 = bits_t(1,   LCK1_POS),
           LCK2 = bits_t(1,   LCK2_POS),
           LCK3 = bits_t(1,   LCK3_POS),
           LCK4 = bits_t(1,   LCK4_POS),
           LCK5 = bits_t(1,   LCK5_POS),
           LCK6 = bits_t(1,   LCK6_POS),
           LCK7 = bits_t(1,   LCK7_POS),
           LCK8 = bits_t(1,   LCK8_POS),
           LCK9 = bits_t(1,   LCK9_POS),
          LCK10 = bits_t(1,  LCK10_POS),
          LCK11 = bits_t(1,  LCK11_POS),
          LCK12 = bits_t(1,  LCK12_POS),
          LCK13 = bits_t(1,  LCK13_POS),
          LCK14 = bits_t(1,  LCK14_POS),
          LCK15 = bits_t(1,  LCK15_POS);

        REGBITS_BITS_RANGE("Gpio::Lckr",
                           PORT,
                           port,
                           uint32_t);
    };  // struct Lckr
    using lckr_t = Reg<uint32_t, Lckr>;
          lckr_t   lckr;

    struct Afrl {
        using            pos_t = Pos<uint32_t, Afrl>;
        static constexpr pos_t
           AFRL0_POS = pos_t( 0),
           AFRL1_POS = pos_t( 4),
           AFRL2_POS = pos_t( 8),
           AFRL3_POS = pos_t(12),
           AFRL4_POS = pos_t(16),
           AFRL5_POS = pos_t(20),
           AFRL6_POS = pos_t(24),
           AFRL7_POS = pos_t(28);

        static const uint32_t
              AFRL0_MASK =       0xFU,
              AFRL1_MASK =       0xFU,
              AFRL2_MASK =       0xFU,
              AFRL3_MASK =       0xFU,
              AFRL4_MASK =       0xFU,
              AFRL5_MASK =       0xFU,
              AFRL6_MASK =       0xFU,
              AFRL7_MASK =       0xFU;

        static const uint32_t   AF0  =  0,
                                AF1  =  1,
                                AF2  =  2,
                                AF3  =  3,
                                AF4  =  4,
                                AF5  =  5,
                                AF6  =  6,
                                AF7  =  7,
                                AF8  =  8,
                                AF9  =  9,
                                AF10 = 10,
                                AF11 = 11,
                                AF12 = 12,
                                AF13 = 13,
                                AF14 = 14,
                                AF15 = 15;

        using            mskd_t = Mskd<uint32_t, Afrl>;
        using            shft_t = Shft<uint32_t, Afrl>;

        REGBITS_MSKD_RANGE("Gpio::Afrl0",
                           AFRL0,
                           afrl0,
                           AFRL0_MASK,
                           AFRL0_POS,
                           AFRL0_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl1",
                           AFRL1,
                           afrl1,
                           AFRL1_MASK,
                           AFRL1_POS,
                           AFRL1_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl2",
                           AFRL2,
                           afrl2,
                           AFRL2_MASK,
                           AFRL2_POS,
                           AFRL2_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl3",
                           AFRL3,
                           afrl3,
                           AFRL3_MASK,
                           AFRL3_POS,
                           AFRL3_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl4",
                           AFRL4,
                           afrl4,
                           AFRL4_MASK,
                           AFRL4_POS,
                           AFRL4_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl5",
                           AFRL5,
                           afrl5,
                           AFRL5_MASK,
                           AFRL5_POS,
                           AFRL5_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl6",
                           AFRL6,
                           afrl6,
                           AFRL6_MASK,
                           AFRL6_POS,
                           AFRL6_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrl7",
                           AFRL7,
                           afrl7,
                           AFRL7_MASK,
                           AFRL7_POS,
                           AFRL7_MASK);
    };  // struct Afrl
    using afrl_t = Reg<uint32_t, Afrl>;
          afrl_t   afrl;


    struct Afrh {
        using            pos_t = Pos<uint32_t, Afrh>;
        static constexpr pos_t
            AFRH8_POS = pos_t( 0),
            AFRH9_POS = pos_t( 4),
           AFRH10_POS = pos_t( 8),
           AFRH11_POS = pos_t(12),
           AFRH12_POS = pos_t(16),
           AFRH13_POS = pos_t(20),
           AFRH14_POS = pos_t(24),
           AFRH15_POS = pos_t(28);

        static const uint32_t
              AFRH8_MASK =       0xFU,
              AFRH9_MASK =       0xFU,
              AFRH10_MASK =      0xFU,
              AFRH11_MASK =      0xFU,
              AFRH12_MASK =      0xFU,
              AFRH13_MASK =      0xFU,
              AFRH14_MASK =      0xFU,
              AFRH15_MASK =      0xFU;

        static const uint32_t   AF0  =  0,
                                AF1  =  1,
                                AF2  =  2,
                                AF3  =  3,
                                AF4  =  4,
                                AF5  =  5,
                                AF6  =  6,
                                AF7  =  7,
                                AF8  =  8,
                                AF9  =  9,
                                AF10 = 10,
                                AF11 = 11,
                                AF12 = 12,
                                AF13 = 13,
                                AF14 = 14,
                                AF15 = 15;

        using            mskd_t = Mskd<uint32_t, Afrh>;
        using            shft_t = Shft<uint32_t, Afrh>;

        REGBITS_MSKD_RANGE("Gpio::Afrh8",
                           AFRH8,
                           afrh8,
                           AFRH8_MASK,
                           AFRH8_POS,
                           AFRH8_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh9",
                           AFRH9,
                           afrh9,
                           AFRH9_MASK,
                           AFRH9_POS,
                           AFRH9_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh10",
                           AFRH10,
                           afrh10,
                           AFRH10_MASK,
                           AFRH10_POS,
                           AFRH10_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh11",
                           AFRH11,
                           afrh11,
                           AFRH11_MASK,
                           AFRH11_POS,
                           AFRH11_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh12",
                           AFRH12,
                           afrh12,
                           AFRH12_MASK,
                           AFRH12_POS,
                           AFRH12_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh13",
                           AFRH13,
                           afrh13,
                           AFRH13_MASK,
                           AFRH13_POS,
                           AFRH13_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh14",
                           AFRH14,
                           afrh14,
                           AFRH14_MASK,
                           AFRH14_POS,
                           AFRH14_MASK);
        REGBITS_MSKD_RANGE("Gpio::Afrh15",
                           AFRH15,
                           afrh15,
                           AFRH15_MASK,
                           AFRH15_POS,
                           AFRH15_MASK);

    };  // struct Afrh
    using afrh_t = Reg<uint32_t, Afrh>;
          afrh_t   afrh;

};  // struct Gpio
static_assert(sizeof(Gpio) == 40, "sizeof(Gpio) != 40");



struct SysCfg {
    struct Memrmp {
        using            pos_t = Pos<uint32_t, Memrmp>;
        static constexpr pos_t
            MEM_BOOT_POS = pos_t( 0),
              SWP_FB_POS = pos_t( 8),
             SWP_FMC_POS = pos_t(10);

        using            bits_t = Bits<uint32_t, Memrmp>;
        static constexpr bits_t
            MEM_BOOT         = bits_t(1,     MEM_BOOT_POS),
            SWP_FB           = bits_t(1,       SWP_FB_POS);

        static const uint32_t
                SWP_FMC_MASK =       0x3U;

        using            mskd_t = Mskd<uint32_t, Memrmp>;
        static constexpr mskd_t
            SWP_FMC_NONE     = mskd_t(    SWP_FMC_MASK, 0b00,      SWP_FMC_POS),
            SWP_FMC_NOR_RAM  = mskd_t(    SWP_FMC_MASK, 0b00,      SWP_FMC_POS);
    };  // struct Memrmp
    using memrmp_t = Reg<uint32_t, Memrmp>;
          memrmp_t   memrmp;


    struct Pmc {
        using            pos_t = Pos<uint32_t, Pmc>;
        static constexpr pos_t
            I2C1_FMP_POS = pos_t( 0),
            I2C2_FMP_POS = pos_t( 1),
            I2C3_FMP_POS = pos_t( 2),
            I2C4_FMP_POS = pos_t( 3),
         I2C_PB6_FMP_POS = pos_t( 4),
         I2C_PB7_FMP_POS = pos_t( 5),
         I2C_PB8_FMP_POS = pos_t( 6),
         I2C_PB9_FMP_POS = pos_t( 7),
             ADCxDC2_POS = pos_t(16),
             ADC1DC2_POS = pos_t(16),
             ADC2DC2_POS = pos_t(17),
             ADC3DC2_POS = pos_t(18),
        MII_RMII_SEL_POS = pos_t(23);

        using            bits_t = Bits<uint32_t, Pmc>;
        static constexpr bits_t
        I2C1_FMP         = bits_t(1,     I2C1_FMP_POS),
        I2C2_FMP         = bits_t(1,     I2C2_FMP_POS),
        I2C3_FMP         = bits_t(1,     I2C3_FMP_POS),
        I2C4_FMP         = bits_t(1,     I2C4_FMP_POS),
        I2C_PB6_FMP      = bits_t(1,  I2C_PB6_FMP_POS),
        I2C_PB7_FMP      = bits_t(1,  I2C_PB7_FMP_POS),
        I2C_PB8_FMP      = bits_t(1,  I2C_PB8_FMP_POS),
        I2C_PB9_FMP      = bits_t(1,  I2C_PB9_FMP_POS),
        ADC1DC2          = bits_t(1,      ADC1DC2_POS),
        ADC2DC2          = bits_t(1,      ADC2DC2_POS),
        ADC3DC2          = bits_t(1,      ADC3DC2_POS),
        MII_RMII_SEL     = bits_t(1, MII_RMII_SEL_POS);

        static const uint32_t
                ADCxDC2_MASK =       0x7U;
    };  // struct Pmc
    using pmc_t = Reg<uint32_t, Pmc>;
          pmc_t   pmc;


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

        REGBITS_MSKD_RANGE("SysCfg::Exti0",
                           EXTI0,
                           exti0,
                           EXTI0_MASK,
                           EXTI0_POS,
                           EXTI0_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti1",
                           EXTI1,
                           exti1,
                           EXTI1_MASK,
                           EXTI1_POS,
                           EXTI1_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti2",
                           EXTI2,
                           exti2,
                           EXTI2_MASK,
                           EXTI2_POS,
                           EXTI2_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti3",
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

        REGBITS_MSKD_RANGE("SysCfg::Exti4",
                           EXTI4,
                           exti4,
                           EXTI4_MASK,
                           EXTI4_POS,
                           EXTI4_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti5",
                           EXTI5,
                           exti5,
                           EXTI5_MASK,
                           EXTI5_POS,
                           EXTI5_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti6",
                           EXTI6,
                           exti6,
                           EXTI6_MASK,
                           EXTI6_POS,
                           EXTI6_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti7",
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

        REGBITS_MSKD_RANGE("SysCfg::Exti8",
                           EXTI8,
                           exti8,
                           EXTI8_MASK,
                           EXTI8_POS,
                           EXTI8_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti9",
                           EXTI9,
                           exti9,
                           EXTI9_MASK,
                           EXTI9_POS,
                           EXTI9_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti10",
                           EXTI10,
                           exti10,
                           EXTI10_MASK,
                           EXTI10_POS,
                           EXTI10_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti11",
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

        REGBITS_MSKD_RANGE("SysCfg::Exti12",
                           EXTI12,
                           exti12,
                           EXTI12_MASK,
                           EXTI12_POS,
                           EXTI12_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti13",
                           EXTI13,
                           exti13,
                           EXTI13_MASK,
                           EXTI13_POS,
                           EXTI13_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti14",
                           EXTI14,
                           exti14,
                           EXTI14_MASK,
                           EXTI14_POS,
                           EXTI14_MASK);
        REGBITS_MSKD_RANGE("SysCfg::Exti15",
                           EXTI15,
                           exti15,
                           EXTI15_MASK,
                           EXTI15_POS,
                           EXTI15_MASK);
    };  // struct Exticr4
    using exticr4_t = Reg<uint32_t, Exticr4>;
          exticr4_t   exticr4;


    private: uint32_t _reserved;  public:


    struct Cbr {
        using            pos_t = Pos<uint32_t, Cbr>;
        static constexpr pos_t
                 CLL_POS = pos_t(0),
                PVDL_POS = pos_t(2);

        using            bits_t = Bits<uint32_t, Cbr>;
        static constexpr bits_t
            CLL              = bits_t(1,  CLL_POS),
            PVDL             = bits_t(1, PVDL_POS);
    };  // struct Cbr
    using cbr_t = Reg<uint32_t, Cbr>;
          cbr_t   cbr;


    struct Cmpcr {
        using            pos_t = Pos<uint32_t, Cmpcr>;
        static constexpr pos_t
              CMP_PD_POS = pos_t(0),
               READY_POS = pos_t(8);

        using            bits_t = Bits<uint32_t, Cmpcr>;
        static constexpr bits_t
            CMP_PD           = bits_t(1,   CMP_PD_POS),
            READY            = bits_t(1,    READY_POS);
    };  // struct Cmpcr
    using cmpcr_t = Reg<uint32_t, Cmpcr>;
          cmpcr_t   cmpcr;

};  // struct SysCfg
static_assert(sizeof(SysCfg) == 36, "sizeof(SysCfg) != 36");


struct DmaStream {
    struct Sxcr {
        using              pos_t = Pos<uint32_t, Sxcr>;
        static constexpr   pos_t
               CHSEL_POS = pos_t(25),
              MBURST_POS = pos_t(23),
              PBURST_POS = pos_t(21),
                  CT_POS = pos_t(19),
                 DBM_POS = pos_t(18),
                  PL_POS = pos_t(16),
              PINCOS_POS = pos_t(15),
               MSIZE_POS = pos_t(13),
               PSIZE_POS = pos_t(11),
                MINC_POS = pos_t(10),
                PINC_POS = pos_t( 9),
                CIRC_POS = pos_t( 8),
                 DIR_POS = pos_t( 6),
              PFCTRL_POS = pos_t( 5),
                TCIE_POS = pos_t( 4),
                HTIE_POS = pos_t( 3),
                TEIE_POS = pos_t( 2),
               DMEIE_POS = pos_t( 1),
                  EN_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Sxcr>;
        static constexpr   bits_t
        CT               = bits_t(1,           CT_POS),
        DBM              = bits_t(1,          DBM_POS),
        PINCOS           = bits_t(1,       PINCOS_POS),
        MINC             = bits_t(1,         MINC_POS),
        PINC             = bits_t(1,         PINC_POS),
        CIRC             = bits_t(1,         CIRC_POS),
        PFCTRL           = bits_t(1,       PFCTRL_POS),
        TCIE             = bits_t(1,         TCIE_POS),
        HTIE             = bits_t(1,         HTIE_POS),
        TEIE             = bits_t(1,         TEIE_POS),
        DMEIE            = bits_t(1,        DMEIE_POS),
        EN               = bits_t(1,           EN_POS);

        static const uint32_t
              CHSEL_MASK =       0xFU,
             MBURST_MASK =       0x3U,
             PBURST_MASK =       0x3U,
                 PL_MASK =       0x3U,
              MSIZE_MASK =       0x3U,
              PSIZE_MASK =       0x3U,
                DIR_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Sxcr>;
        using              shft_t = Shft<uint32_t, Sxcr>;

        static constexpr   mskd_t
        MBURST_SINGLE    = mskd_t(     MBURST_MASK,  0b00,       MBURST_POS),
        MBURST_INCR_4    = mskd_t(     MBURST_MASK,  0b01,       MBURST_POS),
        MBURST_INCR_8    = mskd_t(     MBURST_MASK,  0b10,       MBURST_POS),
        MBURST_INCR_16   = mskd_t(     MBURST_MASK,  0b11,       MBURST_POS),
        PBURST_SINGLE    = mskd_t(     PBURST_MASK,  0b00,       PBURST_POS),
        PBURST_INCR_4    = mskd_t(     PBURST_MASK,  0b01,       PBURST_POS),
        PBURST_INCR_8    = mskd_t(     PBURST_MASK,  0b10,       PBURST_POS),
        PBURST_INCR_16   = mskd_t(     PBURST_MASK,  0b11,       PBURST_POS),
        PL_LOW           = mskd_t(         PL_MASK,  0b00,           PL_POS),
        PL_MEDIUM        = mskd_t(         PL_MASK,  0b01,           PL_POS),
        PL_HIGH          = mskd_t(         PL_MASK,  0b10,           PL_POS),
        PL_VERY_HIGH     = mskd_t(         PL_MASK,  0b11,           PL_POS),
        MSIZE_8_BIT      = mskd_t(      MSIZE_MASK,  0b00,        MSIZE_POS),
        MSIZE_16_BIT     = mskd_t(      MSIZE_MASK,  0b01,        MSIZE_POS),
        MSIZE_32_BIT     = mskd_t(      MSIZE_MASK,  0b10,        MSIZE_POS),
        PSIZE_8_BIT      = mskd_t(      PSIZE_MASK,  0b00,        PSIZE_POS),
        PSIZE_16_BIT     = mskd_t(      PSIZE_MASK,  0b01,        PSIZE_POS),
        PSIZE_32_BIT     = mskd_t(      PSIZE_MASK,  0b10,        PSIZE_POS),
        DIR_PRPH_TO_MEM  = mskd_t(        DIR_MASK,  0b00,          DIR_POS),
        DIR_MEM_TO_PRPH  = mskd_t(        DIR_MASK,  0b01,          DIR_POS),
        DIR_MEM_TO_MEM   = mskd_t(        DIR_MASK,  0b10,          DIR_POS);

        REGBITS_MSKD_RANGE("Scxr::Chsel",
                           CHSEL,
                           chsel,
                           CHSEL_MASK,
                           CHSEL_POS,
                           CHSEL_MASK);
    };  // struct Sxcr
    using sxcr_t = Reg<uint32_t, Sxcr>;
          sxcr_t   sxcr;


    struct Sxndt {
        using              pos_t = Pos<uint32_t, Sxndt>;
        static constexpr   pos_t
                 NDT_POS = pos_t( 0);

        using              mskd_t = Mskd<uint32_t, Sxndt>;
        using              shft_t = Shft<uint32_t, Sxndt>;

        static const uint32_t
                NDT_MASK =    0xFFFFU;

        REGBITS_MSKD_RANGE("Sxndt::Ndt",
                           NDT,
                           ndt,
                           NDT_MASK,
                           NDT_POS,
                           NDT_MASK);
    };  // struct Sxndt
    using sxndt_t = Reg<uint32_t, Sxndt>;
          sxndt_t   sxndt;


    struct Sxpar {
        // access using operator=(unit32_t) and word() -- no masking/shifting
    };  // struct Sxpar
    using sxpar_t = Reg<uint32_t, Sxpar>;
          sxpar_t   sxpar;


    struct Sxm0ar {
        // access using operator=(unit32_t) and word() -- no masking/shifting
    };  // struct Sxm0ar
    using sxm0ar_t = Reg<uint32_t, Sxm0ar>;
          sxm0ar_t  sxm0ar;


    struct Sxm1ar {
        // access using operator=(unit32_t) and word() -- no masking/shifting
    };  // struct Sxm1ar
    using sxm1ar_t = Reg<uint32_t, Sxm1ar>;
          sxm1ar_t  sxm1ar;

    struct Sxfcr {
        using              pos_t = Pos<uint32_t, Sxfcr>;
        static constexpr   pos_t
                FEIE_POS = pos_t( 7),
                  FS_POS = pos_t( 3),
               DMDIS_POS = pos_t( 2),
                 FTH_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Sxfcr>;
        static constexpr   bits_t
        FEIE             = bits_t(1,         FEIE_POS),
        DMDIS            = bits_t(1,        DMDIS_POS);

        static const uint32_t
                 FS_MASK =       0x7U,
                FTH_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Sxfcr>;
        static constexpr   mskd_t
        FS_000_TO_025    = mskd_t(         FS_MASK,  0b000,          FS_POS),
        FS_025_TO_050    = mskd_t(         FS_MASK,  0b001,          FS_POS),
        FS_050_TO_075    = mskd_t(         FS_MASK,  0b010,          FS_POS),
        FS_075_TO_100    = mskd_t(         FS_MASK,  0b011,          FS_POS),
        FS_EMPTY         = mskd_t(         FS_MASK,  0b100,          FS_POS),
        FS_FULL          = mskd_t(         FS_MASK,  0b101,          FS_POS),
        FTH_25_PERCENT   = mskd_t(        FTH_MASK,  0b00,          FTH_POS),
        FTH_50_PERCENT   = mskd_t(        FTH_MASK,  0b01,          FTH_POS),
        FTH_75_PERCENT   = mskd_t(        FTH_MASK,  0b10,          FTH_POS),
        FTH_100_PERCENT  = mskd_t(        FTH_MASK,  0b11,          FTH_POS);
    };  // struct Sxfcr
    using sxfcr_t = Reg<uint32_t, Sxfcr>;
          sxfcr_t   sxfcr;

};  // struct DmaStream
static_assert(sizeof(DmaStream) == 24, "sizeof(DmaStream) != 24");



struct Dma {
    struct Lisr {
        using              pos_t = Pos<uint32_t, Lisr>;
        static constexpr   pos_t
               TCIF3_POS = pos_t(27),
               HTIF3_POS = pos_t(26),
               TEIF3_POS = pos_t(25),
              DMEIF3_POS = pos_t(24),
               FEIF3_POS = pos_t(22),
               TCIF2_POS = pos_t(21),
               HTIF2_POS = pos_t(20),
               TEIF2_POS = pos_t(19),
              DMEIF2_POS = pos_t(18),
               FEIF2_POS = pos_t(16),
               TCIF1_POS = pos_t(11),
               HTIF1_POS = pos_t(10),
               TEIF1_POS = pos_t( 9),
              DMEIF1_POS = pos_t( 8),
               FEIF1_POS = pos_t( 6),
               TCIF0_POS = pos_t( 5),
               HTIF0_POS = pos_t( 4),
               TEIF0_POS = pos_t( 3),
              DMEIF0_POS = pos_t( 2),
               FEIF0_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Lisr>;
        static constexpr   bits_t
        TCIF3            = bits_t(1,        TCIF3_POS),
        HTIF3            = bits_t(1,        HTIF3_POS),
        TEIF3            = bits_t(1,        TEIF3_POS),
        DMEIF3           = bits_t(1,       DMEIF3_POS),
        FEIF3            = bits_t(1,        FEIF3_POS),
        TCIF2            = bits_t(1,        TCIF2_POS),
        HTIF2            = bits_t(1,        HTIF2_POS),
        TEIF2            = bits_t(1,        TEIF2_POS),
        DMEIF2           = bits_t(1,       DMEIF2_POS),
        FEIF2            = bits_t(1,        FEIF2_POS),
        TCIF1            = bits_t(1,        TCIF1_POS),
        HTIF1            = bits_t(1,        HTIF1_POS),
        TEIF1            = bits_t(1,        TEIF1_POS),
        DMEIF1           = bits_t(1,       DMEIF1_POS),
        FEIF1            = bits_t(1,        FEIF1_POS),
        TCIF0            = bits_t(1,        TCIF0_POS),
        HTIF0            = bits_t(1,        HTIF0_POS),
        TEIF0            = bits_t(1,        TEIF0_POS),
        DMEIF0           = bits_t(1,       DMEIF0_POS),
        FEIF0            = bits_t(1,        FEIF0_POS);
    };  // struct Lisr
    using lisr_t = Reg<uint32_t, Lisr>;
          lisr_t   lisr;


    struct Hisr {
        using              pos_t = Pos<uint32_t, Hisr>;
        static constexpr   pos_t
               TCIF7_POS = pos_t(27),
               HTIF7_POS = pos_t(26),
               TEIF7_POS = pos_t(25),
              DMEIF7_POS = pos_t(24),
               FEIF7_POS = pos_t(22),
               TCIF6_POS = pos_t(21),
               HTIF6_POS = pos_t(20),
               TEIF6_POS = pos_t(19),
              DMEIF6_POS = pos_t(18),
               FEIF6_POS = pos_t(16),
               TCIF5_POS = pos_t(11),
               HTIF5_POS = pos_t(10),
               TEIF5_POS = pos_t( 9),
              DMEIF5_POS = pos_t( 8),
               FEIF5_POS = pos_t( 6),
               TCIF4_POS = pos_t( 5),
               HTIF4_POS = pos_t( 4),
               TEIF4_POS = pos_t( 3),
              DMEIF4_POS = pos_t( 2),
               FEIF4_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Hisr>;
        static constexpr   bits_t
        TCIF7            = bits_t(1,        TCIF7_POS),
        HTIF7            = bits_t(1,        HTIF7_POS),
        TEIF7            = bits_t(1,        TEIF7_POS),
        DMEIF7           = bits_t(1,       DMEIF7_POS),
        FEIF7            = bits_t(1,        FEIF7_POS),
        TCIF6            = bits_t(1,        TCIF6_POS),
        HTIF6            = bits_t(1,        HTIF6_POS),
        TEIF6            = bits_t(1,        TEIF6_POS),
        DMEIF6           = bits_t(1,       DMEIF6_POS),
        FEIF6            = bits_t(1,        FEIF6_POS),
        TCIF5            = bits_t(1,        TCIF5_POS),
        HTIF5            = bits_t(1,        HTIF5_POS),
        TEIF5            = bits_t(1,        TEIF5_POS),
        DMEIF5           = bits_t(1,       DMEIF5_POS),
        FEIF5            = bits_t(1,        FEIF5_POS),
        TCIF4            = bits_t(1,        TCIF4_POS),
        HTIF4            = bits_t(1,        HTIF4_POS),
        TEIF4            = bits_t(1,        TEIF4_POS),
        DMEIF4           = bits_t(1,       DMEIF4_POS),
        FEIF4            = bits_t(1,        FEIF4_POS);
    };  // struct Hisr
    using hisr_t = Reg<uint32_t, Hisr>;
          hisr_t   hisr;


    struct Lifcr {
        using              pos_t = Pos<uint32_t, Lifcr>;
        static constexpr   pos_t
              CTCIF3_POS = pos_t(27),
              CHTIF3_POS = pos_t(26),
              CTEIF3_POS = pos_t(25),
             CDMEIF3_POS = pos_t(24),
              CFEIF3_POS = pos_t(22),
              CTCIF2_POS = pos_t(21),
              CHTIF2_POS = pos_t(20),
              CTEIF2_POS = pos_t(19),
             CDMEIF2_POS = pos_t(18),
              CFEIF2_POS = pos_t(16),
              CTCIF1_POS = pos_t(11),
              CHTIF1_POS = pos_t(10),
              CTEIF1_POS = pos_t( 9),
             CDMEIF1_POS = pos_t( 8),
              CFEIF1_POS = pos_t( 6),
              CTCIF0_POS = pos_t( 5),
              CHTIF0_POS = pos_t( 4),
              CTEIF0_POS = pos_t( 3),
             CDMEIF0_POS = pos_t( 2),
              CFEIF0_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Lifcr>;
        static constexpr   bits_t
        CTCIF3           = bits_t(1,       CTCIF3_POS),
        CHTIF3           = bits_t(1,       CHTIF3_POS),
        CTEIF3           = bits_t(1,       CTEIF3_POS),
        CDMEIF3          = bits_t(1,      CDMEIF3_POS),
        CFEIF3           = bits_t(1,       CFEIF3_POS),
        CTCIF2           = bits_t(1,       CTCIF2_POS),
        CHTIF2           = bits_t(1,       CHTIF2_POS),
        CTEIF2           = bits_t(1,       CTEIF2_POS),
        CDMEIF2          = bits_t(1,      CDMEIF2_POS),
        CFEIF2           = bits_t(1,       CFEIF2_POS),
        CTCIF1           = bits_t(1,       CTCIF1_POS),
        CHTIF1           = bits_t(1,       CHTIF1_POS),
        CTEIF1           = bits_t(1,       CTEIF1_POS),
        CDMEIF1          = bits_t(1,      CDMEIF1_POS),
        CFEIF1           = bits_t(1,       CFEIF1_POS),
        CTCIF0           = bits_t(1,       CTCIF0_POS),
        CHTIF0           = bits_t(1,       CHTIF0_POS),
        CTEIF0           = bits_t(1,       CTEIF0_POS),
        CDMEIF0          = bits_t(1,      CDMEIF0_POS),
        CFEIF0           = bits_t(1,       CFEIF0_POS);
    };  // struct Lifcr
    using lifcr_t = Reg<uint32_t, Lifcr>;
          lifcr_t   lifcr;


    struct Hifcr {
        using              pos_t = Pos<uint32_t, Hifcr>;
        static constexpr   pos_t
              CTCIF7_POS = pos_t(27),
              CHTIF7_POS = pos_t(26),
              CTEIF7_POS = pos_t(25),
             CDMEIF7_POS = pos_t(24),
              CFEIF7_POS = pos_t(22),
              CTCIF6_POS = pos_t(21),
              CHTIF6_POS = pos_t(20),
              CTEIF6_POS = pos_t(19),
             CDMEIF6_POS = pos_t(18),
              CFEIF6_POS = pos_t(16),
              CTCIF5_POS = pos_t(11),
              CHTIF5_POS = pos_t(10),
              CTEIF5_POS = pos_t( 9),
             CDMEIF5_POS = pos_t( 8),
              CFEIF5_POS = pos_t( 6),
              CTCIF4_POS = pos_t( 5),
              CHTIF4_POS = pos_t( 4),
              CTEIF4_POS = pos_t( 3),
             CDMEIF4_POS = pos_t( 2),
              CFEIF4_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Hifcr>;
        static constexpr   bits_t
        CTCIF7           = bits_t(1,       CTCIF7_POS),
        CHTIF7           = bits_t(1,       CHTIF7_POS),
        CTEIF7           = bits_t(1,       CTEIF7_POS),
        CDMEIF7          = bits_t(1,      CDMEIF7_POS),
        CFEIF7           = bits_t(1,       CFEIF7_POS),
        CTCIF6           = bits_t(1,       CTCIF6_POS),
        CHTIF6           = bits_t(1,       CHTIF6_POS),
        CTEIF6           = bits_t(1,       CTEIF6_POS),
        CDMEIF6          = bits_t(1,      CDMEIF6_POS),
        CFEIF6           = bits_t(1,       CFEIF6_POS),
        CTCIF5           = bits_t(1,       CTCIF5_POS),
        CHTIF5           = bits_t(1,       CHTIF5_POS),
        CTEIF5           = bits_t(1,       CTEIF5_POS),
        CDMEIF5          = bits_t(1,      CDMEIF5_POS),
        CFEIF5           = bits_t(1,       CFEIF5_POS),
        CTCIF4           = bits_t(1,       CTCIF4_POS),
        CHTIF4           = bits_t(1,       CHTIF4_POS),
        CTEIF4           = bits_t(1,       CTEIF4_POS),
        CDMEIF4          = bits_t(1,      CDMEIF4_POS),
        CFEIF4           = bits_t(1,       CFEIF4_POS);
    };  // struct Hifcr
    using hifcr_t = Reg<uint32_t, Hifcr>;
          hifcr_t   hifcr;


    static const uint32_t   NUM_STREAMS = 8;

    REGBITS_ARRAY_RANGE("Dma",
                        STREAM,
                        stream,
                        DmaStream,
                        _streams,
                        NUM_STREAMS - 1);

  protected:
    DmaStream   _streams[NUM_STREAMS];

};  // struct Dma
static_assert( sizeof(Dma) == 16 + 8 * sizeof(DmaStream),
              "sizeof(Dma) != 16 + 8 * sizeof(DmaStream)");



struct Exti {
    struct Imr {
        using            pos_t = Pos<uint32_t, Imr>;
        static constexpr pos_t
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
            MR18_POS = pos_t(18),
            MR19_POS = pos_t(19),
            MR20_POS = pos_t(20),
            MR21_POS = pos_t(21),
            MR22_POS = pos_t(22),
            MR23_POS = pos_t(23),
            MR24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Imr>;
        static constexpr bits_t
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
        MR18             = bits_t(1,         MR18_POS),
        MR19             = bits_t(1,         MR19_POS),
        MR20             = bits_t(1,         MR20_POS),
        MR21             = bits_t(1,         MR21_POS),
        MR22             = bits_t(1,         MR22_POS),
        MR23             = bits_t(1,         MR23_POS),
        MR24             = bits_t(1,         MR24_POS);
    };  // struct Imr
    using imr_t = Reg<uint32_t, Imr>;
          imr_t   imr;


    struct Emr {
        using            pos_t = Pos<uint32_t, Emr>;
        static constexpr pos_t
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
            MR18_POS = pos_t(18),
            MR19_POS = pos_t(19),
            MR20_POS = pos_t(20),
            MR21_POS = pos_t(21),
            MR22_POS = pos_t(22),
            MR23_POS = pos_t(23),
            MR24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Emr>;
        static constexpr bits_t
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
        MR18             = bits_t(1,         MR18_POS),
        MR19             = bits_t(1,         MR19_POS),
        MR20             = bits_t(1,         MR20_POS),
        MR21             = bits_t(1,         MR21_POS),
        MR22             = bits_t(1,         MR22_POS),
        MR23             = bits_t(1,         MR23_POS),
        MR24             = bits_t(1,         MR24_POS);
    };  // struct Emr
    using emr_t = Reg<uint32_t, Emr>;
          emr_t   emr;


    struct Rtsr {
        using            pos_t = Pos<uint32_t, Rtsr>;
        static constexpr pos_t
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
            TR18_POS = pos_t(18),
            TR19_POS = pos_t(19),
            TR20_POS = pos_t(20),
            TR21_POS = pos_t(21),
            TR22_POS = pos_t(22),
            TR23_POS = pos_t(23),
            TR24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Rtsr>;
        static constexpr bits_t
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
        TR18             = bits_t(1,         TR18_POS),
        TR19             = bits_t(1,         TR19_POS),
        TR20             = bits_t(1,         TR20_POS),
        TR21             = bits_t(1,         TR21_POS),
        TR22             = bits_t(1,         TR22_POS),
        TR23             = bits_t(1,         TR23_POS),
        TR24             = bits_t(1,         TR24_POS);
    };  // struct Rtsr
    using rtsr_t = Reg<uint32_t, Rtsr>;
          rtsr_t   rtsr;


    struct Ftsr {
        using            pos_t = Pos<uint32_t, Ftsr>;
        static constexpr pos_t
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
            TR18_POS = pos_t(18),
            TR19_POS = pos_t(19),
            TR20_POS = pos_t(20),
            TR21_POS = pos_t(21),
            TR22_POS = pos_t(22),
            TR23_POS = pos_t(23),
            TR24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Ftsr>;
        static constexpr bits_t
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
        TR18             = bits_t(1,         TR18_POS),
        TR19             = bits_t(1,         TR19_POS),
        TR20             = bits_t(1,         TR20_POS),
        TR21             = bits_t(1,         TR21_POS),
        TR22             = bits_t(1,         TR22_POS),
        TR23             = bits_t(1,         TR23_POS),
        TR24             = bits_t(1,         TR24_POS);
    };  // struct Ftsr
    using ftsr_t = Reg<uint32_t, Ftsr>;
          ftsr_t   ftsr;


    struct Swier {
        using            pos_t = Pos<uint32_t, Swier>;
        static constexpr pos_t
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
         SWIER18_POS = pos_t(18),
         SWIER19_POS = pos_t(19),
         SWIER20_POS = pos_t(20),
         SWIER21_POS = pos_t(21),
         SWIER22_POS = pos_t(22),
         SWIER23_POS = pos_t(23),
         SWIER24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Swier>;
        static constexpr bits_t
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
        SWIER18          = bits_t(1,      SWIER18_POS),
        SWIER19          = bits_t(1,      SWIER19_POS),
        SWIER20          = bits_t(1,      SWIER20_POS),
        SWIER21          = bits_t(1,      SWIER21_POS),
        SWIER22          = bits_t(1,      SWIER22_POS),
        SWIER23          = bits_t(1,      SWIER23_POS),
        SWIER24          = bits_t(1,      SWIER24_POS);
    };  // struct Swier
    using swier_t = Reg<uint32_t, Swier>;
          swier_t   swier;


    struct Pr {
        using            pos_t = Pos<uint32_t, Pr>;
        static constexpr pos_t
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
            PR18_POS = pos_t(18),
            PR19_POS = pos_t(19),
            PR20_POS = pos_t(20),
            PR21_POS = pos_t(21),
            PR22_POS = pos_t(22),
            PR23_POS = pos_t(23),
            PR24_POS = pos_t(24);

        using            bits_t = Bits<uint32_t, Pr>;
        static constexpr bits_t
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
        PR18             = bits_t(1,         PR18_POS),
        PR19             = bits_t(1,         PR19_POS),
        PR20             = bits_t(1,         PR20_POS),
        PR21             = bits_t(1,         PR21_POS),
        PR22             = bits_t(1,         PR22_POS),
        PR23             = bits_t(1,         PR23_POS),
        PR24             = bits_t(1,         PR24_POS);
    };  // struct Pr
    using pr_t = Reg<uint32_t, Pr>;
          pr_t   pr;

};  // struct Exti
static_assert(sizeof(Exti) == 24, "sizeof(Exti) != 24");



// timers
//


// timer types
//

// check to include private stm32f767xx_tim.hxx from here
#define STM32F767XX_TIM_HXX_INCLUDE

struct Tim
{
#include "stm32f767xx_tim.hxx"
};

struct TimCr2
{
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_CR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_CR2
};

struct TimCr2Ccds
{
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_CR2_CCDS
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CR2_CCDS
#undef STM32F767XX_TIM_CR2
};

struct TimSmcr
{
#define STM32F767XX_TIM_SMCR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_SMCR
};

struct TimCcmr1_1_2_3_4_5_8_9_12
{
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
};

struct TimCcmr1_10_11_13_14
{
#define STM32F767XX_TIM_CCMR1_10_11_13_14
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCMR1_10_11_13_14
};

struct TimCcmr2
{
#define STM32F767XX_TIM_CCMR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCMR2
};

struct TimRcr
{
#define STM32F767XX_TIM_RCR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_RCR
};

struct TimCcr1
{
#define STM32F767XX_TIM_CCR1
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCR1
};

struct TimCcr2
{
#define STM32F767XX_TIM_CCR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCR2
};

struct TimCcr3_4
{
#define STM32F767XX_TIM_CCR3_4
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_CCR3_4
};

struct TimDcr
{
#define STM32F767XX_TIM_DCR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_DCR
};

struct TimDmar
{
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_DMAR
};

struct TimOrr_2
{
#define STM32F767XX_TIM_ORR_2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_ORR_2
};

struct TimOrr_5
{
#define STM32F767XX_TIM_ORR_5
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_ORR_5
};

struct TimOrr_11
{
#define STM32F767XX_TIM_ORR_11
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_TIM_ORR_11
};


// timers classes
//

struct AdvTim_1_8
{
#define STM32F767XX_ADV_TIM_1_8
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_RCR
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_ADV_TIM_1_8
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_RCR
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct AdvTim_1_8
static_assert(sizeof(AdvTim_1_8) == 104, "sizeof(AdvTim_1_8) != 104");

struct GenTim_2_3_4_5
{
#define STM32F767XX_GEN_TIM_2_3_4_5
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_2_3_4_5
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct GenTim_2_3_4_5
static_assert(sizeof(GenTim_2_3_4_5) == 104, "sizeof(GenTim_2_3_4_5) != 104");

struct GenTim_2_5
{
    volatile GenTim_2_3_4_5* gen_tim_2_3_4_5() volatile {
        return reinterpret_cast<volatile GenTim_2_3_4_5*>(this); }
             GenTim_2_3_4_5* gen_tim_2_3_4_5()          {
        return reinterpret_cast<         GenTim_2_3_4_5*>(this); }
#define STM32F767XX_GEN_TIM_2_5
#define STM32F767XX_GEN_TIM_2_3_4_5
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_2_5
#undef STM32F767XX_GEN_TIM_2_3_4_5
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct GenTim_2_5
static_assert(sizeof(GenTim_2_5) == 104, "sizeof(GenTim_2_5) != 104");

struct GenTim_2
{
    volatile GenTim_2_3_4_5* gen_tim_2_3_4_5() volatile {
        return reinterpret_cast<volatile GenTim_2_3_4_5*>(this); }
             GenTim_2_3_4_5* gen_tim_2_3_4_5()          {
        return reinterpret_cast<         GenTim_2_3_4_5*>(this); }
    volatile GenTim_2_5* gen_tim_2_5() volatile {
        return reinterpret_cast<volatile GenTim_2_5*>(this); }
             GenTim_2_5* gen_tim_2_5()          {
        return reinterpret_cast<         GenTim_2_5*>(this); }
#define STM32F767XX_GEN_TIM_2
#define STM32F767XX_GEN_TIM_2_5
#define STM32F767XX_GEN_TIM_2_3_4_5
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_2
#undef STM32F767XX_GEN_TIM_2_5
#undef STM32F767XX_GEN_TIM_2_3_4_5
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct GenTim_2
static_assert(sizeof(GenTim_2) == 104, "sizeof(GenTim_2) != 104");

struct GenTim_3_4
{
    volatile GenTim_2_3_4_5* gen_tim_2_3_4_5() volatile {
        return reinterpret_cast<volatile GenTim_2_3_4_5*>(this); }
             GenTim_2_3_4_5* gen_tim_2_3_4_5()          {
        return reinterpret_cast<         GenTim_2_3_4_5*>(this); }
#define STM32F767XX_GEN_TIM_3_4
#define STM32F767XX_GEN_TIM_2_3_4_5
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_3_4
#undef STM32F767XX_GEN_TIM_2_3_4_5
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct GenTim_3_4
static_assert(sizeof(GenTim_3_4) == 104, "sizeof(GenTim_3_4) != 104");

struct GenTim_5
{
    volatile GenTim_2_3_4_5* gen_tim_2_3_4_5()volatile  {
        return reinterpret_cast<volatile GenTim_2_3_4_5*>(this); }
             GenTim_2_3_4_5* gen_tim_2_3_4_5()          {
        return reinterpret_cast<         GenTim_2_3_4_5*>(this); }
    volatile GenTim_2_5* gen_tim_2_5() volatile {
        return reinterpret_cast<volatile GenTim_2_5*>(this); }
             GenTim_2_5* gen_tim_2_5()          {
        return reinterpret_cast<         GenTim_2_5*>(this); }
#define STM32F767XX_GEN_TIM_2_3_4_5
#define STM32F767XX_GEN_TIM_2_5
#define STM32F767XX_GEN_TIM_5
#define STM32F767XX_TIM_CR2
#define STM32F767XX_TIM_SMCR
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCMR2
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#define STM32F767XX_TIM_CCR3_4
#define STM32F767XX_TIM_DCR
#define STM32F767XX_TIM_DMAR
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_2_3_4_5
#undef STM32F767XX_GEN_TIM_2_5
#undef STM32F767XX_GEN_TIM_5
#undef STM32F767XX_TIM_CR2
#undef STM32F767XX_TIM_SMCR
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCMR2
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
#undef STM32F767XX_TIM_CCR3_4
#undef STM32F767XX_TIM_DCR
#undef STM32F767XX_TIM_DMAR
};  // struct GenTim_5
static_assert(sizeof(GenTim_5) == 104, "sizeof(GenTim_5) != 104");

struct BscTim_6_7
{
#define STM32F767XX_BSC_TIM_6_7
#define STM32F767XX_TIM_CR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_BSC_TIM_6_7
#undef STM32F767XX_TIM_CR2
};  // struct BscTim_6_7
static_assert(sizeof(BscTim_6_7) == 104, "sizeof(BscTim_6_7) != 104");

struct   GenTim_9_10_11_12_13_14
{
#define STM32F767XX_GEN_TIM_9_10_11_12_13_14
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
};  // struct GenTim_9_10_11_12_13_14
static_assert( sizeof(GenTim_9_10_11_12_13_14) == 104,
              "sizeof(GenTim_9_10_11_12_13_14) != 104");

struct GenTim_9_12
{
    volatile GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14() volatile {
        return reinterpret_cast<volatile GenTim_9_10_11_12_13_14*>(this); }
             GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14()          {
        return reinterpret_cast<         GenTim_9_10_11_12_13_14*>(this); }
#define STM32F767XX_GEN_TIM_9_10_11_12_13_14
#define STM32F767XX_GEN_TIM_9_12
#define STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#define STM32F767XX_TIM_CCR1
#define STM32F767XX_TIM_CCR2
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#undef STM32F767XX_GEN_TIM_9_12
#undef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
#undef STM32F767XX_TIM_CCR1
#undef STM32F767XX_TIM_CCR2
};  // struct GenTim_9_12
static_assert(sizeof(GenTim_9_12) == 104, "sizeof(GenTim_9_12) != 104");

struct GenTim_10_11_13_14
{
    volatile GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14() volatile {
        return reinterpret_cast<volatile GenTim_9_10_11_12_13_14*>(this); }
             GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14()          {
        return reinterpret_cast<         GenTim_9_10_11_12_13_14*>(this); }
#undef STM32F767XX_GEN_TIM_10_11_13_14
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#define STM32F767XX_GEN_TIM_10_11_13_14
#define STM32F767XX_TIM_CCMR1_10_11_13_14
#define STM32F767XX_TIM_CCR1
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_10_11_13_14
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#undef STM32F767XX_TIM_CCMR1_10_11_13_14
#undef STM32F767XX_TIM_CCR1
};  // struct GenTim_10_13_14
static_assert( sizeof(GenTim_10_11_13_14) == 104,
              "sizeof(GenTim_10_11_13_14) != 104");

struct GenTim_10_13_14
{
    volatile GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14() volatile {
        return reinterpret_cast<volatile GenTim_9_10_11_12_13_14*>(this);}
             GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14()          {
        return reinterpret_cast<         GenTim_9_10_11_12_13_14*>(this);}
    volatile GenTim_10_11_13_14* gen_tim_10_11_13_14() volatile {
        return reinterpret_cast<volatile GenTim_10_11_13_14*>(this); }
             GenTim_10_11_13_14* gen_tim_10_11_13_14()          {
        return reinterpret_cast<         GenTim_10_11_13_14*>(this); }
#define STM32F767XX_GEN_TIM_9_10_11_12_13_14
#define STM32F767XX_GEN_TIM_10_11_13_14
#define STM32F767XX_GEN_TIM_10_13_14
#define STM32F767XX_TIM_CCMR1_10_11_13_14
#define STM32F767XX_TIM_CCR1
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_10_13_14
#undef STM32F767XX_GEN_TIM_10_11_13_14
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#undef STM32F767XX_TIM_CCMR1_10_11_13_14
#undef STM32F767XX_TIM_CCR1
};  // struct GenTim_10_13_14
static_assert( sizeof(GenTim_10_13_14) == 104, "sizeof(GenTim_10_13_14) != 104");

struct GenTim_11
{
    volatile GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14() volatile {
        return reinterpret_cast<volatile GenTim_9_10_11_12_13_14*>(this); }
             GenTim_9_10_11_12_13_14* gen_tim_9_10_11_12_13_14()          {
        return reinterpret_cast<         GenTim_9_10_11_12_13_14*>(this); }
    volatile GenTim_10_11_13_14* gen_tim_10_11_13_14() volatile {
        return reinterpret_cast<volatile GenTim_10_11_13_14*>(this); }
#define STM32F767XX_GEN_TIM_9_10_11_12_13_14
#define STM32F767XX_GEN_TIM_10_11_13_14
#define STM32F767XX_GEN_TIM_11
#include "stm32f767xx_tim.hxx"
#undef STM32F767XX_GEN_TIM_9_10_11_12_13_14
#undef STM32F767XX_GEN_TIM_10_11_13_14
#undef STM32F767XX_GEN_TIM_11
#undef STM32F767XX_GEN_TIM_10_11_13_14
#undef STM32F767XX_TIM_CCMR1_10_11_13_14
#undef STM32F767XX_TIM_CCR1
};  // struct GenTim_11
static_assert( sizeof(GenTim_11) == 104, "sizeof(GenTim_11) != 104");

#undef STM32F767XX_TIM_HXX_INCLUDE



struct LpTim {
    struct Isr {
        using            pos_t = Pos<uint32_t, Isr>;
        static constexpr pos_t
            CMPM_POS = pos_t( 0),
            ARRM_POS = pos_t( 1),
         EXTTRIG_POS = pos_t( 2),
           CMPOK_POS = pos_t( 3),
           ARROK_POS = pos_t( 4),
              UP_POS = pos_t( 5),
            DOWN_POS = pos_t( 6);

    using            bits_t = Bits<uint32_t, Isr>;
    static constexpr bits_t
    CMPM             = bits_t(1,         CMPM_POS),
    ARRM             = bits_t(1,         ARRM_POS),
    EXTTRIG          = bits_t(1,      EXTTRIG_POS),
    CMPOK            = bits_t(1,        CMPOK_POS),
    ARROK            = bits_t(1,        ARROK_POS),
    UP               = bits_t(1,           UP_POS),
    DOWN             = bits_t(1,         DOWN_POS);
    };  // struct Isr
    using isr_t = Reg<uint32_t, Isr>;
          isr_t   isr;


    struct Icr {
        using            pos_t = Pos<uint32_t, Icr>;
        static constexpr pos_t
          CMPMCF_POS = pos_t( 0),
          ARRMCF_POS = pos_t( 1),
       EXTTRIGCF_POS = pos_t( 2),
         CMPOKCF_POS = pos_t( 3),
         ARROKCF_POS = pos_t( 4),
            UPCF_POS = pos_t( 5),
          DOWNCF_POS = pos_t( 6);

    using            bits_t = Bits<uint32_t, Icr>;
        static constexpr bits_t
        CMPMCF           = bits_t(1,       CMPMCF_POS),
        ARRMCF           = bits_t(1,       ARRMCF_POS),
        EXTTRIGCF        = bits_t(1,    EXTTRIGCF_POS),
        CMPOKCF          = bits_t(1,      CMPOKCF_POS),
        ARROKCF          = bits_t(1,      ARROKCF_POS),
        UPCF             = bits_t(1,         UPCF_POS),
        DOWNCF           = bits_t(1,       DOWNCF_POS);
    };  // struct Icr
    using icr_t = Reg<uint32_t, Icr>;
          icr_t   icr;


    struct Ier {
        using            pos_t = Pos<uint32_t, Ier>;
        static constexpr pos_t
           CMPMIE_POS = pos_t( 0),
           ARRMIE_POS = pos_t( 1),
        EXTTRIGIE_POS = pos_t( 2),
          CMPOKIE_POS = pos_t( 3),
          ARROKIE_POS = pos_t( 4),
             UPIE_POS = pos_t( 5),
           DOWNIE_POS = pos_t( 6);

    using            bits_t = Bits<uint32_t, Ier>;
        static constexpr bits_t
        CMPMIE           = bits_t(1,       CMPMIE_POS),
        ARRMIE           = bits_t(1,       ARRMIE_POS),
        EXTTRIGIE        = bits_t(1,    EXTTRIGIE_POS),
        CMPOKIE          = bits_t(1,      CMPOKIE_POS),
        ARROKIE          = bits_t(1,      ARROKIE_POS),
        UPIE             = bits_t(1,         UPIE_POS),
        DOWNIE           = bits_t(1,       DOWNIE_POS);
    };  // struct Ier
    using ier_t = Reg<uint32_t, Ier>;
          ier_t   ier;


    struct Cfgr {
        using            pos_t = Pos<uint32_t, Cfgr>;
        static constexpr pos_t
            CKSEL_POS = pos_t( 0),
            CKPOL_POS = pos_t( 1),
            CKFLT_POS = pos_t( 3),
           TRGFLT_POS = pos_t( 6),
            PRESC_POS = pos_t( 9),
          TRIGSEL_POS = pos_t(13),
           TRIGEN_POS = pos_t(17),
           TIMOUT_POS = pos_t(19),
             WAVE_POS = pos_t(20),
           WAVPOL_POS = pos_t(21),
          PRELOAD_POS = pos_t(22),
        COUNTMODE_POS = pos_t(23),
              ENC_POS = pos_t(24);

    using            bits_t = Bits<uint32_t, Cfgr>;
        static constexpr bits_t
        CKSEL            = bits_t(1,        CKSEL_POS),
        TIMOUT           = bits_t(1,       TIMOUT_POS),
        WAVE             = bits_t(1,         WAVE_POS),
        WAVPOL           = bits_t(1,       WAVPOL_POS),
        PRELOAD          = bits_t(1,      PRELOAD_POS),
        COUNTMODE        = bits_t(1,    COUNTMODE_POS),
        ENC              = bits_t(1,          ENC_POS);

        static const uint32_t
              CKPOL_MASK =       0x3U,
              CKFLT_MASK =       0x3U,
             TRGFLT_MASK =       0x3U,
              PRESC_MASK =       0x7U,
            TRIGSEL_MASK =       0x7U,
             TRIGEN_MASK =       0x3U;

        using            mskd_t = Mskd<uint32_t, Cfgr>;
        static constexpr mskd_t
        CKPOL_RISING_SUB1   = mskd_t(    CKPOL_MASK, 0b00,     CKPOL_POS),
        CKPOL_FALLING_SUB2  = mskd_t(    CKPOL_MASK, 0b01,     CKPOL_POS),
        CKPOL_BOTH_SUB3     = mskd_t(    CKPOL_MASK, 0b10,     CKPOL_POS),
        CKFLT_ANY           = mskd_t(    CKFLT_MASK, 0b00,     CKFLT_POS),
        CKFLT_2_CLK         = mskd_t(    CKFLT_MASK, 0b01,     CKFLT_POS),
        CKFLT_4_CLK         = mskd_t(    CKFLT_MASK, 0b10,     CKFLT_POS),
        CKFLT_8_CLK         = mskd_t(    CKFLT_MASK, 0b11,     CKFLT_POS),
        TRGFLT_ANY          = mskd_t(   TRGFLT_MASK, 0b00,    TRGFLT_POS),
        TRGFLT_2_CLK        = mskd_t(   TRGFLT_MASK, 0b01,    TRGFLT_POS),
        TRGFLT_4_CLK        = mskd_t(   TRGFLT_MASK, 0b10,    TRGFLT_POS),
        TRGFLT_8_CLK        = mskd_t(   TRGFLT_MASK, 0b11,    TRGFLT_POS),
        PRESC_DIV_1         = mskd_t(    PRESC_MASK, 0b000,    PRESC_POS),
        PRESC_DIV_2         = mskd_t(    PRESC_MASK, 0b001,    PRESC_POS),
        PRESC_DIV_4         = mskd_t(    PRESC_MASK, 0b010,    PRESC_POS),
        PRESC_DIV_8         = mskd_t(    PRESC_MASK, 0b011,    PRESC_POS),
        PRESC_DIV_16        = mskd_t(    PRESC_MASK, 0b100,    PRESC_POS),
        PRESC_DIV_32        = mskd_t(    PRESC_MASK, 0b101,    PRESC_POS),
        PRESC_DIV_64        = mskd_t(    PRESC_MASK, 0b110,    PRESC_POS),
        PRESC_DIV_128       = mskd_t(    PRESC_MASK, 0b111,    PRESC_POS),
        TRIGSEL_0           = mskd_t(  TRIGSEL_MASK, 0,      TRIGSEL_POS),
        TRIGSEL_1           = mskd_t(  TRIGSEL_MASK, 1,      TRIGSEL_POS),
        TRIGSEL_2           = mskd_t(  TRIGSEL_MASK, 2,      TRIGSEL_POS),
        TRIGSEL_3           = mskd_t(  TRIGSEL_MASK, 3,      TRIGSEL_POS),
        TRIGSEL_4           = mskd_t(  TRIGSEL_MASK, 4,      TRIGSEL_POS),
        TRIGSEL_5           = mskd_t(  TRIGSEL_MASK, 5,      TRIGSEL_POS),
        TRIGSEL_6           = mskd_t(  TRIGSEL_MASK, 6,      TRIGSEL_POS),
        TRIGSEL_7           = mskd_t(  TRIGSEL_MASK, 7,      TRIGSEL_POS),
        TRIGEN_SOFTWARE     = mskd_t(   TRIGEN_MASK, 0b00,    TRIGEN_POS),
        TRIGEN_RISING       = mskd_t(   TRIGEN_MASK, 0b01,    TRIGEN_POS),
        TRIGEN_FALLING      = mskd_t(   TRIGEN_MASK, 0b10,    TRIGEN_POS),
        TRIGEN_BOTH         = mskd_t(   TRIGEN_MASK, 0b11,    TRIGEN_POS);
    };  // struct Cfgr
    using cfgr_t = Reg<uint32_t, Cfgr>;
          cfgr_t   cfgr;


    struct Cr {
        using            pos_t = Pos<uint32_t, Cr>;
        static constexpr pos_t
              ENABLE_POS = pos_t( 0),
             SNGSTRT_POS = pos_t( 1),
             CNTSTRT_POS = pos_t( 2);

        using            bits_t = Bits<uint32_t, Cr>;
        static constexpr bits_t
            ENABLE           = bits_t(1,       ENABLE_POS),
            SNGSTRT          = bits_t(1,      SNGSTRT_POS),
            CNTSTRT          = bits_t(1,      CNTSTRT_POS);
    };  // struct Cr
    using cr_t = Reg<uint32_t, Cr>;
          cr_t   cr;


    struct Cmp {
        using            pos_t = Pos<uint32_t, Cmp>;
        static constexpr pos_t  CMP_POS = pos_t(0);

        static const uint32_t   CMP_MASK = 0xFFFFU;

        using           mskd_t = Mskd<uint32_t, Cmp>;
        using           shft_t = Shft<uint32_t, Cmp>;

        REGBITS_MSKD_RANGE("LpTim::Cmp",
                           CMP,
                           cmp,
                           CMP_MASK,
                           CMP_POS,
                           CMP_MASK);
    };  // struct Cmp
    using cmp_t = Reg<uint32_t, Cmp>;
          cmp_t   cmp;


    struct Arr {
        using            pos_t = Pos<uint32_t, Arr>;
        static constexpr pos_t  ARR_POS = pos_t(0);

        static const uint32_t   ARR_MASK = 0xFFFFU;

        using           mskd_t = Mskd<uint32_t, Arr>;
        using           shft_t = Shft<uint32_t, Arr>;

        REGBITS_MSKD_RANGE("LpTim::Arr",
                           ARR,
                           arr,
                           ARR_MASK,
                           ARR_POS,
                           ARR_MASK);
    };  // struct Arr
    using arr_t = Reg<uint32_t, Arr>;
          arr_t   arr;


    struct Cnt {
        using            pos_t = Pos<uint32_t, Cnt>;
        static constexpr pos_t  CNT_POS = pos_t(0);

        static const uint32_t   CNT_MASK = 0xFFFFU;

        using           mskd_t = Mskd<uint32_t, Cnt>;
        using           shft_t = Shft<uint32_t, Cnt>;

        REGBITS_MSKD_RANGE("LpTim::Cnt",
                           CNT,
                           cnt,
                           CNT_MASK,
                           CNT_POS,
                           CNT_MASK);
    };  // struct Cnt
    using cnt_t = Reg<uint32_t, Cnt>;
          cnt_t   cnt;

};  // struct LpTim
static_assert(sizeof(LpTim) == 32, "sizeof(LpTim) != 32");



struct Rtc {
    struct Tr {
        using              pos_t = Pos<uint32_t, Tr>;
        static constexpr   pos_t
                  PM_POS = pos_t(22),
                  HT_POS = pos_t(20),
                  HU_POS = pos_t(16),
                 MNT_POS = pos_t(12),
                 MNU_POS = pos_t( 8),
                  ST_POS = pos_t( 4),
                  SU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Tr>;
        static constexpr   bits_t
        PM               = bits_t(1,           PM_POS);

        static const uint32_t
                 HT_MASK =       0x3U,
                 HU_MASK =       0xFU,
                MNT_MASK =       0x7U,
                MNU_MASK =       0xFU,
                 ST_MASK =       0x7U,
                 SU_MASK =       0xFU,
                  HT_MAX =       2,
                  HU_MAX =       9,
                 MNT_MAX =       5,
                 MNU_MAX =       9,
                  ST_MAX =       5,
                  SU_MAX =       9;

        using              mskd_t = Mskd<uint32_t, Tr>;
        using              shft_t = Shft<uint32_t, Tr>;

        REGBITS_MSKD_RANGE("Rtc::Tr",
                           HT,
                           ht,
                           HT_MASK,
                           HT_POS,
                           HT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tr",
                           HU,
                           hu,
                           HU_MASK,
                           HU_POS,
                           HU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tr",
                           MNT,
                           mnt,
                           MNT_MASK,
                           MNT_POS,
                           MNT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tr",
                           MNU,
                           mnu,
                           MNU_MASK,
                           MNU_POS,
                           MNU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tr",
                           ST,
                           st,
                           ST_MASK,
                           ST_POS,
                           ST_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tr",
                           SU,
                           su,
                           SU_MASK,
                           SU_POS,
                           SU_MAX);
    };  // struct Tr
    using tr_t = Reg<uint32_t, Tr>;
          tr_t   tr;


    struct Dr {
        using              pos_t = Pos<uint32_t, Dr>;
        static constexpr   pos_t
                  YT_POS = pos_t(20),
                  YU_POS = pos_t(16),
                 WDU_POS = pos_t(13),
                  MT_POS = pos_t(12),
                  MU_POS = pos_t( 8),
                  DT_POS = pos_t( 4),
                  DU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Dr>;
        static constexpr   bits_t
        MT               = bits_t(1,           MT_POS);

        static const uint32_t
                 YT_MASK =       0xFU,
                 YU_MASK =       0xFU,
                WDU_MASK =       0x7U,
                 MU_MASK =       0xFU,
                 DT_MASK =       0x3U,
                 DU_MASK =       0xFU,
                  YT_MAX =       YT_MASK,
                  YU_MAX =       YU_MASK,
                 WDU_MAX =       WDU_MASK,
                  MU_MAX =       2,
                  DT_MAX =       3,
                  DU_MAX =       9;

        using              mskd_t = Mskd<uint32_t, Dr>;
        using              shft_t = Shft<uint32_t, Dr>;

        REGBITS_MSKD_RANGE("Rtc::Dr",
                           YT,
                           yt,
                           YT_MASK,
                           YT_POS,
                           YT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Dr",
                           YU,
                           yu,
                           YU_MASK,
                           YU_POS,
                           YU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Dr",
                           WDU,
                           wdu,
                           WDU_MASK,
                           WDU_POS,
                           WDU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Dr",
                           MU,
                           mu,
                           MU_MASK,
                           MU_POS,
                           MU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Dr",
                           DT,
                           dt,
                           DT_MASK,
                           DT_POS,
                           DT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Dr",
                           DU,
                           du,
                           DU_MASK,
                           DU_POS,
                           DU_MAX);
    };  // struct Dr
    using dr_t = Reg<uint32_t, Dr>;
          dr_t   dr;


    struct Cr {
        using              pos_t = Pos<uint32_t, Cr>;
        static constexpr   pos_t
                ITSE_POS = pos_t(24),
                 COE_POS = pos_t(23),
                OSEL_POS = pos_t(21),
                 POL_POS = pos_t(20),
               COSEL_POS = pos_t(19),
                 BKP_POS = pos_t(18),
               SUB1H_POS = pos_t(17),
               ADD1H_POS = pos_t(16),
                TSIE_POS = pos_t(15),
               WUTIE_POS = pos_t(14),
              ALRBIE_POS = pos_t(13),
              ALRAIE_POS = pos_t(12),
                 TSE_POS = pos_t(11),
                WUTE_POS = pos_t(10),
               ALRBE_POS = pos_t( 9),
               ALRAE_POS = pos_t( 8),
                 FMT_POS = pos_t( 6),
             BYPSHAD_POS = pos_t( 5),
             REFCKON_POS = pos_t( 4),
              TSEDGE_POS = pos_t( 3),
             WUCKSEL_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Cr>;
        static constexpr   bits_t
        ITSE             = bits_t(1,         ITSE_POS),
        COE              = bits_t(1,          COE_POS),
        POL              = bits_t(1,          POL_POS),
        COSEL            = bits_t(1,        COSEL_POS),
        BKP              = bits_t(1,          BKP_POS),
        SUB1H            = bits_t(1,        SUB1H_POS),
        ADD1H            = bits_t(1,        ADD1H_POS),
        TSIE             = bits_t(1,         TSIE_POS),
        WUTIE            = bits_t(1,        WUTIE_POS),
        ALRBIE           = bits_t(1,       ALRBIE_POS),
        ALRAIE           = bits_t(1,       ALRAIE_POS),
        TSE              = bits_t(1,          TSE_POS),
        WUTE             = bits_t(1,         WUTE_POS),
        ALRBE            = bits_t(1,        ALRBE_POS),
        ALRAE            = bits_t(1,        ALRAE_POS),
        FMT              = bits_t(1,          FMT_POS),
        BYPSHAD          = bits_t(1,      BYPSHAD_POS),
        REFCKON          = bits_t(1,      REFCKON_POS),
        TSEDGE           = bits_t(1,       TSEDGE_POS);

        static const uint32_t
               OSEL_MASK =       0x3U,
            WUCKSEL_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Cr>;
        static constexpr   mskd_t
        OSEL_DISABLED        = mskd_t(       OSEL_MASK,  0b00,         OSEL_POS),
        OSEL_A_ENABLED       = mskd_t(       OSEL_MASK,  0b00,         OSEL_POS),
        OSEL_B_ENABLED       = mskd_t(       OSEL_MASK,  0b00,         OSEL_POS),
        OSEL_WAKEUP_ENABLED  = mskd_t(       OSEL_MASK,  0b00,         OSEL_POS),
        WUCKSEL_RTC_DIV_16   = mskd_t(    WUCKSEL_MASK,  0b000,     WUCKSEL_POS),
        WUCKSEL_RTC_DIV_8    = mskd_t(    WUCKSEL_MASK,  0b001,     WUCKSEL_POS),
        WUCKSEL_RTC_DIV_4    = mskd_t(    WUCKSEL_MASK,  0b010,     WUCKSEL_POS),
        WUCKSEL_RTC_DIV_2    = mskd_t(    WUCKSEL_MASK,  0b011,     WUCKSEL_POS),
        WUCKSEL_CK_SPRT      = mskd_t(    WUCKSEL_MASK,  0b100,     WUCKSEL_POS),
        WUCKSEL_CK_SPRE_PLUS = mskd_t(    WUCKSEL_MASK,  0b110,     WUCKSEL_POS);
    };  // struct Cr
    using cr_t = Reg<uint32_t, Cr>;
          cr_t   cr;


    struct Isr {
        using              pos_t = Pos<uint32_t, Isr>;
        static constexpr   pos_t
                ITSF_POS = pos_t(17),
             RECALPF_POS = pos_t(16),
              TAMP3F_POS = pos_t(15),
              TAMP2F_POS = pos_t(14),
              TAMP1F_POS = pos_t(13),
               TSOVF_POS = pos_t(12),
                 TSF_POS = pos_t(11),
                WUTF_POS = pos_t(10),
               ALRBF_POS = pos_t( 9),
               ALRAF_POS = pos_t( 8),
                INIT_POS = pos_t( 7),
               INITF_POS = pos_t( 6),
                 RSF_POS = pos_t( 5),
               INITS_POS = pos_t( 4),
                SHPF_POS = pos_t( 3),
               WUTWF_POS = pos_t( 2),
              ALRBWF_POS = pos_t( 1),
              ALRAWF_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Isr>;
        static constexpr   bits_t
        ITSF             = bits_t(1,         ITSF_POS),
        RECALPF          = bits_t(1,      RECALPF_POS),
        TAMP3F           = bits_t(1,       TAMP3F_POS),
        TAMP2F           = bits_t(1,       TAMP2F_POS),
        TAMP1F           = bits_t(1,       TAMP1F_POS),
        TSOVF            = bits_t(1,        TSOVF_POS),
        TSF              = bits_t(1,          TSF_POS),
        WUTF             = bits_t(1,         WUTF_POS),
        ALRBF            = bits_t(1,        ALRBF_POS),
        ALRAF            = bits_t(1,        ALRAF_POS),
        INIT             = bits_t(1,         INIT_POS),
        INITF            = bits_t(1,        INITF_POS),
        RSF              = bits_t(1,          RSF_POS),
        INITS            = bits_t(1,        INITS_POS),
        SHPF             = bits_t(1,         SHPF_POS),
        WUTWF            = bits_t(1,        WUTWF_POS),
        ALRBWF           = bits_t(1,       ALRBWF_POS),
        ALRAWF           = bits_t(1,       ALRAWF_POS);
    };  // struct Isr
    using isr_t = Reg<uint32_t, Isr>;
          isr_t   isr;


    struct Prer {
        using              pos_t = Pos<uint32_t, Prer>;
        static constexpr   pos_t
            PREDIV_A_POS = pos_t(16),
            PREDIV_S_POS = pos_t( 0);

        static const uint32_t
           PREDIV_A_MASK =      0x7FU,
           PREDIV_S_MASK =    0x7FFFU;

        using              mskd_t = Mskd<uint32_t, Prer>;
        using              shft_t = Shft<uint32_t, Prer>;

        REGBITS_MSKD_RANGE("Rtc::Prer",
                           PREDIV_A,
                           prediv_a,
                           PREDIV_A_MASK,
                           PREDIV_A_POS,
                           PREDIV_A_MASK);
        REGBITS_MSKD_RANGE("Rtc::Prer",
                           PREDIV_S,
                           prediv_s,
                           PREDIV_S_MASK,
                           PREDIV_S_POS,
                           PREDIV_S_MASK);
    };  // struct Prer
    using prer_t = Reg<uint32_t, Prer>;
          prer_t   prer;


    struct Wutr {
        using              pos_t = Pos<uint32_t, Wutr>;
        static constexpr   pos_t
                 WUT_POS = pos_t( 0);

        static const uint32_t
                WUT_MASK =    0xFFFFU;

        using             mskd_t = Mskd<uint32_t, Wutr>;
        using             shft_t = Shft<uint32_t, Wutr>;

        REGBITS_MSKD_RANGE("Rtc::Wutr",
                           WUT,
                           wut,
                           WUT_MASK,
                           WUT_POS,
                           WUT_MASK);
    };  // struct Wutr
    using wutr_t = Reg<uint32_t, Wutr>;
          wutr_t   wutr;


    private: uint32_t   __reserved; public:


    struct Alrmar {
        using              pos_t = Pos<uint32_t, Alrmar>;
        static constexpr   pos_t
                MSK4_POS = pos_t(31),
               WDSEL_POS = pos_t(30),
                  DT_POS = pos_t(28),
                  DU_POS = pos_t(24),
                MSK3_POS = pos_t(23),
                  PM_POS = pos_t(22),
                  HT_POS = pos_t(20),
                  HU_POS = pos_t(16),
                MSK2_POS = pos_t(15),
                 MNT_POS = pos_t(12),
                 MNU_POS = pos_t( 8),
                MSK1_POS = pos_t( 7),
                  ST_POS = pos_t( 4),
                  SU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Alrmar>;
        static constexpr   bits_t
        MSK4             = bits_t(1,         MSK4_POS),
        WDSEL            = bits_t(1,        WDSEL_POS),
        MSK3             = bits_t(1,         MSK3_POS),
        PM               = bits_t(1,           PM_POS),
        MSK2             = bits_t(1,         MSK2_POS),
        MSK1             = bits_t(1,         MSK1_POS);

        static const uint32_t
                 DT_MASK =       0x3U,
                 DU_MASK =       0xFU,
                 HT_MASK =       0x3U,
                 HU_MASK =       0xFU,
                MNT_MASK =       0x7U,
                MNU_MASK =       0xFU,
                 ST_MASK =       0x7U,
                 SU_MASK =       0xFU,
                  DT_MAX =       3,
                  DU_MAX =       9,
                  HT_MAX =       1,
                  HU_MAX =       2,
                 MNT_MAX =       5,
                 MNU_MAX =       9,
                  ST_MAX =       5,
                  SU_MAX =       9;

        using              mskd_t = Mskd<uint32_t, Alrmar>;
        using              shft_t = Shft<uint32_t, Alrmar>;

        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           DT,
                           dt,
                           DT_MASK,
                           DT_POS,
                           DT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           DU,
                           du,
                           DU_MASK,
                           DU_POS,
                           DU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           HT,
                           ht,
                           HT_MASK,
                           HT_POS,
                           HT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           HU,
                           hu,
                           HU_MASK,
                           HU_POS,
                           HU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           MNT,
                           mnt,
                           MNT_MASK,
                           MNT_POS,
                           MNT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           MNU,
                           mnu,
                           MNU_MASK,
                           MNU_POS,
                           MNU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           ST,
                           st,
                           ST_MASK,
                           ST_POS,
                           ST_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmar",
                           SU,
                           su,
                           SU_MASK,
                           SU_POS,
                           SU_MAX);
    };  // struct Alrmar
    using alrmar_t = Reg<uint32_t, Alrmar>;
          alrmar_t   alrmar;


    struct Alrmbr {
        using              pos_t = Pos<uint32_t, Alrmbr>;
        static constexpr   pos_t
                MSK4_POS = pos_t(31),
               WDSEL_POS = pos_t(30),
                  DT_POS = pos_t(28),
                  DU_POS = pos_t(24),
                MSK3_POS = pos_t(23),
                  PM_POS = pos_t(22),
                  HT_POS = pos_t(20),
                  HU_POS = pos_t(16),
                MSK2_POS = pos_t(15),
                 MNT_POS = pos_t(12),
                 MNU_POS = pos_t( 8),
                MSK1_POS = pos_t( 7),
                  ST_POS = pos_t( 4),
                  SU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Alrmbr>;
        static constexpr   bits_t
        MSK4             = bits_t(1,         MSK4_POS),
        WDSEL            = bits_t(1,        WDSEL_POS),
        MSK3             = bits_t(1,         MSK3_POS),
        PM               = bits_t(1,           PM_POS),
        MSK2             = bits_t(1,         MSK2_POS),
        MSK1             = bits_t(1,         MSK1_POS);

        static const uint32_t
                 DT_MASK =       0x3U,
                 DU_MASK =       0xFU,
                 HT_MASK =       0x3U,
                 HU_MASK =       0xFU,
                MNT_MASK =       0x7U,
                MNU_MASK =       0xFU,
                 ST_MASK =       0x7U,
                 SU_MASK =       0xFU,
                  DT_MAX =       3,
                  DU_MAX =       9,
                  HT_MAX =       1,
                  HU_MAX =       2,
                 MNT_MAX =       5,
                 MNU_MAX =       9,
                  ST_MAX =       5,
                  SU_MAX =       9;

        using              mskd_t = Mskd<uint32_t, Alrmbr>;
        using              shft_t = Shft<uint32_t, Alrmbr>;

        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           DT,
                           dt,
                           DT_MASK,
                           DT_POS,
                           DT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           DU,
                           du,
                           DU_MASK,
                           DU_POS,
                           DU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           HT,
                           ht,
                           HT_MASK,
                           HT_POS,
                           HT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           HU,
                           hu,
                           HU_MASK,
                           HU_POS,
                           HU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           MNT,
                           mnt,
                           MNT_MASK,
                           MNT_POS,
                           MNT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           MNU,
                           mnu,
                           MNU_MASK,
                           MNU_POS,
                           MNU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           ST,
                           st,
                           ST_MASK,
                           ST_POS,
                           ST_MAX);
        REGBITS_MSKD_RANGE("Rtc::Alrmbr",
                           SU,
                           su,
                           SU_MASK,
                           SU_POS,
                           SU_MAX);
    };  // struct Alrmbr
    using alrmbr_t = Reg<uint32_t, Alrmbr>;
          alrmbr_t   alrmbr;


    struct Wpr {
        using              pos_t = Pos<uint32_t, Wpr>;
        static constexpr   pos_t
                 KEY_POS = pos_t( 0);

        static const uint32_t
                KEY_MASK =      0xFFU;

        using              mskd_t = Mskd<uint32_t, Wpr>;
        using              shft_t = Shft<uint32_t, Wpr>;

        REGBITS_MSKD_RANGE("Rtc::Wpr",
                           KEY,
                           key,
                           KEY_MASK,
                           KEY_POS,
                           KEY_MASK);
    };  // struct Wpr
    using wpr_t = Reg<uint32_t, Wpr>;
          wpr_t   wpr;


    struct Ssr {
        using              pos_t = Pos<uint32_t, Ssr>;
        static constexpr   pos_t
                  SS_POS = pos_t( 0);

        static const uint32_t
                 SS_MASK =    0xFFFFU;

        using              mskd_t = Mskd<uint32_t, Ssr>;
        using              shft_t = Shft<uint32_t, Ssr>;

        REGBITS_MSKD_RANGE("Rtc::Ssr",
                           SS,
                           ss,
                           SS_MASK,
                           SS_POS,
                           SS_MASK);
    };  // struct Ssr
    using ssr_t = Reg<uint32_t, Ssr>;
          ssr_t   ssr;


    struct Shiftr {
        using              pos_t = Pos<uint32_t, Shiftr>;
        static constexpr   pos_t
               SUBFS_POS = pos_t( 0),
               ADD1S_POS = pos_t(31);

        using              bits_t = Bits<uint32_t, Shiftr>;
        static constexpr   bits_t
        ADD1S            = bits_t(1,        ADD1S_POS);

        static const uint32_t
              SUBFS_MASK =    0x7FFFU;

        using              mskd_t = Mskd<uint32_t, Shiftr>;
        using              shft_t = Shft<uint32_t, Shiftr>;

        REGBITS_MSKD_RANGE("Rtc::Shiftr",
                           SUBFS,
                           subfs,
                           SUBFS_MASK,
                           SUBFS_POS,
                           SUBFS_MASK);
    };  // struct Shiftr
    using shiftr_t = Reg<uint32_t, Shiftr>;
          shiftr_t   shiftr;


    struct Tstr {
        using              pos_t = Pos<uint32_t, Tstr>;
        static constexpr   pos_t
                  PM_POS = pos_t(22),
                  HT_POS = pos_t(20),
                  HU_POS = pos_t(16),
                 MNT_POS = pos_t(12),
                 MNU_POS = pos_t( 8),
                  ST_POS = pos_t( 4),
                  SU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Tstr>;
        static constexpr   bits_t
        PM               = bits_t(1,           PM_POS);

        static const uint32_t
                 HT_MASK =       0x3U,
                 HU_MASK =       0xFU,
                MNT_MASK =       0x7U,
                MNU_MASK =       0xFU,
                 ST_MASK =       0x7U,
                 SU_MASK =       0xFU,
                  HT_MAX =       2,
                  HU_MAX =       9,
                 MNT_MAX =       5,
                 MNU_MAX =       9,
                  ST_MAX =       5,
                  SU_MAX =       9;

        using              mskd_t = Mskd<uint32_t, Tstr>;
        using              shft_t = Shft<uint32_t, Tstr>;

        REGBITS_MSKD_RANGE("Rtc::tstr",
                           HT,
                           ht,
                           HT_MASK,
                           HT_POS,
                           HT_MAX);
        REGBITS_MSKD_RANGE("Rtc::tstr",
                           HU,
                           hu,
                           HU_MASK,
                           HU_POS,
                           HU_MAX);
        REGBITS_MSKD_RANGE("Rtc::tstr",
                           MNT,
                           mnt,
                           MNT_MASK,
                           MNT_POS,
                           MNT_MAX);
        REGBITS_MSKD_RANGE("Rtc::tstr",
                           MNU,
                           mnu,
                           MNU_MASK,
                           MNU_POS,
                           MNU_MAX);
        REGBITS_MSKD_RANGE("Rtc::tstr",
                           ST,
                           st,
                           ST_MASK,
                           ST_POS,
                           ST_MAX);
        REGBITS_MSKD_RANGE("Rtc::tstr",
                           SU,
                           su,
                           SU_MASK,
                           SU_POS,
                           SU_MAX);
    };  // struct Tstr
    using tstr_t = Reg<uint32_t, Tstr>;
          tstr_t   tstr;


    struct Tsdr {
        using              pos_t = Pos<uint32_t, Tsdr>;
        static constexpr   pos_t
                 WDU_POS = pos_t(13),
                  MT_POS = pos_t(12),
                  MU_POS = pos_t( 8),
                  DT_POS = pos_t( 4),
                  DU_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Tsdr>;
        static constexpr   bits_t
        MT               = bits_t(1,           MT_POS);

        static const uint32_t
                WDU_MASK =       0x7U,
                 MU_MASK =       0xFU,
                 DT_MASK =       0x3U,
                 DU_MASK =       0xFU,
                 WDU_MAX =       WDU_MASK,
                  MU_MAX =       2,
                  DT_MAX =       3,
                  DU_MAX =       9;
        using              mskd_t = Mskd<uint32_t, Tsdr>;
        using              shft_t = Shft<uint32_t, Tsdr>;

        REGBITS_MSKD_RANGE("Rtc::Tsdr",
                           WDU,
                           wdu,
                           WDU_MASK,
                           WDU_POS,
                           WDU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tsdr",
                           MU,
                           mu,
                           MU_MASK,
                           MU_POS,
                           MU_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tsdr",
                           DT,
                           dt,
                           DT_MASK,
                           DT_POS,
                           DT_MAX);
        REGBITS_MSKD_RANGE("Rtc::Tsdr",
                           DU,
                           du,
                           DU_MASK,
                           DU_POS,
                           DU_MAX);
    };  // struct Tsdr
    using tsdr_t = Reg<uint32_t, Tsdr>;
          tsdr_t   tsdr;


    struct Tsssr {
        using              pos_t = Pos<uint32_t, Tsssr>;
        static constexpr   pos_t
                  SS_POS = pos_t( 0);

        static const uint32_t
                 SS_MASK =    0xFFFFU;

        using              mskd_t = Mskd<uint32_t, Tsssr>;
        using              shft_t = Shft<uint32_t, Tsssr>;

        REGBITS_MSKD_RANGE("Rtc::Tsssr",
                           SS,
                           ss,
                           SS_MASK,
                           SS_POS,
                           SS_MASK);
    };  // struct Tstsssr
    using tsssr_t = Reg<uint32_t, Tsssr>;
          tsssr_t   tsssr;


    struct Calr {
        using              pos_t = Pos<uint32_t, Calr>;
        static constexpr   pos_t
                CALP_POS = pos_t(15),
               CALW8_POS = pos_t(14),
              CALW16_POS = pos_t(13),
                CALM_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Calr>;
        static constexpr   bits_t
        CALP             = bits_t(1,        CALP_POS),
        CALW8            = bits_t(1,       CALW8_POS),
        CALW16           = bits_t(1,      CALW16_POS);

        static const uint32_t
              CALM_MASK =      0x1FFU;

        using              mskd_t = Mskd<uint32_t, Calr>;
        using              shft_t = Shft<uint32_t, Calr>;

        REGBITS_MSKD_RANGE("Rtc::Calr",
                           CALM,
                           calm,
                           CALM_MASK,
                           CALM_POS,
                           CALM_MASK);
    };  // struct Calr
    using calr_t = Reg<uint32_t, Calr>;
          calr_t                 calr;


    struct Tampcr {
        using              pos_t = Pos<uint32_t, Tampcr>;
        static constexpr   pos_t
             TAMP3MF_POS = pos_t(24),
        TAMP3NOERASE_POS = pos_t(23),
             TAMP3IE_POS = pos_t(22),
             TAMP2MF_POS = pos_t(21),
        TAMP2NOERASE_POS = pos_t(20),
             TAMP2IE_POS = pos_t(19),
             TAMP1MF_POS = pos_t(18),
        TAMP1NOERASE_POS = pos_t(17),
             TAMP1IE_POS = pos_t(16),
           TAMPPUDIS_POS = pos_t(15),
            TAMPPRCH_POS = pos_t(13),
             TAMPFLT_POS = pos_t(11),
            TAMPFREQ_POS = pos_t( 8),
              TAMPTS_POS = pos_t( 7),
            TAMP3TRG_POS = pos_t( 6),
              TAMP3E_POS = pos_t( 5),
            TAMP2TRG_POS = pos_t( 4),
              TAMP2E_POS = pos_t( 3),
              TAMPIE_POS = pos_t( 2),
            TAMP1TRG_POS = pos_t( 1),
              TAMP1E_POS = pos_t( 0);

        using              bits_t = Bits<uint32_t, Tampcr>;
        static constexpr   bits_t
        TAMP3MF          = bits_t(1,      TAMP3MF_POS),
        TAMP3NOERASE     = bits_t(1, TAMP3NOERASE_POS),
        TAMP3IE          = bits_t(1,      TAMP3IE_POS),
        TAMP2MF          = bits_t(1,      TAMP2MF_POS),
        TAMP2NOERASE     = bits_t(1, TAMP2NOERASE_POS),
        TAMP2IE          = bits_t(1,      TAMP2IE_POS),
        TAMP1MF          = bits_t(1,      TAMP1MF_POS),
        TAMP1NOERASE     = bits_t(1, TAMP1NOERASE_POS),
        TAMP1IE          = bits_t(1,      TAMP1IE_POS),
        TAMPPUDIS        = bits_t(1,    TAMPPUDIS_POS),
        TAMPTS           = bits_t(1,       TAMPTS_POS),
        TAMP3TRG         = bits_t(1,     TAMP3TRG_POS),
        TAMP3E           = bits_t(1,       TAMP3E_POS),
        TAMP2TRG         = bits_t(1,     TAMP2TRG_POS),
        TAMP2E           = bits_t(1,       TAMP2E_POS),
        TAMPIE           = bits_t(1,       TAMPIE_POS),
        TAMP1TRG         = bits_t(1,     TAMP1TRG_POS),
        TAMP1E           = bits_t(1,       TAMP1E_POS);

        static const uint32_t
           TAMPPRCH_MASK =       0x3U,
            TAMPFLT_MASK =       0x3U,
           TAMPFREQ_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Tampcr>;
        static constexpr   mskd_t
        TAMPPRCH_1_RTCCLK  = mskd_t(     TAMPPRCH_MASK,  0x0,      TAMPPRCH_POS),
        TAMPPRCH_2_RTCCLK  = mskd_t(     TAMPPRCH_MASK,  0x1,      TAMPPRCH_POS),
        TAMPPRCH_4_RTCCLK  = mskd_t(     TAMPPRCH_MASK,  0x2,      TAMPPRCH_POS),
        TAMPPRCH_8_RTCCLK  = mskd_t(     TAMPPRCH_MASK,  0x3,      TAMPPRCH_POS),
        TAMPFLT_EDGE       = mskd_t(      TAMPFLT_MASK,  0x1,       TAMPFLT_POS),
        TAMPFLT_2_SAMPLES  = mskd_t(      TAMPFLT_MASK,  0x2,       TAMPFLT_POS),
        TAMPFLT_4_SAMPLES  = mskd_t(      TAMPFLT_MASK,  0x3,       TAMPFLT_POS),
        TAMPFLT_8_SAMPLES  = mskd_t(      TAMPFLT_MASK,  0x4,       TAMPFLT_POS),
        TAMPFREQ_DIV_32768 = mskd_t(     TAMPFREQ_MASK,  0x0,      TAMPFREQ_POS),
        TAMPFREQ_DIV_16384 = mskd_t(     TAMPFREQ_MASK,  0x1,      TAMPFREQ_POS),
        TAMPFREQ_DIV_8192  = mskd_t(     TAMPFREQ_MASK,  0x2,      TAMPFREQ_POS),
        TAMPFREQ_DIV_4096  = mskd_t(     TAMPFREQ_MASK,  0x3,      TAMPFREQ_POS),
        TAMPFREQ_DIV_2048  = mskd_t(     TAMPFREQ_MASK,  0x4,      TAMPFREQ_POS),
        TAMPFREQ_DIV_1024  = mskd_t(     TAMPFREQ_MASK,  0x5,      TAMPFREQ_POS),
        TAMPFREQ_DIV_512   = mskd_t(     TAMPFREQ_MASK,  0x6,      TAMPFREQ_POS),
        TAMPFREQ_DIV_256    = mskd_t(    TAMPFREQ_MASK,  0x7,      TAMPFREQ_POS);
    };  // struct Tampcr
    using tampcr_t = Reg<uint32_t, Tampcr>;
          tampcr_t   tampcr;


    struct Alrmassr {
        using              pos_t = Pos<uint32_t, Alrmassr>;
        static constexpr   pos_t
              MASKSS_POS = pos_t(24),
                  SS_POS = pos_t( 0);

        static const uint32_t
             MASKSS_MASK =       0xFU,
                 SS_MASK =    0x7FFFU;

        using              mskd_t = Mskd<uint32_t, Alrmassr>;
        using              shft_t = Shft<uint32_t, Alrmassr>;

        REGBITS_MSKD_RANGE("Rtc::Alrmassr",
                           MASKSS,
                           Maskss,
                           MASKSS_MASK,
                           MASKSS_POS,
                           MASKSS_MASK);
        REGBITS_MSKD_RANGE("Rtc::Alrmassr",
                           SS,
                           Ss,
                           SS_MASK,
                           SS_POS,
                           SS_MASK);
    };  // struct Alrmassr
    using alrmassr_t = Reg<uint32_t, Alrmassr>;
          alrmassr_t   alrmassr;


    struct Alrmbssr {
        using              pos_t = Pos<uint32_t, Alrmbssr>;
        static constexpr   pos_t
              MASKSS_POS = pos_t(24),
                  SS_POS = pos_t( 0);

        static const uint32_t
             MASKSS_MASK =       0xFU,
                 SS_MASK =    0x7FFFU;

        using              mskd_t = Mskd<uint32_t, Alrmbssr>;
        using              shft_t = Shft<uint32_t, Alrmbssr>;

        REGBITS_MSKD_RANGE("Rtc::Alrmbssr",
                           MASKSS,
                           Maskss,
                           MASKSS_MASK,
                           MASKSS_POS,
                           MASKSS_MASK);
        REGBITS_MSKD_RANGE("Rtc::Alrmbssr",
                           SS,
                           Ss,
                           SS_MASK,
                           SS_POS,
                           SS_MASK);
    };  // struct Alrmbssr
    using alrmbssr_t = Reg<uint32_t, Alrmbssr>;
          alrmbssr_t   alrmbssr;


    struct Orr {
        using              pos_t = Pos<uint32_t, Orr>;
        static constexpr   pos_t
             TSINSEL_POS = pos_t( 1),
        ALARMOUTTYPE_POS = pos_t( 3);

        using              bits_t = Bits<uint32_t, Orr>;
        static constexpr   bits_t
        ALARMOUTTYPE     = bits_t(1, ALARMOUTTYPE_POS);

        static const uint32_t
            TSINSEL_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Orr>;
        static constexpr   mskd_t
        TSINSEL_PC13     = mskd_t(    TSINSEL_MASK,  0b00,      TSINSEL_POS),
        TSINSEL_PI8      = mskd_t(    TSINSEL_MASK,  0b01,      TSINSEL_POS),
        TSINSEL_PC1      = mskd_t(    TSINSEL_MASK,  0b10,      TSINSEL_POS),
        TSINSEL_PC1_DUP  = mskd_t(    TSINSEL_MASK,  0b11,      TSINSEL_POS);
    };  // struct Orr
    using orr_t = Reg<uint32_t, Orr>;
          orr_t   orr;


    struct Bkpxr {
        static const uint32_t   NUM_BKPXRS = 32;

        REGBITS_ARRAY_RANGE("Rtc::Bkpxr",
                            WORDS,
                            words,
                            uint32_t,
                            _words,
                            NUM_BKPXRS - 1);
      private:
        uint32_t    _words[NUM_BKPXRS];
    };  // struct Bkpxr
    Bkpxr   bkpxr;
    static_assert(sizeof(Bkpxr) == 128, "sizeof(Bkpxr) != 128");

};  // struct Rtc
static_assert(sizeof(Rtc) == 208, "sizeof(Rtc) != 208");



struct I2c {
    struct Cr1 {
        using            pos_t = Pos<uint32_t, Cr1>;
        static constexpr pos_t
              PE_POS = pos_t( 0),
            TXIE_POS = pos_t( 1),
            RXIE_POS = pos_t( 2),
          ADDRIE_POS = pos_t( 3),
          NACKIE_POS = pos_t( 4),
          STOPIE_POS = pos_t( 5),
            TCIE_POS = pos_t( 6),
           ERRIE_POS = pos_t( 7),
             DNF_POS = pos_t( 8),
          ANFOFF_POS = pos_t(12),
         TXDMAEN_POS = pos_t(14),
         RXDMAEN_POS = pos_t(15),
             SBC_POS = pos_t(16),
       NOSTRETCH_POS = pos_t(17),
            GCEN_POS = pos_t(19),
          SMBHEN_POS = pos_t(20),
          SMBDEN_POS = pos_t(21),
         ALERTEN_POS = pos_t(22),
           PECEN_POS = pos_t(23);

        using            bits_t = Bits<uint32_t, Cr1>;
        static constexpr bits_t
        PE               = bits_t(1,           PE_POS),
        TXIE             = bits_t(1,         TXIE_POS),
        RXIE             = bits_t(1,         RXIE_POS),
        ADDRIE           = bits_t(1,       ADDRIE_POS),
        NACKIE           = bits_t(1,       NACKIE_POS),
        STOPIE           = bits_t(1,       STOPIE_POS),
        TCIE             = bits_t(1,         TCIE_POS),
        ERRIE            = bits_t(1,        ERRIE_POS),
        ANFOFF           = bits_t(1,       ANFOFF_POS),
        TXDMAEN          = bits_t(1,      TXDMAEN_POS),
        RXDMAEN          = bits_t(1,      RXDMAEN_POS),
        SBC              = bits_t(1,          SBC_POS),
        NOSTRETCH        = bits_t(1,    NOSTRETCH_POS),
        GCEN             = bits_t(1,         GCEN_POS),
        SMBHEN           = bits_t(1,       SMBHEN_POS),
        SMBDEN           = bits_t(1,       SMBDEN_POS),
        ALERTEN          = bits_t(1,      ALERTEN_POS),
        PECEN            = bits_t(1,        PECEN_POS);

        static const uint32_t
                DNF_MASK =       0xFU;

        using    mskd_t = Mskd<uint32_t, Cr1>;
        using    shft_t = Shft<uint32_t, Cr1>;

        REGBITS_MSKD_RANGE("I2C::Cr1",
                           DNF,
                           dnf,
                           DNF_MASK,
                           DNF_POS,
                           DNF_MASK);
    };  // struct Cr1
    using cr1_t = Reg<uint32_t, Cr1>;
          cr1_t   cr1;


    struct Cr2 {
        using            pos_t = Pos<uint32_t, Cr2>;
        static constexpr pos_t
            SADD_POS = pos_t( 0),
          RD_WRN_POS = pos_t(10),
           ADD10_POS = pos_t(11),
         HEAD10R_POS = pos_t(12),
           START_POS = pos_t(13),
            STOP_POS = pos_t(14),
            NACK_POS = pos_t(15),
          NBYTES_POS = pos_t(16),
          RELOAD_POS = pos_t(24),
         AUTOEND_POS = pos_t(25),
         PECBYTE_POS = pos_t(26);

        using            bits_t = Bits<uint32_t, Cr2>;
        static constexpr bits_t
        RD_WRN           = bits_t(1,       RD_WRN_POS),
        ADD10            = bits_t(1,        ADD10_POS),
        HEAD10R          = bits_t(1,      HEAD10R_POS),
        START            = bits_t(1,        START_POS),
        STOP             = bits_t(1,         STOP_POS),
        NACK             = bits_t(1,         NACK_POS),
        RELOAD           = bits_t(1,       RELOAD_POS),
        AUTOEND          = bits_t(1,      AUTOEND_POS),
        PECBYTE          = bits_t(1,      PECBYTE_POS);

        static const uint32_t
           SADD_MASK =     0x3FFU,
         NBYTES_MASK =      0xFFU;

        using    mskd_t = Mskd<uint32_t, Cr2>;
        using    shft_t = Shft<uint32_t, Cr2>;

        REGBITS_MSKD_RANGE("I2C::Cr2",
                           SADD,
                           sadd,
                           SADD_MASK,
                           SADD_POS,
                           SADD_MASK);

        REGBITS_MSKD_RANGE("I2C::Cr2",
                           NBYTES,
                           nbytes,
                           NBYTES_MASK,
                           NBYTES_POS,
                           NBYTES_MASK);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;


    struct Oar1 {
        using            pos_t = Pos<uint32_t, Oar1>;
        static constexpr pos_t
             OA1_POS = pos_t( 0),
         OA1MODE_POS = pos_t(10),
           OA1EN_POS = pos_t(15);

        using            bits_t = Bits<uint32_t, Oar1>;
        static constexpr bits_t
        OA1MODE          = bits_t(1,      OA1MODE_POS),
        OA1EN            = bits_t(1,        OA1EN_POS);

        static const uint32_t
                    OA1_MASK =     0x3FFU;

        using    mskd_t = Mskd<uint32_t, Oar1>;
        using    shft_t = Shft<uint32_t, Oar1>;

        REGBITS_MSKD_RANGE("I2C::Oar1",
                           OA1,
                           oa1,
                           OA1_MASK,
                           OA1_POS,
                           OA1_MASK);
    };  // struct Oar1
    using oar1_t = Reg<uint32_t, Oar1>;
          oar1_t   oar1;


    struct Oar2 {
        using            pos_t = Pos<uint32_t, Oar2>;
        static constexpr pos_t
             OA2_POS = pos_t( 1),
          OA2MSK_POS = pos_t( 8),
           OA2EN_POS = pos_t(15);

        using            bits_t = Bits<uint32_t, Oar2>;
        static constexpr bits_t
        OA2EN            = bits_t(1,        OA2EN_POS);

        static const uint32_t
           OA2_MASK     =       0x7FU,
        OA2MSK_MASK     =        0x7U;

        using            mskd_t = Mskd<uint32_t, Oar2>;
        using            shft_t = Shft<uint32_t, Oar2>;

        static constexpr mskd_t
        OA2MSK_NONE     = mskd_t(OA2MSK_MASK, 0b000, OA2MSK_POS),
        OA2MSK_BIT_1    = mskd_t(OA2MSK_MASK, 0b001, OA2MSK_POS),
        OA2MSK_BITS_2_1 = mskd_t(OA2MSK_MASK, 0b010, OA2MSK_POS),
        OA2MSK_BITS_3_1 = mskd_t(OA2MSK_MASK, 0b011, OA2MSK_POS),
        OA2MSK_BITS_4_1 = mskd_t(OA2MSK_MASK, 0b100, OA2MSK_POS),
        OA2MSK_BITS_5_1 = mskd_t(OA2MSK_MASK, 0b101, OA2MSK_POS),
        OA2MSK_BITS_6_1 = mskd_t(OA2MSK_MASK, 0b110, OA2MSK_POS),
        OA2MSK_BITS_7_1 = mskd_t(OA2MSK_MASK, 0b110, OA2MSK_POS);

        REGBITS_MSKD_RANGE("I2C::Oar2",
                           OA2,
                           oa2,
                           OA2_MASK,
                           OA2_POS,
                           OA2_MASK);

    };  // struct Oar2
    using oar2_t = Reg<uint32_t, Oar2>;
          oar2_t   oar2;


    struct Timingr {
        using            pos_t = Pos<uint32_t, Timingr>;
        static constexpr pos_t
            SCLL_POS = pos_t( 0),
            SCLH_POS = pos_t( 8),
          SDADEL_POS = pos_t(16),
          SCLDEL_POS = pos_t(20),
           PRESC_POS = pos_t(28);

        static const uint32_t
               SCLL_MASK =      0xFFU,
               SCLH_MASK =      0xFFU,
             SDADEL_MASK =       0xFU,
             SCLDEL_MASK =       0xFU,
              PRESC_MASK =       0xFU;

        using            mskd_t = Mskd<uint32_t, Timingr>;
        using            shft_t = Shft<uint32_t, Timingr>;

        REGBITS_MSKD_RANGE("I2C::Timingr",
                           SCLL,
                           scll,
                           SCLL_MASK,
                           SCLL_POS,
                           SCLL_MASK);
        REGBITS_MSKD_RANGE("I2C::Timingr",
                           SCLH,
                           sclh,
                           SCLH_MASK,
                           SCLH_POS,
                           SCLH_MASK);
        REGBITS_MSKD_RANGE("I2C::Timingr",
                           SDADEL,
                           sdadel,
                           SDADEL_MASK,
                           SDADEL_POS,
                           SDADEL_MASK);
        REGBITS_MSKD_RANGE("I2C::Timingr",
                           SCLDEL,
                           scldel,
                           SCLDEL_MASK,
                           SCLDEL_POS,
                           SCLDEL_MASK);
        REGBITS_MSKD_RANGE("I2C::Timingr",
                           PRESC,
                           presc,
                           PRESC_MASK,
                           PRESC_POS,
                           PRESC_MASK);
    };  // struct Timingr
    using timingr_t = Reg<uint32_t, Timingr>;
          timingr_t   timingr;


    struct Timeoutr {
        using            pos_t = Pos<uint32_t, Timeoutr>;
        static constexpr pos_t
            TIMEOUTA_POS = pos_t( 0),
               TIDLE_POS = pos_t(12),
            TIMOUTEN_POS = pos_t(15),
            TIMEOUTB_POS = pos_t(16),
              TEXTEN_POS = pos_t(31);

        using            bits_t = Bits<uint32_t, Timeoutr>;
        static constexpr bits_t
        TIDLE            = bits_t(1,        TIDLE_POS),
        TIMOUTEN         = bits_t(1,     TIMOUTEN_POS),
        TEXTEN           = bits_t(1,       TEXTEN_POS);

        static const uint32_t
           TIMEOUTA_MASK =     0xFFFU,
           TIMEOUTB_MASK =     0xFFFU;

        using            mskd_t = Mskd<uint32_t, Timeoutr>;
        using            shft_t = Shft<uint32_t, Timeoutr>;

        REGBITS_MSKD_RANGE("I2C::Timoutr",
                           TIMEOUTA,
                           timeouta,
                           TIMEOUTA_MASK,
                           TIMEOUTA_POS,
                           TIMEOUTA_MASK);
        REGBITS_MSKD_RANGE("I2C::Timoutr",
                           TIMEOUTB,
                           timeoutb,
                           TIMEOUTB_MASK,
                           TIMEOUTB_POS,
                           TIMEOUTB_MASK);
    };  // struct Timeoutr
    using timeoutr_t = Reg<uint32_t, Timeoutr>;
          timeoutr_t   timeoutr;


    struct Isr {
        using            pos_t = Pos<uint32_t, Isr>;
        static constexpr pos_t
             TXE_POS = pos_t( 0),
            TXIS_POS = pos_t( 1),
            RXNE_POS = pos_t( 2),
            ADDR_POS = pos_t( 3),
           NACKF_POS = pos_t( 4),
           STOPF_POS = pos_t( 5),
              TC_POS = pos_t( 6),
             TCR_POS = pos_t( 7),
            BERR_POS = pos_t( 8),
            ARLO_POS = pos_t( 9),
             OVR_POS = pos_t(10),
          PECERR_POS = pos_t(11),
         TIMEOUT_POS = pos_t(12),
           ALERT_POS = pos_t(13),
            BUSY_POS = pos_t(15),
             DIR_POS = pos_t(16),
         ADDCODE_POS = pos_t(17);

        using            bits_t = Bits<uint32_t, Isr>;
        static constexpr bits_t
        TXE              = bits_t(1,          TXE_POS),
        TXIS             = bits_t(1,         TXIS_POS),
        RXNE             = bits_t(1,         RXNE_POS),
        ADDR             = bits_t(1,         ADDR_POS),
        NACKF            = bits_t(1,        NACKF_POS),
        STOPF            = bits_t(1,        STOPF_POS),
        TC               = bits_t(1,           TC_POS),
        TCR              = bits_t(1,          TCR_POS),
        BERR             = bits_t(1,         BERR_POS),
        ARLO             = bits_t(1,         ARLO_POS),
        OVR              = bits_t(1,          OVR_POS),
        PECERR           = bits_t(1,       PECERR_POS),
        TIMEOUT          = bits_t(1,      TIMEOUT_POS),
        ALERT            = bits_t(1,        ALERT_POS),
        BUSY             = bits_t(1,         BUSY_POS),
        DIR              = bits_t(1,          DIR_POS);

        static const uint32_t
                ADDCODE_MASK =      0x7FU;

        using            mskd_t = Mskd<uint32_t, Isr>;
        using            shft_t = Shft<uint32_t, Isr>;

        REGBITS_MSKD_RANGE("I2C::Isr",
                           ADDCODE,
                           addcode,
                           ADDCODE_MASK,
                           ADDCODE_POS,
                           ADDCODE_MASK);
    };  // struct Isr
    using isr_t = Reg<uint32_t, Isr>;
          isr_t   isr;



    struct Icr {
        using            pos_t = Pos<uint32_t, Icr>;
        static constexpr pos_t
          ADDRCF_POS = pos_t( 3),
          NACKCF_POS = pos_t( 4),
          STOPCF_POS = pos_t( 5),
          BERRCF_POS = pos_t( 8),
          ARLOCF_POS = pos_t( 9),
           OVRCF_POS = pos_t(10),
           PECCF_POS = pos_t(11),
        TIMOUTCF_POS = pos_t(12),
         ALERTCF_POS = pos_t(13);

        using            bits_t = Bits<uint32_t, Icr>;
        static constexpr bits_t
        ADDRCF           = bits_t(1,       ADDRCF_POS),
        NACKCF           = bits_t(1,       NACKCF_POS),
        STOPCF           = bits_t(1,       STOPCF_POS),
        BERRCF           = bits_t(1,       BERRCF_POS),
        ARLOCF           = bits_t(1,       ARLOCF_POS),
        OVRCF            = bits_t(1,        OVRCF_POS),
        PECCF            = bits_t(1,        PECCF_POS),
        TIMOUTCF         = bits_t(1,     TIMOUTCF_POS),
        ALERTCF          = bits_t(1,      ALERTCF_POS);
    };  // struct Icr
    using icr_t = Reg<uint32_t, Icr>;
          icr_t   icr;


    struct Pecr {
        using            pos_t = Pos<uint32_t, Pecr>;
        static constexpr pos_t
             PEC_POS = pos_t( 0);

        static const uint32_t
            PEC_MASK =      0xFFU;

        using            mskd_t = Mskd<uint32_t, Pecr>;
        static constexpr mskd_t
                    PEC = mskd_t(PEC_MASK, PEC_MASK, PEC_POS);
    };  // struct Pecr
    using pecr_t = Reg<uint32_t, Pecr>;
          pecr_t   pecr;


    struct Rxdr {
        using            pos_t = Pos<uint32_t, Rxdr>;
        static constexpr pos_t
          RXDATA_POS = pos_t( 0);

        static const uint32_t
             RXDATA_MASK =      0xFFU;

        using            mskd_t = Mskd<uint32_t, Rxdr>;
        static constexpr mskd_t
                    RXDATA = mskd_t(RXDATA_MASK, RXDATA_MASK, RXDATA_POS);
    };  // struct Rxdr
    using rxdr_t = Reg<uint32_t, Rxdr>;
          rxdr_t   rxdr;


    struct Txdr {
        using            pos_t = Pos<uint32_t, Txdr>;
        static constexpr pos_t
          TXDATA_POS = pos_t( 0);

        static const uint32_t
             TXDATA_MASK =      0xFFU;

        using            mskd_t = Mskd<uint32_t, Txdr>;
        using            shft_t = Shft<uint32_t, Txdr>;

        REGBITS_MSKD_RANGE("I2c::Txdr",
                           TXDATA,
                           txdata,
                           TXDATA_MASK,
                           TXDATA_POS,
                           TXDATA_MASK);
    };  // struct Txdr
    using txdr_t = Reg<uint32_t, Txdr>;
          txdr_t   txdr;

};  // struct I2c
static_assert(sizeof(I2c) == 44, "sizeof(I2c) != 44");



struct Usart {
    struct Cr1 {
        using              pos_t = Pos<uint32_t, Cr1>;
        static constexpr   pos_t
                  UE_POS = pos_t( 0),
                  RE_POS = pos_t( 2),
                  TE_POS = pos_t( 3),
              IDLEIE_POS = pos_t( 4),
              RXNEIE_POS = pos_t( 5),
                TCIE_POS = pos_t( 6),
               TXEIE_POS = pos_t( 7),
                PEIE_POS = pos_t( 8),
                  PS_POS = pos_t( 9),
                 PCE_POS = pos_t(10),
                WAKE_POS = pos_t(11),
                   M_POS = pos_t(12),
                 MME_POS = pos_t(13),
                CMIE_POS = pos_t(14),
               OVER8_POS = pos_t(15),
                DEDT_POS = pos_t(16),
                DEAT_POS = pos_t(21),
               RTOIE_POS = pos_t(26),
               EOBIE_POS = pos_t(27);

        using              bits_t = Bits<uint32_t, Cr1>;
        static constexpr   bits_t
        UE               = bits_t(1,           UE_POS),
        RE               = bits_t(1,           RE_POS),
        TE               = bits_t(1,           TE_POS),
        IDLEIE           = bits_t(1,       IDLEIE_POS),
        RXNEIE           = bits_t(1,       RXNEIE_POS),
        TCIE             = bits_t(1,         TCIE_POS),
        TXEIE            = bits_t(1,        TXEIE_POS),
        PEIE             = bits_t(1,         PEIE_POS),
        PS               = bits_t(1,           PS_POS),
        PCE              = bits_t(1,          PCE_POS),
        WAKE             = bits_t(1,         WAKE_POS),
        MME              = bits_t(1,          MME_POS),
        CMIE             = bits_t(1,         CMIE_POS),
        OVER8            = bits_t(1,        OVER8_POS),
        RTOIE            = bits_t(1,        RTOIE_POS),
        EOBIE            = bits_t(1,        EOBIE_POS);

        static const uint32_t
                  M_MASK =   0x10001U,
               DEDT_MASK =      0x1FU,
               DEAT_MASK =      0x1FU;

        using              mskd_t = Mskd<uint32_t, Cr1>;
        using              shft_t = Shft<uint32_t, Cr1>;

        static constexpr   mskd_t
        M_8_DATA_BITS    = mskd_t(          M_MASK,  0b00,             M_POS),
        M_9_DATA_BITS    = mskd_t(          M_MASK,  0b01,             M_POS),
        M_7_DATA_BITS    = mskd_t(          M_MASK,  0b10,             M_POS);

        REGBITS_MSKD_RANGE("Usart::Cr1",
                           DEDT,
                           dedt,
                           DEDT_MASK,
                           DEDT_POS,
                           DEDT_MASK);
        REGBITS_MSKD_RANGE("Usart::Cr1",
                           DEAT,
                           deat,
                           DEAT_MASK,
                           DEAT_POS,
                           DEAT_MASK);
    };  // struct Cr1
    using cr1_t = Reg<uint32_t, Cr1>;
          cr1_t   cr1;


    struct Cr2 {
        using              pos_t = Pos<uint32_t, Cr2>;
        static constexpr   pos_t
               ADDM7_POS = pos_t( 4),
                LBDL_POS = pos_t( 5),
               LBDIE_POS = pos_t( 6),
                LBCL_POS = pos_t( 8),
                CPHA_POS = pos_t( 9),
                CPOL_POS = pos_t(10),
               CLKEN_POS = pos_t(11),
                STOP_POS = pos_t(12),
               LINEN_POS = pos_t(14),
                SWAP_POS = pos_t(15),
               RXINV_POS = pos_t(16),
               TXINV_POS = pos_t(17),
             DATAINV_POS = pos_t(18),
            MSBFIRST_POS = pos_t(19),
               ABREN_POS = pos_t(20),
             ABRMODE_POS = pos_t(21),
               RTOEN_POS = pos_t(23),
                 ADD_POS = pos_t(24);

        using              bits_t = Bits<uint32_t, Cr2>;
        static constexpr   bits_t
        ADDM7            = bits_t(1,        ADDM7_POS),
        LBDL             = bits_t(1,         LBDL_POS),
        LBDIE            = bits_t(1,        LBDIE_POS),
        LBCL             = bits_t(1,         LBCL_POS),
        CPHA             = bits_t(1,         CPHA_POS),
        CPOL             = bits_t(1,         CPOL_POS),
        CLKEN            = bits_t(1,        CLKEN_POS),
        LINEN            = bits_t(1,        LINEN_POS),
        SWAP             = bits_t(1,         SWAP_POS),
        RXINV            = bits_t(1,        RXINV_POS),
        TXINV            = bits_t(1,        TXINV_POS),
        DATAINV          = bits_t(1,      DATAINV_POS),
        MSBFIRST         = bits_t(1,     MSBFIRST_POS),
        ABREN            = bits_t(1,        ABREN_POS),
        RTOEN            = bits_t(1,        RTOEN_POS);

        static const uint32_t
               STOP_MASK =       0x3U,
            ABRMODE_MASK =       0x3U,
                ADD_MASK =      0xFFU;

        using              mskd_t = Mskd<uint32_t, Cr2>;
        using              shft_t = Shft<uint32_t, Cr2>;

        static constexpr   mskd_t
        STOP_1_BIT         = mskd_t(   STOP_MASK,    0b00,         STOP_POS),
        STOP_0_5_BITS      = mskd_t(   STOP_MASK,    0b01,         STOP_POS),
        STOP_2_BITS        = mskd_t(   STOP_MASK,    0b10,         STOP_POS),
        STOP_1_5_BITS      = mskd_t(   STOP_MASK,    0b11,         STOP_POS),
        ABRMODE_START_BIT  = mskd_t(ABRMODE_MASK,    0b00,      ABRMODE_POS),
        ABRMODE_FALL_EDGE  = mskd_t(ABRMODE_MASK,    0b01,      ABRMODE_POS),
        ABRMODE_0X7F_FRAME = mskd_t(ABRMODE_MASK,    0b10,      ABRMODE_POS),
        ABRMODE_0X55_FRAME = mskd_t(ABRMODE_MASK,    0b11,      ABRMODE_POS);

        REGBITS_MSKD_RANGE("Usart::Cr2",
                           ADD,
                           add,
                           ADD_MASK,
                           ADD_POS,
                           ADD_MASK);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;


    struct Cr3 {
        using              pos_t = Pos<uint32_t, Cr3>;
        static constexpr   pos_t
                 EIE_POS = pos_t( 0),
                IREN_POS = pos_t( 1),
                IRLP_POS = pos_t( 2),
               HDSEL_POS = pos_t( 3),
                NACK_POS = pos_t( 4),
                SCEN_POS = pos_t( 5),
                DMAR_POS = pos_t( 6),
                DMAT_POS = pos_t( 7),
                RTSE_POS = pos_t( 8),
                CTSE_POS = pos_t( 9),
               CTSIE_POS = pos_t(10),
              ONEBIT_POS = pos_t(11),
              OVRDIS_POS = pos_t(12),
                DDRE_POS = pos_t(13),
                 DEM_POS = pos_t(14),
                 DEP_POS = pos_t(15),
             SCARCNT_POS = pos_t(17);

        using              bits_t = Bits<uint32_t, Cr3>;
        static constexpr   bits_t
        EIE              = bits_t(1,          EIE_POS),
        IREN             = bits_t(1,         IREN_POS),
        IRLP             = bits_t(1,         IRLP_POS),
        HDSEL            = bits_t(1,        HDSEL_POS),
        NACK             = bits_t(1,         NACK_POS),
        SCEN             = bits_t(1,         SCEN_POS),
        DMAR             = bits_t(1,         DMAR_POS),
        DMAT             = bits_t(1,         DMAT_POS),
        RTSE             = bits_t(1,         RTSE_POS),
        CTSE             = bits_t(1,         CTSE_POS),
        CTSIE            = bits_t(1,        CTSIE_POS),
        ONEBIT           = bits_t(1,       ONEBIT_POS),
        OVRDIS           = bits_t(1,       OVRDIS_POS),
        DDRE             = bits_t(1,         DDRE_POS),
        DEM              = bits_t(1,          DEM_POS),
        DEP              = bits_t(1,          DEP_POS);

        static const uint32_t
            SCARCNT_MASK =       0x7U;

        using              mskd_t = Mskd<uint32_t, Cr3>;
        using              shft_t = Shft<uint32_t, Cr3>;

        REGBITS_MSKD_RANGE("Usart::Cr3",
                           SCARCNT,
                           scarcnt,
                           SCARCNT_MASK,
                           SCARCNT_POS,
                           SCARCNT_MASK);
    };  // struct Cr3
    using cr3_t = Reg<uint32_t, Cr3>;
          cr3_t   cr3;


    struct Brr {
        using              pos_t = Pos<uint32_t, Brr>;
        static constexpr   pos_t
        DIV_FRACTION_POS = pos_t( 0),
        DIV_MANTISSA_POS = pos_t( 4);

        static const uint32_t
        DIV_FRACTION_MASK =       0xFU,
        DIV_MANTISSA_MASK =     0xFFFU;

        using              mskd_t = Mskd<uint32_t, Brr>;
        using              shft_t = Shft<uint32_t, Brr>;

        REGBITS_MSKD_RANGE("Usart::Brr",
                           DIV_FRACTION,
                           div_fraction,
                           DIV_FRACTION_MASK,
                           DIV_FRACTION_POS,
                           DIV_FRACTION_MASK);
        REGBITS_MSKD_RANGE("Usart::Brr",
                           DIV_MANTISSA,
                           div_mantissa,
                           DIV_MANTISSA_MASK,
                           DIV_MANTISSA_POS,
                           DIV_MANTISSA_MASK);
    };  // struct Brr
    using brr_t = Reg<uint32_t, Brr>;
          brr_t   brr;


    struct Gtpr {
        using              pos_t = Pos<uint32_t, Gtpr>;
        static constexpr   pos_t
                 PSC_POS = pos_t( 0),
                  GT_POS = pos_t( 8);

        static const uint32_t
                PSC_MASK =      0xFFU,
                 GT_MASK =      0xFFU;

        using              mskd_t = Mskd<uint32_t, Gtpr>;
        using              shft_t = Shft<uint32_t, Gtpr>;

        REGBITS_MSKD_RANGE("Usart::Gtpr",
                           PSC,
                           psc,
                           PSC_MASK,
                           PSC_POS,
                           PSC_MASK);
        REGBITS_MSKD_RANGE("Usart::Gtpr",
                           GT,
                           gt,
                           GT_MASK,
                           GT_POS,
                           GT_MASK);
    };  // struct Gtpr
    using gtpr_t = Reg<uint32_t, Gtpr>;
          gtpr_t   gtpr;


    struct Rtor {
        using              pos_t = Pos<uint32_t, Rtor>;
        static constexpr   pos_t
                 RTO_POS = pos_t( 0),
                BLEN_POS = pos_t(24);

        static const uint32_t
                RTO_MASK =  0xFFFFFFU,
               BLEN_MASK =      0xFFU;

        using              mskd_t = Mskd<uint32_t, Rtor>;
        using              shft_t = Shft<uint32_t, Rtor>;

        REGBITS_MSKD_RANGE("Usart::Rtor",
                           RTO,
                           rto,
                           RTO_MASK,
                           RTO_POS,
                           RTO_MASK);
        REGBITS_MSKD_RANGE("Usart::Rtor",
                           BLEN,
                           blen,
                           BLEN_MASK,
                           BLEN_POS,
                           BLEN_MASK);
    };  // struct Rtor
    using rtor_t = Reg<uint32_t, Rtor>;
          rtor_t   rtor;


    struct Rqr {
        using              pos_t = Pos<uint32_t, Rqr>;
        static constexpr   pos_t
               ABRRQ_POS = pos_t( 0),
               SBKRQ_POS = pos_t( 1),
                MMRQ_POS = pos_t( 2),
               RXFRQ_POS = pos_t( 3),
               TXFRQ_POS = pos_t( 4);

        using              bits_t = Bits<uint32_t, Rqr>;
        static constexpr   bits_t
        ABRRQ            = bits_t(1,        ABRRQ_POS),
        SBKRQ            = bits_t(1,        SBKRQ_POS),
        MMRQ             = bits_t(1,         MMRQ_POS),
        RXFRQ            = bits_t(1,        RXFRQ_POS),
        TXFRQ            = bits_t(1,        TXFRQ_POS);
    };  // struct Rqr
    using rqr_t = Reg<uint32_t, Rqr>;
          rqr_t   rqr;



    struct Isr {
        using              pos_t = Pos<uint32_t, Isr>;
        static constexpr   pos_t
                  PE_POS = pos_t( 0),
                  FE_POS = pos_t( 1),
                  NE_POS = pos_t( 2),
                 ORE_POS = pos_t( 3),
                IDLE_POS = pos_t( 4),
                RXNE_POS = pos_t( 5),
                  TC_POS = pos_t( 6),
                 TXE_POS = pos_t( 7),
                LBDF_POS = pos_t( 8),
               CTSIF_POS = pos_t( 9),
                 CTS_POS = pos_t(10),
                RTOF_POS = pos_t(11),
                EOBF_POS = pos_t(12),
                ABRE_POS = pos_t(14),
                ABRF_POS = pos_t(15),
                BUSY_POS = pos_t(16),
                 CMF_POS = pos_t(17),
                SBKF_POS = pos_t(18),
                 RWU_POS = pos_t(19),
               TEACK_POS = pos_t(21);

        using              bits_t = Bits<uint32_t, Isr>;
        static constexpr   bits_t
        PE               = bits_t(1,           PE_POS),
        FE               = bits_t(1,           FE_POS),
        NE               = bits_t(1,           NE_POS),
        ORE              = bits_t(1,          ORE_POS),
        IDLE             = bits_t(1,         IDLE_POS),
        RXNE             = bits_t(1,         RXNE_POS),
        TC               = bits_t(1,           TC_POS),
        TXE              = bits_t(1,          TXE_POS),
        LBDF             = bits_t(1,         LBDF_POS),
        CTSIF            = bits_t(1,        CTSIF_POS),
        CTS              = bits_t(1,          CTS_POS),
        RTOF             = bits_t(1,         RTOF_POS),
        EOBF             = bits_t(1,         EOBF_POS),
        ABRE             = bits_t(1,         ABRE_POS),
        ABRF             = bits_t(1,         ABRF_POS),
        BUSY             = bits_t(1,         BUSY_POS),
        CMF              = bits_t(1,          CMF_POS),
        SBKF             = bits_t(1,         SBKF_POS),
        RWU              = bits_t(1,          RWU_POS),
        TEACK            = bits_t(1,        TEACK_POS);
    };  // struct Isr
    using isr_t = Reg<uint32_t, Isr>;
          isr_t   isr;


    struct Icr {
        using              pos_t = Pos<uint32_t, Icr>;
        static constexpr   pos_t
                PECF_POS = pos_t( 0),
                FECF_POS = pos_t( 1),
                 NCF_POS = pos_t( 2),
               ORECF_POS = pos_t( 3),
              IDLECF_POS = pos_t( 4),
                TCCF_POS = pos_t( 6),
               LBDCF_POS = pos_t( 8),
               CTSCF_POS = pos_t( 9),
               RTOCF_POS = pos_t(11),
               EOBCF_POS = pos_t(12),
                CMCF_POS = pos_t(17);

        using              bits_t = Bits<uint32_t, Icr>;
        static constexpr   bits_t
        PECF             = bits_t(1,         PECF_POS),
        FECF             = bits_t(1,         FECF_POS),
        NCF              = bits_t(1,          NCF_POS),
        ORECF            = bits_t(1,        ORECF_POS),
        IDLECF           = bits_t(1,       IDLECF_POS),
        TCCF             = bits_t(1,         TCCF_POS),
        LBDCF            = bits_t(1,        LBDCF_POS),
        CTSCF            = bits_t(1,        CTSCF_POS),
        RTOCF            = bits_t(1,        RTOCF_POS),
        EOBCF            = bits_t(1,        EOBCF_POS),
        CMCF             = bits_t(1,         CMCF_POS);
    };  // struct Icr
    using icr_t = Reg<uint32_t, Icr>;
          icr_t   icr;

    struct Rdr {
        using              pos_t = Pos<uint32_t, Rdr>;
        static constexpr   pos_t
                 RDR_POS = pos_t( 0);

        static const uint32_t
                RDR_MASK =     0x1FFU;

        using   shft_t = Shft<uint32_t, Rdr>;

        shft_t  RDR = shft_t(RDR_MASK, RDR_POS);
    };  // struct Rdr
    using rdr_t = Reg<uint32_t, Rdr>;
          rdr_t   rdr;


    struct Tdr {
        using              pos_t = Pos<uint32_t, Tdr>;
        static constexpr   pos_t
                 TDR_POS = pos_t( 0);

        static const uint32_t
                TDR_MASK =     0x1FFU;

        using              mskd_t = Mskd<uint32_t, Tdr>;
        using              shft_t = Shft<uint32_t, Tdr>;

        REGBITS_MSKD_RANGE("Usart::Tdr",
                           TDR,
                           tdr,
                           TDR_MASK,
                           TDR_POS,
                           TDR_MASK);
    };  // struct Tdr
    using tdr_t = Reg<uint32_t, Tdr>;
          tdr_t   tdr;

};  // struct Usart
static_assert(sizeof(Usart) == 44, "sizeof(Usart) != 44");



struct Spi {
    struct Cr1 {
        using            pos_t = Pos<uint32_t, Cr1>;
        static constexpr pos_t
                CPHA_POS = pos_t( 0),
                CPOL_POS = pos_t( 1),
                MSTR_POS = pos_t( 2),
                  BR_POS = pos_t( 3),
                 SPE_POS = pos_t( 6),
            LSBFIRST_POS = pos_t( 7),
                 SSI_POS = pos_t( 8),
                 SSM_POS = pos_t( 9),
              RXONLY_POS = pos_t(10),
                CRCL_POS = pos_t(11),
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
        CRCL             = bits_t(1,         CRCL_POS),
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
                NSSP_POS = pos_t( 3),
                 FRF_POS = pos_t( 4),
               ERRIE_POS = pos_t( 5),
              RXNEIE_POS = pos_t( 6),
               TXEIE_POS = pos_t( 7),
                  DS_POS = pos_t( 8),
               FRXTH_POS = pos_t(12),
              LDMARX_POS = pos_t(13),
              LDMATX_POS = pos_t(14);

        using              bits_t = Bits<uint32_t, Cr2>;
        static constexpr   bits_t
        RXDMAEN          = bits_t(1,      RXDMAEN_POS),
        TXDMAEN          = bits_t(1,      TXDMAEN_POS),
        SSOE             = bits_t(1,         SSOE_POS),
        NSSP             = bits_t(1,         NSSP_POS),
        FRF              = bits_t(1,          FRF_POS),
        ERRIE            = bits_t(1,        ERRIE_POS),
        RXNEIE           = bits_t(1,       RXNEIE_POS),
        TXEIE            = bits_t(1,        TXEIE_POS),
        FRXTH            = bits_t(1,        FRXTH_POS),
        LDMARX           = bits_t(1,       LDMARX_POS),
        LDMATX           = bits_t(1,       LDMATX_POS);

        static const uint32_t
                 DS_MASK =       0xFU;

        using              mskd_t = Mskd<uint32_t, Cr2>;
        static constexpr   mskd_t
        DS_4             = mskd_t(         DS_MASK,  0b0011,         DS_POS),
        DS_5             = mskd_t(         DS_MASK,  0b0100,         DS_POS),
        DS_6             = mskd_t(         DS_MASK,  0b0101,         DS_POS),
        DS_7             = mskd_t(         DS_MASK,  0b0110,         DS_POS),
        DS_8             = mskd_t(         DS_MASK,  0b0111,         DS_POS),
        DS_9             = mskd_t(         DS_MASK,  0b1000,         DS_POS),
        DS_10            = mskd_t(         DS_MASK,  0b1001,         DS_POS),
        DS_11            = mskd_t(         DS_MASK,  0b1010,         DS_POS),
        DS_12            = mskd_t(         DS_MASK,  0b1011,         DS_POS),
        DS_13            = mskd_t(         DS_MASK,  0b1100,         DS_POS),
        DS_14            = mskd_t(         DS_MASK,  0b1101,         DS_POS),
        DS_15            = mskd_t(         DS_MASK,  0b1110,         DS_POS),
        DS_16            = mskd_t(         DS_MASK,  0b1111,         DS_POS);
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
                 BSY_POS = pos_t( 7),
                 FRE_POS = pos_t( 8),
               FRLVL_POS = pos_t( 9),
               FTLVL_POS = pos_t(11);

        using              bits_t = Bits<uint32_t, Sr>;
        static constexpr   bits_t
        RXNE             = bits_t(1,         RXNE_POS),
        TXE              = bits_t(1,          TXE_POS),
        CHSIDE           = bits_t(1,       CHSIDE_POS),
        UDR              = bits_t(1,          UDR_POS),
        CRCERR           = bits_t(1,       CRCERR_POS),
        MODF             = bits_t(1,         MODF_POS),
        OVR              = bits_t(1,          OVR_POS),
        BSY              = bits_t(1,          BSY_POS),
        FRE              = bits_t(1,          FRE_POS);

        static const uint32_t
              FRLVL_MASK =       0x3U,
              FTLVL_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Sr>;
        static constexpr   mskd_t
        FRLVL_EMPTY     = mskd_t(      FRLVL_MASK,  0b00,        FRLVL_POS),
        FRLVL_QURTR     = mskd_t(      FRLVL_MASK,  0b01,        FRLVL_POS),
        FRLVL_HALF      = mskd_t(      FRLVL_MASK,  0b10,        FRLVL_POS),
        FRLVL_FULL      = mskd_t(      FRLVL_MASK,  0b11,        FRLVL_POS),
        FTLVL_EMPTY     = mskd_t(      FTLVL_MASK,  0b00,        FTLVL_POS),
        FTLVL_QURTR     = mskd_t(      FTLVL_MASK,  0b01,        FTLVL_POS),
        FTLVL_HALF      = mskd_t(      FTLVL_MASK,  0b10,        FTLVL_POS),
        FTLVL_FULL      = mskd_t(      FTLVL_MASK,  0b11,        FTLVL_POS);
    };  // struct Sr
    using sr_t = Reg<uint32_t, Sr>;
          sr_t   sr;


    union {
        uint16_t      dr16;
        struct {
            uint8_t   dr8,
                     _high_byte;
        };
    };

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
               CHLEN_POS = pos_t( 0),
              DATLEN_POS = pos_t( 1),
               CKPOL_POS = pos_t( 3),
              I2SSTD_POS = pos_t( 4),
             PCMSYNC_POS = pos_t( 7),
              I2SCFG_POS = pos_t( 8),
                I2SE_POS = pos_t(10),
              I2SMOD_POS = pos_t(11),
             ASTRTEN_POS = pos_t(12);

        using              bits_t = Bits<uint32_t, I2scfgr>;
        static constexpr   bits_t
        CHLEN            = bits_t(1,        CHLEN_POS),
        CKPOL            = bits_t(1,        CKPOL_POS),
        PCMSYNC          = bits_t(1,      PCMSYNC_POS),
        I2SE             = bits_t(1,         I2SE_POS),
        I2SMOD           = bits_t(1,       I2SMOD_POS),
        ASTRTEN          = bits_t(1,      ASTRTEN_POS);

        static const uint32_t
             DATLEN_MASK =       0x3U,
             I2SSTD_MASK =       0x3U,
             I2SCFG_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, I2scfgr>;
        static constexpr   mskd_t
        DATLEN_16        = mskd_t(     DATLEN_MASK,  0b00,       DATLEN_POS),
        DATLEN_24        = mskd_t(     DATLEN_MASK,  0b01,       DATLEN_POS),
        DATLEN_32        = mskd_t(     DATLEN_MASK,  0b10,       DATLEN_POS),
        I2SSTD_I2S       = mskd_t(     I2SSTD_MASK,  0b00,       I2SSTD_POS),
        I2SSTD_MSB       = mskd_t(     I2SSTD_MASK,  0b01,       I2SSTD_POS),
        I2SSTD_LSB       = mskd_t(     I2SSTD_MASK,  0b10,       I2SSTD_POS),
        I2SCFG_SLV_TXMT  = mskd_t(     I2SCFG_MASK,  0b00,       I2SCFG_POS),
        I2SCFG_SLV_RECV  = mskd_t(     I2SCFG_MASK,  0b01,       I2SCFG_POS),
        I2SCFG_MST_TXMT  = mskd_t(     I2SCFG_MASK,  0b10,       I2SCFG_POS),
        I2SCFG_MST_RECV  = mskd_t(     I2SCFG_MASK,  0b11,       I2SCFG_POS);
    };  // struct I2scfgr
    using i2scfgr_t = Reg<uint32_t, I2scfgr>;
          i2scfgr_t   i2scfgr;


    struct I2spr {
        using              pos_t = Pos<uint32_t, I2spr>;
        static constexpr   pos_t
              I2SDIV_POS = pos_t( 0),
                 ODD_POS = pos_t( 8),
               MCKOE_POS = pos_t( 9);

        using              bits_t = Bits<uint32_t, I2spr>;
        static constexpr   bits_t
        ODD              = bits_t(1,          ODD_POS),
        MCKOE            = bits_t(1,        MCKOE_POS);

        static const uint32_t
             I2SDIV_MASK =      0xFFU;

        using            mskd_t = Mskd<uint32_t, I2spr>;
        using            shft_t = Shft<uint32_t, I2spr>;

        REGBITS_MSKD_RANGE("I2C::Isr",
                           I2SDIV,
                           i2sdiv,
                           I2SDIV_MASK,
                           I2SDIV_POS,
                           I2SDIV_MASK);
    };  // struct I2spr
    using i2spr_t = Reg<uint32_t, I2spr>;
          i2spr_t   i2spr;

};  // struct Spi
static_assert(sizeof(Spi) == 36, "sizeof(Spi) != 36");





static const uint32_t   PERIPH_BASE         = 0x40000000U;

// Peripheral memory map
static const uint32_t   APB1PERIPH_BASE     = PERIPH_BASE              ,
                        APB2PERIPH_BASE     = PERIPH_BASE + 0x00010000U,
                        AHB1PERIPH_BASE     = PERIPH_BASE + 0x00020000U,
                        AHB2PERIPH_BASE     = PERIPH_BASE + 0x10000000U;

// APB1 peripherals
static const uint32_t   TIM2_BASE           = APB1PERIPH_BASE + 0x0000U,
                        TIM3_BASE           = APB1PERIPH_BASE + 0x0400U,
                        TIM4_BASE           = APB1PERIPH_BASE + 0x0800U,
                        TIM5_BASE           = APB1PERIPH_BASE + 0x0C00U,
                        TIM6_BASE           = APB1PERIPH_BASE + 0x1000U,
                        TIM7_BASE           = APB1PERIPH_BASE + 0x1400U,
                        TIM12_BASE          = APB1PERIPH_BASE + 0x1800U,
                        TIM13_BASE          = APB1PERIPH_BASE + 0x1C00U,
                        TIM14_BASE          = APB1PERIPH_BASE + 0x2000U,
                        LPTIM1_BASE         = APB1PERIPH_BASE + 0x2400U,
                        RTC_BASE            = APB1PERIPH_BASE + 0x2800U,
                        WWDG_BASE           = APB1PERIPH_BASE + 0x2C00U,
                        IWDG_BASE           = APB1PERIPH_BASE + 0x3000U,
                        SPI2_BASE           = APB1PERIPH_BASE + 0x3800U,
                        SPI3_BASE           = APB1PERIPH_BASE + 0x3C00U,
                        USART2_BASE         = APB1PERIPH_BASE + 0x4400U,
                        USART3_BASE         = APB1PERIPH_BASE + 0x4800U,
                        UART4_BASE          = APB1PERIPH_BASE + 0x4C00U,
                        UART5_BASE          = APB1PERIPH_BASE + 0x5000U,
                        I2C1_BASE           = APB1PERIPH_BASE + 0x5400U,
                        I2C2_BASE           = APB1PERIPH_BASE + 0x5800U,
                        I2C3_BASE           = APB1PERIPH_BASE + 0x5C00U,
                        I2C4_BASE           = APB1PERIPH_BASE + 0x6000U,
                        UART7_BASE          = APB1PERIPH_BASE + 0x7800U,
                        UART8_BASE          = APB1PERIPH_BASE + 0x7C00U;

// APB2 peripherals
static const uint32_t   TIM1_BASE           = APB2PERIPH_BASE + 0x0000U,
                        TIM8_BASE           = APB2PERIPH_BASE + 0x0400U,
                        USART1_BASE         = APB2PERIPH_BASE + 0x1000U,
                        USART6_BASE         = APB2PERIPH_BASE + 0x1400U,
                        SDMMC2_BASE         = APB2PERIPH_BASE + 0x1C00U,
                        ADC1_BASE           = APB2PERIPH_BASE + 0x2000U,
                        ADC2_BASE           = APB2PERIPH_BASE + 0x2100U,
                        ADC3_BASE           = APB2PERIPH_BASE + 0x2200U,
                        ADC_BASE            = APB2PERIPH_BASE + 0x2300U,
                        SDMMC1_BASE         = APB2PERIPH_BASE + 0x2C00U,
                        SPI1_BASE           = APB2PERIPH_BASE + 0x3000U,
                        SPI4_BASE           = APB2PERIPH_BASE + 0x3400U,
                        SYSCFG_BASE         = APB2PERIPH_BASE + 0x3800U,
                        EXTI_BASE           = APB2PERIPH_BASE + 0x3C00U,
                        TIM9_BASE           = APB2PERIPH_BASE + 0x4000U,
                        TIM10_BASE          = APB2PERIPH_BASE + 0x4400U,
                        TIM11_BASE          = APB2PERIPH_BASE + 0x4800U,
                        SPI5_BASE           = APB2PERIPH_BASE + 0x5000U,
                        SPI6_BASE           = APB2PERIPH_BASE + 0x5400U;

// AHB1 peripherals
static const uint32_t   RCC_BASE            = AHB1PERIPH_BASE + 0x3800U,
                        DMA1_BASE           = AHB1PERIPH_BASE + 0x6000U,
                        DMA2_BASE           = AHB1PERIPH_BASE + 0x6400U,
                        GPIOA_BASE          = AHB1PERIPH_BASE + 0x0000U,
                        GPIOB_BASE          = AHB1PERIPH_BASE + 0x0400U,
                        GPIOC_BASE          = AHB1PERIPH_BASE + 0x0800U,
                        GPIOD_BASE          = AHB1PERIPH_BASE + 0x0C00U,
                        GPIOE_BASE          = AHB1PERIPH_BASE + 0x1000U,
                        GPIOF_BASE          = AHB1PERIPH_BASE + 0x1400U,
                        GPIOG_BASE          = AHB1PERIPH_BASE + 0x1800U,
                        GPIOH_BASE          = AHB1PERIPH_BASE + 0x1C00U,
                        GPIOI_BASE          = AHB1PERIPH_BASE + 0x2000U,
                        GPIOJ_BASE          = AHB1PERIPH_BASE + 0x2400U,
                        GPIOK_BASE          = AHB1PERIPH_BASE + 0x2800U,
                        CRC_BASE            = AHB1PERIPH_BASE + 0x3000U;


#define STM32F767XX_PERIPH(TYPE, PERIPH, BASE)      \
    static volatile TYPE* const                     \
    PERIPH = reinterpret_cast<volatile TYPE*>(BASE)

STM32F767XX_PERIPH( Rcc,                rcc,            RCC_BASE    );

STM32F767XX_PERIPH( Gpio,               gpioa,          GPIOA_BASE  );
STM32F767XX_PERIPH( Gpio,               gpiob,          GPIOB_BASE  );
STM32F767XX_PERIPH( Gpio,               gpioc,          GPIOC_BASE  );
STM32F767XX_PERIPH( Gpio,               gpiod,          GPIOD_BASE  );
STM32F767XX_PERIPH( Gpio,               gpioe,          GPIOE_BASE  );
STM32F767XX_PERIPH( Gpio,               gpiof,          GPIOF_BASE  );
STM32F767XX_PERIPH( Gpio,               gpiog,          GPIOG_BASE  );
STM32F767XX_PERIPH( Gpio,               gpioh,          GPIOH_BASE  );
STM32F767XX_PERIPH( Gpio,               gpioi,          GPIOI_BASE  );
STM32F767XX_PERIPH( Gpio,               gpioj,          GPIOJ_BASE  );
STM32F767XX_PERIPH( Gpio,               gpiok,          GPIOK_BASE  );

STM32F767XX_PERIPH( SysCfg,             sys_cfg,        SYSCFG_BASE );

STM32F767XX_PERIPH( Dma,                dma1,           DMA1_BASE   );
STM32F767XX_PERIPH( Dma,                dma2,           DMA2_BASE   );

STM32F767XX_PERIPH( Exti,               exti,           EXTI_BASE   );


STM32F767XX_PERIPH( AdvTim_1_8,         adv_tim_1,      TIM1_BASE   );
STM32F767XX_PERIPH( AdvTim_1_8,         adv_tim_8,      TIM8_BASE   );

STM32F767XX_PERIPH( GenTim_2,           gen_tim_2,      TIM2_BASE   );

STM32F767XX_PERIPH( GenTim_5,           gen_tim_5,      TIM5_BASE   );

STM32F767XX_PERIPH( GenTim_3_4,         gen_tim_3,      TIM3_BASE   );
STM32F767XX_PERIPH( GenTim_3_4,         gen_tim_4,      TIM4_BASE   );

STM32F767XX_PERIPH( GenTim_9_12,        gen_tim_9,      TIM9_BASE   );
STM32F767XX_PERIPH( GenTim_9_12,        gen_tim_12,     TIM12_BASE  );

STM32F767XX_PERIPH( GenTim_10_13_14,    gen_tim_10,     TIM10_BASE  );
STM32F767XX_PERIPH( GenTim_10_13_14,    gen_tim_13,     TIM13_BASE  );
STM32F767XX_PERIPH( GenTim_10_13_14,    gen_tim_14,     TIM14_BASE  );

STM32F767XX_PERIPH( GenTim_11,          gen_tim_11,     TIM11_BASE  );

STM32F767XX_PERIPH( BscTim_6_7,         bsc_tim_6,      TIM6_BASE   );
STM32F767XX_PERIPH( BscTim_6_7,         bsc_tim_7,      TIM7_BASE   );


STM32F767XX_PERIPH( LpTim,              lp_tim_1,       LPTIM1_BASE );

STM32F767XX_PERIPH( Rtc,                rtc,            RTC_BASE    );

STM32F767XX_PERIPH( Spi,                spi1,           SPI1_BASE   );
STM32F767XX_PERIPH( Spi,                spi2,           SPI2_BASE   );
STM32F767XX_PERIPH( Spi,                spi3,           SPI3_BASE   );
STM32F767XX_PERIPH( Spi,                spi4,           SPI4_BASE   );
STM32F767XX_PERIPH( Spi,                spi5,           SPI5_BASE   );
STM32F767XX_PERIPH( Spi,                spi6,           SPI6_BASE   );

STM32F767XX_PERIPH( I2c,                i2c1,           I2C1_BASE   );
STM32F767XX_PERIPH( I2c,                i2c2,           I2C2_BASE   );
STM32F767XX_PERIPH( I2c,                i2c3,           I2C3_BASE   );
STM32F767XX_PERIPH( I2c,                i2c4,           I2C4_BASE   );

#undef STM32F767XX_PERIPH

}  // namespace stm32f767xx

#endif  // #ifndef STM32F767XX_HXX
