//FormAI DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(void) {
  int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
  clock_t t1, t2;

  // Initialize arrays with random values
  for(int i = 0; i < MAX_SIZE; i++) {
    a[i] = rand() % 100;
    b[i] = rand() % 100;
  }

  // Benchmarking array addition with a loop
  printf("Benchmarking loop addition...\n");
  t1 = clock();
  for(int i = 0; i < MAX_SIZE; i++) {
    c[i] = a[i] + b[i];
  }
  t2 = clock();
  double t_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("Time taken: %f\n\n", t_diff);

  // Benchmarking array addition with SIMD vectorization
  printf("Benchmarking SIMD vectorization addition...\n");
  t1 = clock();
  #pragma omp simd
  for(int i = 0; i < MAX_SIZE; i++) {
    c[i] = a[i] + b[i];
  }
  t2 = clock();
  t_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("Time taken: %f\n\n", t_diff);

  return 0;
}