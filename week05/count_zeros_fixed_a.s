.global count_zeros_fixed_a
.func count_zeros_fixed_a

count_zeros_fixed_a:
        sub sp, sp, #8
        str r4, [sp]
        
        mov r2, #0
        mov r3, #0
loop:
        cmp r2, r1
        beq done
        ldr r4, [r0]
        cmp r4, #0
        addeq r3, r3, #1
        add r0, r0, #4
        add r2, r2, #1
        b loop
done:
        mov r0, r3

        ldr r4, [sp]
        add sp, sp, #8
        bx lr
