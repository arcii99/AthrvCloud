//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node { // defining the structure
   int data;
   struct node *next;
};

void push(struct node **head_ref, int new_data) { // function to insert new node at the beginning of the linked list
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}

void display(struct node *node) { // function to display the linked list
   while (node != NULL) {
      printf("%d -> ", node->data);
      node = node->next;
   }
   printf("NULL\n");
}

void deletion(struct node **head_ref, int key) { // function to delete a node from the linked list
   struct node* temp = *head_ref, *prev;
   
   if (temp != NULL && temp->data == key) {
      *head_ref = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) return;

   prev->next = temp->next;
   free(temp);
}

int main() { // main function
   struct node* head = NULL;

   push(&head, 8); // creating the linked list
   push(&head, 12);
   push(&head, 6);
   push(&head, 3);
   push(&head, 2);

   printf("Linked List: ");
   display(head);

   deletion(&head, 6); // deleting a node from the linked list

   printf("Linked List after deletion: ");
   display(head);
}