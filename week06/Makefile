ASM_PROGS = toupper_memory hello01 hello01_args hello01_printf store01 store01_gnu toupper

%.o : %.s
	$(AS) -o $@ $<

all: $(ASM_PROGS)

toupper_memory: toupper_memory.o
	$(CC) -o $@ $<

hello01: hello01.o
	$(CC) -o $@ $<

hello01_args: hello01_args.o
	$(CC) -o $@ $<

hello01_printf: hello01_printf.o
	$(CC) -o $@ $<

store01: store01.o
	$(CC) -o $@ $<

store01_gnu: store01_gnu.o
	$(CC) -o $@ $<

toupper: toupper.o
	$(CC) -o $@ $<

clean:
	rm -rf $(ASM_PROGS) *.o
