//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>

void printReverse(int arr[], int size, int index)
{
  if(index >= size)
    return;
    
  printReverse(arr, size, index + 1);
  printf("%d ", arr[index]);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original Array: ");
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  printf("\nReversed Array: ");
  printReverse(arr, size, 0);

  return 0;
}