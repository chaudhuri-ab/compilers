#include "global.h"

/**
 * Run all automated tests
 */
 
void run_tests(){
	
	linked_list_tests();

}


/**
 * Test the functionality of the linked list structure
 */
 
void linked_list_tests(){
	int max = 12;
	int index = 0;
	union val value;
	struct linked_list_node* node;

	//Linked List
	struct linked_list* list = create_linked_list();
	
	//Test 1 - Queue Values
	printf("\n\nTest 1\n");
	for(int i = 0; i < max; i++){
		value.integer = i;
		queue(list, create_linked_list_node(value));
	}
	
	//Walk List And Verify
	node = list->head->next;
	//node->value.integer = 100; Force Test To Fail
	index = 0;
	
	while(node != list->tail){
		if(node->value.integer != index)
			error(1, 1, "Linked List Failed Test 1");

		node = node->next;
		index++;
	}
	
	//Print List
	print_list(list);
	
	//Test 2 - Dequeue Values
	printf("\n\nTest 2\n");

	node = dequeue(list);
	//node->value.integer = 100; Force Test To Fail
	index = 0;
	
	while(node != NULL){
		if(node->value.integer != index)
			error(1, 1, "Linked List Failed Test 2a");

		node = dequeue(list);
		index++;
	}
	
	if(list->head->next != list->tail)
		error(1, 1, "Linked List Failed Test 2b");

	//Print List
	print_list(list);
	
	//Test 3 - Push Values
	printf("\n\nTest 3\n");
	for(int i = 0; i < max; i++){
		value.integer = i;
		push(list, create_linked_list_node(value));
	}
	
	//Walk List And Verify
	node = list->head->next;
	//node->value.integer = 100; Force Test To Fail
	index = max - 1;
	
	while(node != list->tail){
		if(node->value.integer != index)
			error(1, 1, "Linked List Failed Test 3");

		node = node->next;
		index--;
	}
	
	//Print List
	print_list(list);
	
	//Test 2 - Pop Values
	printf("\n\nTest 4\n");

	node = pop(list);
	//node->value.integer = 100; Force Test To Fail
	index = max - 1;
	
	while(node != NULL){
		if(node->value.integer != index)
			error(1, 1, "Linked List Failed Test 4a");

		node = dequeue(list);
		index--;
	}
	
	if(list->head->next != list->tail)
		error(1, 1, "Linked List Failed Test 4b");

	//Print List
	print_list(list);
}
