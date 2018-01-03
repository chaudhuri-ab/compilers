all:
	rm -f a.out
	bison -d fb1-5.y
	flex fb1-5.l
	gcc lex.yy.c fb1-5.tab.c -lfl


