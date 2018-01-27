#ifndef SYMBOL_TAB_H
#define SYMBOL_TAB_H

struct symbol_tab_entry{
    uint type;
    size_t offset;
    size_t length;    
};

extern struct hash_table* symbol_table;
#define SYM_TAB_SIZE 512

#endif /* SYMBOL_TAB_H */

