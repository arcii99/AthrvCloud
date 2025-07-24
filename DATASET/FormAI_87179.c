//FormAI DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
  int i, j, temp;

  for(i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int arr[10] = { 4, 2, 1, 5, 6, 10, 8, 9, 7, 3 };
  printf("Unsorted array: ");

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  bubbleSort(arr, 10);

  printf("\nSorted array: ");

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}