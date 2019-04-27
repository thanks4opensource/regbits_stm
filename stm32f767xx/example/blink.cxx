// for STM32F767 Nucleo-144 evaluation board

// regbits_stm definitions
#include <stm32f767xx.hxx>

// allow namespace/prefix-less access to regbits_stm
using namespace stm32f767xx;


// default STM32F767xx clock is 16MHz HSI
static const uint32_t   MAIN_CLOCK_KHZ = 16000;



// using basic timer 6
void delay(
uint32_t    milliseconds)
{
    // disable before making changes
    bsctim6->cr1 = 0;

    // initialize
    bsctim6->sr  = 0;
    bsctim6->arr = milliseconds;

    // enable and start one-pulse timer
    bsctim6->cr1 = Bsctim_6_7::Cr1::OPM | Bsctim_6_7::Cr1::CEN;

    // wait for timer to finish
    while (bsctim6->sr != Bsctim_6_7::Sr::UIF)
        asm("nop");
}



int main()
{
    // enable peripherals
    rcc->ahb1enr |= Rcc::Ahb1enr::GPIOB;
    rcc->apb1enr |= Rcc::Apb1enr::TIM6;

    // reset peripherals
    rcc->ahb1rstr = Rcc::Ahb1rstr::GPIOB;
    rcc->apb1rstr = Rcc::Apb1rstr::TIM6;
    rcc->ahb1rstr = 0;
    rcc->apb1rstr = 0;

    // set on-board green LED port to output
    gpiob->moder = Gpio::Moder::OUTPUT_0;

    // set basic timer 6 prescaler to 1 count per millisecond
    bsctim6->psc = Bsctim_6_7::Psc::PSC<MAIN_CLOCK_KHZ + 1>();
    // generate "update event" to load PSC register into actual
    //   prescaler counter shadow register
    bsctim6->egr = Bsctim_6_7::Egr::UG;

    // turn LED on for 4 seconds
    gpiob->bsrr = Gpio::Bsrr::BS0;
    delay(4000);

    // turn LED off for 2 second
    gpiob->bsrr = Gpio::Bsrr::BR0;
    delay(2000);

    // infinite loop, blink LED at 1 Hz
    while (true) {
        // turn LED on for 0.1 seconds
        gpiob->bsrr = Gpio::Bsrr::BS0;
        delay(100);

        // turn LED off for 0.9 seconds
        gpiob->bsrr = Gpio::Bsrr::BR0;
        delay(900);
    }
}
