    .arm
    .section .text.start
    .global _start

_start:
    b reset

    @ gbafix will inject the logo here.
    .fill 0xBC, 1, 0 

reset:
    @ Set up stacks
    @ IRQ Mode
    mov r0, #0xD2
    msr cpsr_c, r0
    ldr sp, =0x03007FA0

    @ SVC Mode
    mov r0, #0xD3
    msr cpsr_c, r0
    ldr sp, =0x03007FE0

    @ System Mode
    mov r0, #0x5F
    msr cpsr_c, r0
    ldr sp, =0x03007F00

    @ Copy .data to EWRAM
    ldr r0, =__data_rom_start__
    ldr r1, =__data_start__
    ldr r2, =__data_end__
copy_data:
    cmp r1, r2
    ldrcc r3, [r0], #4
    strcc r3, [r1], #4
    bcc copy_data

    @ Clear .bss
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__
    mov r3, #0
clear_bss:
    cmp r1, r2
    strcc r3, [r1], #4
    bcc clear_bss

    @ Jump to C code (Switch to THUMB state)
    ldr r0, =PayloadMain
    bx r0

    .section .data
    .align 2
    .arm
    .global IntrMain
IntrMain:
    mov r3, #0x04000000
    add r3, r3, #0x200    @ r3 = 0x04000200 (REG_IE)
    ldrh r2, [r3]         @ r2 = REG_IE
    ldrh r1, [r3, #2]     @ r1 = REG_IF
    and r1, r1, r2        @ r1 = REG_IE & REG_IF
    strh r1, [r3, #2]     @ Acknowledge REG_IF
    
    ldr r2, =0x03FFFFF8   @ INTR_CHECK for BIOS Wait
    ldrh r3, [r2]
    orr r3, r3, r1
    strh r3, [r2]
    
    bx lr

hang:
    b hang
