//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int num;
  struct Node* next;
};

void printList(struct Node* head){
  while(head != NULL){
    printf("%d ", head->num);
    head = head->next;
  }
  printf("\n");
}

int main(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  head->num = 1;
  head->next = second;

  second->num = 2;
  second->next = third;

  third->num = 3;
  third->next = NULL;

  printList(head);

  return 0;
}