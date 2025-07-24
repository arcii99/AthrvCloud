//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main()
{
   int *array;
   array = (int*) malloc(ARRAY_SIZE * sizeof(int));
   
   if(array == NULL)
   {
      printf("Memory allocation failed");
      return 1;
   }
   
   for(int i = 0; i < ARRAY_SIZE; i++)
   {
      array[i] = i;
   }
   
   long long sum = 0;
   
   for(int i = 0; i < ARRAY_SIZE; i++)
   {
      sum += array[i];
   }
   
   printf("Sum = %lld\n", sum);
   
   free(array);
   return 0;
}