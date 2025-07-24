//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the number of iterations
#define ITERATIONS 1000000

// Function to be benchmarked
int fib(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

// Main function
int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  // Start benchmarking
  for (int i = 0; i < ITERATIONS; i++) {
    fib(20); // Calculate the 20th Fibonacci number
  }

  end = clock();

  // Calculate the time taken
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Print the results
  printf("Time taken: %f seconds\n", cpu_time_used);
  printf("Iterations per second: %f\n", ITERATIONS / cpu_time_used);

  return 0;
}