//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* num; 

   // allocate memory for one integer
   num = (int*) malloc(sizeof(int));

   if(num == NULL) { // check for failure
      printf("Memory allocation failed. Exiting program.");
      exit(1);
   }

   *num = 42; // store value 42 in allocated memory

   printf("The value stored in num is %d\n", *num);

   // increase the allocated memory space to store an array of integers
   num = (int*) realloc(num, 5 * sizeof(int));

   if(num == NULL) { // check for failure
      printf("Memory allocation failed. Exiting program.");
      exit(1);
   }

   // store values in newly allocated memory space
   for(int i = 0; i < 5; i++) {
      num[i] = i + 1;
   }

   printf("The values in num are: ");
   for(int i = 0; i < 5; i++) {
      printf("%d ", num[i]);
   }
   printf("\n");

   free(num); // deallocate memory
   
   return 0;
}