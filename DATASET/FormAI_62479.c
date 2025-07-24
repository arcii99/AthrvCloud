//FormAI DATASET v1.0 Category: Sorting ; Style: bold
#include <stdio.h>

void bubbleSort(int arr[], int n);

int main() {
  int arr[10] = {5, 3, 2, 8, 1, 4, 7, 6, 10, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  bubbleSort(arr, n);

  printf("\n\nAfter sorting:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}