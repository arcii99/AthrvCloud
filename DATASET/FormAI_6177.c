//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void insert(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

void traverse(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d\t", current_node->data);
        current_node = current_node->next;
    }
}

int main() {
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    traverse(head);
    return 0;
}