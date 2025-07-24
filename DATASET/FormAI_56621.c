//FormAI DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
  int *array = malloc(ARRAY_SIZE * sizeof(int));
  int sum = 0;

  srand(time(NULL));

  // Fill array with random integers between 1 and 10
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 10 + 1;
  }

  clock_t start = clock();

  for (int i = 0; i < ARRAY_SIZE; i++) {
    sum += array[i];
  }

  clock_t end = clock();
  double time_elapsed = (double) (end - start) / CLOCKS_PER_SEC;

  printf("Sum of array: %d\n", sum);
  printf("Time taken: %f seconds\n", time_elapsed);

  free(array);

  return 0;
}