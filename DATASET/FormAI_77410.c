//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
   int i,n, *ptr, sum = 0; //declaring variables

   printf("Enter number of elements: ");
   scanf("%d", &n);

   ptr = (int*) malloc(n * sizeof(int)); //allocating dynamic memory 

   if(ptr == NULL)                     
   {
      printf("Error! memory not allocated.");
      exit(0);
   }

   printf("Enter elements of array: ");
   for(i = 0; i < n; i++)               
   {
      scanf("%d", ptr+i);
      sum += *(ptr+i);                   //calculating sum of all elements
   }

   printf("Sum = %d", sum);              

   free(ptr);                             //deallocating dynamic memory

   return 0;
}