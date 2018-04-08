all: compiler prog

prog: *.c
	gcc -o dist/app $^ -I . -I include/ -lm -lfl -g

compiler: clean
	bison -d main.y && flex main.l
clean:
	rm -f dist/app
	rm -f main.tab.c
	rm -f main.tab.h
	rm -f lex.yy.c
	rm -f y.tab.c
	

