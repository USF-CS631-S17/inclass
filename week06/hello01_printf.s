/* -- hello01.s */
.data
 
greeting:
 .asciz "Hello world\n"
 
.balign 4
return: .word 0
 
.text
 
.global main
main:
        sub sp, sp, #8
        str lr, [sp]              /*   *r1 ← lr */
 
        ldr r0, =greeting         /* r0 ← &address_of_greeting */
                                  /* First parameter of puts */
 
        bl printf                 /* Call to puts */
                                  /* lr ← address of next instruction */
 
        ldr lr, [sp]
        add sp, sp, #8

        bx lr                     /* return from main */
 
/* External */
.global printf
