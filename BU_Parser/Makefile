all: compiler prog

prog: *.c
	gcc -o dist/app $^ -lm -lfl -g -I . -I include/ 

compiler: clean
	bison -d -v main.y && flex main.l
clean:
	rm -f dist/app
	rm -f main.tab.c
	rm -f main.tab.h
	rm -f lex.yy.c
	rm -f y.tab.c
	

