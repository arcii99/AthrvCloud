//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main() {
   int size, *ptr, sum = 0;

   printf("Enter the number of integers: ");
   scanf("%d", &size);

   ptr = (int*)malloc(size * sizeof(int)); // Allocating memory dynamically

   if(ptr == NULL) { // Checking whether the memory is allocated successfully or not
      printf("Error! Memory not allocated.");
      exit(0);
   }

   printf("Enter the integers:\n");

   for(int i = 0 ; i < size ; i++){
      scanf("%d", ptr + i);
      sum += *(ptr + i); // Adding all the integers
   }

   printf("The integers are: ");

   for(int i = 0 ; i < size ; i++)
      printf("%d ", *(ptr + i)); // Printing all the integers

   printf("\nSum of the integers is %d", sum);

   free(ptr); // Freeing the memory

   return 0;
}