//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtBeginning(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

void insertAtEnd(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    struct node* last = *head_ref; 
    new_node->data = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 

void deleteNode(struct node **head_ref, int key) 
{ 
    struct node* temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next; 
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

void printList(struct node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{ 
    struct node* head = NULL; 
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4); 
    deleteNode(&head, 1); 
    printList(head); 
    return 0; 
}