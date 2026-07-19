OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY {
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 32M
    ewram (rw) : ORIGIN = 0x02000000, LENGTH = 256K
}

SECTIONS {
    .text : {
        *(.text.start)
        EXCLUDE_FILE(multiboot.o) *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        __text_end__ = .;
    } > rom

    .data : {
        __data_start__ = .;
        *(.data*)
        /* MultiBootMain calls SWI 0x25 which disables ROM. */
        /* All multiboot code must run from EWRAM. */
        multiboot.o(.text*)
        . = ALIGN(4);
        __data_end__ = .;
    } > ewram AT > rom

    __data_rom_start__ = LOADADDR(.data);

    .bss : {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > ewram
}
