    .arm
    .section .text.start
    .global _start

_start:
    @ Multiboot payloads execute directly from the first byte (0x02000000)
    @ without any 192-byte ROM header.
    @ Set up the stack pointer at the end of the GBA's fast WRAM (0x03007F00)

reset:
    @ Set up the stack pointer at the end of the GBA's fast WRAM (0x03007F00)
    ldr sp, =0x03007F00
    
    @ Jump to the C code (Switch to THUMB state!)
    ldr r0, =PayloadMain
    bx r0

hang:
    b hang
