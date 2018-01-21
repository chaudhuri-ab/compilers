#ifndef SYMBOL_TAB_H
#define SYMBOL_TAB_H

struct symbol_entry{
    char* name;
    uint type;
    size_t offset;
    size_t length;    
};


#endif /* SYMBOL_TAB_H */

