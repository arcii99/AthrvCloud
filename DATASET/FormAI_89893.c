//FormAI DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>

int main() {
  int arr[] = {5, 3, 1, 9, 8, 2, 4, 7, 6}; // array to be sorted
  int n = sizeof(arr) / sizeof(arr[0]);
  int i, j, temp;

  // bubble sort algorithm
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // display sorted array
  printf("Sorted array:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}