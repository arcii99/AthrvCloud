//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Defining a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
// Time complexity: O(1)
void insertAtBeginning(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to insert a new node after a given node in the linked list
// Time complexity: O(1)
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
    printf("The given previous node cannot be NULL.");
    return;
  }
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Function to insert a new node at the end of the linked list
// Time complexity: O(n)
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
  return;
}

// Function to delete a node from the linked list
// Time complexity: O(n)
void deleteNode(struct Node** head_ref, int key) {
  struct Node* temp = *head_ref;
  struct Node* prev = NULL;
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    return;
  }
  prev->next = temp->next;
  free(temp);
}

// Function to print all the elements of the linked list
// Time complexity: O(n)
void printList(struct Node* n) {
  while (n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
}

int main() {
  struct Node* head = NULL;

  // Inserting nodes at the beginning
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 1);

  // Inserting node after a given node
  insertAfter(head->next, 4);

  // Inserting nodes at the end
  insertAtEnd(&head, 6);
  insertAtEnd(&head, 8);

  // Deleting a node from the linked list
  deleteNode(&head, 4);

  // Printing the linked list
  printList(head);

  return 0;
}