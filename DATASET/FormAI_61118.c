//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

int main() {
  int numbers[MAX_NUMBERS];
  int i, j, temp;
  clock_t start, end;
  double time_used;

  // initialize array with random numbers
  srand(time(NULL));
  for (i = 0; i < MAX_NUMBERS; i++) {
    numbers[i] = rand() % MAX_NUMBERS;
  }

  // benchmark sorting algorithm
  start = clock();
  for (i = 0; i < MAX_NUMBERS - 1; i++) {
    for (j = 0; j < MAX_NUMBERS - i - 1; j++) {
      if (numbers[j] > numbers[j+1]) {
        temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;
      }
    }
  }
  end = clock();
  time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Sorted an array of %d numbers in %f seconds\n", MAX_NUMBERS, time_used);

  return 0;
}