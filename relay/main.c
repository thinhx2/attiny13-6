/* 9.6 Mhz */
#define F_CPU 9600000UL

#include <avr/io.h>
#include <util/delay.h>

void delay(int t) {
  while(t--) {
    _delay_us(100);
  }
}

int main(void) {
  int portb = 1;
  int state = 0;
  DDRB = 0b10;
  PORTB |= portb;
  while(1) { 
    while(PORTB & 1) {
      PORTB |= 2;
      state = 1;
    };
    if(state) {
    }
    _delay_ms(50);
  }
}
