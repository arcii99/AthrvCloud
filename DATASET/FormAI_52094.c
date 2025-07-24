//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a node at the beginning of the list
void insertAtBeginning(struct node** head, int data) {
    struct node* new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* new_node = newNode(data);
    struct node* temp = *head;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Delete a node from the list
void deleteNode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Print the list
void printList(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printf("Linked list: ");
    printList(head);
    deleteNode(&head, 2);
    printf("Linked list after deletion of node with value 2: ");
    printList(head);
    return 0;
}