//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_node(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void display_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    push(&head, 3);
    push(&head, 1);
    push(&head, 7);
    push(&head, 4);
    push(&head, 5);

    printf("List before deletion: ");
    display_list(head);

    delete_node(&head, 7);
    printf("\nList after deletion: ");
    display_list(head);

    return 0;
}