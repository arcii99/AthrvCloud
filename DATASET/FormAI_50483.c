//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

void insert(node** head, int newdata)
{
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = newdata;
  newnode->next = (*head);
  (*head) = newnode;
}

void delete(node** head, int key)
{
  node* temp = (*head), *prev;
  if (temp != NULL && temp->data == key)
  {
    (*head) = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
  return;
  prev->next = temp->next;
  free(temp);
}

void display(node* head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main()
{
  node* head = NULL;
  insert(&head, 8);
  insert(&head, 10);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 1);
  printf("Original linked list:\n");
  display(head);
  delete(&head, 3);
  printf("Linked list after deleting node with value 3:\n");
  display(head);
  return 0;
}