//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* ptr;

   // allocate memory for 5 integers dynamically
   ptr = (int*)malloc(5 * sizeof(int));

   // check if memory is successfully allocated
   if (ptr == NULL)                     
   {
       printf("Memory allocation failed\n");
       exit(0);
   }

   // store values in dynamically allocated memory
   for (int i = 0; i < 5; i++)
   {
      ptr[i] = i + 1;
   }

   // print values stored in dynamically allocated memory
   printf("Values stored in dynamically allocated memory:\n");
   for (int i = 0; i < 5; i++)
   {
      printf("%d\n", ptr[i]);
   }

   // reallocate memory to store 10 integers dynamically
   ptr = (int*)realloc(ptr, 10 * sizeof(int));

   // check if memory is successfully reallocated
   if (ptr == NULL)                     
   {
       printf("Memory reallocation failed\n");
       exit(0);
   }

   // store values in reallocated memory
   for (int i = 5; i < 10; i++)
   {
      ptr[i] = i + 1;
   }

   // print values stored in reallocated memory
   printf("Values stored in reallocated memory:\n");
   for (int i = 0; i < 10; i++)
   {
      printf("%d\n", ptr[i]);
   }

   // free dynamically allocated memory
   free(ptr);

   return 0;
}