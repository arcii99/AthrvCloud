//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert(Node **head_ref, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next=(*head_ref);
    (*head_ref) = new_node;
}

void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    printf("Linked List: ");
    display(head);
    return 0;
}