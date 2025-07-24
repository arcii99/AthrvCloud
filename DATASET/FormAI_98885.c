//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>

// Define a struct for a node in a linked list
struct Node {
    int value;
    struct Node* next;
};

int main() {
    // Create three nodes and link them together
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));
    
    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = NULL;

    // Print out the linked list visually
    printf("Linked List Visualization:\n");
    printf("%d -> %d -> %d -> NULL\n", head->value, second->value, third->value);

    return 0;
}