//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>

int main() {
  int arr[] = {5, 2, 8, 3, 1};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }

  // Bubble sort
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap values using a temporary variable
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\nAfter sorting: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}