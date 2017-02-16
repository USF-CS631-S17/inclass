/* -- ifelse.s */
.global main
.func main

/* C code
x = 99;
y = 99;

if (x == y) {
	x = x + 1;
} else {
	y = y + 2;
}

*/
	
main:
	mov r0, #99
	mov r1, #99

	cmp r0, r1
	bne else
	add r0, r0, #1
	b endif
else:	
	add r1, r1, #2
endif:
	bx lr      /* Return from main */
