//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>

int main() {
  int i, j, temp;
  int arr[] = {5, 3, 1, 9, 8, 2, 7, 4, 6};

  printf("Unsorted array: ");
  for (i = 0; i < 9; i++) {
    printf("%d ", arr[i]);
  }

  printf("\nSorting...\n");

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8-i; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("\nSorted array: ");
  for (i = 0; i < 9; i++) {
    printf("%d ", arr[i]);
  }

  printf("\nHappy Valentine's Day!");

  return 0;
}