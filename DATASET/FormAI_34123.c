//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {12, 7, 10, 5, 9, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  bubble_sort(arr, n);
  printf("Array Sorted in Ascending Order:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}