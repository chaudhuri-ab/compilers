#include "global.h"


/**
 * Create a doubly linked list 
 * 
 * Returns a pointer to struct linked_list*
 */
 
struct linked_list* create_linked_list(){
	struct linked_list* list = (struct linked_list*) malloc(sizeof(struct linked_list));
	
	list->head = (struct linked_list_node*) malloc(sizeof(struct linked_list_node));
	list->tail = (struct linked_list_node*) malloc(sizeof(struct linked_list_node));
	
	//Raise Error if No Memory Allocated
	if(list == NULL || list->head == NULL || list->tail == NULL){
		error(1, 12, "Create Linked List");
	}
	
	list->head->prev = NULL;
	list->head->next = list->tail;
	
	list->tail->prev = list->head;
	list->tail->next = NULL;
	
	return list;
}
