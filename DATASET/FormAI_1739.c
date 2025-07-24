//FormAI DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

// Node structure of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create and return a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Main Function
int main() {
    // Create a linked list with 5 nodes
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Display the linked list
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}