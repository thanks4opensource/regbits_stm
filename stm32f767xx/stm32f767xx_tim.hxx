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


// included multiple times, only from stm32f767.hxx
#ifndef STM32F767XX_TIM_HXX_INCLUDE
#error -- private file, #include stm32f767xx_tim.hxx only from stm32f767.hxx
#else

    volatile Tim*   tim() volatile {
        return reinterpret_cast<volatile Tim*>(this); }
             Tim*   tim()          {
        return reinterpret_cast<         Tim*>(this); }

    struct Cr1 {
        using            pos_t = Pos<uint32_t, Cr1>;
        static constexpr pos_t      CEN_POS      = pos_t( 0),
                                    UDIS_POS     = pos_t( 1),
                                    URS_POS      = pos_t( 2),
                                    OPM_POS      = pos_t( 3),
                                    DIR_POS      = pos_t( 4),
                                    CMS_POS      = pos_t( 5),
                                    ARPE_POS     = pos_t( 7),
                                    CKD_POS      = pos_t( 8),
                                    UIFREMAP_POS = pos_t(11);


        using            bits_t = Bits<uint32_t, Cr1>;
        static constexpr bits_t     CEN      = bits_t(1, CEN_POS            ),
                                    UDIS     = bits_t(1, UDIS_POS           ),
                                    URS      = bits_t(1, URS_POS            ),
                                    OPM      = bits_t(1, OPM_POS            ),
                                    DIR      = bits_t(1, DIR_POS            ),
                                    ARPE     = bits_t(1, ARPE_POS           ),
                                    UIFREMAP = bits_t(1, UIFREMAP_POS       );

        static const uint32_t       CMS_MASK = 0x3,
                                    CKD_MASK = 0x3;

        using            mskd_t = Mskd<uint32_t, Cr1>;
        static constexpr mskd_t CMS_EDGE     = mskd_t(CMS_MASK, 0b00, CMS_POS),
                                CMS_CENTER_1 = mskd_t(CMS_MASK, 0b01, CMS_POS),
                                CMS_CENTER_2 = mskd_t(CMS_MASK, 0b10, CMS_POS),
                                CMS_CENTER_3 = mskd_t(CMS_MASK, 0b11, CMS_POS),
                                CKD_DIV_1    = mskd_t(CKD_MASK, 0b00, CKD_POS),
                                CKD_DIV_2    = mskd_t(CKD_MASK, 0b01, CKD_POS),
                                CKD_DIV_4    = mskd_t(CKD_MASK, 0b10, CKD_POS);
    };  // struct Cr1
    using cr1_t = Reg<uint32_t, Cr1>;
          cr1_t   cr1;


