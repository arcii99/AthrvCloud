//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* ptr;
   int size = 5;
   int i;
   
   printf("Memory allocation for %d integers\n", size);
   ptr = (int*) malloc(size * sizeof(int));
   
   if(ptr == NULL) {
      printf("Memory allocation failed\n");
      exit(0);
   }
   
   for(i = 0; i < size; i++) {
      *(ptr + i) = i + 1;
   }
   
   printf("Printing the %d integers allocated dynamically\n", size);
   for(i = 0; i < size; i++) {
      printf("%d\n", *(ptr + i));
   }
   
   size = 10;
   
   printf("Changing the size of allocated memory to %d integers\n", size);
   ptr = realloc(ptr, size * sizeof(int));
   
   if(ptr == NULL) {
      printf("Memory reallocation failed\n");
      exit(0);
   }
   
   for(i = 5; i < size; i++) {
      *(ptr + i) = i + 1;
   }
   
   printf("Printing the %d integers allocated dynamically\n", size);
   for(i = 0; i < size; i++) {
      printf("%d\n", *(ptr + i));
   }
   
   free(ptr);

   return 0;
}