#include "global.h"

struct hash_table* symbol_table;

/**
 * Initialize Symbol Table
 */
void symbol_table_init() {
    int i;
    int key_word_start_const = 300;
    union val value;
    struct symbol_tab_entry* sym_tab_ent;

    symbol_table = create_hash_table(SYM_TAB_SIZE);

    //Insert Keywords
    for (i = 0; i < KEYWORD_COUNT; i++) {

        sym_tab_ent = calloc(1, sizeof (struct symbol_tab_entry));
        sym_tab_ent->type = key_word_start_const + i;

        value.pointer = sym_tab_ent;
        insert_value(symbol_table, keywords[i], value);

    }
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

/**
 * Free Symbol Table
 * 
 * @param symbol_table pointer to symbol table
 */
void free_symbol_table(struct hash_table* symbol_table) {

    size_t i;
    struct linked_list** ptr_list = symbol_table->array;
    printf("Hash Entry Count = %03ld | Collision Count = %03ld | Max Chain Len = %03ld\n-------------------------\n", symbol_table->entry_count, symbol_table->collision_count, symbol_table->max_chain_len);

    //Initialize hash table
    for (i = 0; i < symbol_table->array_size; i++) {
        printf("Index: %3ld\n", i);
        free_symbol_tab_list(*(ptr_list + i));
    }
    free_hash_table(symbol_table);

}

/**
 * Frees chain of hash table
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

        free(symbol_entry);

        node = node->next;
    }

}