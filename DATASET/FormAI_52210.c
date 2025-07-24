//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the linked list
struct node {
   int data;
   struct node *next;
};

// Function to insert a new node at the beginning of the linked list
void push(struct node **head_ref, int new_data) {
   struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
   new_node->data = new_data; // Assign data to the new node
   new_node->next = (*head_ref); // Make the next of new node as head
   (*head_ref) = new_node; // Move the head to point to the new node
}

// Function to insert a new node after the given prev_node
void insertAfter(struct node *prev_node, int new_data) {
   if(prev_node == NULL) {
      printf("The given previous node cannot be NULL");
      return;
   }
   struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
   new_node->data = new_data; // Assign data to the new node
   new_node->next = prev_node->next; // Make next of new node as next of prev_node
   prev_node->next = new_node; // Move the next of prev_node to point to the new_node
}

// Function to insert a new node at the end of the linked list
void append(struct node **head_ref, int new_data) {
   struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
   struct node *last = *head_ref; // This will be used to traverse till the last node
   new_node->data = new_data; // Assign data to the new node
   new_node->next = NULL; // Assign NULL to the next of new node as it will be the last node
   if (*head_ref == NULL) { // If the linked list is empty, make the new node as head
      *head_ref = new_node;
      return;
   }
   while (last->next != NULL) // Else traverse till the last node
      last = last->next;
   last->next = new_node; // Change the next of the last node to new node
   return;
}

// Function to delete a node with a given key
void deleteNode(struct node **head_ref, int key) {
   struct node *temp = *head_ref, *prev;
   if (temp != NULL && temp->data == key) { // If head node itself holds the key to be deleted
      *head_ref = temp->next; // Change the head node
      free(temp);
      return;
   }
   while (temp != NULL && temp->data != key) { // Search for the key to be deleted
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL) return; // If key is not present in linked list
   prev->next = temp->next; // Unlink the node from linked list
   free(temp); // Free memory
}

// Function to print the linked list
void printList(struct node *node) {
   while (node != NULL) {
      printf(" %d ", node->data);
      node = node->next;
   }
}

// Main function to test the implementation of the linked list operations
int main() {
   struct node *head = NULL; // Initialize an empty linked list
   printf("Linked List before insertion: ");
   printList(head); // Print the linked list before insertion
   push(&head, 5); // Insert 5 at the beginning
   push(&head, 4); // Insert 4 at the beginning
   printf("\nLinked List after insertion of two nodes at beginning: ");
   printList(head); // Print the linked list after insertion of two nodes at the beginning
   insertAfter(head->next, 6); // Insert 6 after 4
   printf("\nLinked List after inserting 6 after 4: ");
   printList(head); // Print the linked list after inserting 6 after 4
   append(&head, 7); // Insert 7 at the end
   append(&head, 8); // Insert 8 at the end
   printf("\nLinked List after appending two nodes at end: ");
   printList(head); // Print the linked list after appending two nodes at the end
   deleteNode(&head, 4); // Delete node with key 4
   printf("\nLinked List after deletion of node with key 4: ");
   printList(head); // Print the linked list after deletion of node with key 4
   return 0;
}