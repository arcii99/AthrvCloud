//FormAI DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void insert_end(Node **head, int value) {
  Node *new_node = (Node *) malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void print_list(Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
  } else {
    printf("Current list:\n");
    Node *current = head;
    while (current != NULL) {
      printf("%d -> ", current->data);
      current = current->next;
    }
    printf("NULL\n");
  }
}

int main() {
  Node *head = NULL;

  insert_end(&head, 10);
  insert_end(&head, 20);
  insert_end(&head, 30);

  print_list(head);

  return 0;
}