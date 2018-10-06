

#define F_CPU 9600000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

typedef void (*fptr)();

void dothing() {
  PORTB |= (1<<PB1);
}

#define CALLBACKS_COUNT 5
fptr callbacks[CALLBACKS_COUNT][2];

#define ON_HIGH(pin, text) \
    void _on_pin_high_pin() text \
    callbacks[pin][1] = _on_pin_high_pin;

ON_HIGH(1) {
  
}

int main(void) {
  DDRB |= (1 << PB0);
  PORTB &= ~(1<<PB0);
  MCUCR |= (1 << ISC00) | (1 << ISC01);

  while (1) {
    for(int i = 0; i < CALLBACKS_LEN; i++) {
      (*callbacks[i])();
    }
    _delay_ms(10);
  }
  return 0;
}
