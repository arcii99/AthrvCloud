//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
   int data;
   struct Node* next;
};

// Function to add a node to the front of the list
void push(struct Node** head_ref, int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}

// Function to add a node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
   // Check if the given prev_node is NULL
   if (prev_node == NULL) {
       printf("The given previous node cannot be NULL");
       return;
   }

   // Create a new node and insert it after the given prev_node
   struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = prev_node->next;
   prev_node->next = new_node;
}

// Function to add a node to the end of the list
void append(struct Node** head_ref, int new_data) {
   struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
   struct Node *last = *head_ref; // Used in step 5
   
   // Fill in the data for the new node
   new_node->data = new_data;
   new_node->next = NULL;

   // Check if the list is empty
   if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
   }

   // Find the last node in the list
   while (last->next != NULL) {
       last = last->next;
   }

   // Append the new node to the end of the list
   last->next = new_node;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
   // Store the head node
   struct Node *temp = *head_ref, *prev;

   // Check if the head node itself holds the key to be deleted
   if (temp != NULL && temp->data == key) {
       *head_ref = temp->next; // Changed head
       free(temp);            // free old head
       return;
   }

   // Search for the key to be deleted, keep track of the
   // previous node as we need to change 'prev->next'
   while (temp != NULL && temp->data != key) {
       prev = temp;
       temp = temp->next;
   }

   // If key was not present in linked list
   if (temp == NULL) {
       return;
   }

   // Unlink the node from linked list
   prev->next = temp->next;
   free(temp);
}

// Function to print the contents of the linked list
void printList(struct Node *node) {
   while (node != NULL) {
       printf("%d ", node->data);
       node = node->next;
   }
}

// Driver program to test above functions
int main() {
   // Create a linked list and add some data
   struct Node* head = NULL;
   append(&head, 6);
   push(&head, 7);
   push(&head, 1);
   append(&head, 4);
   insertAfter(head->next, 8);

   // Print the linked list
   printf("Linked list: ");
   printList(head);

   // Delete a node and print the updated list
   deleteNode(&head, 7);
   printf("\nLinked list after deletion of 7: ");
   printList(head);

   return 0;
}