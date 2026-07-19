TOOLCHAIN ?= $(DEVKITARM)
PREFIX := arm-none-eabi-
CC := $(PREFIX)gcc
AS := $(PREFIX)as
LD := $(PREFIX)ld
OBJCOPY := $(PREFIX)objcopy

INCLUDES := -I../tools/agbcc/include -iquote ../include
CFLAGS := -mthumb -mthumb-interwork -O2 -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -Wall -ffunction-sections -fdata-sections -DMODERN=1 -DEMERALD=1 -std=gnu17 $(INCLUDES)

all: DistServer.gba

DistServer.gba: server.elf
	$(OBJCOPY) -O binary $< $@
	../tools/gbafix/gbafix $@ -t"DIST SERVER" -cDST0 -m01 -r0 --silent
	truncate -s 32M $@
	@echo "Distribution Server compiled successfully to DistServer.gba!"

server.elf: crt0.o main.o multiboot.o payload.o
	$(LD) -T server.ld --gc-sections -o $@ $^

crt0.o: crt0.s
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -S -o main.s $<
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ main.s


multiboot.o: multiboot.s
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ $<

payload.o: payload.s
	$(AS) -mthumb-interwork -mcpu=arm7tdmi -meabi=5 -o $@ $<

clean:
	rm -f *.o *.elf *.gba 
