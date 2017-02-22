PROGS = count_zeros_test
OBJS = count_zeros_a.o
CFLAGS = -g

all : ${PROGS}

count_zeros_a.o : count_zeros_a.s
	as -o count_zeros_a.o count_zeros_a.s

count_zeros_test : count_zeros_test.c count_zeros_a.o
	gcc -o count_zeros_test count_zeros_test.c count_zeros_a.o

clean:
	rm -rf ${PROGS} ${OBJS}
