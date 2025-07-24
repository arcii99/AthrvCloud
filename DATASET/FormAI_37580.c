//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int num, i, *ptr;
  printf("Enter the number of terms to be generated in the Fibonacci Sequence: ");
  scanf("%d", &num);

  ptr = (int*) malloc(num * sizeof(int));

  // Initial two terms
  *(ptr + 0) = 0;
  *(ptr + 1) = 1;

  for(i=2; i<num; i++) 
  {
      /*
      *  cryptic style calculation using exclusive OR
      */
      *(ptr + i) = *(ptr + (i-1)) ^ *(ptr + (i-2));
  }

  printf("Fibonacci Sequence: \n");
  
  for(i=0; i<num; i++)
  {
      /*
      *  cryptic style printing with alternating modulo operation
      */
      if(i%2)
        printf("%d \n", *(ptr + i));
      else
        printf("%d ", *(ptr + i));
  }

  free(ptr);

  return 0;
}