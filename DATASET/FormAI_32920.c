//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};

void createList(struct node **head, int n, int arr[]) {
   struct node* temp = *head;
   int i;
   for(i = 0; i < n; i++) {
      struct node* newNode = (struct node*) malloc(sizeof(struct node));
      newNode->data = arr[i];
      newNode->next = NULL;
      temp->next = newNode;
      temp = temp->next;
   }
}

void printList(struct node *head) {
   while(head != NULL) {
      printf("%d -> ", head->data);
      head = head->next;
   }
   printf("NULL\n");
}

int main() {
   struct node *head = (struct node*) malloc(sizeof(struct node));
   head->data = 1;
   head->next = NULL;
   int arr[5] = {2, 3, 4, 5, 6};
   createList(&head, 5, arr);
   printf("Linked List Visualized:\n");
   printList(head);
   return 0;
}