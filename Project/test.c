#include "global.h"

/**
 * Run all automated tests
 */

void run_tests() {

    linked_list_tests();
    hash_table_tests();
    printf("\n\n%sPassed All Tests %s\n\n\n", KGRN, KNRM);

}

void hash_table_tests() {
    int i;
    int keyword_start_const = 300;
    union val value;
    struct symbol_tab_entry* sym_tab_ent;

    bool is_found = false;

    printf("\n\n%sHT Test 1%s\n", KBLU, KNRM);

    //Insert Keywords
    for (i = 0; i < KEYWORD_COUNT; i++) {
        is_found = false;
        value = get_value(symbol_table, keywords[i], &is_found);

        if (!is_found)
            error(1, 1, "Hash Table Failed Test 1");

        sym_tab_ent = (struct symbol_tab_entry*) value.pointer;

        printf("%03d\n", sym_tab_ent->type);
        if (sym_tab_ent->type != i + keyword_start_const)
            error(1, 1, "Hash Table Failed Test 1 (Loc B)");
    }

    printf("\n\n%sHT Test 2%s\n", KBLU, KNRM);
    value = get_value(symbol_table, "HelloWorld!!!", &is_found);
    if (is_found)
        error(1, 1, "Hash Table Failed Test 2");



    print_symbol_table(symbol_table);

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
    printf("\n\n%sLL Test 1%s\n", KBLU, KNRM);
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
    printf("\n\n%sLL Test 2%s\n", KBLU, KNRM);

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
    printf("\n\n%sLL Test 3%s\n", KBLU, KNRM);
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
    printf("\n\n%sLL Test 4%s\n", KBLU, KNRM);

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
