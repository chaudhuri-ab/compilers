all:
	nasm -g -O0 -f elf32 -l test.lst  test.asm
	gcc -g -m32 -O0 -o test test.o
