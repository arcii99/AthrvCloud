//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>

typedef struct node {
   int data;
   struct node *next;
} NODE;

int main() {
   int n, i; 

   printf("How many elements do you want to add in the linked list? ");
   scanf("%d", &n);

   NODE *head, *temp, *current; // create the linked list 

   head = (NODE *)malloc(sizeof(NODE));
   head->next = NULL;
   current = head;

   for(i = 0; i < n; i++) {
      temp = (NODE *)malloc(sizeof(NODE));

      printf("Enter the element %d: ", i+1);
      scanf("%d", &temp->data);

      temp->next = NULL;
      current->next = temp;
      current = current->next;
   }

   printf("\n");
   printf("Here's how your linked list looks like visually:\n");

   // visualization 
   current = head->next;
   while(current != NULL) {
      printf("| %d |  -> ", current->data);
      current = current->next;
   }
   printf("NULL\n");

   return 0;
}