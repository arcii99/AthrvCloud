//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <time.h>

#define NUM_ITERATIONS 1000000

void perform_task() {
  // Simulate some work to be done
  int sum = 0;
  for (int i = 0; i < 100; i++) {
    sum += i;
  }
}

int main() {
  // Get start time
  clock_t start_time = clock();

  // Perform task NUM_ITERATIONS times
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    perform_task();
  }

  // Get end time
  clock_t end_time = clock();

  // Calculate elapsed time
  double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

  // Print results
  printf("Elapsed time: %f seconds\n", elapsed_time);
  printf("Time per iteration: %f microseconds\n", elapsed_time / NUM_ITERATIONS * 1000000);

  return 0;
}