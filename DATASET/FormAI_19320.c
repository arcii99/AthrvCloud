//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

// Define the structure for the node in the linked list
struct Node
{
    int data;
    struct Node* next;
};

// Function to insert node at the end of the linked list
void insertNodeAtEnd(struct Node** head_ref, int new_data)
{
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    // Assign new data to the new node and set the pointer to NULL
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, then the new node is the head node
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Traverse the linked list to get to the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Set the next pointer of the last node to the new node
    last->next = new_node;
    return;
}

// Function to print the linked list
void printLinkedList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to demonstrate the linked list operations
int main()
{
    struct Node* head = NULL;

    // Insert some nodes in the linked list
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);

    // Print the linked list
    printLinkedList(head);

    return 0;
}