//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>

int main() {
   int n, i, *ptr, sum = 0; // Define variables

   printf("Enter number of integers: ");
   scanf("%d", &n);

   ptr = (int*) malloc(n * sizeof(int)); // Use malloc to allocate memory

   if(ptr == NULL) { // Check if memory allocation failed
      printf("Error! memory not allocated.");
      exit(0);
   }

   printf("Enter %d integers:\n", n);
   for(i = 0; i < n; i++) {
      scanf("%d", ptr + i); // Input numbers
      sum += *(ptr + i); // Calculate sum
   }

   free(ptr); // Free allocated memory

   printf("Sum = %d", sum); // Output sum

   return 0;
}