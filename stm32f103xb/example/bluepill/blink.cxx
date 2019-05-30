// for STM32F767 Nucleo-144 evaluation board

// regbits_stm definitions
#include <stm32f103xb.hxx>

// allow namespace/prefix-less access to regbits_stm
using namespace stm32f103xb;


// default STM32F103xb clock is 8 MHz HSI
static const uint32_t   MAIN_CLOCK_KHZ = 8000;



// using basic timer 6
void delay(
uint32_t    milliseconds)
{
    // disable before making changes
    gen_tim_2->cr1 = 0;

    // initialize
    gen_tim_2->sr    = 0;
    gen_tim_2->arr = milliseconds;

    // enable and start one-pulse timer
    gen_tim_2->cr1 = GenTim_2_3_4::Cr1::OPM | GenTim_2_3_4::Cr1::CEN;

    // wait for timer to finish
    while (!gen_tim_2->sr.any(GenTim_2_3_4::Sr::UIF))
        asm("nop");
}



int main()
{
    // enable peripherals
    rcc->apb2enr |= stm32f103xb::Rcc::Apb2enr::IOPCEN;
    rcc->apb1enr |= stm32f103xb::Rcc::Apb1enr::TIM2EN;
    asm("nop"); asm("nop"); asm("nop");

    // reset peripherals
    rcc->apb2rstr |= stm32f103xb::Rcc::Apb2rstr::IOPCRST;
    rcc->apb1rstr |= stm32f103xb::Rcc::Apb1rstr::TIM2RST;
    rcc->apb2rstr  = 0;
    rcc->apb1rstr  = 0;

    // set port 13 to output, open-drain, 2MHz max
    gpioc->crh /=    stm32f103xb::Gpio::Crh::CNF13_OUTPUT_OPEN_DRAIN
                   | stm32f103xb::Gpio::Crh::MODE13_OUTPUT_2_MHZ    ;

    // set general timer 2 prescaler to 1 count per millisecond
    gen_tim_2->psc = MAIN_CLOCK_KHZ + 1;
    // generate "update event" to load PSC register into actual
    //   prescaler counter shadow register
    gen_tim_2->egr = GenTim_2_3_4::Egr::UG;

    // turn LED on for 4 seconds
    gpioc->bsrr = Gpio::Bsrr::BR13;
    delay(4000);

    // turn LED off for 2 second
    gpioc->bsrr = Gpio::Bsrr::BS13;
    delay(2000);

    // infinite loop, blink LED at 1 Hz
    while (true) {
        // turn LED on for 0.1 seconds
        gpioc->bsrr = Gpio::Bsrr::BR13;
        delay(100);

        // turn LED off for 0.9 seconds
        gpioc->bsrr = Gpio::Bsrr::BS13;
        delay(900);
    }
}
