//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int key) {
  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, key, result;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the key to search: ");
  scanf("%d", &key);

  result = linear_search(arr, n, key);

  if (result == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index: %d\n", result);
  }

  return 0;
}