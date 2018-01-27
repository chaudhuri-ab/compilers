#include "global.h"

FILE* curr_fp;
struct val token_value; /* Used By Parser To Get Token Value */
int scanner_current_state; 


//Keep in sych with token constant values in scanner.h to ensure accuracy of initialization
struct token keywords[KEYWORD_COUNT] = {{"auto", AUTO}, {"double", DOUBLE} , {"int", INT}, {"struct", STRUCT}, {"const", CONST}, {"float", FLOAT}, {"short", SHORT},
{"unsigned", UNSIGNED}, {"break", BREAK}, {"else", ELSE}, {"long", LONG}, {"switch", SWITCH}, {"continue", CONTINUE}, {"for", FOR}, {"signed", SIGNED}, {"void", VOID},
{"case", CASE}, {"enum", ENUM}, {"register", REGISTER}, {"typedef", TYPEDEF}, {"default", DEFAULT}, {"goto", GOTO}, {"sizeof", SIZEOF}, {"volatile", VOLATILE}, {"char", CHAR}, {"extern", EXTERN}, {"return", RETURN}, {"union", UNION}, {"do", DO}, {"if", IF}, {"static", STATIC}, {"while", WHILE}};



int next_token(){
    int c;
    while( (c = getc(curr_fp)) != EOF){
        printf("%s%c%s", KCYN, c, KNRM);
    }
    
    
    return END_OF_FILE;
}
