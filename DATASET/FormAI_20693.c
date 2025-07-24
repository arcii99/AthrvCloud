//FormAI DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* ptr;
   int n, i;

   printf("Enter number of elements: ");
   scanf("%d", &n);

   ptr = (int*)calloc(n, sizeof(int));
   if(ptr == NULL) {
      printf("Error! Memory not allocated.");
      exit(0);
   }

   for(i = 0; i < n; i++) {
      printf("Enter element %d: ", i+1);
      scanf("%d", ptr+i);
   }

   printf("Elements are: ");
   for(i = 0; i < n; i++)
      printf("%d ", *(ptr+i));

   free(ptr);
   return 0;
}