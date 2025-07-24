//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void add_data(node_t **head, int data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

void print_list(node_t *head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    node_t *head = NULL;

    add_data(&head, 5);
    add_data(&head, 10);
    add_data(&head, 15);

    print_list(head);

    return 0;
}