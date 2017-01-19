
MMCU=attiny13a
AVRDUDE_MCU=t13
CC=avr-gcc
CFLAGS=-g -mmcu=$(MMCU)
OBJCOPY=avr-objcopy

avrdude: attiny13.hex
	avrdude -p $(AVRDUDE_MCU) -c usbtiny -P usb -U flash:w:$<:i

get:
	avrdude -p $(AVRDUDE_MCU) -c usbtiny -P usb flash:r:gotten:i

attiny13.hex: attiny13.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

attiny13.o: attiny13.c
	$(CC) $(CFLAGS) -Os -c $<

attiny13.elf: attiny13.o
	$(CC) $(CFLAGS) -o $@ $<

sim: attiny13.hex
	simulavr -d $(MMCU) $<

clean:
	rm -rf *.elf *.hex *.o
