//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
  for (int i = 0; i < n; i++)
    if (arr[i] == x)
      return i;
  return -1;
}

int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x)
      return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Array: ");
  for (int i=0; i<n; i++)
    printf("%d ",arr[i]);
  printf("\n");
  
  int x = 10;
  int result = linearSearch(arr, n, x);
  (result == -1)
    ? printf("Element %d is not present in array\n", x)
    : printf("Element %d is present at index %d\n", x, result);
    
  result = binarySearch(arr, 0, n-1, x);
  (result == -1)
    ? printf("Element %d is not present in array\n", x)
    : printf("Element %d is present at index %d\n", x, result);
    
  return 0;
}