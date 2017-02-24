PROGS = count_zeros_test fact_test
OBJS = count_zeros_a.o count_zeros_index_a.o count_zeros_fixed_a.o fact.o
CFLAGS = -g

all : ${PROGS}

count_zeros_a.o : count_zeros_a.s
	as -o count_zeros_a.o count_zeros_a.s

count_zeros_index_a.o : count_zeros_index_a.s
	as -o count_zeros_index_a.o count_zeros_index_a.s

count_zeros_fixed_a.o : count_zeros_fixed_a.s
	as -o count_zeros_fixed_a.o count_zeros_fixed_a.s

count_zeros_test : count_zeros_test.c count_zeros_a.o count_zeros_index_a.o count_zeros_fixed_a.o
	gcc -o count_zeros_test count_zeros_test.c count_zeros_a.o count_zeros_index_a.o count_zeros_fixed_a.o

fact.o: fact.s
	as -o fact.o fact.s

fact_test: fact_test.c fact.o
	gcc -o fact_test fact_test.c fact.o

clean:
	rm -rf ${PROGS} ${OBJS}
