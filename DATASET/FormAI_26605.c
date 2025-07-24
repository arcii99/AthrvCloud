//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  const int n = 10000;
  int arr[n];

  // Fill the array with random integers
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  // Benchmarking
  clock_t start = clock();
  bubble_sort(arr, n);
  clock_t end = clock();

  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array in %f seconds", time_taken);

  return 0;
}