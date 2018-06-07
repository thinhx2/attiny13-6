#include <avr/io.h>
#include <avr/interrupt.h>

volatile int counter = 0;

int main(void) {
  // Setup Timer for isr.
  // f_timer = (f_cpu / prescalar / counter), or f_timer = f_cpu / (prescalar * counter)
  //             1mhz /   1024   /   255 = 3,82 hz
  OCR0A = 255;

  // Waveform Generation Mode: CTC
  TCCR0A |= (1 << WGM01);

  // Timer/Counter0 Output Compare Match A Interrupt Enable
  TIMSK0 |= (1<<OCIE0A);

  // clkI/O/1024 (From prescaler)
  TCCR0B |= (1 << CS00) | (1 << CS02);

  // Pin change interrupt
  GIMSK = (1 << PCIE);  // PCIE: Pin Change Interrupt Enable
  PCMSK = (1 << PCINT1); // Pin Change Enable Mask for PB1.

  // Setup port directions. 0 input 1 output. PB0 output, PB2 output, PB1 input
  DDRB |= (1 << PB0) | (1 << PB2);
  DDRB &= ~(1<< PB1) ; // 0 is default tho.

  // Enable pullup resistor on the input.
  PORTB |= (1<<PB1);

  // Set both leds low to start with,
  PORTB &= ~(1<<PB0) & ~(1<< PB2);

  sei();
  while (1) { }
  return 0;
}

ISR(TIM0_COMPA_vect) {
  counter++;
  if(counter == 70 || counter == 72 || counter == 78) {
    PORTB ^= (1<<PB0);
  } else if(counter == 80) {
    PORTB ^= (1<<PB0);
    counter = 0;
  }
}

ISR(PCINT0_vect) {
  PORTB ^= (1<<PB2);
}
