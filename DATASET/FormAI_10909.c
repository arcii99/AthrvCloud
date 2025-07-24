//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void allocateMemory(node** head, int size) {
    *head = (node*) malloc(size * sizeof(node));
    if(!(*head)) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
}

void freeMemory(node* head) {
    if(!head) {
        printf("Error: Empty Memory\n");
        return;
    }
    free(head);
}

void printList(node* head) {
    node* current = head;
    int i = 1;
    while(current != NULL) {
        printf("[%d] Data: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

int main() {
    node* head = NULL;
    int size = 3;
    allocateMemory(&head, size);
    head[0].data = 1;
    head[0].next = &head[1];
    head[1].data = 2;
    head[1].next = &head[2];
    head[2].data = 3;
    head[2].next = NULL;

    printList(head);
    freeMemory(head);

    return 0;
}