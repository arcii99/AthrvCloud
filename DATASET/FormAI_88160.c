//FormAI DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr;          /* Declare pointer */
  int num, i, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &num);

  ptr = (int*) malloc(num * sizeof(int)); /* Allocate memory using malloc() */

  /* Check if memory has been successfully allocated */
  if(ptr == NULL)                     
  {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements: ");
  for(i = 0; i < num; ++i)             /* Input elements */
  {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);            /* Print sum */

  /* Deallocate memory using free() */
  free(ptr);

  return 0;
}