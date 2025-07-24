//FormAI DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a node for linked list
struct Node {
    int data;       // data for the node
    struct Node* next;  // pointer to the next node
};

// Define a function to insert a node at the head of the linked list
void insert(struct Node** headRef, int data)
{
    // create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    
    // make the next of new node to point to the head node
    newNode->next = *headRef;
    
    // make the head of linked list to point to the new node
    *headRef = newNode;
}

// Define a function to visualize the linked list
void visualize(struct Node* head)
{
    struct Node* current = head;
    
    // loop over all the nodes of linked list
    while(current != NULL) {
        // print the data of current node
        printf("%d -> ", current->data);
        
        // move the pointer to the next node
        current = current->next;
    }
    
    // print NULL indicating the end of linked list
    printf("NULL\n");
}

int main()
{
    // Initialize a linked list
    struct Node* head = NULL;
    
    // Insert some data into the linked list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    
    // Visualize the linked list
    printf("Linked List Visualization:\n");
    visualize(head);
    
    return 0;
}