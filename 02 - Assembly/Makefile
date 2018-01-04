all:
	nasm -O0 -f elf32 -l test.lst  test.asm
	gcc -m32 -O0 -o test test.o
