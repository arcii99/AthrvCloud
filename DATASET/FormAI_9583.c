//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num;
   int *arr;

   // Get the number of integers to allocate from user
   printf("Enter the number of integers to allocate: ");
   scanf("%d", &num);

   // Allocate memory dynamically for an array of integers
   arr = (int *) malloc(num * sizeof(int));

   // Check if memory allocation was successful
   if (arr == NULL) {
      printf("Memory allocation failed!");
      exit(1);
   }

   // Get integers from user and store them in array
   printf("Enter %d integers:\n", num);
   for (int i = 0; i < num; i++) {
      scanf("%d", &arr[i]);
   }

   // Print the integers stored in the array
   printf("The integers you entered are:\n");
   for (int i = 0; i < num; i++) {
      printf("%d ", arr[i]);
   }

   // Free the memory allocated for the array
   free(arr);

   return 0;
}