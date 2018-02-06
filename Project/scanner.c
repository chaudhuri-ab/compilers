#include "global.h"

FILE* curr_fp;
int token_const;
struct val token_value; /* Used By Parser To Get Token Value */
int scanner_current_state;
bool token_found_flag;
bool beginning_of_token_found;
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
    reset_scanner();

    struct state next_state;
    void (*fcn_ptr)(int);
    void (*fcn_ptr2)();
    int c;

    if (token_value.pointer != NULL) {
        //free(token_value.pointer);
    }

    while ((c = getc(curr_fp)) != EOF && !token_found_flag) {
        if (beginning_of_token_found && (c == '\n' || c == ' ' || c == '\t')) {

            break; //end of token

        } else if (!beginning_of_token_found && (c == '\n' || c == ' ' || c == '\t')) {
            continue; //consume input
        } else {
            beginning_of_token_found = true;
        }

        scanner_input_buffer[scanner_input_buffer_index++] = c;


        next_state = scanner_state_machine[scanner_current_state][c - '!'];
        scanner_current_state = next_state.next_state; //Transition to next state

#ifdef VERBOSE_SCANNER
        printf("%s%c%s", KCYN, c, KNRM);
#endif


        //Call Transition Function if not null
        if (next_state.transition_fcn != NULL && next_state.token_val != 0) {
#ifdef VERBOSE_SCANNER
            //printf(" %sChar = %c%s ", KRED, c, KNRM);
#endif
            fcn_ptr = next_state.transition_fcn;
            (*fcn_ptr) (next_state.token_val);

        } else if (next_state.transition_fcn != NULL && next_state.token_val == 0) {
#ifdef VERBOSE_SCANNER
            //printf(" %sChar = %c%s ", KRED, c, KNRM);
#endif
            fcn_ptr2 = next_state.transition_fcn;
            (*fcn_ptr2) ();
        }

        //  

        if (token_found_flag)
            break;

    }



    if (c == EOF || token_const == EOF)
        return EOF;
    else if (token_const == BAD_TOKEN) {
#ifndef SCANNER_PROCESS_BAD_TOKEN
        scanner_error();
#endif
        return BAD_TOKEN;
    } else if (token_const == ID) {
        scanner_input_buffer[scanner_input_buffer_index] = '\0';
        //Tokenized an ID. Check if keyword
        bool isfound = false;
        struct val value = get_value(symbol_table, scanner_input_buffer, &isfound);
        //printf("Searching For - %s, Found = %d\n", scanner_input_buffer, isfound);
        if (isfound) {
            struct symbol_tab_entry* sym_tab_entry = (struct symbol_tab_entry*) value.pointer;
            token_const = sym_tab_entry->value.integer;
        } else {
            token_value.pointer = strdup(scanner_input_buffer);
        }
        return token_const;
    } else
        return token_const;
}

/**
 * Called during transition if a token is found and the value of the char is directly returned as the token val
 */
void token_found_direct_return() {
    token_found_flag = true;
    token_const = scanner_input_buffer[scanner_input_buffer_index - 1];
}

/**
 * Called during transition if a id is found
 */
void id_found_return() {
    ungetc(scanner_input_buffer[scanner_input_buffer_index - 1], curr_fp);
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index - 1] = '\0';
}

/**
 * Called to collect characters of an ID
 * @param num Not Used
 */
void collect_id() {
    //printf("\nCollect\n");
    token_const = ID;
}

/**
 * Called to collect characters of an inline comment
 */
void collect_inline_comment() {
    int c;
    while ((c = getc(curr_fp)) != EOF && c != '\n') {
        //consume comments
#ifdef VERBOSE_SCANNER
        printf(" %sChar = %c%s\n ", KGRN, c, KNRM);
#endif
    }
    if (c == EOF) {
        token_const = EOF;
    } else {
        reset_scanner();
    }
}

void collect_multiline_comment() {
    int c;
    while ((c = getc(curr_fp)) != EOF) {
        if (c == '*') {
            if (peek() == '/') {
                getc(curr_fp); //consume char
                break;
            }
        }
#ifdef VERBOSE_SCANNER
        printf(" %sChar = %c%s\n ", KRED, c, KNRM);
#endif
    }
    if (c == EOF) {
        token_const = EOF;
    } else {
        reset_scanner();
    }
}

/**
 * Error tokenizing. Print invalid token and stop compiler.
 */
void scanner_error() {
    scanner_input_buffer[scanner_input_buffer_index] = '\0';
    error(1, 5, "Scanner - Invalid Token - %s \n", scanner_input_buffer);

}

/**
 * Peek at next char in stream
 * @return char or EOF
 */
int peek() {
    int c;
    c = getc(curr_fp);
    ungetc(c, curr_fp);
    return c;
}

/**
 * Reset the scanner
 */
void reset_scanner() {
    scanner_current_state = 0; //Init to FSM to S0
    token_found_flag = false;
    scanner_input_buffer_index = 0;
    token_const = BAD_TOKEN;
    beginning_of_token_found = false;
}