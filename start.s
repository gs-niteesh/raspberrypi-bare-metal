.section ".text.boot"

.global _start

_start:
    mrs x1, mpidr_el1
    and x1, x1, #0x3
    cbz x1, primary

1:  wfe            // Put other cores to endless loop(standby mode).
    b 1b

primary:
    ldr x1, =_start//Setup stack for C
    mov sp, x1

bss_clear:
    ldr x1, =__bss_start
    ldr x2, =__bss_size
loop:
    cbz w2, kernel 
    str xzr, [x1], #8
    sub w2, w2, #1
    cbnz w2, loop

kernel:
    bl main

hang:
    b hang
