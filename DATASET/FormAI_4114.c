//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
  int i, j, temp;
  int a[ARRAY_SIZE];
  clock_t start, end;
  double cpu_time_used;

  // Populate array with random values
  for (i = 0; i < ARRAY_SIZE; i++) {
    a[i] = rand();
  }

  // Bubble sort
  start = clock();
  for (i = 0; i < ARRAY_SIZE-1; i++) {
     for (j = 0; j < ARRAY_SIZE-i-1; j++) {
        if (a[j] > a[j+1]) {
           temp = a[j];
           a[j] = a[j+1];
           a[j+1] = temp;
        }
     }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Bubble sort time: %f seconds\n", cpu_time_used);

  // Selection sort
  start = clock();
  for (i = 0; i < ARRAY_SIZE-1; i++) {
     int min_idx = i;
     for (j = i+1; j < ARRAY_SIZE; j++) {
        if (a[j] < a[min_idx]) {
           min_idx = j;
        }
     }
     temp = a[min_idx];
     a[min_idx] = a[i];
     a[i] = temp;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Selection sort time: %f seconds\n", cpu_time_used);

  return 0;
}