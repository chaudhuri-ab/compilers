#include "global.h"



/**
 * Print Symbol Table
 * @param hash_tab hash table
 */
void print_symbol_table(struct hash_table* symbol_table) {
    size_t i;
    struct linked_list** ptr_list = symbol_table->array;
    printf("Hash Entry Count = %03ld | Collision Count = %03ld | Max Chain Len = %03ld\n-------------------------\n", symbol_table->entry_count, symbol_table->collision_count, symbol_table->max_chain_len);

    //Initialize hash table
    for (i = 0; i < symbol_table->array_size; i++) {
        printf("Index: %3ld\n", i);
        print_symbol_tab_list(*(ptr_list + i));
    }
}

/**
 * Print Symbol List
 * 
 * list - pointer to linked list in symbol table
 */

void print_symbol_tab_list(struct linked_list* list) {
    struct linked_list_node* node = list->head->next;
    struct hash_entry* hash_entry;
    struct symbol_tab_entry* symbol_entry;
    
    printf("Head %s<=>%s", KRED, KNRM);
    while (node != list->tail) {
        hash_entry = (struct hash_entry*) node->value.pointer;
        symbol_entry = hash_entry->data.pointer;
        
        printf(" %s: type = %d, offset = %ld, length = %ld %s<=>%s", hash_entry->key_string, symbol_entry->type, symbol_entry->offset, symbol_entry->length, KRED, KNRM);
        node = node->next;

    }

    printf(" Tail\n");
    printf("List Count -> %d\n\n", (int) list->count);


}


