//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
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
  int arr[5] = {5, 4, 3, 2, 1};
  int i;

  printf("Array before sorting: ");
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  bubble_sort(arr, 5);

  printf("\nArray after sorting: ");
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}