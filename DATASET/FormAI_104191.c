//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, i, *ptr, sum = 0;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   ptr = (int*) malloc(n * sizeof(int)); // allocating dynamic memory using malloc

   if(ptr == NULL)  { // if memory not allocated, exit
      printf("Error! memory not allocated.");
      exit(0);
   }

   printf("Enter elements of the array: ");
   for(i = 0; i < n; ++i) {
      scanf("%d", ptr + i);
      sum += *(ptr + i); // summing up all the elements
   }

   printf("Sum = %d", sum);

   free(ptr); // freeing up the allocated memory

   return 0;
}