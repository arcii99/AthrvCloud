//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  int array[ARRAY_SIZE];
  int i, sum = 0;
  clock_t start_time, end_time;

  // Initialize the array with random values
  srand(time(NULL));
  for (i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }

  // Start the timer
  start_time = clock();

  // Calculate the sum of all array elements
  for (i = 0; i < ARRAY_SIZE; i++) {
    sum += array[i];
  }

  // End the timer
  end_time = clock();

  // Print the sum and the time taken
  printf("Sum of array elements is %d\n", sum);
  printf("Time taken: %f seconds\n",
         ((double) (end_time - start_time)) / CLOCKS_PER_SEC);
 
  return 0;
}