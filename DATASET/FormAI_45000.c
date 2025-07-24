//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

int main() {
  int arr[] = { 9, 3, 7, 1, 5, 8, 2, 6, 4 };
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // sort the array in ascending order using bubble sort
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Sorted array in ascending order: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // sort the array in descending order using selection sort
  for (int i = 0; i < len - 1; i++) {
    int max_index = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] > arr[max_index]) {
        max_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[max_index];
    arr[max_index] = temp;
  }

  printf("Sorted array in descending order: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}