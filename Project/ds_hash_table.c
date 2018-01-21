#include "global.h"

//TODO Optimize for resize at n/2 and n/4

struct hash_table* create_hash_table(size_t size) {
    size_t i;
    struct hash_table* hash_tab = calloc(1, sizeof (struct hash_table));
    hash_tab->array = calloc(size, sizeof (struct linked_list*));
    hash_tab->array_size = size;
    struct linked_list** list = hash_tab->array;

    //Initialize hash table
    for (i = 0; i < size; i++) {
        *(list + i) = create_linked_list();
    }
    return hash_tab;
}

/**
 * Fixed size string hash - djb2
 * http://www.cse.yorku.ca/~oz/hash.html 
 * 
 * @param str null terminated string
 * @return fixed size hash value of string
 */
size_t string_hash(char* str) {
    size_t hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/**
 * Calculates which index in the hash table array to place item
 * 
 * @param str_hash value returned from calling string_hash
 * @param hash_tab_array_size - size of hash table array
 * @return index in hash table array to place item
 */
size_t key_index(size_t str_hash, size_t hash_tab_array_size) {
    static double C = 0.6180339887;
    double k_hash_calc;

    //Multiplicative Hash Function
    k_hash_calc = (double) hash_tab_array_size * (fmod((C * str_hash), 1.0));

    return (size_t) k_hash_calc;
}

/**
 * Insert Entry Into Hash Table
 * 
 * @param hash_tab - hash table
 * @param entry - entry to insert(key, data) pair
 * @return insert index
 */
size_t insert_entry(struct hash_table* hash_tab, struct hash_entry* entry) {
    size_t index;
    //Check if entry exists
    struct linked_list_node* node = get_hash_entry_node(hash_tab, entry->key_string);

    if (node == NULL) {
        union val value;
        value.pointer = entry;
        struct linked_list_node* node = create_linked_list_node(value);

        entry->hashed_key = string_hash(entry->key_string);
        index = key_index(entry->hashed_key, hash_tab->array_size);
        queue(hash_tab->array[index], node);
        hash_tab->entry_count++;

        //If chain length is bigger than max recorded update max
        if (hash_tab->max_chain_len < hash_tab->array[index]->count)
            hash_tab->max_chain_len = hash_tab->array[index]->count;
        
        //Check For Collision
        if(hash_tab->array[index]->count > 1)
            hash_tab->collision_count++;
        
    } else {
        free(node->value.pointer);
        node->value.pointer = entry;
    }

    return index;
}

/**
 * Get the linked list node of the entry matching the key
 * 
 * @param hash_tab hash table
 * @param key key to find
 * @return pointer to the linked list node of the entry or NULL if not found
 */
struct linked_list_node* get_hash_entry_node(struct hash_table* hash_tab, char* key) {
    size_t str_hash = string_hash(key);
    size_t index = key_index(str_hash, hash_tab->array_size);
    struct linked_list* list = hash_tab->array[index];

    //Traverse Linked List At Index
    struct linked_list_node* node = list->head->next;

    while (node != list->tail) {
        struct hash_entry* entry = (struct hash_entry*) node->value.pointer;
        if (entry->hashed_key == str_hash && strcmp(key, entry->key_string) == 0) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

/**
 * External Use
 * 
 * Get entry of hash table
 * 
 * @param hash_tab hash table
 * @param key key to look up
 * @return pointer to value (data of entry) 
 */
union val* get_value(struct hash_table* hash_tab, char* key) {
    struct linked_list_node* node = get_hash_entry_node(hash_tab, key);
    if (node == NULL)
        return NULL;
    else
        return &(((struct hash_entry*) node->value.pointer)->data);
}

/**
 * External Use
 * 
 * @param hash_tab hash table
 * @param key key
 * @param data data value to be inserted
 * @return index entry is inserted
 */
size_t insert_value(struct hash_table* hash_tab, char* key, union val data) {
    struct hash_entry* entry = calloc(1, sizeof (struct hash_entry));
    entry->data = data;
    entry->hashed_key = string_hash(key);
    entry->key_string = strdup(key);
    return insert_entry(hash_tab, entry);

}

/**
 * Print Hash Table
 * @param hash_tab hash table
 */
void print_hash_table(struct hash_table* hash_tab) {
    size_t i;
    struct linked_list** list = hash_tab->array;
    printf("Hash Entry Count = %03ld | Collision Count = %03ld | Max Chain Len = %03ld\n-------------------------\n", hash_tab->entry_count, hash_tab->collision_count, hash_tab->max_chain_len);

    //Initialize hash table
    for (i = 0; i < hash_tab->array_size; i++) {
        printf("Index: %3ld\n", i);

        print_list(*(list + i));
    }
}

/**
 * Free entry
 * 
 * @param entry pointer to entry to be freed
 */
void free_hash_entry(struct hash_entry* entry) {
    free(entry->key_string);
    free(entry);
}

/**
 * Free hash table
 */
void free_hash_table(struct hash_table* hash_tab) {
    size_t i;
    struct linked_list* list;
    struct linked_list_node* node;
    struct hash_entry* entry;


    for (i = 0; i < hash_tab->entry_count; i++) {
        list = hash_tab->array[i];

        //Free Entry Pointers
        node = list->head->next;
        while (node != list->tail) {
            entry = (struct hash_entry*) node->value.pointer;
            free_hash_entry(entry);
            node = node->next;
        }

        //Free Linked List at Index
        free_linked_list(list);
    }

    //Free List Pointer Array
    free(hash_tab->array);

    free(hash_tab);
}