#ifndef DS_HASH_TABLE_H
#define DS_HASH_TABLE_H

struct hash_table{
    struct linked_list** array; //Pointer to first bucket in array
    size_t collision_count;
    size_t size; /*number of items in table*/
    size_t array_size; /*size of array*/
    size_t max_chain_len;
};

/* What each entry will look like in the list*/
struct hash_entry{
    size_t hashed_key; /*String Hashed Value*/
    char* key_string;
    void* data;
};

#endif /* DS_HASH_TABLE_H */

