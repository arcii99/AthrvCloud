//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h> 

/* structure for a node */
struct Node
{
    int data;
    struct Node *next;
};

/* function to insert a new node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    /* put in the data */
    new_node->data = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* function to insert a new node after a given node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /* check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    
    /* allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    
    /* put in the data */
    new_node->data = new_data;
    
    /* make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    
    /* move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* function to insert a new node at the end of linked list */
void append(struct Node** head_ref, int new_data)
{
    /* allocate new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    struct Node *last = *head_ref;  /* used in step 5 */
    
    /* put in the data */
    new_node->data  = new_data;
    
    /* this new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;
    
    /* if the linked list is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    
    /* else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    
    /* change the next of last node */
    last->next = new_node;
    return;
}

/* function to delete a node */
void deleteNode(struct Node **head_ref, int key)
{
    /* store head node */
    struct Node* temp = *head_ref, *prev;
 
    /* if head node itself holds the key to be deleted */
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    /* search for the key to be deleted, keep track of the
       previous node as we need to change 'prev->next' */
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    /* if key was not present in linked list */
    if (temp == NULL) return;
 
    /* unlink the node from linked list */
    prev->next = temp->next;
 
    free(temp);  // Free memory
}

/* function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* main function */
int main()
{
    /* start with the empty list */
    struct Node* head = NULL;
    
    /* insert 6, 4, 3, 8, 12 at the beginning */
    push(&head, 12);
    push(&head, 8);
    push(&head, 3);
    push(&head, 4);
    push(&head, 6);
    
    /* insert 10 after 3 and 15 after 8 */
    insertAfter(head->next->next, 10);
    insertAfter(head->next->next->next->next, 15);
    
    /* append 20 and 25 to the end */
    append(&head, 20);
    append(&head, 25);
    
    /* print list */
    printf("Created Linked list is: ");
    printList(head);
    
    /* delete 3 and print */
    deleteNode(&head, 3);
    printf("\nLinked list after deletion of 3 is: ");
    printList(head);
    
    /* delete 8 and print */
    deleteNode(&head, 8);
    printf("\nLinked list after deletion of 8 is: ");
    printList(head);
    
    return 0;
}