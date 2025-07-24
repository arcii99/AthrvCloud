//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>

// Implementing linear search algorithm in C

int linear_search(int arr[], int len, int key) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == key) {
      return i;  // We found the key at this index, return it
    }
  }
  return -1;  // Key does not exist in the array
}

int main() {
  int arr[] = {12, 65, 23, 47, 7, 34, 52, 80};
  int len = sizeof(arr) / sizeof(arr[0]);
  int key = 47;

  int result = linear_search(arr, len, key);

  if (result == -1) {
    printf("Key not found in the array\n");
  } else {
    printf("Key found at index %d\n", result);
  }
  return 0;
}