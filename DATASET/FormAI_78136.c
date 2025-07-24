//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

void binary_search(int arr[], int low, int high, int target) {
  int mid = (low + high) / 2;

  if (arr[mid] == target) {
    printf("Target %d found at index %d!\n", target, mid);
    return;
  }

  if (low >= high) {
    printf("Target %d not found in array!\n", target);
    return;
  }

  if (arr[mid] > target) {
    binary_search(arr, low, mid - 1, target);
  } else {
    binary_search(arr, mid + 1, high, target);
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 13;

  binary_search(arr, 0, n - 1, target);

  return 0;
}