//FormAI DATASET v1.0 Category: Sorting ; Style: rigorous
#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    // Last i elements are already sorted
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        // swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}