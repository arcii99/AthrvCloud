//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, *ptr, sum = 0;

  /* Allocate Memory */
  ptr = (int*) malloc(10 * sizeof(int));

  /* Check if Memory Allocation is Successful */
  if(ptr == NULL)                     
  {
      printf("Failed to allocate memory!");
      exit(0);
  }

  /* Input Elements */
  printf("Enter elements:\n");
  for(i = 0; i < 10; i++)
  {
      scanf("%d", ptr + i);
      sum += *(ptr + i);
  }

  /* Display Elements */
  printf("Elements are:\n");
  for(i = 0; i < 10; i++)
      printf("%d\n", *(ptr + i));
  printf("Sum of elements is %d\n", sum);

  /* Free the Memory */
  free(ptr);

  return 0;
}