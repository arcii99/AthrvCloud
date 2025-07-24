//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, n;
   int *arr;
   
   printf("Enter the number of elements: ");
   scanf("%d", &n);
   
   arr = (int*) malloc(n * sizeof(int)); // allocating memory
   
   if(arr == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
   }
   
   printf("Enter %d integers:\n", n);
   
   for(i = 0; i < n; i++)
      scanf("%d", arr + i);
   
   printf("The entered integers are: ");
   
   for(i = 0; i < n; i++)
      printf("%d ", *(arr + i));
   
   free(arr); // deallocating memory
   
   return 0;
}