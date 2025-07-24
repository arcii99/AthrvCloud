//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

int linear_search(int arr[], int size, int key) {
  int i;

  for (i = 0; i < size; i++) {
    if (arr[i] == key)
      return i;
  }

  return -1;
}


int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int search_key = 6;

  printf("Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  int index = linear_search(arr, size, search_key);

  if (index == -1) {
    printf("Key %d not found in the array.\n", search_key);
  } else {
    printf("Key %d found at index %d in the array.\n", search_key, index);
  }

  return 0;
}