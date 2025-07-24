//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t start_time, end_time;
  int n = 100000000;
  int sum = 0;

  start_time = clock();
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  end_time = clock();
  printf("The sum of first %d natural number is %d\n", n, sum);
  printf("Time taken for loop execution: %f ms\n\n", ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

  start_time = clock();
  sum = (n * (n + 1)) / 2;
  end_time = clock();
  printf("The sum of first %d natural number is %d\n", n, sum);
  printf("Time taken for formula execution: %f ms\n\n", ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

  return 0;
}