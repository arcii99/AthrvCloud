//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>

// Define a struct for a linked list node
struct ListNode {
    int value;
    struct ListNode* next;
};

// Define a function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct ListNode** head, int value) {
    // Create a new node
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // Set its value and next pointer
    newNode->value = value;
    newNode->next = (*head);
    // Set the head to the new node
    (*head) = newNode;
}

// Define a function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with 5 nodes
    struct ListNode* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the linked list
    printList(head);

    return 0;
}