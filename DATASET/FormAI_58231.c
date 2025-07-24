//FormAI DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int *ptr;    //declaration of integer pointer
   int size, i;
   printf("Enter the number of integers you want to store in the memory: ");
   scanf("%d", &size);   //taking input from user
   
   ptr = (int*) malloc(size * sizeof(int));   //allocating memory dynamically
   
   if(ptr == NULL)   //checking if memory is allocated or not
   {
      printf("Memory allocation failed");
      exit(0);   //if memory not allocated then program will exit
   }
   else
   {
      printf("Memory allocation successful\n");
   }
   
   //entering data into the memory
   for(i=0; i<size; i++)
   {
      printf("Enter an integer: ");
      scanf("%d", ptr+i);   //taking input into the allocated memory block
   }
   
   //displaying the data
   printf("\nData stored in memory: ");
   for(i=0; i<size; i++)
   {
      printf("%d ", *(ptr+i));
   }
   
   free(ptr);   //freeing the memory block
   
   printf("\nMemory freed successfully\n");
   
   return 0;
}