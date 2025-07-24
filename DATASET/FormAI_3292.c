//FormAI DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int binary_search(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) {
      return binary_search(arr, l, mid - 1, x);
    }
    return binary_search(arr, mid + 1, r, x);
  }
  return -1;
}

int main() {
  int arr[] = { 2, 4, 5, 8, 10 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 5;
  
  printf("Linear Search:\n");
  int result = linear_search(arr, n, x);
  (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
  
  printf("\nBinary Search:\n");
  int result2 = binary_search(arr, 0, n - 1, x);
  (result2 == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result2);
  return 0;
}