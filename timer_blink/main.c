#include <avr/io.h>
#include <avr/interrupt.h>

volatile int counter = 0;

int main(void)
{
    /* ------------------------------------------------------------------------------ */
    // Setup Timer for isr.
    // f_timer = (f_cpu / prescalar / counter), or f_timer = f_cpu / (prescalar * counter)
    //             1mhz /   1024   /   255 = 3,82 hz
    OCR0A = 255;

    // Waveform Generation Mode: CTC
    TCCR0A |= (1 << WGM01);

    // Timer/Counter0 Output Compare Match A Interrupt Enable
    TIMSK0 |= (1<<OCIE0A);

    // clkI/O/1024 (From prescaler)
    //TCCR0B |= (1 << CS02) | (1 << CS00);
    TCCR0B |= (1 << CS02);


    DDRB = (1 << PB0);

    sei();
    while (1) { }
    return 0;
}

ISR(TIM0_COMPA_vect)
{
    if(counter == 30) {
        PORTB ^= (1 << PB0);
        counter = 0;
    }
    counter++;
}
