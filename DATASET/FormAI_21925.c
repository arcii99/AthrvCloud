//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>

int main() {
   // using malloc to allocate memory
   int* ptr = (int*) malloc(5 * sizeof(int));

   
   if (ptr == NULL) {
       printf("Memory allocation failed");
       exit(0);
   }
   else {
       printf("Memory allocation successful\n");
       
       // using realloc to allocate additional memory
       int* ptr2 = (int*) realloc(ptr, 10 * sizeof(int));
       
       if (ptr2 == NULL) {
           printf("Memory allocation failed");
           exit(0);
       }
       else {
           printf("Additional memory allocation successful\n");
           
           // freeing allocated memory
           free(ptr2);
           printf("Memory Freed");
       }
   }
   return 0;
}