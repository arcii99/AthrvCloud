//FormAI DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* Defining a structure representing a node of a linked list */
struct Node
{
    int data;           /* Data stored in node */
    struct Node* next;  /* Pointer to the next node */
};

/* Function to push a new node to the beginning of the linked list */
void push(struct Node** head_ref, int new_data)
{
    /* Allocate memory to new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* Insert the data into new node */
    new_node->data = new_data;

    /* Set the next of new node as head node */
    new_node->next = (*head_ref);

    /* Set the head as new node */
    (*head_ref) = new_node;
}

/* Function to delete a node with given key in the linked list */
void deleteNode(struct Node** head_ref, int key)
{
    /* Store head node */
    struct Node *temp = *head_ref, *prev;

    /* If head node itself holds the key */
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;     /* Change head */
        free(temp);                 /* Free old head memory */
        return;
    }

    /* Search for the node to be deleted */
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    /* If node with given key is not found */
    if (temp == NULL)
        return;

    /* Unlink the node from linked list */
    prev->next = temp->next;

    /* Free the memory of the node */
    free(temp);
}

/* Function to display the linked list */
void displayList(struct Node* node)
{
    printf("Linked List: ");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver function */
int main()
{
    /* Initialize the linked list */
    struct Node* head = NULL;

    /* Insert nodes into the linked list */
    push(&head, 7);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);

    /* Display the linked list */
    displayList(head);

    /* Delete a node with given key */
    deleteNode(&head, 3);

    /* Display the modified linked list */
    displayList(head);

    return 0;
}