//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_node(struct node** head_ref, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* list = NULL;

    insert_node(&list, 5);
    insert_node(&list, 4);
    insert_node(&list, 3);
    insert_node(&list, 2);
    insert_node(&list, 1);

    print_list(list);

    return 0;
}