//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  int arr[ARRAY_SIZE];
  int sum = 0;
  double time_taken;
  clock_t t;

  // initialize the array
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = i;
  }

  // start the clock
  t = clock();

  // sum the elements of the array
  for (int i = 0; i < ARRAY_SIZE; i++) {
    sum += arr[i];
  }

  // stop the clock
  t = clock() - t;
  time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("Sum of elements in array: %d\n", sum);
  printf("Time taken to sum elements: %f seconds\n", time_taken);

  return 0;
}