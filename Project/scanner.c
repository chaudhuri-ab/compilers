#include "global.h"

FILE* curr_fp;


//Keep in sych with token constant values in scanner.h to ensure accuracy of initialization
char* keywords[] = {"auto", "double", "int", "struct", "const", "float", "short",
    "unsigned", "break", "else", "long", "switch", "continue", "for", "signed", "void",
    "case", "enum", "register", "typedef", "default", "goto", "sizeof", "volatile", "char",
    "extern", "return", "union", "do", "if", "static", "while"};



int next_token(){
    int c;
    while( (c = getc(curr_fp)) != EOF){
        printf("%c", c);
    }
    
    return EOF;
}
