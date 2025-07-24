//FormAI DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>

int main() {
  int arr[10] = {6, 2, 9, 5, 1, 8, 4, 7, 3, 0};
  int n = 10;

  printf("Original Array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  // Sort the array using bubble sort algorithm
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Sorted Array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}