/* 9.6 Mhz */
#define F_CPU 9600000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB |= (1 << DDB0);
  while(1) {
    PORTB = ~(1 << DDB0);
    _delay_ms(1200);
    PORTB |= (1 << DDB0);
    _delay_ms(200);
    PORTB = ~(1 << DDB0);
    _delay_ms(200);
    PORTB |= (1 << DDB0);
    _delay_ms(200);
  }
}
