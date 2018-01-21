#https://www.gnu.org/software/make/manual/make.html#toc-An-Introduction-to-Makefiles

TOPDIR		=	.

test: test.o test.asm
	@echo "\nLinking"
	gcc -g -m32 -O0 -o $@ test.o
	@echo "\n\nDone"
	@ls -lh

test.o: test.asm
	@echo "\nAssembling"
	nasm -g -O0 -f elf32 -l test.lst  test.asm
	

clean:
	rm -rf test
	rm -rf test.o
	rm -rf test.lst