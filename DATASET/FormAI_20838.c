//FormAI DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>

int main() {
  int arr[] = {5, 3, 8, 2, 1, 4}; // array to sort
  int n = sizeof(arr) / sizeof(int); // size of array

  printf("Unsorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // bubble sort algorithm
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}