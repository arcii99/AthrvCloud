//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *node) {
    printf("HEAD -->");
    while (node != NULL) {
        printf(" %d -->", node->data);
        node = node->next;
    }
    printf(" NULL\n");
}

int main() {
    struct node* head = NULL;
    printf("Empty Linked List:\n");
    printList(head);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printf("Linked List after adding 3 elements:\n");
    printList(head);
    return 0;
}