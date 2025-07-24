//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>

void bubbleSort(int arr[], int n) {
  // Standard Bubble Sort Algorithm
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {10, 3, 5, 16, 9, 7, 1, 2, 8, 4};
  
  int n = sizeof(arr)/sizeof(arr[0]);
  
  printf("Before sorting: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  bubbleSort(arr, n);
  
  printf("After sorting: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}