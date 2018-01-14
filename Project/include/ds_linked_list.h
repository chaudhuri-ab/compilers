#ifndef DS_LINKED_LIST
#define DS_LINKED_LIST

struct linked_list{
	struct linked_list_node* head;
	struct linked_list_node* tail;
	size_t count;
};

union val{
	char character;
	unsigned char u_character;
	int integer;
	unsigned int u_integer;
	long long_int;
	unsigned long u_long_int;
	float float_val;
	double double_val;
	char*	string;
	void* pointer;
};

struct linked_list_node{
	struct linked_list_node* next;
	struct linked_list_node* prev;
	union val value;
};


#endif
