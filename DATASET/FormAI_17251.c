//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

// Structure of linked list node
struct linked_list {
    int data;
    struct linked_list* next;
};

// Function to create a new node
struct linked_list* createNode(int data) {
    struct linked_list* newNode = (struct linked_list*)malloc(sizeof(struct linked_list));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of linked list
void insertAtBeginning(struct linked_list** head, int data) {
    struct linked_list* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the end of linked list
void insertAtEnd(struct linked_list** head, int data) {
    struct linked_list* newNode, *temp = *head;
    newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from linked list
void deleteNode(struct linked_list** head, int key) {
    struct linked_list *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// Function to display linked list
void displayList(struct linked_list* head) {
    struct linked_list* temp = head;
    if (head == NULL) {
        printf("List is empty");
        return;
    }
    printf("Linked List:");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct linked_list* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 8);
    insertAtEnd(&head, 10);
    displayList(head);
    deleteNode(&head, 8);
    displayList(head);
    return 0;
}