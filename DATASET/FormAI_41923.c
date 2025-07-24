//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node* next;
} Node;

Node* head = NULL;

void push(int value) {
   Node* temp = (Node*)malloc(sizeof(Node));
   temp->data = value;
   temp->next = head;
   head = temp;
}

void display() {
   Node* temp = head;
   while(temp != NULL) {
      printf("%d ->", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

int main() {
   push(5);
   push(10);
   push(15);
   display();
   return 0;
}