/* 9.6 Mhz */
#define F_CPU 9600000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect) {
  PORTB ^= (1 << PB2);
}

int main(void) {
  DDRB = (1 << PB1);
  PORTB = (1 << PB0);

  // Enable INT0 on rising edge
  MCUCR |= (1 << ISC00) | (1 << ISC01);

  // Enable INT and disable PCINT
  GIMSK |= (1 << INT0);
  GIMSK &= ~(1 << PCIE);

  // Enable global interrupt
  sei();

  while(1) {
    PORTB = ~(1 << PB0);
    _delay_ms(1200);
    PORTB |= (1 << PB0);
    _delay_ms(200);
    PORTB = ~(1 << PB0);
    _delay_ms(200);
    PORTB |= (1 << PB0);
    _delay_ms(200);
  }
}
