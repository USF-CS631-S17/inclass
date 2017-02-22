.global max
.func max
 
max:
        cmp r0, r1
        bgt done
        mov r0, r1
done:   
	bx lr      
