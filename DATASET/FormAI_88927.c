//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

//Structure for creating a node in linked list
struct node{
    int data;
    struct node* next;
};

//Function to insert elements in the linked list
void insert(struct node** head_ref, int new_data){
    
    //Creating a new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    //Adding data to new node
    new_node->data = new_data;

    //Making the new node the head of the linked list
    new_node->next = (*head_ref);

    //Making the new node as head of the linked list
    (*head_ref) = new_node;
}

//Function to delete a particular element from the linked list
void delete(struct node** head_ref, int key){
    
    //Creating 2 pointers for deleting the required element
    struct node *temp = *head_ref, *prev;
    
    //If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }
    
    //Search for the key to be deleted, and keeping track of its previous node
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    //If key was not present in linked list
    if (temp == NULL) return;

    //Deleting the node containing the key
    prev->next = temp->next;
    free(temp);  
}

//Function to display the elements of linked list
void display(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

//Main function to test the above functions
int main()
{
    struct node* head = NULL;
    
    //Inserting integer values in the linked list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);

    //Displaying the elements of linked list
    printf("Linked list before deletion: ");
    display(head);
    
    //Deleting an element from the linked list
    delete(&head, 30);

    //Displaying the elements of linked list again
    printf("\nLinked list after deletion: ");
    display(head);

    return 0;
}