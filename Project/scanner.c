#include "global.h"

FILE* curr_fp;
int token_const;
struct val token_value; /* Used By Parser To Get Token Value */
int scanner_current_state;
bool token_found_flag;
bool beginning_of_token_found;
char scanner_input_buffer[SCANNER_INPUT_BUFFER];
size_t scanner_input_buffer_index;


/**
 * Get next token
 * @return return int of token found
 */
int next_token() {
    reset_scanner();
    struct state next_state;
    void (*fcn_ptr)(int);
    void (*fcn_ptr2)();
    int c;

    if (token_value.pointer != NULL) {
        free(token_value.pointer);
    }

    while ((c = getc(curr_fp)) != EOF && !token_found_flag) {
        if (token_const != STRING_LITERAL && beginning_of_token_found && (c == '\n' || c == ' ' || c == '\t')) {
#ifdef VERBOSE_SCANNER
            //printf("| State = %d |", scanner_current_state);
            printf("%s%c%s", KCYN, c, KNRM);
#endif
            scanner_input_buffer[scanner_input_buffer_index++] = '\0';
            break; //end of token

        } else if (token_const != STRING_LITERAL && (!beginning_of_token_found && (c == '\n' || c == ' ' || c == '\t'))) {
#ifdef VERBOSE_SCANNER
            //printf("| State = %d |", scanner_current_state);
            printf("%s%c%s", KCYN, c, KNRM);
#endif
            continue; //consume input
        } else if ((token_const == STRING_LITERAL) && (c == '\n' || c == ' ' || c == '\t')) {
#ifdef VERBOSE_SCANNER
            //printf("| State = %d |", scanner_current_state);
            printf("%s%c%s", KCYN, c, KNRM);
#endif
            scanner_input_buffer[scanner_input_buffer_index++] = c;
            continue;
        } else {
            beginning_of_token_found = true;
        }

        scanner_input_buffer[scanner_input_buffer_index++] = c;


        next_state = scanner_state_machine[scanner_current_state][c - '!'];
        scanner_current_state = next_state.next_state; //Transition to next state

#ifdef VERBOSE_SCANNER
        //printf("| State = %d |", scanner_current_state);
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


    //Return Token
    if (c == EOF || token_const == EOF) {
        return EOF;
    } else if (token_const == BAD_TOKEN) {
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

    } else if (token_const == PREPROCESSOR_FLAG) {
        bool isfound = false;
        struct val value = get_value(symbol_table, scanner_input_buffer, &isfound);
        //printf("Searching For - %s, Found = %d\n", scanner_input_buffer, isfound);
        if (isfound) {
            struct symbol_tab_entry* sym_tab_entry = (struct symbol_tab_entry*) value.pointer;
            token_const = sym_tab_entry->value.integer;
        } else {
            scanner_error();
        }
        return token_const;
    } else if (token_const == STRING_LITERAL) {
        token_value.pointer = strdup(scanner_input_buffer);
        return token_const;

    } else if (token_const == CONSTANT) {
        token_value.pointer = strdup(scanner_input_buffer);
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
    scanner_input_buffer_index--;
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index] = '\0';
}

/**
 * Called during transition if a string literal ("string") is found
 */
void string_lit_found_return() {
    //ungetc(scanner_input_buffer[scanner_input_buffer_index - 1], curr_fp);
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index - 1] = '\0';
}

/**
 * Called during transition if constant is found.
 */
void constant_found_return() {
    ungetc(scanner_input_buffer[scanner_input_buffer_index - 1], curr_fp);
    scanner_input_buffer_index--;
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index] = '\0';
}

/**
 * Token Found Push Back Last Char and Return Token
 */
void token_found_unget_return(int token_val) {
    token_const = token_val;
    ungetc(scanner_input_buffer[scanner_input_buffer_index - 1], curr_fp);
    scanner_input_buffer_index--;
    token_found_flag = true;
}

/**
 * Token Found Push Back Last Char and Return Token
 */
void token_found_direct_return_w_val(int token_val) {
    token_const = token_val;
    token_found_flag = true;
}


void token_found_char_constant(int token_type){
    token_const = token_type;
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index - 1] = '\0';
}


void token_found_escaped_char_constant(char c){
    token_const = CONSTANT;
    token_found_flag = true;
    scanner_input_buffer[scanner_input_buffer_index - 2] = c;
    scanner_input_buffer[scanner_input_buffer_index - 1] = '\0';
}

/**
 * Called to collect characters of an ID
 */
void collect_id() {
    //printf("\nCollect\n");
    token_const = ID;
}

/**
 * Collecting potential preprocessor token
 */
void collect_preprocessor() {
    token_const = PREPROCESSOR_FLAG;
}

/**
 * Collecting string literal characters
 */
void collect_string_lit() {
    token_const = STRING_LITERAL;
    scanner_input_buffer_index--; //ignore the "
}

/**
 * Collecting char literal characters
 */
void collect_char_lit() {
    token_const = CONSTANT;
    scanner_input_buffer_index--; //ignore the '
}

/**
 * Collecting Constant
 */
void collect_constant() {
    token_const = CONSTANT;
}

/**
 * Collecting a token that has repeating characters
 * @param token constant of smaller token to be used if larger token is not found (e.g. + when trying to find += or ++)
 */
void collect_token(int token) {
    token_const = token;
}

/**
 * Called to collect characters of an inline comment
 */
void collect_inline_comment() {
    int c;
    while ((c = getc(curr_fp)) != EOF && c != '\n') {
        //consume comments
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
 * Called to collect characters of a multiline comment
 */
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
        printf(" %sChar = %c%s\n ", KYEL, c, KNRM);
#endif
    }
    if (c == EOF) {
        token_const = EOF;
    } else {
        reset_scanner();
    }
}


void string_escape_char(char c){
    scanner_input_buffer_index = scanner_input_buffer_index - 2;
    scanner_input_buffer[scanner_input_buffer_index++] = c;
    
}

/**
 * Error tokenizing. Print invalid token and stop compiler.
 */
void scanner_error() {
    scanner_input_buffer[scanner_input_buffer_index] = '\0';
    error(1, 5, "Scanner (State %d) - Invalid Token - %s \n", scanner_current_state, scanner_input_buffer);

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