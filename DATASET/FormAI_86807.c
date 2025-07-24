//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {
  clock_t start, end;
  double cpu_time_used;

  // benchmarking code using iterative multiplication
  start = clock();
  int result = 1;
  for (int i = 1; i <= 10000; i++) {
    result *= i;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Result: %d\n", result);
  printf("Time taken to execute iterative multiplication: %lf seconds\n", cpu_time_used);

  // benchmarking code using recursive multiplication
  start = clock();
  result = recursive_multiply(1, 10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Result: %d\n", result);
  printf("Time taken to execute recursive multiplication: %lf seconds\n", cpu_time_used);

  return 0;
}

int recursive_multiply(int start, int end) {
  if (start == end) {
    return start;
  }
  int mid = (start + end) / 2;
  return recursive_multiply(start, mid) * recursive_multiply(mid + 1, end);
}