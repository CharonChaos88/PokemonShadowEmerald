    .section .rodata
    .align 2
    .global gMultibootEventPayload
    .global gMultibootEventPayloadSize

gMultibootEventPayload:
    .incbin "../multiboot_payload/mb_event_distribution.gba"

    .align 2
gMultibootEventPayloadEnd:

    .align 2
gMultibootEventPayloadSize:
    .word gMultibootEventPayloadEnd - gMultibootEventPayload
