//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr1, *ptr2, *ptr3, *ptr4, *ptr5;
 
   ptr1 = (int*)malloc(2*sizeof(int)); 
   ptr2 = (int*)malloc(3*sizeof(int)); 
   ptr3 = (int*)calloc(2, sizeof(int));  
   ptr4 = (int*)realloc(ptr2, 4*sizeof(int)); 
   ptr5 = (int*)realloc(ptr1, 3*sizeof(int)); 

   if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL || ptr5 == NULL) {
      printf("Error: Unable to allocate memory.\n");
      return 1;
   }
 
   printf("Addresses of allocated memory: \n");
   printf("ptr1 = %p\n", ptr1); 
   printf("ptr2 = %p\n", ptr2); 
   printf("ptr3 = %p\n", ptr3);
   printf("ptr4 = %p\n", ptr4);
   printf("ptr5 = %p\n", ptr5);

   free(ptr1);
   free(ptr2);
   free(ptr3);
   free(ptr4);
   free(ptr5);

   return 0;
}