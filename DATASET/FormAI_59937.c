//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>

struct node {
   int value;
   struct node *next;
};

int main() {
   struct node n1, n2, n3;

   n1.value = 10;
   n1.next = &n2;

   n2.value = 20;
   n2.next = &n3;

   n3.value = 30;
   n3.next = NULL;

   struct node *current = &n1;

   while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
   }

   return 0;
}