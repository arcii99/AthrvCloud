//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
  int temp = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertion_sort(int arr[], int n) {
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

void selection_sort(int arr[], int n) {
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

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {2, 5, 1, 6, 9, 3, 8, 4, 7, 0};
  int n = 10;

  printf("Original Array: ");
  print_array(arr, n);

  printf("Bubble Sort: ");
  bubble_sort(arr, n);
  print_array(arr, n);

  printf("Insertion Sort: ");
  insertion_sort(arr, n);
  print_array(arr, n);

  printf("Selection Sort: ");
  selection_sort(arr, n);
  print_array(arr, n);

  return 0;
}