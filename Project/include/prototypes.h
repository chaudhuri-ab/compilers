#ifndef prototypes
#define prototypes


/* ds_hash_table */
struct hash_table* create_hash_table(size_t size);
size_t string_hash(char* str);
size_t key_index(size_t str_hash, size_t hash_tab_array_size);
size_t insert_entry(struct hash_table* hash_tab, struct hash_entry* entry);
struct linked_list_node* get_hash_entry_node(struct hash_table* hash_tab, char* key);
union val get_value(struct hash_table* hash_tab, char* key, bool* is_found);
size_t insert_value(struct hash_table* hash_tab, char* key, union val data);
void print_hash_table(struct hash_table* hash_tab);
void free_hash_table(struct hash_table* hash_tab);
void free_hash_entry(struct hash_entry* entry);

/* ds_linked_list.c */
struct linked_list_node* create_linked_list_node(union val value);
struct linked_list* create_linked_list();
void queue(struct linked_list* list, struct linked_list_node* node);
struct linked_list_node* dequeue(struct linked_list* list);
void push (struct linked_list* list, struct linked_list_node* node);
struct linked_list_node* pop(struct linked_list* list);
void print_list(struct linked_list* list);
void free_linked_list(struct linked_list* list);

/* main.c */
void init(int args, char* argc[]);

/* parser.c */
void parse();


/* scanner.c */
int next_token();

/* symbol_tab.c */
void print_symbol_table(struct hash_table* symbol_table);
void print_symbol_tab_list (struct linked_list* list);
void free_symbol_table(struct hash_table* symbol_table);
void free_symbol_tab_list(struct linked_list* list);
void symbol_table_init();


/*test.c*/
void run_tests();
void linked_list_tests();
void hash_table_tests();

#endif
