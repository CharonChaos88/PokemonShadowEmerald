OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY {
    wram (wx) : ORIGIN = 0x02000000, LENGTH = 256K
}

SECTIONS {
    .text : {
        *(.text.start)
        *(.text*)
        *(.rodata*)
    } > wram

    .data : {
        *(.data*)
    } > wram

    .bss : {
        *(.bss*)
        *(COMMON)
    } > wram
}
