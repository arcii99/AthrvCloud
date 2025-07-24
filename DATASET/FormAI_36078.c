//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include<stdio.h>
#include<stdlib.h>
// Defining a structure for a linked list node
struct Node {
   int data;
   struct Node* next;
};
// Function to create a new node with given data
struct Node* newNode(int data) {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}
// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
   struct Node* new_node = newNode(new_data);
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}
// Function to insert a node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
   if (prev_node == NULL) {
      printf("The given previous node cannot be NULL");
      return;
   }
   struct Node* new_node = newNode(new_data);
   new_node->next = prev_node->next;
   prev_node->next = new_node;
}
// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
   struct Node* new_node = newNode(new_data);
   struct Node* last = *head_ref;
   if (*head_ref == NULL) {
      *head_ref = new_node;
      return;
   }
   while (last->next != NULL)
   last = last->next;
   last->next = new_node;
   return;
}
// Function to delete a node with given key
void deleteNode(struct Node** head_ref, int key) {
   struct Node *temp = *head_ref, *prev;
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
// Function to print the linked list
void printList(struct Node *node) {
   while(node != NULL) {
      printf("%d ", node->data);
      node = node->next;
   }
}
// Driver program to test the above functions
int main() {
   struct Node* head = NULL;
   insertAtEnd(&head, 8);
   insertAtBeginning(&head, 6);
   insertAtBeginning(&head, 5);
   insertAtEnd(&head, 9);
   insertAfter(head->next, 7);
   printf("\nLinked list before deleting a node: ");
   printList(head);
   deleteNode(&head, 7);
   printf("\nLinked list after deleting a node: ");
   printList(head);
   printf("\n");
   return 0;
}