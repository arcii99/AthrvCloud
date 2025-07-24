//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* ptr;
   int size, i, sum = 0;

   printf("Enter the size of the array: ");
   scanf("%d", &size);

   ptr = (int*) malloc(size * sizeof(int));   // Memory allocation

   if(ptr == NULL)                     
   {
      printf("Memory allocation failed!\n");
      exit(0);
   }

   printf("Enter %d numbers: ", size);

   for(i = 0;i < size; i++)
   {
      scanf("%d", ptr + i);     // Adding values to the allocated memory
      sum += *(ptr + i);        //Calculating sum of the array
   }

   printf("The entered array is: ");
   for(i = 0; i < size; i++)
      printf("%d ", *(ptr+i));

   printf("\nThe sum of the entered array is: %d", sum);

   free(ptr);                   // Deallocating the memory

   return 0;    
}