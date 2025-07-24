//FormAI DATASET v1.0 Category: Linked list operations ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
struct Node
{
    int data;
    struct Node *next;
};

// A function to add a new node at the beginning
void push(struct Node** head_ref, int new_data)
{
    // Allocating the memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    // Assigning the new data to the new node
    new_node->data = new_data;
    
    // Making the next of new node as head
    new_node->next = (*head_ref);
    
    // Making the new node as head
    (*head_ref) = new_node;
}

// A function to add a new node after a given node
void insertAfter(struct Node* prev_node, int new_data)
{
    // Checking if the previous node is NULL
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL.");
        return;
    }
    
    // Allocating the memory for new node
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    
    // Assigning the new data to the new node
    new_node->data = new_data;
    
    // Making the next of new node as next of prev node
    new_node->next = prev_node->next;
    
    // Making the next of prev node as new node
    prev_node->next = new_node;
}

// A function to add a new node at the end
void append(struct Node** head_ref, int new_data)
{
    // Allocating the memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    struct Node *last = *head_ref; 
 
    // Assigning the new data to the new node
    new_node->data = new_data;
    
    // Setting the next of new node as NULL
    new_node->next = NULL;
    
    // If the linked list is empty, make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
  
    // Traverse till the end of the list
    while (last->next != NULL)
    {
        last = last->next;
    }
  
    // Change the next of the last node
    last->next = new_node;
    return;
}

// A function to delete a node with given value
void deleteNode(struct Node **head_ref, int key)
{
    // Storing the head node
    struct Node* temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Change the head
        free(temp);               // Free the old head
        return;
    }
 
    // Traverse through the linked list
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key is not present in the linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp);  // Free memory
}

// A function to print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    // Creating the linked list
    struct Node* head = NULL;
    
    // Adding nodes to the linked list
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
 
    // Printing the linked list
    printf("Created Linked list is: ");
    printList(head);
 
    // Deleting the node with value 1
    deleteNode(&head, 1);
 
    // Printing the linked list again
    printf("\nLinked list after deletion of 1: ");
    printList(head);
    
    return 0;
}