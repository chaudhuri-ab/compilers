#include "global.h"
extern char scanner_input_buffer[SCANNER_INPUT_BUFFER];
extern size_t scanner_input_buffer_index;

void parse() {

#ifdef SCANNER_TEST
    scanner_test();
#endif

}

/**
 * Test the Scanner. Runs Scanner and quits program.
 */
void scanner_test() {
    int val;
    while ((val = next_token()) != EOF) {
        printf("\nToken Found - %d", val);
        if (val == ID || val == STRING_LITERAL || val == CONSTANT) {
            printf(" Val_ = %s%s%s", KGRN, (char*) token_value.pointer, KNRM);
            free(token_value.pointer);
            token_value.pointer = NULL;
        } else {
            scanner_input_buffer[scanner_input_buffer_index] = '\0';
            printf(" Val = %s%s%s", KGRN, (char*) scanner_input_buffer, KNRM);

        }
        printf("\n");

    }
}