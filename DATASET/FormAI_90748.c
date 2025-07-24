//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>

//Recursive Function to print an array
void printArray(int arr[], int size)
{
  if (size == 0)
    return;
  else
  {
    printArray(arr, size - 1);
    printf("%d ", arr[size - 1]);
  }
}

//Recursive Function to find the maximum value in an array
int findMax(int arr[], int size)
{
  if (size == 1)
    return arr[0];

  //Recursive call to find the max value
  int max = findMax(arr, size - 1);

  if (max > arr[size - 1])
    return max;
  else
    return arr[size - 1];
}

int main()
{
  int arr[5] = {3, 5, 10, 2, 7};

  printf("The initial array is: ");
  printArray(arr, 5);

  int max = findMax(arr, 5);
  printf("\nThe maximum value in the array is: %d", max);

  return 0;
}