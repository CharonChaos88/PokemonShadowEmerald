TOOLCHAIN ?= $(DEVKITARM)
PREFIX := arm-none-eabi-
CC := $(PREFIX)gcc
AS := $(PREFIX)as
LD := $(PREFIX)ld
OBJCOPY := $(PREFIX)objcopy

INCLUDES := -I../tools/agbcc/include -iquote ../include
CFLAGS := -mthumb -mthumb-interwork -O2 -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -Wall -ffunction-sections -fdata-sections -DMODERN=1 -DEMERALD=1 -std=gnu17 $(INCLUDES)

all: mb_event_distribution.gba

mb_event_distribution.gba: payload.elf
	$(OBJCOPY) -O binary $< $@
	@echo "Payload compiled successfully to mb_event_distribution.gba!"

payload.elf: crt0.o main.o
	$(LD) -T payload.ld --gc-sections -o $@ $^

crt0.o: crt0.s
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -S -o main.s $<
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ main.s

clean:
	rm -f *.o *.elf *.gba
