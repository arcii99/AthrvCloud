//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

void append(struct node** head_ref, int data) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   struct node *last = *head_ref;
   new_node -> data = data;
   new_node -> next = NULL;

   if (*head_ref == NULL) {
      *head_ref = new_node;
      return;
   }

   while (last -> next != NULL)
      last = last -> next;

   last -> next = new_node;
}

void push(struct node** head_ref, int data) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node -> data = data;
   new_node -> next = (*head_ref);
   (*head_ref) = new_node;
}

void insert_after(struct node* prev_node, int data) {
   if (prev_node == NULL) {
      printf("Previous node cannot be NULL");
      return;
   }

   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node -> data = data;
   new_node -> next = prev_node -> next;
   prev_node -> next = new_node;
}

void delete(struct node** head_ref, int key) {
   struct node* temp = *head_ref, *prev;

   if (temp != NULL && temp -> data == key) {
      *head_ref = temp -> next;
      free(temp);
      return;
   }

   while (temp != NULL && temp -> data != key) {
      prev = temp;
      temp = temp -> next;
   }

   if (temp == NULL)
      return;

   prev -> next = temp -> next;

   free(temp);
}

void print_list(struct node *node) {
   while (node != NULL) {
      printf(" %d ", node -> data);
      node = node -> next;
   }
}

int main() {
   struct node* head = NULL;

   // Add elements to the linked list
   append(&head, 1);
   append(&head, 2);
   append(&head, 3);

   // Insert 4 at the beginning. So linked list becomes 4->3->2->1
   push(&head, 4);

   // Insert 5 after node with value 3. So linked list becomes 4->3->5->2->1
   insert_after(head -> next, 5);

   // Delete node with value 2. So linked list becomes 4->3->5->1
   delete(&head, 2);

   // Prints the list
   printf("\nCreated Linked list is: ");
   print_list(head);

   return 0;
}