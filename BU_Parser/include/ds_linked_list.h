#ifndef DS_LINKED_LIST
#define DS_LINKED_LIST

struct linked_list{
	struct linked_list_node* head;
	struct linked_list_node* tail;
	size_t count;
};



struct linked_list_node{
	struct linked_list_node* next;
	struct linked_list_node* prev;
	struct val value;
};


#endif
