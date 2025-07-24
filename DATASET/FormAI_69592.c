//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void selection_sort(int arr[], int n) {
  int i, j, min_index;
  for (i = 0; i < n-1; i++) {
    min_index = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  int arr[100000], i, n = 100000;
  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }

  start = clock();
  bubble_sort(arr, n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken for bubble sort: %f seconds\n", cpu_time_used);

  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }

  start = clock();
  selection_sort(arr, n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken for selection sort: %f seconds\n", cpu_time_used);

  return 0;
}