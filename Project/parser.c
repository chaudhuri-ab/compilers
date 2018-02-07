#include "global.h"

void parse() {
    int val;
    while ((val = next_token()) != EOF) {
        printf(" Token Found - %d", val);
        if (val == ID || val == STRING_LITERAL || val == CONSTANT) {
            printf(" Val = %s", (char*) token_value.pointer);
            free(token_value.pointer);
            token_value.pointer = NULL;
        } 
        printf("\n");

    }
}