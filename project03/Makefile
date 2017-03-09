all : armemu

add.o : add.s
	as -o add.o add.s

armemu : armemu.c add.o
	gcc -o armemu armemu.c add.o

clean:
	rm -rf armemu add.o

