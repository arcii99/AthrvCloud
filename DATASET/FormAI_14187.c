//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaration of function to be benchmarked
int sum(int a, int b) {
  return a + b;
}

// Declaration of function to calculate elapsed time
double elapsedTime(struct timespec start, struct timespec end) {
  double start_sec = (double)start.tv_sec * 1000000000.0 + (double)start.tv_nsec;
  double end_sec = (double)end.tv_sec * 1000000000.0 + (double)end.tv_nsec;
  if (end_sec < start_sec) {
    return 0;
  }
  return (end_sec - start_sec) / 1000000.0;
}

int main() {
  int a = 5;
  int b = 10;

  struct timespec start, end;

  // Loop to do benchmarking
  int num_iter = 10000000;
  double avg_time = 0;
  for (int i = 0; i < num_iter; i++) {
    clock_gettime(CLOCK_REALTIME, &start);
    int res = sum(a, b);
    clock_gettime(CLOCK_REALTIME, &end);
    avg_time += elapsedTime(start, end);
  }

  // Calculate average time taken by function
  avg_time /= num_iter;

  // Output results
  printf("Benchmarking results:\n");
  printf("Iterations: %d\n", num_iter);
  printf("Function: sum(a, b)\n");
  printf("Average time: %f ms\n", avg_time);

  return 0;
}