.global count_zeros_a
.func count_zeros_a

count_zeros_a:
        mov r2, #0 /* i */
        mov r3, #0 /* count */
loop:
        cmp r2, r1
        beq done
        /* ldr r4, [r0] */
        ldr r4, [r0, r2, LSL #2] /* a + (i * 4) */
        cmp r4, #0
        addeq r3, r3, #1
        /* add r0, r0, #4 */
        add r2, r2, #1
        b loop
done:
        mov r0, r3
        bx lr
