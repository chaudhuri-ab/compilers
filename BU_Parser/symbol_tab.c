#include "global.h"

struct hash_table* symbol_table;
struct hash_table* token_val_to_str_lookup; /* Look up table to get string from token value */



/**
 * Initialize Symbol Table
 */
void symbol_table_init() {
    int i;
    int keyword_start_const = 300;
    struct val value;
    struct symbol_tab_entry* sym_tab_ent, sym_tab_ent2;
    char* str;

    symbol_table = create_hash_table(SYM_TAB_SIZE);
    token_val_to_str_lookup = create_hash_table(VAL_TO_STR_LOOKUP_SIZE);


}

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
        if ((*(ptr_list + i))->count == 0)
            continue; //don't print blanks

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

        printf(" %s: type = %d, offset = %ld, length = %ld, value = %ld | %s %s<=>%s", hash_entry->key_string, symbol_entry->type, symbol_entry->offset, symbol_entry->length, symbol_entry->value.long_int, symbol_entry->value.static_string, KRED, KNRM);
        node = node->next;

    }

    printf(" Tail\n");
    printf("List Count -> %d\n\n", (int) list->count);


}

/**
 * Free Symbol Table
 * 
 * @param symbol_table pointer to symbol table
 */
void free_symbol_table(struct hash_table* symbol_table) {

    size_t i;
    struct linked_list** ptr_list = symbol_table->array;

    //Free symbol table
    for (i = 0; i < symbol_table->array_size; i++) {
        free_symbol_tab_list(*(ptr_list + i));
    }
    free_hash_table(symbol_table);

}

/**
 * Frees chain of symbol table
 * 
 * @param list list of nodes in hash table index
 */
void free_symbol_tab_list(struct linked_list* list) {
    struct linked_list_node* node = list->head->next;
    struct hash_entry* hash_entry;
    struct symbol_tab_entry* symbol_entry;

    while (node != list->tail) {
        hash_entry = (struct hash_entry*) node->value.pointer;
        symbol_entry = hash_entry->data.pointer;

        if (symbol_entry->value.pointer != NULL) {
            free(symbol_entry->value.pointer);
            symbol_entry->value.pointer = NULL;
        }

        free(symbol_entry);
        hash_entry->data.pointer = NULL;

        node = node->next;
    }

}