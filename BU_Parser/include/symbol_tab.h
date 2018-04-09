#ifndef SYMBOL_TAB_H
#define SYMBOL_TAB_H

struct symbol_tab_entry{
    uint type;
    size_t offset;
    size_t length;
    struct val value; /* Do no use pointer member as it will leak memory */
};

extern struct hash_table* symbol_table;
#define SYM_TAB_SIZE 512

extern struct hash_table* token_val_to_str_lookup;
#define VAL_TO_STR_LOOKUP_SIZE 512

#endif /* SYMBOL_TAB_H */

