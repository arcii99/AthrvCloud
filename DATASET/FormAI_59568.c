//FormAI DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, *ptr, i, sum = 0;

   printf("Enter number of elements: ");
   scanf("%d", &n);

   ptr = (int*) malloc(n * sizeof(int));

   if (ptr == NULL) {
      printf("Error! memory not allocated.");
      exit(0);
   }

   printf("Enter elements of array:");

   for(i = 0; i < n; ++i) {
      scanf("%d", ptr + i);
      sum += *(ptr + i);
   }

   printf("Sum = %d", sum);

   free(ptr);
   return 0;
}