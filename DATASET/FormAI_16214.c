//FormAI DATASET v1.0 Category: Memory management ; Style: protected
/* 
   The following program demonstrates an example of C Memory management in a protected style. 
   It creates a table of integers using malloc function and then it frees the memory using free function 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num, i, *ptr, sum = 0;
	
   printf("Enter number of elements: ");
   scanf("%d", &num);

   ptr = (int*) malloc(num * sizeof(int)); // Allocate memory using malloc function

   if(ptr == NULL)                     
   {
       printf("Error! Memory is not allocated.\n");
       exit(0);
   }

   // Inputting elements of the memory allocated
   printf("Enter elements of array: ");
   for(i = 0; i < num; ++i)
   {
       scanf("%d", ptr + i);
       sum += *(ptr + i);
   }

   printf("Sum = %d\n", sum);

   free(ptr); // Free the memory using free function

   return 0;
}