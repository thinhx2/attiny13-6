
MMCU=attiny13a
AVRDUDE_MCU=t13
CC=avr-gcc
CFLAGS=-g -mmcu=$(MMCU)
OBJCOPY=avr-objcopy

avrdude: main.hex
	avrdude -p $(AVRDUDE_MCU) -c usbtiny -P usb -U flash:w:$<:i

get:
	avrdude -p $(AVRDUDE_MCU) -c usbtiny -P usb flash:r:gotten:i

main.hex: main.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

main.o: main.c
	$(CC) $(CFLAGS) -Os -c $<

main.elf: main.o
	$(CC) $(CFLAGS) -o $@ $<

sim: main.hex
	simulavr -d $(MMCU) $<

clean:
	rm -rf *.elf *.hex *.o
