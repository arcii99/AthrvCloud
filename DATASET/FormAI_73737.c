//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n; // declare integer variable
   printf("Enter the number of integers to be allocated: ");
   scanf("%d", &n); // read input from user

   // allocate memory dynamically
   int *ptr = (int*)malloc(n * sizeof(int));

   // check for successful allocation of memory
   if(ptr == NULL) {
      printf("Memory allocation failed. Exiting program...");
      exit(0);
   }

   // initialize allocated memory with random values
   for(int i=0; i<n; i++) {
      *(ptr+i) = rand() % 100;
   }

   // display the initial values
   printf("\nThe initial values in the dynamically allocated memory: \n");
   for(int i=0; i<n; i++) {
      printf("%d ", *(ptr+i));
   }

   // prompt the user to update the values
   printf("\nEnter the new values for the dynamically allocated memory: \n");
   for(int i=0; i<n; i++) {
      scanf("%d", (ptr+i));
   }

   // display the updated values
   printf("\nThe updated values in the dynamically allocated memory: \n");
   for(int i=0; i<n; i++) {
      printf("%d ", *(ptr+i));
   }

   // deallocate the dynamically allocated memory
   free(ptr);
   printf("\nMemory has been deallocated. Exiting program...");

   return 0;
}