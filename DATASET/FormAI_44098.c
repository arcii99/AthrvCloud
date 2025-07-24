//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMS 1000000

int main(void) {
  int arr[NUM_ELEMS];

  // populate array with random values
  srand(time(NULL));
  for (int i = 0; i < NUM_ELEMS; ++i) {
    arr[i] = rand() % 100 + 1;
  }

  printf("Starting benchmark...\n");

  // measure time taken to sort the array using bubble sort
  clock_t start_time = clock();
  for (int i = 0; i < NUM_ELEMS - 1; ++i) {
    for (int j = 0; j < NUM_ELEMS - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  clock_t end_time = clock();

  // calculate time taken in milliseconds
  double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC * 1000;
  printf("Bubble sort took %.2f milliseconds to sort %d elements\n", elapsed_time, NUM_ELEMS);

  return 0;
}