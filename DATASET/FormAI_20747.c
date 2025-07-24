//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* ptr = NULL;
   int i, num;

   printf("Enter number of integers: ");
   scanf("%d", &num);

   printf("Allocating memory...\n\n");
   ptr = (int*) malloc(num * sizeof(int));

   if(ptr == NULL) {
      printf("Memory allocation failed! Exiting...\n");
      exit(1);
   }

   for(i = 0; i < num; i++) {
      printf("Enter an integer: ");
      scanf("%d", ptr + i);
   }

   printf("\nPrinting the integers from memory:\n\n");

   for(i = 0; i < num; i++)
      printf("Integer %d: %d\n", i+1, *(ptr + i));

   printf("\nFreeing up the allocated memory...\n\n");

   free(ptr);
   
   printf("Memory released successfully!\n");
   return 0;
}