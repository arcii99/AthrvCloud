//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

// This program sorts an array of integers in ascending order using the bubble sort algorithm.

int main() {
  int arr[] = {6, 3, 8, 5, 2, 7, 4, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i, j, temp;

  // Print the original array
  printf("Original array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  // Sort the array using bubble sort algorithm
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // Print the sorted array
  printf("\nSorted array in ascending order: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}