//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Declaration of a structure for Linked List
struct Node {
  int data;
  struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
  // Allocation of a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;

  // Make new node as head
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void pop(struct Node** head_ref) {
  struct Node* temp = *head_ref;
  *head_ref = temp->next;
  free(temp);
}

int main() {
  struct Node* head = NULL;
  
  // Insertion of first 5 positive integers
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  
  // Removal of first 3 positive integers
  pop(&head);
  pop(&head);
  pop(&head);

  // Freeing the memory
  free(head);

  return 0;
}