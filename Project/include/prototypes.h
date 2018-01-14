#ifndef prototypes
#define prototypes

/* ds_linked_list.c */
struct linked_list_node* create_linked_list_node(union val value);
struct linked_list* create_linked_list();
void queue(struct linked_list* list, struct linked_list_node* node);
struct linked_list_node* dequeue(struct linked_list* list);
void push (struct linked_list* list, struct linked_list_node* node);
struct linked_list_node* pop(struct linked_list* list);
void print_list(struct linked_list* list);
void free_linked_list(struct linked_list* list);

/*test.c*/
void run_tests();
void linked_list_tests();

#endif
