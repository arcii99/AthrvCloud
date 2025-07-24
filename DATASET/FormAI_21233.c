//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_ITERATIONS 1000000
#define ARRAY_SIZE 1000

int main(void) {
  // Declare variables
  int i, j, temp;
  int arr[ARRAY_SIZE] = {0};
  clock_t start, stop;
  double total_time;

  // Initialize random seed
  srand(time(NULL));

  // Populate array with random integers
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % ARRAY_SIZE;
  }

  // Start clock and perform bubble sort
  start = clock();
  for (i = 0; i < NUM_ITERATIONS; i++) {
    for (j = 0; j < ARRAY_SIZE; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  stop = clock();

  // Calculate total time taken
  total_time = ((double) (stop - start)) / CLOCKS_PER_SEC;

  // Print benchmark results
  printf("Sorting %d integers with bubble sort took %f seconds.\n", ARRAY_SIZE, total_time);

  return 0;
}