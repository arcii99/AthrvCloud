//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>

/* This program sorts an array using the bubble sort algorithm */

void bubbleSort(int arr[], int n) {
  int i, j, temp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Original Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  bubbleSort(arr, n);
  
  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}