//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
  srand(time(NULL)); // Seed random number generator with current time
  int arr[ARRAY_SIZE];

  // Fill array with random numbers
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand();
  }

  // Start timer for benchmarking
  clock_t start = clock();

  // Perform bubble sort on array
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Stop timer and calculate elapsed time
  clock_t end = clock();
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Print sorted array and elapsed time
  printf("Sorted array:\n");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nElapsed time: %f seconds\n", elapsed_time);

  return 0;
}