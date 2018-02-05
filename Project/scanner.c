#include "global.h"

FILE* curr_fp;
int token_const;
struct val token_value; /* Used By Parser To Get Token Value */
int scanner_current_state;
int token_found_flag;
char scanner_input_buffer[SCANNER_INPUT_BUFFER];
size_t scanner_input_buffer_index;


//Keep in sych with token constant values in scanner.h to ensure accuracy of initialization
struct token keywords[KEYWORD_COUNT] = {
    {"auto", AUTO},
    {"double", DOUBLE},
    {"int", INT},
    {"struct", STRUCT},
    {"const", CONST},
    {"float", FLOAT},
    {"short", SHORT},
    {"unsigned", UNSIGNED},
    {"break", BREAK},
    {"else", ELSE},
    {"long", LONG},
    {"switch", SWITCH},
    {"continue", CONTINUE},
    {"for", FOR},
    {"signed", SIGNED},
    {"void", VOID},
    {"case", CASE},
    {"enum", ENUM},
    {"register", REGISTER},
    {"typedef", TYPEDEF},
    {"default", DEFAULT},
    {"goto", GOTO},
    {"sizeof", SIZEOF},
    {"volatile", VOLATILE},
    {"char", CHAR},
    {"extern", EXTERN},
    {"return", RETURN},
    {"union", UNION},
    {"do", DO},
    {"if", IF},
    {"static", STATIC},
    {"while", WHILE}
};

int next_token() {
    scanner_current_state = 0; //Init to FSM to S0
    token_found_flag = false;
    scanner_input_buffer_index = 0;
    token_const = BAD_TOKEN;
    struct state next_state;

    int c;

    //Consume space characters
    while ((c = getc(curr_fp)) != EOF) {
#ifdef VERBOSE_SCANNER
        printf("%s%c%s", KCYN, c, KNRM);
#endif

        if (c == '\n' || c == ' ' || c == '\t')
            continue; //end of token
        else
            break;
    }

    while ((c = getc(curr_fp)) != EOF && !token_found_flag) {
        if (c == '\n' || c == ' ' || c == '\t')
            break; //end of token

        scanner_input_buffer[scanner_input_buffer_index] = c;
        scanner_input_buffer_index++;

        next_state = scanner_state_machine[scanner_current_state][c - '!'];
        scanner_current_state = next_state.next_state; //Transition to next state
        //Call Transition Function if not null
        //        if(next_state.transition_fcn != NULL){
        //            next_state.transition_fcn(next_state.);
        //        }
        //  
#ifdef VERBOSE_SCANNER
        printf("%s%c%s", KCYN, c, KNRM);
#endif
    }

    if (c == EOF)
        return EOF;
    else if (token_const == BAD_TOKEN) {
#ifndef SCANNER_PROCESS_BAD_TOKEN
        scanner_error();
#endif
        return BAD_TOKEN;
    } else
        return token_const;
}

/**
 * Called during transition if a token is found
 */
void token_found_direct_return() {
    token_found_flag = true;
    token_const = scanner_input_buffer[0];
}

/**
 * Called during transition if a token is found
 */
void token_found_return(int token_val) {

}

/**
 * Error tokenizing. Print invalid token and stop compiler.
 */
void scanner_error() {
    scanner_input_buffer[scanner_input_buffer_index] = '\0';
    error(1, 5, "Scanner - Invalid Token - %s \n", scanner_input_buffer);

}