//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) 
      return mid;
    else if (arr[mid] < key) 
      low = mid + 1;
    else 
      high = mid - 1;
  }
  return -1;
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 8;
  int result = binarySearch(arr, 0, n - 1, key);
  if (result == -1) {
      printf("Element not found\n");
  }
  else {
      printf("Element found at index %d\n", result);
  }
  return 0;
}