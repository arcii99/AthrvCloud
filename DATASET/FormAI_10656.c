//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  int i;
  for(i=0; i<n; i++) {
    if(arr[i] == x) {
      return i;   // element found
    }
  }
  return -1;   // element not found
}

int main() {
  int arr[] = {1, 5, 3, 9, 8, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 9;
  int result = linear_search(arr, n, x);
  if(result == -1) {
    printf("Element not found.\n");
  }
  else {
    printf("Element found at index %d.\n", result);
  }
  return 0;
}