//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

// define the structure of the linked list node
struct Node {
  int data;
  struct Node *next;
};

// function to insert a new node at the end of the linked list
void insert_end(struct Node **head, int data) {
  struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  if(*head == NULL) {
    *head = new_node;
    return;
  }

  struct Node *temp = *head;

  while(temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

// function to delete a node from the linked list
void delete_node(struct Node **head, int key) {
  struct Node *temp = *head;
  struct Node *prev = NULL;

  if(temp != NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    return;
  }

  while(temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL) {
    printf("Key not found\n");
    return;
  }

  prev->next = temp->next;
  free(temp);
}

// function to display the linked list
void display_list(struct Node *head) {
  struct Node *temp = head;

  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int main() {
  struct Node *head = NULL;
  insert_end(&head, 10);
  insert_end(&head, 20);
  insert_end(&head, 30);
  insert_end(&head, 40);

  printf("Initial linked list: ");
  display_list(head);

  delete_node(&head, 30);

  printf("\nLinked list after deletion of node with key 30: ");
  display_list(head);

  return 0;
}