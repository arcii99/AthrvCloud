//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

void generate_array() {
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 1000;
  }
}

int compute_sum() {
  int sum = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    sum += array[i];
  }
  return sum;
}

int main() {
  generate_array();
  clock_t start = clock();
  int sum = compute_sum();
  clock_t end = clock();
  printf("The sum of the array is: %d\n", sum);
  printf("Elapsed time: %.3f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

  return 0;
}