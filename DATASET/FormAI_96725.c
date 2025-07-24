//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include<stdio.h>

int findIndex(int arr[], int size, int key);

int main()
{
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int key, index;
  printf("Enter the number you want to search: ");
  scanf("%d",&key);
  index = findIndex(arr, 10, key);
  if(index == -1)
    printf("Number not found in the array!");
  else
    printf("The number %d was found at index %d of the array.", key, index);
  return 0;
}

int findIndex(int arr[], int size, int key)
{
  int low = 0, high = size - 1, mid;
  while(low <= high)
  {
    mid = (low + high) / 2;
    if(arr[mid] == key)
      return mid;
    else if(arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}