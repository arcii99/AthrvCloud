//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void selection_sort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

void insertion_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
      while (arr[i] <= pivot && i < high) {
        i++;
      }
      while (arr[j] > pivot) {
        j--;
      }
      if (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    quick_sort(arr, low, j - 1);
    quick_sort(arr, j + 1, high);
  }
}

int main() {
  int arr[ARRAY_SIZE];
  srand(time(NULL));

  printf("Generating random array of size %d...\n", ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand();
  }

  clock_t start = clock();
  selection_sort(arr, ARRAY_SIZE);
  clock_t end = clock();
  double selection_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

  start = clock();
  insertion_sort(arr, ARRAY_SIZE);
  end = clock();
  double insertion_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

  start = clock();
  quick_sort(arr, 0, ARRAY_SIZE - 1);
  end = clock();
  double quick_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Selection sort took %f seconds\n", selection_sort_time);
  printf("Insertion sort took %f seconds\n", insertion_sort_time);
  printf("Quick sort took %f seconds\n", quick_sort_time);

  return 0;
}