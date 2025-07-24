//FormAI DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>

void sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        printf("Swapped %d and %d\n", arr[i], arr[j]);
      }
    }
  }
  printf("Array sorted successfully!");
}

int main() {
  int arr[5] = {56, 7, 98, 23, 45};
  printf("Original array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  sort(arr, 5);
  printf("Sorted array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}