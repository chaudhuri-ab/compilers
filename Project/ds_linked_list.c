#include "global.h"

/**
 * Create a doubly linked list node
 * 
 * Returns a pointer to struct linked_list_node*
 */
 
struct linked_list_node* create_linked_list_node(union val value){
	struct linked_list_node* node = (struct linked_list_node*) calloc(1, sizeof(struct linked_list_node));
	
	if(node == NULL){
		error(1, 12, "Creating Linked List Node Failed");
	}
	
	node->value = value;
	return node;
}



/**
 * Free a doubly linked list node
 */
 
void free_linked_list_node(struct linked_list_node* node){
	union val value = node->value;
	//free node
	free(node);	
}



/**
 * Create a doubly linked list 
 * 
 * Returns a pointer to struct linked_list*
 */
 
struct linked_list* create_linked_list(){
	struct linked_list* list = (struct linked_list*) malloc(sizeof(struct linked_list));
	union val default_value;
	default_value.integer = -1;
	list->head = create_linked_list_node(default_value);
	list->tail = create_linked_list_node(default_value);
	
	//Raise Error if No Memory Allocated
	if(list == NULL){
		error(1, 12, "Creating Linked List Failed");
	}
	
	list->head->prev = NULL;
	list->head->next = list->tail;
	
	list->tail->prev = list->head;
	list->tail->next = NULL;
	
	list->count = 0;
	
	return list;
}



/**
 * Queue node at the tail of the doubly linked list
 * 
 * list - pointer to linked list
 * node - pointer to node
 */
 
void queue(struct linked_list* list, struct linked_list_node* node){
	struct linked_list_node* old_last_node = list->tail->prev;
	
	list->tail->prev = node;
	
	node->prev = old_last_node;
	node->next = list->tail;
	
	old_last_node->next = node;
	
	list->count++;
}


/**
 * Dequeue node at head of list
 * 
 * list - pointer to linked list
 * node - pointer to node
 * 
 * Returns node or NULL if list is empty
 */
 
struct linked_list_node* dequeue(struct linked_list* list){
	
	if(list->head->next == list->tail)
		return NULL;
	
	struct linked_list_node* old_first_node = list->head->next;
	
	list->head->next = old_first_node->next;
	old_first_node->next->prev = list->head;
	
	list->count--;
	
	return old_first_node;
	
}



/**
 * Push a node onto the head of the list
 * 
 * list - pointer to linked list
 * node - pointer to node
 */ 

void push(struct linked_list* list, struct linked_list_node* node){
	struct linked_list_node* old_first_node = list->head->next;
	
	list->head->next = node;
	
	node->prev = list->head;
	node->next = old_first_node;
	
	old_first_node->prev = node;

	list->count++;
		
}



/**
 * Pop node at head of list
 * 
 * list - pointer to linked list
 * node - pointer to node
 * 
 * Returns node or NULL if list is empty
 */
 
struct linked_list_node* pop(struct linked_list* list){

		return dequeue(list);
}


/**
 * Print list
 * 
 * list - pointer to linked list
 */
 
void print_list(struct linked_list* list){
	struct linked_list_node* node = list->head->next;
	
	printf("Head <=> ");
	
	while(node != list->tail){
		
		printf("%d <=> ", node->value.integer);
		node = node->next;
			
	}
	
	printf("Tail\n");
	printf("List Count -> %d\n\n", (int)list->count);

	
}


/**
 * Free a doubly linked list node
 * 
 */
 
void free_linked_list(struct linked_list* list){
	struct linked_list_node* old_node = NULL;
	struct linked_list_node* node = list->head->next;
	
	while(node != list->tail){
		struct linked_list_node* next_node = node->next;
		
		free_linked_list_node(node);
		
		node = next_node;	
	}
	
	free_linked_list_node(list->head);
	free_linked_list_node(list->tail);
	free(list);
}


