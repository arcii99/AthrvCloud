//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

int main() {
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        printf("Error: unable to allocate memory\n");
        return 1;
    }

    head->data = 1;
    head->next = (node_t*)malloc(sizeof(node_t));
    if (head->next == NULL) {
        printf("Error: unable to allocate memory\n");
        return 1;
    }
    head->next->data = 2;
    head->next->next = (node_t*)malloc(sizeof(node_t));
    if (head->next->next == NULL) {
        printf("Error: unable to allocate memory\n");
        return 1;
    }
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // print the linked list
    node_t* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    // free the memory allocated to the linked list
    current = head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}