//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

int main() {
  clock_t start, end;
  double total_time;
  int numbers[MAX_NUMBERS];
  int min_num = 0;
  int max_num = 0;
  int sum_num = 0;

  // Generate random numbers
  srand(time(NULL));
  for (int i = 0; i < MAX_NUMBERS; i++) {
    numbers[i] = rand() % 1000;
  }

  // Find the minimum number
  start = clock();
  for (int i = 0; i < MAX_NUMBERS; i++) {
    if (numbers[i] < min_num) {
      min_num = numbers[i];
    }
  }
  end = clock();
  total_time = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Minimum number: %d\n", min_num);
  printf("Time taken to find minimum: %f seconds\n", total_time);

  // Find the maximum number
  start = clock();
  for (int i = 0; i < MAX_NUMBERS; i++) {
    if (numbers[i] > max_num) {
      max_num = numbers[i];
    }
  }
  end = clock();
  total_time = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Maximum number: %d\n", max_num);
  printf("Time taken to find maximum: %f seconds\n", total_time);

  // Find the sum of all numbers
  start = clock();
  for (int i = 0; i < MAX_NUMBERS; i++) {
    sum_num += numbers[i];
  }
  end = clock();
  total_time = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sum of all numbers: %d\n", sum_num);
  printf("Time taken to find sum: %f seconds\n", total_time);

  return 0;
}