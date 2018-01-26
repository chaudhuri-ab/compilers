#include "global.h"
#include "symbol_tab.h"

/**
 * Run all automated tests
 */

void run_tests() {

    linked_list_tests();
    hash_table_tests();

}

void hash_table_tests() {
    struct symbol_tab_entry* sym_entry;
    union val value;

    printf("\n\nHT Test 1\n");


    struct hash_table* hash_tab = create_hash_table(10);

    sym_entry = calloc(1, sizeof (sym_entry));
    sym_entry->offset = 1001;

    value.pointer = (void*) sym_entry;
    insert_value(hash_tab, "if", value);

    sym_entry = calloc(1, sizeof (sym_entry));
    sym_entry->offset = 1002;

    value.pointer = (void*) sym_entry;
    insert_value(hash_tab, "if2", value);
    print_symbol_table(hash_tab);

    sym_entry = get_value(hash_tab, "if")->pointer;
    printf("Val = %ld\n", sym_entry->offset);

    sym_entry = get_value(hash_tab, "if2")->pointer;
    printf("Val = %ld\n", sym_entry->offset);
    //free(sym_entry);
    free_hash_table(hash_tab);
}

/**
 * Test the functionality of the linked list structure
 */

void linked_list_tests() {
    int max = 12;
    int index = 0;
    union val value;
    struct linked_list_node* node;

    //Linked List
    struct linked_list* list = create_linked_list();

    //Test 1 - Queue Values
    printf("\n\nLL Test 1\n");
    for (int i = 0; i < max; i++) {
        value.integer = i;
        queue(list, create_linked_list_node(value));
    }

    //Walk List And Verify
    node = list->head->next;
    //node->value.integer = 100; Force Test To Fail
    index = 0;

    while (node != list->tail) {
        if (node->value.integer != index)
            error(1, 1, "Linked List Failed Test 1");

        node = node->next;
        index++;
    }

    if (list->count != max)
        error(1, 1, "Linked List Failed Test 1b");

    //Print List
    print_list(list);

    //Test 2 - Dequeue Values
    printf("\n\nLL Test 2\n");

    node = dequeue(list);
    //node->value.integer = 100; Force Test To Fail
    index = 0;

    while (node != NULL) {
        if (node->value.integer != index)
            error(1, 1, "Linked List Failed Test 2a");

        node = dequeue(list);
        index++;
    }

    if (list->head->next != list->tail)
        error(1, 1, "Linked List Failed Test 2b");

    if (list->count != 0)
        error(1, 1, "Linked List Failed Test 2c");

    //Print List
    print_list(list);

    //Test 3 - Push Values
    printf("\n\nLL Test 3\n");
    for (int i = 0; i < max; i++) {
        value.integer = i;
        push(list, create_linked_list_node(value));
    }

    //Walk List And Verify
    node = list->head->next;
    //node->value.integer = 100; Force Test To Fail
    index = max - 1;

    while (node != list->tail) {
        if (node->value.integer != index)
            error(1, 1, "Linked List Failed Test 3");

        node = node->next;
        index--;
    }

    if (list->count != max)
        error(1, 1, "Linked List Failed Test 3b");

    //Print List
    print_list(list);

    //Test 2 - Pop Values
    printf("\n\nTest 4\n");

    node = pop(list);
    //node->value.integer = 100; Force Test To Fail
    index = max - 1;

    while (node != NULL) {
        if (node->value.integer != index)
            error(1, 1, "Linked List Failed Test 4a");

        node = dequeue(list);
        index--;
    }

    if (list->head->next != list->tail)
        error(1, 1, "Linked List Failed Test 4b");

    if (list->count != 0)
        error(1, 1, "Linked List Failed Test 4c");

    //Print List
    print_list(list);
}
