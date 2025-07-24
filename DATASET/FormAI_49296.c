//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

void add(struct Node **head, int data) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void printList(struct Node *head) {
  struct Node *temp = head;
  while(temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void reverseList(struct Node **head) {
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next = NULL;
  
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  
  *head = prev;
}

int main() {
  struct Node *head = NULL;
  add(&head, 5);
  add(&head, 10);
  add(&head, 15);
  add(&head, 20);
  add(&head, 25);
  
  printf("Original List:\n");
  printList(head);
  
  reverseList(&head);
  
  printf("Reversed List:\n");
  printList(head);
  
  return 0;
}