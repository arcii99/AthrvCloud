//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>

int main() {

  printf("Welcome to my Sorting Program!\n");

  int arr[] = {10, 6, 15, 20, 2, 13};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Initial Array: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Bubble sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Array after Bubble Sorting: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Selection sort
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }

  printf("Array after Selection Sorting: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Insertion sort
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }

  printf("Array after Insertion Sorting: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Thank you for using my Sorting Program!");

  return 0;
}