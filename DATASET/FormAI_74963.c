//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {

   /* Allocate space for three integers */
   int* ptr = (int*) malloc(3 * sizeof(int));
   
   /* Check if malloc succeeded in allocating memory */
   if(ptr == NULL)                     
   {
      printf("Memory allocation failed!");
      exit(1);
   }
   
   /* Assign values to the integers */
   *(ptr + 0) = 10;
   *(ptr + 1) = 20;
   *(ptr + 2) = 30;
   
   /* Print the values */
   for(int i=0; i<3; i++) {
      printf("%d ", *(ptr + i));
   }
   
   /* Reallocate memory for six integers */
   ptr = (int*) realloc(ptr, 6 * sizeof(int));
   
   /* Check if realloc succeeded in allocating memory */
   if(ptr == NULL)                     
   {
      printf("Memory allocation failed!");
      exit(1);
   }
   
   /* Assign values to the new integers */
   *(ptr + 3) = 40;
   *(ptr + 4) = 50;
   *(ptr + 5) = 60;
   
   /* Print the values */
   for(int i=0; i<6; i++) {
      printf("%d ", *(ptr + i));
   }
   
   /* Free the allocated memory */
   free(ptr);

   return 0;
}