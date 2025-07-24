//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {  
   int *ptr1, *ptr2, *ptr3;
   ptr1 = (int*) malloc(sizeof(int));
   ptr2 = (int*) calloc(1, sizeof(int));
   ptr3 = (int*) realloc(ptr1, sizeof(int));

   if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) {
      printf("Memory allocation failed.\n");
      exit(1);
   }

   // Using ptr1
   *ptr1 = 10;
   printf("Value of ptr1: %d\n", *ptr1);

   // Using ptr2
   *ptr2 = 20;
   printf("Value of ptr2: %d\n", *ptr2);

   // Using ptr3
   *ptr3 = 30;
   printf("Value of ptr3: %d\n", *ptr3);

   // freeing memory allocated by malloc and realloc
   free(ptr1);
   free(ptr3);

   // realloc with size zero
   ptr2 = realloc(ptr2, 0);
   if (ptr2 == NULL) {
      printf("Memory reallocation failed.\n");
      exit(1);
   }
   printf("Memory reallocated successfully.\n");

   return 0;  
}