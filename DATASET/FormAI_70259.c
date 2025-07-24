//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct linked_list {
    struct node* head;
    int size;
};

void add_to_list(struct linked_list *list, int val) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void delete_list(struct linked_list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        struct node *temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    list->head = NULL;
    list->size = 0;
}

int main() {
    struct linked_list *list = malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->size = 0;
    add_to_list(list, 5);
    add_to_list(list, 10);
    printf("Size of linked list: %d\n", list->size);
    delete_list(list);
    printf("Size of linked list after deletion: %d\n", list->size);
    free(list);
    return 0;
}