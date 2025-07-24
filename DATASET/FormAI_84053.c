//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr, *ptr1;
   
   // allocate memory for the pointer
   ptr = (int*) malloc(10 * sizeof(int));
   
   if(ptr == NULL)                     
   {
      printf("Memory not allocated.\n");
      exit(0);
   }
   else
    {
      printf("Memory successfully allocated using malloc.\n");
    }

   // deallocate memory from ptr
   free(ptr);
   printf("Memory successfully deallocated using free.\n");

   // allocate memory using calloc
   ptr1 = (int*) calloc(5, sizeof(int));
   
   if(ptr1 == NULL)                     
   {
      printf("Memory not allocated.\n");
      exit(0);
   }
   else
    {
      printf("Memory successfully allocated using calloc.\n");
    }

   // deallocate memory from ptr1
   free(ptr1);
   printf("Memory successfully deallocated using free.\n");

   return 0;
}