//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *ptr1, *ptr2, *ptr3, *ptr4;

   // allocate memory for pointers
   ptr1 = (int*)malloc(2*sizeof(int));
   ptr2 = (int*)calloc(3,sizeof(int));
   ptr3 = (int*)realloc(ptr2, 4*sizeof(int));
   ptr4 = (int*)malloc(2*sizeof(int));

   // check pointer values
   printf("Value of ptr1 = %p\n", ptr1);
   printf("Value of ptr2 = %p\n", ptr2);
   printf("Value of ptr3 = %p\n", ptr3);
   printf("Value of ptr4 = %p\n", ptr4);

   // free memory allocated to pointers
   free(ptr1);
   free(ptr3);
   free(ptr4);

   return 0;
}