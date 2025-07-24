//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
//I am excited to showcase a unique C memory management example program that demonstrates how to allocate and deallocate memory dynamically.

#include <stdio.h>
#include <stdlib.h> //needed for malloc and free functions

int main()
{
  int n;
  int sum = 0;

  printf("How many integers would you like to sum up?\n");
  scanf("%d", &n);

  //dynamically allocate memory for array of n integers
  int *arr = (int*)malloc(n * sizeof(int));

  //if memory allocation was successful
  if(arr != NULL)
  {
    printf("Great! You now have space for %d integers.\n", n);

    //prompt user to enter n integers
    for(int i = 0; i < n; i++)
    {
      printf("Enter the %d-th integer: ", i+1);
      scanf("%d", &arr[i]);
      sum += arr[i];
    }

    printf("The sum of %d integers is %d.\n", n, sum);

    //deallocate memory allocated by malloc
    free(arr);

    printf("Memory has been successfully deallocated.\n");
  }
  else //if memory allocation failed
  {
    printf("Memory allocation failed. Please try again later.\n");
  }

  return 0;
}