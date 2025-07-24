//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, n;
   int *arr;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   // allocate memory for n integers
   arr = (int*) malloc(n * sizeof(int));

   // check if memory allocation was successful
   if(arr == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
   }

   // initialize array elements with user input
   for(i=0; i<n; i++) {
      printf("Enter element %d: ", i+1);
      scanf("%d", &arr[i]);
   }

   // print array elements
   printf("\nArray elements are:\n");
   for(i=0; i<n; i++) {
      printf("%d ", arr[i]);
   }

   // free allocated memory
   free(arr);

   return 0;
}