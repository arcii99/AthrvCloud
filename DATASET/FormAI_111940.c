//FormAI DATASET v1.0 Category: Linked list operations ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

/* Define the structure of a node */
struct node
{
    int data;
    struct node *next;
};

/* Function to push a node in the front of the list */
void push(struct node **head, int val)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next = (*head);
    (*head) = new_node;
}

/* Function to insert a new node after a given node */
void insertAfter(struct node *prev_node, int val)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Function to append a node to the end of the list */
void append(struct node **head, int val)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head;

    new_node->data = val;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

/* Function to delete a node from the list */
void deleteNode(struct node **head, int key)
{
    struct node* temp = *head, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

/* Function to print the list */
void printList(struct node *node)
{
    printf("\n\nLinked List: ");
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL");
}

/* The main driver code */
int main()
{
    struct node* head = NULL;

    /* Append nodes to the list */
    append(&head, 6);
    append(&head, 7);
    append(&head, 1);
    printList(head);

    /* Push a node to the front of the list */
    push(&head, 4);
    printList(head);

    
    /* Insert a node after a given node */
    insertAfter(head->next, 8);
    printList(head);

    /* Delete a node from the list */
    deleteNode(&head, 7);
    printList(head);

    printf("\n\nEnergy Filled - The logic of Linked List has been implemented successfully");
    return 0;
}