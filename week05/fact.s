        .globl fact
        .func fact

fact:
        sub sp, sp, #8
        str lr, [sp]

        cmp r0, #0
        bne rec
        mov r0, #1
        b fact_end
rec:
        str r0, [sp, #4]
        sub r0, r0, #1
        bl fact
        ldr r1, [sp, #4]
        mul r0, r1, r0
fact_end:
        ldr lr, [sp]
        add sp, sp, #8
        bx lr
