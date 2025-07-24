//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

double bench_array[ARRAY_SIZE];

void initialize_array() {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    bench_array[i] = (double)rand() / RAND_MAX;
  }
}

void bench_linear_search() {
  int found_count = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (bench_array[i] > 0.5) {
      found_count++;
    }
  }
  printf("Linear Search Results: Found %d values greater than 0.5\n", found_count);
}

int binary_search(double value, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (bench_array[mid] < value) {
    return binary_search(value, mid+1, high);
  } else if (bench_array[mid] > value) {
    return binary_search(value, low, mid-1);
  }
  return mid;
}

void bench_binary_search() {
  int found_count = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (binary_search(0.5, 0, ARRAY_SIZE-1) >= 0) {
      found_count++;
    }
  }
  printf("Binary Search Results: Found %d values greater than 0.5\n", found_count);
}

int main(void) {
  printf("Initializing array...\n");
  srand(time(NULL));
  initialize_array();

  printf("Running linear search benchmark...\n");
  clock_t start = clock();
  bench_linear_search();
  clock_t end = clock();
  double linear_time = (double)(end-start) / CLOCKS_PER_SEC;
  printf("Execution time: %f seconds\n", linear_time);

  printf("Running binary search benchmark...\n");
  start = clock();
  bench_binary_search();
  end = clock();
  double binary_time = (double)(end-start) / CLOCKS_PER_SEC;
  printf("Execution time: %f seconds\n", binary_time);

  printf("Binary search was %f times faster than linear search\n", linear_time / binary_time);

  return 0;
}