#if    defined(STM32F767XX_ADV_TIM_1_8 ) \
    || defined(STM32F767XX_TIM_CR2     ) \
    || defined(STM32F767XX_TIM_CR2_CCDS)
    struct Cr2 {
        using              pos_t = Pos<uint32_t, Cr2>;
        static constexpr   pos_t
                CCPC_POS = pos_t( 0),
                CCUS_POS = pos_t( 2),
                CCDS_POS = pos_t( 3),
                 MMS_POS = pos_t( 4),
                TI1S_POS = pos_t( 7),
                OIS1_POS = pos_t( 8),
               OIS1N_POS = pos_t( 9),
                OIS2_POS = pos_t(10),
               OIS2N_POS = pos_t(11),
                OIS3_POS = pos_t(12),
               OIS3N_POS = pos_t(13),
                OIS4_POS = pos_t(14),
                OIS5_POS = pos_t(16),
                OIS6_POS = pos_t(18),
                MMS2_POS = pos_t(20);

        using              bits_t = Bits<uint32_t, Cr2>;
        static constexpr   bits_t
        CCPC             = bits_t(1,         CCPC_POS),
        CCUS             = bits_t(1,         CCUS_POS),
        CCDS             = bits_t(1,         CCDS_POS),
        OIS5             = bits_t(1,         OIS5_POS),
        OIS6             = bits_t(1,         OIS6_POS),
        TI1S             = bits_t(1,         TI1S_POS),
        OIS1             = bits_t(1,         OIS1_POS),
        OIS1N            = bits_t(1,        OIS1N_POS),
        OIS2             = bits_t(1,         OIS2_POS),
        OIS2N            = bits_t(1,        OIS2N_POS),
        OIS3             = bits_t(1,         OIS3_POS),
        OIS3N            = bits_t(1,        OIS3N_POS),
        OIS4             = bits_t(1,         OIS4_POS);

        static const uint32_t
                MMS_MASK =       0x7U,
               MMS2_MASK =       0xFU;

        using               mskd_t = Mskd<uint32_t, Cr2>;
        static constexpr    mskd_t
        MMS_RESET         = mskd_t( MMS_MASK,   0b000 , MMS_POS ),
        MMS_ENABLE        = mskd_t( MMS_MASK,   0b001 , MMS_POS ),
        MMS_UPDATE        = mskd_t( MMS_MASK,   0b010 , MMS_POS ),
        MMS_COMPARE       = mskd_t( MMS_MASK,   0b011 , MMS_POS ),
        MMS_OC1REF        = mskd_t( MMS_MASK,   0b100 , MMS_POS ),
        MMS_OC2REF        = mskd_t( MMS_MASK,   0b101 , MMS_POS ),
        MMS_OC3REF        = mskd_t( MMS_MASK,   0b110 , MMS_POS ),
        MMS_OC4REF        = mskd_t( MMS_MASK,   0b111 , MMS_POS ),
        MMS2_RESET        = mskd_t(MMS2_MASK,   0b0000, MMS2_POS),
        MMS2_ENABLE       = mskd_t(MMS2_MASK,   0b0001, MMS2_POS),
        MMS2_UPDATE       = mskd_t(MMS2_MASK,   0b0010, MMS2_POS),
        MMS2_COMPARE      = mskd_t(MMS2_MASK,   0b0011, MMS2_POS),
        MMS2_OC1REF       = mskd_t(MMS2_MASK,   0b0100, MMS2_POS),
        MMS2_OC2REF       = mskd_t(MMS2_MASK,   0b0101, MMS2_POS),
        MMS2_OC3REF       = mskd_t(MMS2_MASK,   0b0110, MMS2_POS),
        MMS2_OC4REF       = mskd_t(MMS2_MASK,   0b0111, MMS2_POS),
        MMS2_OC5REF       = mskd_t(MMS2_MASK,   0b1000, MMS2_POS),
        MMS2_OC6REF       = mskd_t(MMS2_MASK,   0b1001, MMS2_POS),
        MMS2_OC4_RIS_FAL  = mskd_t(MMS2_MASK,   0b1010, MMS2_POS),
        MMS2_OC6_RIS_FAL  = mskd_t(MMS2_MASK,   0b1011, MMS2_POS),
        MMS2_OC4_6_RISE   = mskd_t(MMS2_MASK,   0b1100, MMS2_POS),
        MMS2_OC4_6_FALL   = mskd_t(MMS2_MASK,   0b1101, MMS2_POS),
        MMS2_OC5_6_RISE   = mskd_t(MMS2_MASK,   0b1110, MMS2_POS),
        MMS2_OC5RIS_6FAL  = mskd_t(MMS2_MASK,   0b1111, MMS2_POS);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;
    volatile TimCr2*
    tim_cr2() volatile { return reinterpret_cast<volatile TimCr2*>(this); }
             TimCr2*
    tim_cr2()          { return reinterpret_cast<         TimCr2*>(this); }
#ifdef STM32F767XX_TIM_CR2_CCDS
    volatile TimCr2Ccds*
    tim_cr2_ccds() volatile {
                         return reinterpret_cast<volatile TimCr2Ccds*>(this); }
             TimCr2Ccds*
    tim_cr2_ccds()          {
                         return reinterpret_cast<         TimCr2Ccds*>(this); }
#endif

#elif    defined( STM32F767XX_GEN_TIM_2_3_4_5) \
       || defined(STM32F767XX_TIM_CR2        ) \
       || defined(STM32F767XX_TIM_CR2_CCDS   )
    struct Cr2 {
        using            pos_t = Pos<uint32_t, Cr2>;
        static constexpr pos_t      CCDS_POS = pos_t(3),
                                    MMS_POS  = pos_t(4),
                                    TI1S_POS = pos_t(7);

        using            bits_t = Bits<uint32_t, Cr2>;
        static constexpr bits_t     CCDS = bits_t(1, CCDS_POS),
                                    TI1S = bits_t(1, TI1S_POS);

        static const uint32_t       MMS_MASK = 0x7;

        using            mskd_t = Mskd<uint32_t, Cr2>;
        static constexpr mskd_t MMS_RESET   = mskd_t(MMS_MASK, 0b000, MMS_POS),
                                MMS_ENABLE  = mskd_t(MMS_MASK, 0b001, MMS_POS),
                                MMS_UPDATE  = mskd_t(MMS_MASK, 0b010, MMS_POS),
                                MMS_COMPARE = mskd_t(MMS_MASK, 0b011, MMS_POS),
                                MMS_OC1REF  = mskd_t(MMS_MASK, 0b100, MMS_POS),
                                MMS_OC2REF  = mskd_t(MMS_MASK, 0b101, MMS_POS),
                                MMS_OC3REF  = mskd_t(MMS_MASK, 0b110, MMS_POS),
                                MMS_OC4REF  = mskd_t(MMS_MASK, 0b111, MMS_POS);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;
    volatile TimCr2*
    tim_cr2() volatile { return reinterpret_cast<volatile TimCr2*>(this); }
             TimCr2*
    tim_cr2()          { return reinterpret_cast<         TimCr2*>(this); }
#ifdef STM32F767XX_TIM_CR2_CCDS
    volatile TimCr2Ccds*
    tim_cr2_ccds() volatile {
                         return reinterpret_cast<volatile TimCr2Ccds*>(this); }
             TimCr2Ccds*
    tim_cr2_ccds()          {
                         return reinterpret_cast<         TimCr2Ccds*>(this); }
#endif

#elif    defined(STM32F767XX_BSC_TIM_6_7) \
      || defined(STM32F767XX_TIM_CR2    )

    struct Cr2 {
        using            pos_t = Pos<uint32_t, Cr2>;
        static constexpr pos_t      MMS_POS  = pos_t(4);

        static const uint32_t       MMS_MASK = 0x7;

        using mskd_t = Mskd<uint32_t, Cr2>;
        static constexpr mskd_t MMS_RESET   = mskd_t(MMS_MASK, 0b000, MMS_POS),
                                MMS_ENABLE  = mskd_t(MMS_MASK, 0b001, MMS_POS),
                                MMS_UPDATE  = mskd_t(MMS_MASK, 0b010, MMS_POS);
    };  // struct Cr2
    using cr2_t = Reg<uint32_t, Cr2>;
          cr2_t   cr2;
    volatile TimCr2*
    tim_cr2() volatile { return reinterpret_cast<volatile TimCr2*>(this); }
             TimCr2*
    tim_cr2()          { return reinterpret_cast<         TimCr2*>(this); }
#else
     private: uint32_t  _unimplemented_cr2; public:
#endif  // #ifdef STM32F767XX_TIM_CR2


#ifdef STM32F767XX_TIM_SMCR
    struct Smcr {
        using              pos_t = Pos<uint32_t, Smcr>;
        static constexpr   pos_t
                 SMS_POS = pos_t( 0),
                  TS_POS = pos_t( 4),
                 MSM_POS = pos_t( 7),
                 ETF_POS = pos_t( 8),
                ETPS_POS = pos_t(12),
                 ECE_POS = pos_t(14),
                 ETP_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Smcr>;
        static constexpr   bits_t
        MSM              = bits_t(1,          MSM_POS),
        ECE              = bits_t(1,          ECE_POS),
        ETP              = bits_t(1,          ETP_POS);

        static const uint32_t
                SMS_MASK =   0x10007U,
                 TS_MASK =       0x7U,
                ETF_MASK =       0xFU,
               ETPS_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Smcr>;
        static constexpr   mskd_t
        SMS_SLV_DIS      = mskd_t(        SMS_MASK,  0x00000,       SMS_POS),
        SMS_ENC_1        = mskd_t(        SMS_MASK,  0x00001,       SMS_POS),
        SMS_ENC_2        = mskd_t(        SMS_MASK,  0x00002,       SMS_POS),
        SMS_ENC_3        = mskd_t(        SMS_MASK,  0x00003,       SMS_POS),
        SMS_RESET        = mskd_t(        SMS_MASK,  0x00004,       SMS_POS),
        SMS_GATED        = mskd_t(        SMS_MASK,  0x00005,       SMS_POS),
        SMS_TRIGGER      = mskd_t(        SMS_MASK,  0x00006,       SMS_POS),
        SMS_EXT_1        = mskd_t(        SMS_MASK,  0x00007,       SMS_POS),
        SMS_RST_TRIG     = mskd_t(        SMS_MASK,  0x10000,       SMS_POS),
        TS_INT_0         = mskd_t(         TS_MASK,  0xb000,         TS_POS),
        TS_INT_1         = mskd_t(         TS_MASK,  0xb001,         TS_POS),
        TS_INT_2         = mskd_t(         TS_MASK,  0xb010,         TS_POS),
        TS_INT_3         = mskd_t(         TS_MASK,  0xb011,         TS_POS),
        TS_TI1_EDGE      = mskd_t(         TS_MASK,  0xb100,         TS_POS),
        TS_FILT_1        = mskd_t(         TS_MASK,  0xb101,         TS_POS),
        TS_FILT_2        = mskd_t(         TS_MASK,  0xb110,         TS_POS),
        TS_EXT           = mskd_t(         TS_MASK,  0xb111,         TS_POS),
        ETF_0_NONE       = mskd_t(        ETF_MASK,  0b0000,        ETF_POS),
        ETF_0_INT_N2     = mskd_t(        ETF_MASK,  0b0001,        ETF_POS),
        ETF_0_INT_N4     = mskd_t(        ETF_MASK,  0b0010,        ETF_POS),
        ETF_0_INT_N8     = mskd_t(        ETF_MASK,  0b0011,        ETF_POS),
        ETF_0_DTS_2_N6   = mskd_t(        ETF_MASK,  0b0100,        ETF_POS),
        ETF_0_DTS_2_N8   = mskd_t(        ETF_MASK,  0b0101,        ETF_POS),
        ETF_0_DTS_4_N6   = mskd_t(        ETF_MASK,  0b0110,        ETF_POS),
        ETF_0_DTS_4_N8   = mskd_t(        ETF_MASK,  0b0111,        ETF_POS),
        ETF_0_DTS_8_N6   = mskd_t(        ETF_MASK,  0b1000,        ETF_POS),
        ETF_0_DTS_8_N8   = mskd_t(        ETF_MASK,  0b1001,        ETF_POS),
        ETF_0_DTS_16_N5  = mskd_t(        ETF_MASK,  0b1010,        ETF_POS),
        ETF_0_DTS_16_N6  = mskd_t(        ETF_MASK,  0b1011,        ETF_POS),
        ETF_0_DTS_16_N8  = mskd_t(        ETF_MASK,  0b1100,        ETF_POS),
        ETF_0_DTS_32_N5  = mskd_t(        ETF_MASK,  0b1101,        ETF_POS),
        ETF_0_DTS_32_N6  = mskd_t(        ETF_MASK,  0b1110,        ETF_POS),
        ETF_0_DTS_32_N8  = mskd_t(        ETF_MASK,  0b1111,        ETF_POS),
        ETPS_PRESC_OFF   = mskd_t(       ETPS_MASK,  0b00,         ETPS_POS),
        ETPS_ETRP_DIV_2  = mskd_t(       ETPS_MASK,  0b01,         ETPS_POS),
        ETPS_ETRP_DIV_4  = mskd_t(       ETPS_MASK,  0b10,         ETPS_POS),
        ETPS_ETRP_DIV_8  = mskd_t(       ETPS_MASK,  0b11,         ETPS_POS);
    };  // struct Smcr
    using smcr_t = Reg<uint32_t, Smcr>;
          smcr_t   smcr;
    volatile TimSmcr*
    tim_smcr() volatile { return reinterpret_cast<volatile TimSmcr*>(this); }
             TimSmcr*
    tim_smcr()          { return reinterpret_cast<         TimSmcr*>(this); }
#else
    private: uint32_t   _unimplemented_smcr;     public:
#endif


    struct Dier {
        using              pos_t = Pos<uint32_t, Dier>;
        static constexpr   pos_t
                 UIE_POS = pos_t( 0),
               CC1IE_POS = pos_t( 1),
               CC2IE_POS = pos_t( 2),
               CC3IE_POS = pos_t( 3),
               CC4IE_POS = pos_t( 4),
               COMIE_POS = pos_t( 5),
                 TIE_POS = pos_t( 6),
                 BIE_POS = pos_t( 7),
                 UDE_POS = pos_t( 8),
               CC1DE_POS = pos_t( 9),
               CC2DE_POS = pos_t(10),
               CC3DE_POS = pos_t(11),
               CC4DE_POS = pos_t(12),
               COMDE_POS = pos_t(13),
                 TDE_POS = pos_t(14);

        using              bits_t = Bits<uint32_t, Dier>;
        static constexpr   bits_t
        UIE              = bits_t(1,          UIE_POS),
        CC1IE            = bits_t(1,        CC1IE_POS),
        CC2IE            = bits_t(1,        CC2IE_POS),
        CC3IE            = bits_t(1,        CC3IE_POS),
        CC4IE            = bits_t(1,        CC4IE_POS),
        COMIE            = bits_t(1,        COMIE_POS),
        TIE              = bits_t(1,          TIE_POS),
        BIE              = bits_t(1,          BIE_POS),
        UDE              = bits_t(1,          UDE_POS),
        CC1DE            = bits_t(1,        CC1DE_POS),
        CC2DE            = bits_t(1,        CC2DE_POS),
        CC3DE            = bits_t(1,        CC3DE_POS),
        CC4DE            = bits_t(1,        CC4DE_POS),
        COMDE            = bits_t(1,        COMDE_POS),
        TDE              = bits_t(1,          TDE_POS);
    };  // struct Dier
    using dier_t = Reg<uint32_t, Dier>;
          dier_t   dier;


    struct Sr {
        using              pos_t = Pos<uint32_t, Sr>;
        static constexpr   pos_t
                 UIF_POS = pos_t( 0),
               CC1IF_POS = pos_t( 1),
               CC2IF_POS = pos_t( 2),
               CC3IF_POS = pos_t( 3),
               CC4IF_POS = pos_t( 4),
               COMIF_POS = pos_t( 5),
                 TIF_POS = pos_t( 6),
                 BIF_POS = pos_t( 7),
                B2IF_POS = pos_t( 8),
               CC1OF_POS = pos_t( 9),
               CC2OF_POS = pos_t(10),
               CC3OF_POS = pos_t(11),
               CC4OF_POS = pos_t(12),
                SBIF_POS = pos_t(13),
               CC5IF_POS = pos_t(16),
               CC6IF_POS = pos_t(17);

        using              bits_t = Bits<uint32_t, Sr>;
        static constexpr   bits_t
        UIF              = bits_t(1,          UIF_POS),
        CC1IF            = bits_t(1,        CC1IF_POS),
        CC2IF            = bits_t(1,        CC2IF_POS),
        CC3IF            = bits_t(1,        CC3IF_POS),
        CC4IF            = bits_t(1,        CC4IF_POS),
        COMIF            = bits_t(1,        COMIF_POS),
        TIF              = bits_t(1,          TIF_POS),
        BIF              = bits_t(1,          BIF_POS),
        B2IF             = bits_t(1,         B2IF_POS),
        CC1OF            = bits_t(1,        CC1OF_POS),
        CC2OF            = bits_t(1,        CC2OF_POS),
        CC3OF            = bits_t(1,        CC3OF_POS),
        CC4OF            = bits_t(1,        CC4OF_POS),
        SBIF             = bits_t(1,         SBIF_POS),
        CC5IF            = bits_t(1,        CC5IF_POS),
        CC6IF            = bits_t(1,        CC6IF_POS);
    };  // struct Sr
    using sr_t = Reg<uint32_t, Sr>;
          sr_t   sr;


    struct Egr {
        using              pos_t = Pos<uint32_t, Egr>;
        static constexpr   pos_t
                  UG_POS = pos_t( 0)
#if    defined(STM32F767XX_GEN_TIM_9_10_11_12_13_14) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                CC1G_POS = pos_t( 1)
#endif
#if    defined(STM32F767XX_GEN_TIM_9_12) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                CC2G_POS = pos_t( 2)
#endif
#if    defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                CC3G_POS = pos_t( 3),
                CC4G_POS = pos_t( 4)
#endif
#if    defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                COMG_POS = pos_t( 5)
#endif
#if    defined(STM32F767XX_GEN_TIM_9_12) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                  TG_POS = pos_t( 6)
#endif
#if    defined(STM32F767XX_ADV_TIM_1_8)
                                    ,
                  BG_POS = pos_t( 7),
                 B2G_POS = pos_t( 8)
#endif
                                    ;

        using              bits_t = Bits<uint32_t, Egr>;
        static constexpr   bits_t
        UG               = bits_t(1,           UG_POS)
#if    defined(STM32F767XX_GEN_TIM_9_10_11_12_13_14) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        CC1G             = bits_t(1,         CC1G_POS)
#endif
#if    defined(STM32F767XX_GEN_TIM_9_12) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        CC2G             = bits_t(1,         CC2G_POS)
#endif
#if    defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        CC3G             = bits_t(1,         CC3G_POS),
        CC4G             = bits_t(1,         CC4G_POS)
#endif
#if    defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        COMG             = bits_t(1,         COMG_POS)
#endif
#if    defined(STM32F767XX_GEN_TIM_9_12) \
    || defined(STM32F767XX_GEN_TIM_2_3_4_5) \
    || defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        TG               = bits_t(1,           TG_POS)
#endif
#if    defined(STM32F767XX_ADV_TIM_1_8)
                                                      ,
        BG               = bits_t(1,           BG_POS),
        B2G              = bits_t(1,          B2G_POS)
#endif
                                                      ;
    };  // struct Egr
    using egr_t = Reg<uint32_t, Egr>;
          egr_t   egr;


#ifdef STM32F767XX_TIM_CCMR1_1_2_3_4_5_8_9_12
    struct Ccmr1 {
        using              pos_t = Pos<uint32_t, Ccmr1>;
        static constexpr   pos_t
        // output/compare mode
                CC1S_POS = pos_t( 0),
               OC1FE_POS = pos_t( 2),
               OC1PE_POS = pos_t( 3),
                OC1M_POS = pos_t( 4),
               OC1CE_POS = pos_t( 7),
                CC2S_POS = pos_t( 8),
               OC2FE_POS = pos_t(10),
               OC2PE_POS = pos_t(11),
                OC2M_POS = pos_t(12),
               OC2CE_POS = pos_t(15),
        // input/capture mode
              IC1PSC_POS = pos_t( 2),
                IC1F_POS = pos_t( 4),
              IC2PSC_POS = pos_t(10),
                IC2F_POS = pos_t(12);

        using              bits_t = Bits<uint32_t, Ccmr1>;
        static constexpr   bits_t
        // output/compare mode
        OC1FE            = bits_t(1,        OC1FE_POS),
        OC1PE            = bits_t(1,        OC1PE_POS),
        OC1CE            = bits_t(1,        OC1CE_POS),
        OC2FE            = bits_t(1,        OC2FE_POS),
        OC2PE            = bits_t(1,        OC2PE_POS),
        OC2CE            = bits_t(1,        OC2CE_POS);

        static const uint32_t
        // output/compare mode
               CC1S_MASK =       0x3U,
               OC1M_MASK =    0x1007U,
               CC2S_MASK =       0x3U,
               OC2M_MASK =    0x1007U,
        // input/capture mode
             IC1PSC_MASK =       0x3U,
               IC1F_MASK =       0xFU,
             IC2PSC_MASK =       0x3U,
               IC2F_MASK =       0xFU;

        using              mskd_t = Mskd<uint32_t, Ccmr1>;
        static constexpr   mskd_t
        // both modes
        CC1S_OUTPUT      = mskd_t(       CC1S_MASK,  0b00,         CC1S_POS),
        CC1S_IC1_TI1     = mskd_t(       CC1S_MASK,  0b01,         CC1S_POS),
        CC1S_IC1_TI2     = mskd_t(       CC1S_MASK,  0b10,         CC1S_POS),
        CC1S_IC1_TRC     = mskd_t(       CC1S_MASK,  0b11,         CC1S_POS),
        // output/compare mode
        OC1M_FROZEN      = mskd_t(       OC1M_MASK,  0x0000,          OC1M_POS),
        OC1M_CH1_ACTV    = mskd_t(       OC1M_MASK,  0x0001,          OC1M_POS),
        OC1M_CH1_INACT   = mskd_t(       OC1M_MASK,  0x0002,          OC1M_POS),
        OC1M_TOGGLE      = mskd_t(       OC1M_MASK,  0x0003,          OC1M_POS),
        OC1M_FORCE_LOW   = mskd_t(       OC1M_MASK,  0x0004,          OC1M_POS),
        OC1M_FORCE_HIGH  = mskd_t(       OC1M_MASK,  0x0006,          OC1M_POS),
        OC1M_PWM_MODE_2  = mskd_t(       OC1M_MASK,  0x0007,          OC1M_POS),
        OC1M_RETRIG_1    = mskd_t(       OC1M_MASK,  0x1000,          OC1M_POS),
        OC1M_RETRIG_2    = mskd_t(       OC1M_MASK,  0x1001,          OC1M_POS),
        OC1M_COMB_PWM_1  = mskd_t(       OC1M_MASK,  0x1004,          OC1M_POS),
        OC1M_COMB_PWM_2  = mskd_t(       OC1M_MASK,  0x1005,          OC1M_POS),
        OC1M_ASYM_PWM_1  = mskd_t(       OC1M_MASK,  0x1006,          OC1M_POS),
        OC1M_ASYM_PWM_2  = mskd_t(       OC1M_MASK,  0x1007,          OC1M_POS),
        // both modes
        CC2S_OUT         = mskd_t(       CC2S_MASK,  0b00,             CC2S_POS),
        CC2S_IN_IC2_TI2  = mskd_t(       CC2S_MASK,  0b01,             CC2S_POS),
        CC2S_IN_IC2_TI1  = mskd_t(       CC2S_MASK,  0b10,             CC2S_POS),
        CC2S_IN_IC2_TRC  = mskd_t(       CC2S_MASK,  0b11,             CC2S_POS),
        // input/capture mode
        IC1PSC_PRESCAL_1 = mskd_t(     IC1PSC_MASK,  0b00,           IC1PSC_POS),
        IC1PSC_PRESCAL_2 = mskd_t(     IC1PSC_MASK,  0b01,           IC1PSC_POS),
        IC1PSC_PRESCAL_4 = mskd_t(     IC1PSC_MASK,  0b10,           IC1PSC_POS),
        IC1PSC_PRESCAL_8 = mskd_t(     IC1PSC_MASK,  0b11,           IC1PSC_POS),
        IC1F_NO_FILT     = mskd_t(       IC1F_MASK,  0b0000,           IC1F_POS),
        IC1F_CK_INT_N_2  = mskd_t(       IC1F_MASK,  0b0001,           IC1F_POS),
        IC1F_CK_INT_N_4  = mskd_t(       IC1F_MASK,  0b0010,           IC1F_POS),
        IC1F_CK_INT_N_8  = mskd_t(       IC1F_MASK,  0b0011,           IC1F_POS),
        IC1F_DTS_2_N_6   = mskd_t(       IC1F_MASK,  0b0100,           IC1F_POS),
        IC1F_DTS_2_N_8   = mskd_t(       IC1F_MASK,  0b0101,           IC1F_POS),
        IC1F_DTS_4_N_6   = mskd_t(       IC1F_MASK,  0b0110,           IC1F_POS),
        IC1F_DTS_4_N_8   = mskd_t(       IC1F_MASK,  0b0111,           IC1F_POS),
        IC1F_DTS_8_N_6   = mskd_t(       IC1F_MASK,  0b1000,           IC1F_POS),
        IC1F_DTS_8_N_8   = mskd_t(       IC1F_MASK,  0b1001,           IC1F_POS),
        IC1F_DTS_16_N_5  = mskd_t(       IC1F_MASK,  0b1010,           IC1F_POS),
        IC1F_DTS_16_N_6  = mskd_t(       IC1F_MASK,  0b1011,           IC1F_POS),
        IC1F_DTS_16_N_8  = mskd_t(       IC1F_MASK,  0b1100,           IC1F_POS),
        IC1F_DTS_32_N_5  = mskd_t(       IC1F_MASK,  0b1101,           IC1F_POS),
        IC1F_DTS_32_N_6  = mskd_t(       IC1F_MASK,  0b1110,           IC1F_POS),
        IC1F_DTS_32_N_8  = mskd_t(       IC1F_MASK,  0b1111,           IC1F_POS),
        IC2PSC_PRESCAL_1 = mskd_t(     IC2PSC_MASK,  0b00,           IC2PSC_POS),
        IC2PSC_PRESCAL_2 = mskd_t(     IC2PSC_MASK,  0b01,           IC2PSC_POS),
        IC2PSC_PRESCAL_4 = mskd_t(     IC2PSC_MASK,  0b10,           IC2PSC_POS),
        IC2PSC_PRESCAL_8 = mskd_t(     IC2PSC_MASK,  0b11,           IC2PSC_POS);
    };  // struct Ccmr1
    using ccmr1_t = Reg<uint32_t, Ccmr1>;
          ccmr1_t   ccmr1;
    volatile TimCcmr1_1_2_3_4_5_8_9_12* tim_ccmr1_1_2_3_4_5_8_9_12() volatile {
        return reinterpret_cast<volatile TimCcmr1_1_2_3_4_5_8_9_12*>(this); }
             TimCcmr1_1_2_3_4_5_8_9_12* tim_ccmr1_1_2_3_4_5_8_9_12()          {
        return reinterpret_cast<         TimCcmr1_1_2_3_4_5_8_9_12*>(this); }
#elif defined(STM32F767XX_TIM_CCMR1_10_11_13_14)
    struct Ccmr1 {
        using              pos_t = Pos<uint32_t, Ccmr1>;
        static constexpr   pos_t
        // output/compare mode
                CC1S_POS = pos_t( 0),
               OC1FE_POS = pos_t( 2),
               OC1PE_POS = pos_t( 3),
                OC1M_POS = pos_t( 4),
               OC1CE_POS = pos_t( 7),
        // input/capture mode
              IC1PSC_POS = pos_t( 2),
                IC1F_POS = pos_t( 4);

        using              bits_t = Bits<uint32_t, Ccmr1>;
        static constexpr   bits_t
        // output/compare mode
        OC1FE            = bits_t(1,        OC1FE_POS),
        OC1PE            = bits_t(1,        OC1PE_POS),
        OC1CE            = bits_t(1,        OC1CE_POS);

        static const uint32_t
        // output/compare mode
               CC1S_MASK =       0x3U,
               OC1M_MASK =    0x1007U,
        // input/capture mode
             IC1PSC_MASK =       0x3U,
               IC1F_MASK =       0xFU;

        using              mskd_t = Mskd<uint32_t, Ccmr1>;
        static constexpr   mskd_t
        // both modes
        CC1S_OUTPUT      = mskd_t(       CC1S_MASK,  0b00,         CC1S_POS),
        CC1S_IC1_TI1     = mskd_t(       CC1S_MASK,  0b01,         CC1S_POS),
        CC1S_IC1_TI2     = mskd_t(       CC1S_MASK,  0b10,         CC1S_POS),
        CC1S_IC1_TRC     = mskd_t(       CC1S_MASK,  0b11,         CC1S_POS),
        // output/compare mode
        OC1M_FROZEN      = mskd_t(       OC1M_MASK,  0x0000,          OC1M_POS),
        OC1M_CH1_ACTV    = mskd_t(       OC1M_MASK,  0x0001,          OC1M_POS),
        OC1M_CH1_INACT   = mskd_t(       OC1M_MASK,  0x0002,          OC1M_POS),
        OC1M_TOGGLE      = mskd_t(       OC1M_MASK,  0x0003,          OC1M_POS),
        OC1M_FORCE_LOW   = mskd_t(       OC1M_MASK,  0x0004,          OC1M_POS),
        OC1M_FORCE_HIGH  = mskd_t(       OC1M_MASK,  0x0006,          OC1M_POS),
        OC1M_PWM_MODE_2  = mskd_t(       OC1M_MASK,  0x0007,          OC1M_POS),
        OC1M_RETRIG_1    = mskd_t(       OC1M_MASK,  0x1000,          OC1M_POS),
        OC1M_RETRIG_2    = mskd_t(       OC1M_MASK,  0x1001,          OC1M_POS),
        OC1M_COMB_PWM_1  = mskd_t(       OC1M_MASK,  0x1004,          OC1M_POS),
        OC1M_COMB_PWM_2  = mskd_t(       OC1M_MASK,  0x1005,          OC1M_POS),
        OC1M_ASYM_PWM_1  = mskd_t(       OC1M_MASK,  0x1006,          OC1M_POS),
        OC1M_ASYM_PWM_2  = mskd_t(       OC1M_MASK,  0x1007,          OC1M_POS),
        // input/capture mode
        IC1PSC_PRESCAL_1 = mskd_t(     IC1PSC_MASK,  0b00,           IC1PSC_POS),
        IC1PSC_PRESCAL_2 = mskd_t(     IC1PSC_MASK,  0b01,           IC1PSC_POS),
        IC1PSC_PRESCAL_4 = mskd_t(     IC1PSC_MASK,  0b10,           IC1PSC_POS),
        IC1PSC_PRESCAL_8 = mskd_t(     IC1PSC_MASK,  0b11,           IC1PSC_POS),
        IC1F_NO_FILT     = mskd_t(       IC1F_MASK,  0b0000,           IC1F_POS),
        IC1F_CK_INT_N_2  = mskd_t(       IC1F_MASK,  0b0001,           IC1F_POS),
        IC1F_CK_INT_N_4  = mskd_t(       IC1F_MASK,  0b0010,           IC1F_POS),
        IC1F_CK_INT_N_8  = mskd_t(       IC1F_MASK,  0b0011,           IC1F_POS),
        IC1F_DTS_2_N_6   = mskd_t(       IC1F_MASK,  0b0100,           IC1F_POS),
        IC1F_DTS_2_N_8   = mskd_t(       IC1F_MASK,  0b0101,           IC1F_POS),
        IC1F_DTS_4_N_6   = mskd_t(       IC1F_MASK,  0b0110,           IC1F_POS),
        IC1F_DTS_4_N_8   = mskd_t(       IC1F_MASK,  0b0111,           IC1F_POS),
        IC1F_DTS_8_N_6   = mskd_t(       IC1F_MASK,  0b1000,           IC1F_POS),
        IC1F_DTS_8_N_8   = mskd_t(       IC1F_MASK,  0b1001,           IC1F_POS),
        IC1F_DTS_16_N_5  = mskd_t(       IC1F_MASK,  0b1010,           IC1F_POS),
        IC1F_DTS_16_N_6  = mskd_t(       IC1F_MASK,  0b1011,           IC1F_POS),
        IC1F_DTS_16_N_8  = mskd_t(       IC1F_MASK,  0b1100,           IC1F_POS),
        IC1F_DTS_32_N_5  = mskd_t(       IC1F_MASK,  0b1101,           IC1F_POS),
        IC1F_DTS_32_N_6  = mskd_t(       IC1F_MASK,  0b1110,           IC1F_POS),
        IC1F_DTS_32_N_8  = mskd_t(       IC1F_MASK,  0b1111,           IC1F_POS);
    };  // struct Ccmr1
    using ccmr1_t = Reg<uint32_t, Ccmr1>;
          ccmr1_t   ccmr1;
    volatile TimCcmr1_10_11_13_14* tim_ccmr1_10_11_13_14() volatile {
        return reinterpret_cast<volatile TimCcmr1_10_11_13_14*>(this); }
             TimCcmr1_10_11_13_14* tim_ccmr1_10_11_13_14()          {
        return reinterpret_cast<         TimCcmr1_10_11_13_14*>(this); }
#else
    private: uint32_t   _unimplemented_ccmr1;  public:
#endif


#ifdef STM32F767XX_TIM_CCMR2
    struct Ccmr2 {
        using              pos_t = Pos<uint32_t, Ccmr2>;
        static constexpr   pos_t
        // output/compare mode
                CC3S_POS = pos_t( 0),
               OC3FE_POS = pos_t( 2),
               OC3PE_POS = pos_t( 3),
                OC3M_POS = pos_t( 4),
               OC3CE_POS = pos_t( 7),
                CC4S_POS = pos_t( 8),
               OC4FE_POS = pos_t(10),
               OC4PE_POS = pos_t(11),
                OC4M_POS = pos_t(12),
               OC4CE_POS = pos_t(15),
        // input/capture mode
              IC3PSC_POS = pos_t( 2),
                IC3F_POS = pos_t( 4),
              IC4PSC_POS = pos_t(10),
                IC4F_POS = pos_t(12);

        using              bits_t = Bits<uint32_t, Ccmr2>;
        static constexpr   bits_t
        // output/compare mode
        OC3FE            = bits_t(1,        OC3FE_POS),
        OC3PE            = bits_t(1,        OC3PE_POS),
        OC3CE            = bits_t(1,        OC3CE_POS),
        OC4FE            = bits_t(1,        OC4FE_POS),
        OC4PE            = bits_t(1,        OC4PE_POS),
        OC4CE            = bits_t(1,        OC4CE_POS);

        static const uint32_t
        // output/compare mode
               CC3S_MASK =       0x3U,
               OC3M_MASK =    0x1007U,
               CC4S_MASK =       0x3U,
               OC4M_MASK =    0x1007U,
        // input/capture mode
             IC3PSC_MASK =       0x3U,
               IC3F_MASK =       0xFU,
             IC4PSC_MASK =       0x3U,
               IC4F_MASK =       0xFU;

        using              mskd_t = Mskd<uint32_t, Ccmr2>;
        static constexpr   mskd_t
        // both modes
        CC3S_OUTPUT      = mskd_t(       CC3S_MASK,  0b00,         CC3S_POS),
        CC3S_IC3_TI1     = mskd_t(       CC3S_MASK,  0b01,         CC3S_POS),
        CC3S_IC3_TI2     = mskd_t(       CC3S_MASK,  0b10,         CC3S_POS),
        CC3S_IC3_TRC     = mskd_t(       CC3S_MASK,  0b11,         CC3S_POS),
        // output/compare mode
        OC3M_FROZEN      = mskd_t(       OC3M_MASK,  0x0000,          OC3M_POS),
        OC3M_CH1_ACTV    = mskd_t(       OC3M_MASK,  0x0001,          OC3M_POS),
        OC3M_CH1_INACT   = mskd_t(       OC3M_MASK,  0x0002,          OC3M_POS),
        OC3M_TOGGLE      = mskd_t(       OC3M_MASK,  0x0003,          OC3M_POS),
        OC3M_FORCE_LOW   = mskd_t(       OC3M_MASK,  0x0004,          OC3M_POS),
        OC3M_FORCE_HIGH  = mskd_t(       OC3M_MASK,  0x0006,          OC3M_POS),
        OC3M_PWM_MODE_2  = mskd_t(       OC3M_MASK,  0x0007,          OC3M_POS),
        OC3M_RETRIG_1    = mskd_t(       OC3M_MASK,  0x1000,          OC3M_POS),
        OC3M_RETRIG_2    = mskd_t(       OC3M_MASK,  0x1001,          OC3M_POS),
        OC3M_COMB_PWM_1  = mskd_t(       OC3M_MASK,  0x1004,          OC3M_POS),
        OC3M_COMB_PWM_2  = mskd_t(       OC3M_MASK,  0x1005,          OC3M_POS),
        OC3M_ASYM_PWM_1  = mskd_t(       OC3M_MASK,  0x1006,          OC3M_POS),
        OC3M_ASYM_PWM_2  = mskd_t(       OC3M_MASK,  0x1007,          OC3M_POS),
        // both modes
        CC4S_OUT         = mskd_t(       CC4S_MASK,  0b00,             CC4S_POS),
        CC4S_IN_IC4_TI2  = mskd_t(       CC4S_MASK,  0b01,             CC4S_POS),
        CC4S_IN_IC4_TI1  = mskd_t(       CC4S_MASK,  0b10,             CC4S_POS),
        CC4S_IN_IC4_TRC  = mskd_t(       CC4S_MASK,  0b11,             CC4S_POS),
        // input/capture mode
        IC3PSC_PRESCAL_1 = mskd_t(     IC3PSC_MASK,  0b00,           IC3PSC_POS),
        IC3PSC_PRESCAL_2 = mskd_t(     IC3PSC_MASK,  0b01,           IC3PSC_POS),
        IC3PSC_PRESCAL_4 = mskd_t(     IC3PSC_MASK,  0b10,           IC3PSC_POS),
        IC3PSC_PRESCAL_8 = mskd_t(     IC3PSC_MASK,  0b11,           IC3PSC_POS),
        IC3F_NO_FILT     = mskd_t(       IC3F_MASK,  0b0000,           IC3F_POS),
        IC3F_CK_INT_N_2  = mskd_t(       IC3F_MASK,  0b0001,           IC3F_POS),
        IC3F_CK_INT_N_4  = mskd_t(       IC3F_MASK,  0b0010,           IC3F_POS),
        IC3F_CK_INT_N_8  = mskd_t(       IC3F_MASK,  0b0011,           IC3F_POS),
        IC3F_DTS_2_N_6   = mskd_t(       IC3F_MASK,  0b0100,           IC3F_POS),
        IC3F_DTS_2_N_8   = mskd_t(       IC3F_MASK,  0b0101,           IC3F_POS),
        IC3F_DTS_4_N_6   = mskd_t(       IC3F_MASK,  0b0110,           IC3F_POS),
        IC3F_DTS_4_N_8   = mskd_t(       IC3F_MASK,  0b0111,           IC3F_POS),
        IC3F_DTS_8_N_6   = mskd_t(       IC3F_MASK,  0b1000,           IC3F_POS),
        IC3F_DTS_8_N_8   = mskd_t(       IC3F_MASK,  0b1001,           IC3F_POS),
        IC3F_DTS_16_N_5  = mskd_t(       IC3F_MASK,  0b1010,           IC3F_POS),
        IC3F_DTS_16_N_6  = mskd_t(       IC3F_MASK,  0b1011,           IC3F_POS),
        IC3F_DTS_16_N_8  = mskd_t(       IC3F_MASK,  0b1100,           IC3F_POS),
        IC3F_DTS_32_N_5  = mskd_t(       IC3F_MASK,  0b1101,           IC3F_POS),
        IC3F_DTS_32_N_6  = mskd_t(       IC3F_MASK,  0b1110,           IC3F_POS),
        IC3F_DTS_32_N_8  = mskd_t(       IC3F_MASK,  0b1111,           IC3F_POS),
        IC4PSC_PRESCAL_1 = mskd_t(     IC4PSC_MASK,  0b00,           IC4PSC_POS),
        IC4PSC_PRESCAL_2 = mskd_t(     IC4PSC_MASK,  0b01,           IC4PSC_POS),
        IC4PSC_PRESCAL_4 = mskd_t(     IC4PSC_MASK,  0b10,           IC4PSC_POS),
        IC4PSC_PRESCAL_8 = mskd_t(     IC4PSC_MASK,  0b11,           IC4PSC_POS);
    };  // struct Ccmr2
    using ccmr2_t = Reg<uint32_t, Ccmr2>;
          ccmr2_t   ccmr2;
    volatile TimCcmr2* tim_ccmr2() volatile {
        return reinterpret_cast<volatile TimCcmr2*>(this); }
             TimCcmr2* tim_ccmr2()          {
        return reinterpret_cast<         TimCcmr2*>(this); }
#else
    private: uint32_t   _unimplemented_ccmr2;  public:
#endif


#if defined(STM32F767XX_ADV_TIM_1_8)
    struct Ccer {
        using              pos_t = Pos<uint32_t, Ccer>;
        static constexpr   pos_t
                CC1E_POS = pos_t( 0),
                CC1P_POS = pos_t( 1),
               CC1NE_POS = pos_t( 2),
               CC1NP_POS = pos_t( 3),
                CC2E_POS = pos_t( 4),
                CC2P_POS = pos_t( 5),
               CC2NE_POS = pos_t( 6),
               CC2NP_POS = pos_t( 7),
                CC3E_POS = pos_t( 8),
                CC3P_POS = pos_t( 9),
               CC3NE_POS = pos_t(10),
               CC3NP_POS = pos_t(11),
                CC4E_POS = pos_t(12),
                CC4P_POS = pos_t(13),
               CC4NP_POS = pos_t(15),
                CC5E_POS = pos_t(16),
                CC5P_POS = pos_t(17),
                CC6E_POS = pos_t(20),
                CC6P_POS = pos_t(21);

        using              bits_t = Bits<uint32_t, Ccer>;
        static constexpr   bits_t
        CC1E             = bits_t(1,         CC1E_POS),
        CC1P             = bits_t(1,         CC1P_POS),
        CC1NE            = bits_t(1,        CC1NE_POS),
        CC1NP            = bits_t(1,        CC1NP_POS),
        CC2E             = bits_t(1,         CC2E_POS),
        CC2P             = bits_t(1,         CC2P_POS),
        CC2NE            = bits_t(1,        CC2NE_POS),
        CC2NP            = bits_t(1,        CC2NP_POS),
        CC3E             = bits_t(1,         CC3E_POS),
        CC3P             = bits_t(1,         CC3P_POS),
        CC3NE            = bits_t(1,        CC3NE_POS),
        CC3NP            = bits_t(1,        CC3NP_POS),
        CC4E             = bits_t(1,         CC4E_POS),
        CC4P             = bits_t(1,         CC4P_POS),
        CC4NP            = bits_t(1,        CC4NP_POS),
        CC5E             = bits_t(1,         CC5E_POS),
        CC5P             = bits_t(1,         CC5P_POS),
        CC6E             = bits_t(1,         CC6E_POS),
        CC6P             = bits_t(1,         CC6P_POS);
    };  // struct Ccer
    using ccer_t = Reg<uint32_t, Ccer>;
          ccer_t   ccer;
#elif defined(STM32F767XX_GEN_TIM_2_3_4_5)
    struct Ccer {
        using              pos_t = Pos<uint32_t, Ccer>;
        static constexpr   pos_t
                CC1E_POS = pos_t( 0),
                CC1P_POS = pos_t( 1),
               CC1NE_POS = pos_t( 2),
               CC1NP_POS = pos_t( 3),
                CC2E_POS = pos_t( 4),
                CC2P_POS = pos_t( 5),
               CC2NE_POS = pos_t( 6),
               CC2NP_POS = pos_t( 7),
                CC3E_POS = pos_t( 8),
                CC3P_POS = pos_t( 9),
               CC3NE_POS = pos_t(10),
               CC3NP_POS = pos_t(11),
                CC4E_POS = pos_t(12),
                CC4P_POS = pos_t(13),
               CC4NP_POS = pos_t(15);

        using              bits_t = Bits<uint32_t, Ccer>;
        static constexpr   bits_t
        CC1E             = bits_t(1,         CC1E_POS),
        CC1P             = bits_t(1,         CC1P_POS),
        CC1NE            = bits_t(1,        CC1NE_POS),
        CC1NP            = bits_t(1,        CC1NP_POS),
        CC2E             = bits_t(1,         CC2E_POS),
        CC2P             = bits_t(1,         CC2P_POS),
        CC2NE            = bits_t(1,        CC2NE_POS),
        CC2NP            = bits_t(1,        CC2NP_POS),
        CC3E             = bits_t(1,         CC3E_POS),
        CC3P             = bits_t(1,         CC3P_POS),
        CC3NE            = bits_t(1,        CC3NE_POS),
        CC3NP            = bits_t(1,        CC3NP_POS),
        CC4E             = bits_t(1,         CC4E_POS),
        CC4P             = bits_t(1,         CC4P_POS),
        CC4NP            = bits_t(1,        CC4NP_POS);
    };  // struct Ccer
    using ccer_t = Reg<uint32_t, Ccer>;
          ccer_t   ccer;
#elif defined(STM32F767XX_GEN_TIM_9_12)
    struct Ccer {
        using              pos_t = Pos<uint32_t, Ccer>;
        static constexpr   pos_t
                CC1E_POS = pos_t( 0),
                CC1P_POS = pos_t( 1),
               CC1NE_POS = pos_t( 2),
               CC1NP_POS = pos_t( 3),
                CC2E_POS = pos_t( 4),
                CC2P_POS = pos_t( 5),
               CC2NE_POS = pos_t( 6),
               CC2NP_POS = pos_t( 7);

        using              bits_t = Bits<uint32_t, Ccer>;
        static constexpr   bits_t
        CC1E             = bits_t(1,         CC1E_POS),
        CC1P             = bits_t(1,         CC1P_POS),
        CC1NE            = bits_t(1,        CC1NE_POS),
        CC1NP            = bits_t(1,        CC1NP_POS),
        CC2E             = bits_t(1,         CC2E_POS),
        CC2P             = bits_t(1,         CC2P_POS),
        CC2NE            = bits_t(1,        CC2NE_POS),
        CC2NP            = bits_t(1,        CC2NP_POS);
    };  // struct Ccer
    using ccer_t = Reg<uint32_t, Ccer>;
          ccer_t   ccer;
#elif defined(STM32F767XX_GEN_TIM_10_11_13_14)
    struct Ccer {
        using              pos_t = Pos<uint32_t, Ccer>;
        static constexpr   pos_t
                CC1E_POS = pos_t( 0),
                CC1P_POS = pos_t( 1),
               CC1NE_POS = pos_t( 2),
               CC1NP_POS = pos_t( 3);

        using              bits_t = Bits<uint32_t, Ccer>;
        static constexpr   bits_t
        CC1E             = bits_t(1,         CC1E_POS),
        CC1P             = bits_t(1,         CC1P_POS),
        CC1NE            = bits_t(1,        CC1NE_POS),
        CC1NP            = bits_t(1,        CC1NP_POS);
    };  // struct Ccer
    using ccer_t = Reg<uint32_t, Ccer>;
          ccer_t   ccer;
#else
    private: uint32_t   _unimplemented_ccer;     public:
#endif


#ifdef STM32F767XX_GEN_TIM_2_5
    uint32_t    cnt;
#else
    struct Cnt {
        using              pos_t = Pos<uint32_t, Cnt>;
        static constexpr   pos_t
                 CNT_POS = pos_t( 0),
              UIFCPY_POS = pos_t(31);

        using              bits_t = Bits<uint32_t, Cnt>;
        static constexpr   bits_t
        UIFCPY           = bits_t(1,       UIFCPY_POS);

        static const uint32_t
                CNT_MASK = 0xFFFFFFFFU;

        using   mskd_t = Mskd<uint32_t, Cnt>;
        using   shft_t = Shft<uint32_t, Cnt>;

        REGBITS_MSKD_RANGE("Tim::Cnt",
                           CNT,
                           cnt,
                           CNT_MASK,
                           CNT_POS,
                           CNT_MASK);
    };  // struct Cnt
    using cnt_t = Reg<uint32_t, Cnt>;
          cnt_t   cnt;
#endif


#ifdef STM32F767XX_GEN_TIM_2_5
    uint32_t    psc;
#else
                uint16_t    psc;
    private:    uint16_t    _psc_high_bits;  public:
#endif


#ifdef STM32F767XX_GEN_TIM_2_5
    uint32_t    arr;
#else
                uint16_t    arr;
    private:    uint16_t    _arr_high_bits;  public:
#endif


#ifdef STM32F767XX_ADV_TIM_1_8
                uint16_t    rcr;
    private:    uint16_t    _rcr_high_bits;  public:
#else
    private: uint32_t   _unimplemented_rcr; public:
#endif


#ifdef STM32F767XX_TIM_CCR1
#ifdef STM32F767XX_GEN_TIM_2_5
                uint32_t    ccr1;
#else
                uint16_t    ccr1;
    private:    uint16_t    _ccr1_high_bits;     public:
#endif
    volatile TimCcr1* tim_ccr1() volatile {
        return reinterpret_cast<volatile TimCcr1*>(this); }
             TimCcr1* tim_ccr1()          {
        return reinterpret_cast<         TimCcr1*>(this); }
#else
    private: uint32_t   _unimplemented_ccr1;     public:
#endif


#ifdef STM32F767XX_TIM_CCR2
#ifdef STM32F767XX_GEN_TIM_2_5
                uint32_t    ccr2;
#else
                uint16_t    ccr2;
    private:    uint16_t    _ccr2_high_bits;     public:
#endif
    volatile TimCcr2* tim_ccr2() volatile {
        return reinterpret_cast<volatile TimCcr2*>(this); }
             TimCcr2* tim_ccr2()          {
        return reinterpret_cast<         TimCcr2*>(this); }
#else
    private: uint32_t   _unimplemented_ccr2;     public:
#endif

#ifdef STM32F767XX_TIM_CCR3_4
#ifdef STM32F767XX_GEN_TIM_2_5
                uint32_t    ccr3,
                            ccr4;
#else
                uint16_t    ccr3;
    private:    uint16_t    _ccr3_high_bits;     public:
                uint16_t    ccr4;
    private:    uint16_t    _ccr4_high_bits;     public:
#endif
    volatile TimCcr3_4* tim_ccr3_4() volatile {
        return reinterpret_cast<volatile TimCcr3_4*>(this); }
             TimCcr3_4* tim_ccr3_4()          {
        return reinterpret_cast<         TimCcr3_4*>(this); }
#else
    private: uint32_t   _unimplemented_ccr3_4[2];  public:
#endif


#ifdef STM32F767XX_ADV_TIM_1_8
    struct Bdtr {
        using              pos_t = Pos<uint32_t, Bdtr>;
        static constexpr   pos_t
                 DTG_POS = pos_t( 0),
                LOCK_POS = pos_t( 8),
                OSSI_POS = pos_t(10),
                OSSR_POS = pos_t(11),
                 BKE_POS = pos_t(12),
                 BKP_POS = pos_t(13),
                 AOE_POS = pos_t(14),
                 MOE_POS = pos_t(15),
                 BKF_POS = pos_t(16),
                BK2F_POS = pos_t(20),
                BK2E_POS = pos_t(24),
                BK2P_POS = pos_t(25);

        using              bits_t = Bits<uint32_t, Bdtr>;
        static constexpr   bits_t
        OSSI             = bits_t(1,         OSSI_POS),
        OSSR             = bits_t(1,         OSSR_POS),
        BKE              = bits_t(1,          BKE_POS),
        BKP              = bits_t(1,          BKP_POS),
        AOE              = bits_t(1,          AOE_POS),
        MOE              = bits_t(1,          MOE_POS),
        BK2E             = bits_t(1,         BK2E_POS),
        BK2P             = bits_t(1,         BK2P_POS);

        static const uint32_t
                DTG_MASK =      0xFFU,
               LOCK_MASK =       0x3U,
                BKF_MASK =       0xFU,
               BK2F_MASK =       0xFU;

        using              mskd_t = Mskd<uint32_t, Bdtr>;
        using              shft_t = Shft<uint32_t, Bdtr>;

        static constexpr   mskd_t
        LOCK_OFF         = mskd_t(       LOCK_MASK,  0b00,         LOCK_POS),
        LOCK_LEVEL_2     = mskd_t(       LOCK_MASK,  0b01,         LOCK_POS),
        LOCK_LEVEL_3     = mskd_t(       LOCK_MASK,  0b10,         LOCK_POS),
        LOCK_LEVEL_4     = mskd_t(       LOCK_MASK,  0b11,         LOCK_POS);

        /* note bits 7:5 control step size
          rm0410_f7_6,7_xxx_reference_manual.pdf
          25.4.18 TIM1/TIM8 break and dead-time register (TIMx_BDTR)
          Bits 7:0 DTG[7:0]: Dead-time generator setup
          This bit-field defines the duration of the dead-time inserted
            between the complementary outputs. DT correspond to this
            duration.
          DTG[7:5]=0xx => DT=DTG[7:0]x t dtg with t dtg =t DTS .
          DTG[7:5]=10x => DT=(64+DTG[5:0])xt dtg with T dtg =2xt DTS .
          DTG[7:5]=110 => DT=(32+DTG[4:0])xt dtg with T dtg =8xt DTS .
          DTG[7:5]=111 => DT=(32+DTG[4:0])xt dtg with T dtg =16xt DTS .
          Example if T DTS =125ns (8MHz), dead-time possible values are:
          0 to 15875 ns by 125 ns steps,
          16 us to 31750 ns by 250 ns steps,
          32 us to 63us by 1 us steps,
          64 us to 126 us by 2 us steps
          Note: This bit-field can not be modified as long as LOCK level 1,
                2 or 3 has been programmed (LOCK bits in TIMx_BDTR register).
        */
        REGBITS_MSKD_RANGE("Tim::Bdtr",
                           DTG,
                           dtg,
                           DTG_MASK,
                           DTG_POS,
                           DTG_MASK);
    };  // struct Bdtr
    using bdtr_t = Reg<uint32_t, Bdtr>;
          bdtr_t   bdtr;
#else
    private: uint32_t   _unimplemented_bdtr;     public:
#endif


#ifdef STM32F767XX_TIM_DCR
    struct Dcr {
        using              pos_t = Pos<uint32_t, Dcr>;
        static constexpr   pos_t
                 DBA_POS = pos_t( 0),
                 DBL_POS = pos_t( 8);

        static const uint32_t
                DBA_MASK =      0x1FU,
                DBL_MASK =      0x1FU;

        using   mskd_t = Mskd<uint32_t, Dcr>;
        using   shft_t = Shft<uint32_t, Dcr>;

        REGBITS_MSKD_RANGE("Tim::Dcr",
                           DBA,
                           dba,
                           DBA_MASK,
                           DBA_POS,
                           DBA_MASK);
        REGBITS_MSKD_RANGE("Tim::Dcr",
                           DBL,
                           dbl,
                           DBL_MASK,
                           DBL_POS,
                           DBL_MASK);
    };  // struct Dcr
    using dcr_t = Reg<uint32_t, Dcr>;
          dcr_t   dcr;
    volatile TimDcr* tim_dcr() volatile {
        return reinterpret_cast<volatile TimDcr*>(this); }
             TimDcr* tim_dcr()          {
        return reinterpret_cast<         TimDcr*>(this); }
#else
    private: uint32_t   _unimplemented_dcr; public:
#endif


#ifdef STM32F767XX_TIM_DMAR
    struct Dmar {
        using              pos_t = Pos<uint32_t, Dmar>;
        static constexpr   pos_t
                DMAB_POS = pos_t( 0);

        static const uint32_t
               DMAB_MASK =    0xFFFFU;

        using   mskd_t = Mskd<uint32_t, Dmar>;
        using   shft_t = Shft<uint32_t, Dmar>;

        REGBITS_MSKD_RANGE("Tim::Dcr",
                           DMAB,
                           dmab,
                           DMAB_MASK,
                           DMAB_POS,
                           DMAB_MASK);
    };  // struct Dmar
    using dmar_t = Reg<uint32_t, Dmar>;
          dmar_t   dmar;
    volatile TimDmar*       tim_dmar() volatile {
        return reinterpret_cast<volatile TimDmar*>(this); }
             TimDmar*       tim_dmar()          {
        return reinterpret_cast<         TimDmar*>(this); }
#else
    private: uint32_t   _unimplemented_dmar;     public:
#endif


#ifdef STM32F767XX_GEN_TIM_2
    struct Orr {
        using              pos_t = Pos<uint32_t, Orr>;
        static constexpr   pos_t
            ITR1_RMP_POS = pos_t(10);

        static const uint32_t
           ITR1_RMP_MASK =       0x3U;

        using   mskd_t = Mskd<uint32_t, Orr>;
        using   shft_t = Shft<uint32_t, Orr>;

        static constexpr   mskd_t
        ITR1_RMP_TIM8_TRIGOUT    = mskd_t(ITR1_RMP_MASK,  0b00,  ITR1_RMP_POS),
        ITR1_RMP_ETH_PTP_TRIGOUT = mskd_t(ITR1_RMP_MASK,  0b01,  ITR1_RMP_POS),
        ITR1_RMP_OTG_FS_SOF      = mskd_t(ITR1_RMP_MASK,  0b10,  ITR1_RMP_POS),
        ITR1_RMP_OTG_HS_SOF      = mskd_t(ITR1_RMP_MASK,  0b11,  ITR1_RMP_POS);
    };  // struct Orr
    using orr_t = Reg<uint32_t, Orr>;
          orr_t  orr;
    volatile TimOrr_2*  tim_orr_2() volatile {
        return reinterpret_cast<volatile TimOrr_2*>(this); }
             TimOrr_2*  tim_orr_2()          {
        return reinterpret_cast<         TimOrr_2*>(this); }
#endif

#ifdef STM32F767XX_GEN_TIM_5
    struct Orr {
        using              pos_t = Pos<uint32_t, Orr>;
        static constexpr   pos_t
             TI4_RMP_POS = pos_t( 6);

        static const uint32_t
            TI4_RMP_MASK =       0x3U;

        using   mskd_t = Mskd<uint32_t, Orr>;
        using   shft_t = Shft<uint32_t, Orr>;

        static constexpr   mskd_t
        TI4_RMP_TIM5_CH4_GPIO    = mskd_t(TI4_RMP_MASK,  0b00,   TI4_RMP_POS),
        TI4_RMP_LSI_TIM5_CH4     = mskd_t(TI4_RMP_MASK,  0b01,   TI4_RMP_POS),
        TI4_RMP_LSE_TIM5_CH4     = mskd_t(TI4_RMP_MASK,  0b10,   TI4_RMP_POS),
        TI4_RMP_RTC_TIM5_CH4     = mskd_t(TI4_RMP_MASK,  0b11,   TI4_RMP_POS);
    };  // struct Orr
    using orr_t = Reg<uint32_t, Orr>;
          orr_t  orr;
    volatile TimOrr_5*  tim_orr_5() volatile {
        return reinterpret_cast<volatile TimOrr_5*>(this); }
             TimOrr_5*  tim_orr_5()          {
        return reinterpret_cast<         TimOrr_5*>(this); }
#endif

#ifdef STM32F767XX_GEN_TIM_11
    struct Orr {
        using              pos_t = Pos<uint32_t, Orr>;
        static constexpr   pos_t
             TI1_RMP_POS = pos_t( 0);

        static const uint32_t
            TI1_RMP_MASK =       0x3U;

        using              mskd_t = Mskd<uint32_t, Orr>;
        static constexpr   mskd_t
        TI1_RMP_0        = mskd_t(    TI1_RMP_MASK,  0x1U,      TI1_RMP_POS),
        TI1_RMP_1        = mskd_t(    TI1_RMP_MASK,  0x2U,      TI1_RMP_POS);
    };  // struct Orr
    using orr_t = Reg<uint32_t, Orr>;
          orr_t   orr;
    volatile TimOrr_11* tim_orr_11() volatile {
        return reinterpret_cast<volatile TimOrr_11*>(this);
    }
             TimOrr_11* tim_orr_11()          {
        return reinterpret_cast<         TimOrr_11*>(this);
    }
#endif


#if    !defined(STM32F767XX_GEN_TIM_2)  \
    && !defined(STM32F767XX_GEN_TIM_5)  \
    && !defined(STM32F767XX_GEN_TIM_11)
    private: uint32_t   _unimplemented_orr; public:
#endif


#ifdef STM32F767XX_ADV_TIM_1_8
    struct Ccmr3 {
        using              pos_t = Pos<uint32_t, Ccmr3>;
        static constexpr   pos_t
               OC5FE_POS = pos_t( 2),
               OC5PE_POS = pos_t( 3),
           OC5M_B210_POS = pos_t( 4),
               OC5CE_POS = pos_t( 7),
               OC6FE_POS = pos_t(10),
               OC6PE_POS = pos_t(11),
           OC6M_B210_POS = pos_t(12),
               OC6CE_POS = pos_t(15),
             OC5M_B3_POS = pos_t(16),
             OC6M_B3_POS = pos_t(24);

        using              bits_t = Bits<uint32_t, Ccmr3>;
        static constexpr   bits_t
        OC5FE            = bits_t(1,        OC5FE_POS),
        OC5PE            = bits_t(1,        OC5PE_POS),
        OC5CE            = bits_t(1,        OC5CE_POS),
        OC6FE            = bits_t(1,        OC6FE_POS),
        OC6PE            = bits_t(1,        OC6PE_POS),
        OC6CE            = bits_t(1,        OC6CE_POS),
        OC5M_B3          = bits_t(1,      OC5M_B3_POS),
        OC6M_B3          = bits_t(1,      OC6M_B3_POS);

        static const uint32_t
        OC5M_B210_MASK   = 0x7U,
        OC6M_B210_MASK   = 0x7U;

        using   mskd_t = Mskd<uint32_t, Ccmr3>;
        using   shft_t = Shft<uint32_t, Ccmr3>;

        REGBITS_MSKD_RANGE("Tim::Ccmr3",
                           OC5M_B210,
                           Oc5m_b210,
                           OC5M_B210_MASK,
                           OC5M_B210_POS,
                           OC5M_B210_MASK);
        REGBITS_MSKD_RANGE("Tim::Ccmr3",
                           OC6M_B210,
                           Oc6m_b210,
                           OC6M_B210_MASK,
                           OC6M_B210_POS,
                           OC6M_B210_MASK);
    };  // struct Ccmr3
    using ccmr3_t = Reg<uint32_t, Ccmr3>;
          ccmr3_t   ccmr3;


    struct Ccr5 {
        using              pos_t = Pos<uint32_t, Ccr5>;
        static constexpr   pos_t
                CCR5_POS = pos_t( 0),
               GC5C1_POS = pos_t(29),
               GC5C2_POS = pos_t(30),
               GC5C3_POS = pos_t(31);

        using              bits_t = Bits<uint32_t, Ccr5>;
        static constexpr   bits_t
        GC5C1            = bits_t(1,        GC5C1_POS),
        GC5C2            = bits_t(1,        GC5C2_POS),
        GC5C3            = bits_t(1,        GC5C3_POS);

        static const uint32_t
               CCR5_MASK = 0xFFFFU;

        using mskd_t = Mskd<uint32_t, Ccr5>;
        using shft_t = Shft<uint32_t, Ccr5>;
        REGBITS_MSKD_RANGE("Tim::Ccr5",
                           CCR5,
                           ccr5,
                           CCR5_MASK,
                           CCR5_POS,
                           CCR5_MASK);
    };  // struct Ccr5
    using ccr5_t = Reg<uint32_t, Ccr5>;
          ccr5_t   ccr5;


                uint16_t    ccr6;
    private:    uint16_t    _ccr6_high_bits;     public:


    struct Af1 {
        using              pos_t = Pos<uint32_t, Af1>;
        static constexpr   pos_t
              _BKINE_POS = pos_t( 0),
           _BKDF1BKE_POS = pos_t( 8),
              _BKINP_POS = pos_t( 9);

        using              bits_t = Bits<uint32_t, Af1>;
        static constexpr   bits_t
        _BKINE           = bits_t(1,       _BKINE_POS),
        _BKDF1BKE        = bits_t(1,    _BKDF1BKE_POS),
        _BKINP           = bits_t(1,       _BKINP_POS);
    };  // struct Af1
    using af1_t = Reg<uint32_t, Af1>;
          af1_t   af1;


    struct Af2 {
        using              pos_t = Pos<uint32_t, Af2>;
        static constexpr   pos_t
              BK2INE_POS = pos_t( 0),
           BK2DF1BKE_POS = pos_t( 8),
              BK2INP_POS = pos_t( 9);

        using              bits_t = Bits<uint32_t, Af2>;
        static constexpr   bits_t
        BK2INE           = bits_t(1,       BK2INE_POS),
        BK2DF1BKE        = bits_t(1,    BK2DF1BKE_POS),
        BK2INP           = bits_t(1,       BK2INP_POS);
    };  // struct Af2
    using af2_t = Reg<uint32_t, Af2>;
          af2_t   af2;

#else
  private:
    uint32_t    _unimplemented_ccmr3,
                _unimplemented_ccr5 ,
                _unimplemented_ccr6 ,
                _unimplemented_af1  ,
                _unimplemented_af2  ;
  public:
#endif

#endif  // #ifndef STM32F767XX_TIM_HXX_INCLUDE
