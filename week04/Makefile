PROGS = first_c first_a add_test
OBJS = first_a.o add.o max.o
CFLAGS = -g

all : ${PROGS}

first_a : first_a.s
	as -o first_a.o first_a.s
	gcc -o first_a first_a.o

add.o : add.s
	as -o add.o add.s

max.o : max.s
	as -o max.o max.s

add_test : add_test.c add.o max.o
	gcc -o add_test add_test.c add.o max.o


clean :
	rm -rf ${PROGS} ${OBJS}
