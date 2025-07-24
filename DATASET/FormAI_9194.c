//FormAI DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>

int binarySearch(int arr[], int searchElement, int first, int last) 
{
  while (first <= last) {
    int middle = (first + last) / 2;
    if (arr[middle] == searchElement)
      return middle;
    else if (arr[middle] < searchElement)
      first = middle + 1;
    else
      last = middle - 1;
  }
  return -1;
}

int main() 
{
  int arr[] = {2, 5, 7, 8, 10, 12};
  int searchElement = 10;
  int arrLength = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, searchElement, 0, arrLength - 1);
  if (result == -1)
    printf("Element is not present in array.");
  else
    printf("Element is present at index %d in the array.", result);
  return 0;
}