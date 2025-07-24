//FormAI DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct node** headRef, int newData){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node after a given node in a linked list
void insertAfter(struct node* prevNode, int newData){
    if(prevNode == NULL){
        printf("The given previous node cannot be null!");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct node** headRef, int newData){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Function to delete a node with a given key from the linked list
void deleteNode(struct node **headRef, int key){
    struct node* temp = *headRef, *prev;
    if(temp != NULL && temp->data == key){
        *headRef = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct node* node){
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){

    struct node* head = NULL;

    // Inserting nodes at the beginning of the linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 7);
    printf("Linked List after inserting nodes at beginning: ");
    printList(head);

    // Inserting nodes after a given node in the linked list
    struct node* node2 = head->next;
    insertAfter(node2, 5);
    printf("Linked List after inserting node after node 2: ");
    printList(head);

    // Inserting nodes at the end of the linked list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 6);
    printf("Linked List after inserting nodes at end: ");
    printList(head);

    // Deleting a node from the linked list
    deleteNode(&head, 7);
    printf("Linked List after deleting node 7: ");
    printList(head);

    return 0;
}