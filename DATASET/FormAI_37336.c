//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Initialize an empty linked list
struct Node* head = NULL;

// Insert an element at the beginning of the linked list
void insertAtBeginning(int data) {
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Display the linked list
void displayList() {
    struct Node* current = head;
    printf("The list is: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Delete an element from the linked list
void deleteElement(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Element not found in the list!\n");
        return;
    }
    if(prev == NULL) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
    printf("The element %d was deleted from the list.\n", data);
}

int main() {
    // Insert elements into the linked list
    insertAtBeginning(14);
    insertAtBeginning(7);
    insertAtBeginning(6);
    insertAtBeginning(8);

    // Display the linked list
    displayList();

    // Delete an element from the linked list
    deleteElement(6);

    // Display the linked list after deletion
    displayList();

    return 0;
}