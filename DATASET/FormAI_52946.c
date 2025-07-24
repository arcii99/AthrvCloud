//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr1, *ptr2, *ptr3, *ptr4;
   int size1 = 5, size2 = 8, size3 = 2, size4 = 10;

   ptr1 = (int*)malloc(size1 * sizeof(int)); // allocate memory block of 20 bytes and return pointer to the first byte
   if (ptr1 == NULL) { // check if the allocation was successful
      printf("Memory allocation error!\n");
      return -1;
   }

   ptr2 = (int*)calloc(size2, sizeof(int)); // allocate memory block of 32 bytes and initialize to 0
   if (ptr2 == NULL) { // check if the allocation was successful
      printf("Memory allocation error!\n");
      return -1;
   }

   ptr3 = (int*)realloc(ptr1, size3 * sizeof(int)); // resize the memory block pointed to by ptr1 to 8 bytes
   if (ptr3 == NULL) { // check if the reallocation was successful
      printf("Memory reallocation error!\n");
      free(ptr1); // free the memory block pointed to by ptr1
      return -1;
   }

   ptr4 = (int*)aligned_alloc(16, size4 * sizeof(int)); // allocate memory block of 160 bytes with 16-byte alignment
   if (ptr4 == NULL) { // check if the allocation was successful
      printf("Memory allocation error!\n");
      free(ptr1); // free the memory blocks pointed to by ptr1, ptr2, and ptr3
      free(ptr2);
      free(ptr3);
      return -1;
   }

   printf("Memory blocks allocated:\n");
   printf("ptr1: %p, size1: %d bytes\n", ptr1, size1 * sizeof(int));
   printf("ptr2: %p, size2: %d bytes\n", ptr2, size2 * sizeof(int));
   printf("ptr3: %p, size3: %d bytes\n", ptr3, size3 * sizeof(int));
   printf("ptr4: %p, size4: %d bytes with 16-byte alignment\n", ptr4, size4 * sizeof(int));

   free(ptr1); // free the memory blocks pointed to by ptr1, ptr2, ptr3, and ptr4
   free(ptr2);
   free(ptr3);
   free(ptr4);

   return 0;
}