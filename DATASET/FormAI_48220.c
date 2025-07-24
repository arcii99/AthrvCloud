//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
  int i, j, temp;
  int arr[SIZE];

  // Initializes array with random values
  srand(time(NULL));
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand();
  }

  // Bubble sort - measure time elapsed
  clock_t start = clock();
  for (i = 0; i < SIZE - 1; i++) {
    for (j = 0; j < SIZE - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  clock_t end = clock();
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Print sorted array and elapsed time
  printf("Sorted array: ");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nElapsed time: %f seconds", elapsed_time);
  return 0;
}