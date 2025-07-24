//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>

void selectionSort(int[], int);

int main() {
  int arr[] = {5, 2, 8, 3, 9, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  printf("Original array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  selectionSort(arr, n);
  
  printf("Sorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}

void selectionSort(int arr[], int n) {
  int min_idx;
  for(int i = 0; i < n-1; i++) {
    min_idx = i;
    for(int j = i+1; j < n; j++) {
      if(arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}