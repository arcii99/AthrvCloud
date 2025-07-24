//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* ptr; // declaring a pointer to int
   int i, n;
   
   printf("Enter number of elements: ");
   scanf("%d", &n); // taking input from user
   
   ptr = (int*)malloc(n * sizeof(int)); // allocating memory using malloc
   
   if(ptr == NULL) { // checking if the memory was allocated successfully
      printf("Error! Memory not allocated.");
      exit(0); // exiting the program if memory allocation fails
   }

   printf("Enter elements: ");
   
   for(i = 0; i < n; i++)
      scanf("%d", ptr + i); // taking input values from user
   
   printf("Entered elements are: ");
   
   for(i = 0; i < n; i++)
      printf("%d ", *(ptr + i)); // displaying the input values
   
   free(ptr); // deallocating the memory
   
   return 0;
}