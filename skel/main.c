/* 9.6 Mhz */
#define F_CPU 9600000UL

#include <avr/io.h>
#include <util/delay.h>

void delay(int t) {
  while(t--) {
    _delay_us(100);
  }
}

#define SET_LEVEL(on, off) { \
  int i; \
    PORTB = 1; delay(on); \
    PORTB = 0; delay(off); \
}

#define TOP 100
int main(void) {
  int on, off;
  DDRB = 1;
  while(1) { 
    for(on=0; on <= TOP; ++on) {
      SET_LEVEL(on, TOP)
    }
    for(off=TOP; off >= 0; --off) {
      SET_LEVEL(TOP, off)
    }
    for(off=0; off <= TOP; ++off) {
      SET_LEVEL(TOP, off)
    }
    for(on=TOP; on >= 0; --on) {
      SET_LEVEL(on, TOP)
    }
  }
}
