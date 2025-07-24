//FormAI DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 3);

    printf("Linked List before deletion: ");
    display(head);

    deleteNode(&head, 5);

    printf("Linked List after deletion: ");
    display(head);

    return 0;
}