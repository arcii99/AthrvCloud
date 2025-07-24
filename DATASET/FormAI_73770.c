//FormAI DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data; 
  struct node* next; 
} node_t;

void insert(node_t** head, int data) {
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = (*head);
  (*head) = new_node;
}

void delete(node_t** head, int key) {
  node_t* temp = *head;
  node_t* prev = NULL;
  
  if (temp != NULL && temp->data == key) { 
    *head = temp->next;
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

void print_list(node_t* head) {
  node_t* current = head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

int main() {
  node_t* head = NULL;
  
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  printf("Linked List before deletion: ");
  print_list(head);
  
  delete(&head, 3);

  printf("\nLinked List after deletion: ");
  print_list(head);

  return 0;
}