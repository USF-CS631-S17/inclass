.global testimm
.func testimm

testimm:
        push {r4, r5}
	//mov r0, #1023 bad
	//mov r0, #4095 bad
	mov r0, #1536 // 1024 + 512 good
	mov r0, #1024
	sub r1, r0, #1
        pop {r4, r5}
	bx lr

