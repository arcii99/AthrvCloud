//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void allocateMemoryRandomly() {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Allocated memory at %p\n", newNode);
    int randomValue = rand() % 100;
    newNode->data = randomValue;
    newNode->next = head;
    head = newNode;
}

void freeMemoryRandomly() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    printf("Freed memory at %p\n", temp);
    free(temp);
}

int main() {
    srand(time(0));

    // Allocate memory at random intervals
    for (int i = 1; i <= 10; i++) {
        int delay = rand() % 5;
        sleep(delay);
        allocateMemoryRandomly();
        printf("List after allocation %d:\n", i);
        printList(head);
        printf("==================================\n");
    }

    // Free memory at random intervals
    for (int i = 1; i <= 10; i++) {
        int delay = rand() % 5;
        sleep(delay);
        freeMemoryRandomly();
        printf("List after deallocation %d:\n", i);
        printList(head);
        printf("==================================\n");
    }

    return 0;
}