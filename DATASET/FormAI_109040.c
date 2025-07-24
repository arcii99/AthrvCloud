//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a[100000], i, j, temp;
  clock_t start, end;
  double cpu_time_used;

  srand(time(NULL)); // Set seed for random number generation

  for (i = 0; i < 100000; i++) {
    a[i] = rand() % 1000 + 1; // Fill array with random integers between 1 and 1000
  }

  // Bubble Sort - You know, the one that no one uses
  start = clock();
  for (i = 0; i < 100000; i++) {
    for (j = 0; j < 99999 - i; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Bubble Sort took %f seconds to execute.\n", cpu_time_used);

  // Quicksort - The fast one (if implemented correctly)
  for (i = 0; i < 100000; i++) {
    a[i] = rand() % 1000 + 1; // Refill array with random integers between 1 and 1000
  }

  start = clock();
  quicksort(a, 0, 99999);
  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Quicksort took %f seconds to execute.\n", cpu_time_used);

  return 0;
}

void quicksort(int *a, int start, int end) {
  if (start < end) {
    int pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
  }
}

int partition(int *a, int start, int end) {
  int pivot = a[end];
  int i, j;

  i = start - 1;

  for (j = start; j <= end - 1; j++) {
    if (a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[i + 1], &a[end]);
  return i + 1;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}