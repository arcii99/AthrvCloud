//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int array[]) {
  int i;
  for (i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }
}

void bubble_sort(int array[]) {
  int i, j, temp;
  for (i = 0; i < ARRAY_SIZE - 1; i++) {
    for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

void selection_sort(int array[]) {
  int i, j, min_idx, temp;
  for (i = 0; i < ARRAY_SIZE - 1; i++) {
    min_idx = i;
    for (j = i+1; j < ARRAY_SIZE; j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }
    temp = array[min_idx];
    array[min_idx] = array[i];
    array[i] = temp;
  }
}

int main() {
  int array[ARRAY_SIZE];
  int i;

  fill_array(array);

  clock_t start, end;
  double cpu_time_used;

  start = clock();
  bubble_sort(array);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Bubble Sort Time: %f\n", cpu_time_used);

  fill_array(array);

  start = clock();
  selection_sort(array);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Selection Sort Time: %f\n", cpu_time_used);

  return 0;
}