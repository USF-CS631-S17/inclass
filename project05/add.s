.func main

main:
        mov r0, #1
        mov r1, #2
        bl add
end:
        b end
.endfunc
       
.func add
add:
	add r0, r0, r1
	bx lr      
.endfunc
