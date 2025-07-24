//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    int pi = i + 1;
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main() {
  srand(time(NULL));
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand();
  }
  clock_t start = clock();
  quick_sort(arr, 0, SIZE - 1);
  clock_t end = clock();
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time elapsed: %f seconds\n", elapsed_time);
  return 0;
}