//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int temp, i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr1[] = { 5, 8, 3, 2, 7, 10, 1, 9, 4, 6 };
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  printf("Original array (unsorted):\n");
  for (int i = 0; i < n1; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  bubbleSort(arr1, n1);
  printf("Array sorted with Bubble sort:\n");
  for (int i = 0; i < n1; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  int arr2[] = { 5, 8, 3, 2, 7, 10, 1, 9, 4, 6 };
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  insertionSort(arr2, n2);
  printf("Array sorted with Insertion sort:\n");
  for (int i = 0; i < n2; i++) {
    printf("%d ", arr2[i]);
  }
  printf("\n");

  int arr3[] = { 5, 8, 3, 2, 7, 10, 1, 9, 4, 6 };
  int n3 = sizeof(arr3) / sizeof(arr3[0]);

  selectionSort(arr3, n3);
  printf("Array sorted with Selection sort:\n");
  for (int i = 0; i < n3; i++) {
    printf("%d ", arr3[i]);
  }
  printf("\n");
  return 0;
}