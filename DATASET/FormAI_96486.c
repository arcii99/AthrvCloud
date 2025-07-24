//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

/* Linked List Node */
struct node{
    int data;
    struct node* next;
};

/* Function to insert a new node at the beginning of the linked list */
void insert_front(struct node** head_ref, int new_data){

    /* Allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    /* Put in the data */
    new_node->data = new_data;
    
    /* Link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* Move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to insert a new node after a given node */
void insert_after(struct node* prev_node, int new_data){

    /* Check if the given prev_node is NULL */
    if(prev_node == NULL){
        printf("Previous node cannot be NULL");
        return;
    }
    
    /* Allocate new node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    /* Put in the data */
    new_node->data = new_data;
    
    /* Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    
    /* Move the next of prev_node to point to the new node */
    prev_node->next = new_node;   
}

/* Function to insert a new node at the end of the linked list */
void insert_end(struct node** head_ref, int new_data){

    /* Allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    struct node* last = *head_ref;
    
    /* Put in the data */
    new_node->data = new_data;
    
    /* This new node is going to be the last node, so make next of it as NULL */
    new_node->next = NULL;
    
    /* If the linked list is empty, then make the new node as head */
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    /* Else traverse till the last node */
    while(last->next != NULL){
        last = last->next;
    }
    
    /* Change the next of last node */
    last->next = new_node;
    return;     
}

/* Function to delete a node in the linked list */
void delete_node(struct node **head_ref, int key){
    /* Store head node */
    struct node* temp = *head_ref, *prev;
    
    /* If head node itself holds the key to be deleted */
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    /* Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next' */
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    
    /* If key was not present in linked list */
    if(temp == NULL){
        printf("Key not found in linked list.");
        return;
    }
    
    /* Unlink the node from linked list */
    prev->next = temp->next;
    
    /* Free memory */
    free(temp);
}

/* Function to traverse the linked list and print all elements */
void print_list(struct node* node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Main driver function */
int main(){
    struct node* head = NULL;

    /* Inserting elements into the linked list */
    insert_end(&head, 20);
    insert_front(&head, 10);
    insert_end(&head, 30);
    insert_after(head->next, 15);

    /* Printing the linked list */
    printf("Linked list elements: ");
    print_list(head);

    /* Deleting an element from the linked list */
    printf("\n\nAfter deleting element 15: ");
    delete_node(&head, 15);
    print_list(head);

    return 0;
}