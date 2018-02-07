#include "global.h"

int main(int args, char* argc[]) {
    //run_tests();
    init(args, argc);

    parse();

}

void init(int args, char* argc[]) {
    if (args < 2) {
        error(1, 1, "Missing File Name(s)\n");
    }

    //TODO later create queue of files to open/compile
    curr_fp = fopen(argc[1], "rw");
    if (curr_fp == NULL) {
        error(1, 5, "Error Opening File:\n");

    }


    symbol_table_init();
    
    scanner_current_state = 0;
    token_value.pointer = NULL;
}