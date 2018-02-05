

#include <stdio.h>
#include <stdlib.h>

int min_printable = 33; //!
int max_printable = 126; //~

int num_states = 10;

struct state {
    int next_state;
    void* transition_fcn;
    int token_value;
};


struct state state_machine[10][94];
/*
 * 
 */
int main(int argc, char** argv) {
    int i, j;
    printf("hello World%d\n\n", state_machine[0][0].next_state);

    printf("{\n");

    for (i = 0; i < num_states; i++) {
        if (i != 0)
            printf(",");
        printf("{ /* Index %d */\n", i);
        for (j = 0; j < max_printable - min_printable + 1; j++) {
            if (j != 0)
                printf(",\n");

            printf(" {/* %c */%d, NULL, 0}", min_printable + j, 0);
            
        }
        printf("}\n\n");

    }

    printf("}\n");

    return (EXIT_SUCCESS);
}

