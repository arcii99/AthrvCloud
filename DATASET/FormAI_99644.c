//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* addNode(Node* current, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (current != NULL) {
        current->next = newNode;
    }
    return newNode;
}

void printList(Node* head) {
    if (head == NULL) return;
    printf("%d ", head->data);
    printList(head->next);
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    Node* current = head;
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        if (i == 0) {
            head = addNode(current, data);
            current = head;
        } else {
            current = addNode(current, data);
        }
    }
    printList(head);
    return 0;
}