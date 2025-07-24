//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Define the node structure for linked list
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// Function to create a new node for a linked list
ListNode* createListNode(int value) {
    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    printf("Linked List: ");

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// Function to insert a value at the end of the linked list
void insertAtEnd(ListNode** headRef, int value) {
    ListNode* newNode = createListNode(value);

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        ListNode* current = *headRef;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

int main() {
    // Generate an array of random integers
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    // Convert the array to a linked list
    ListNode* linkedList = NULL;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        insertAtEnd(&linkedList, arr[i]);
    }

    // Print the linked list
    printLinkedList(linkedList);

    return 0;
}