//FormAI DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

int main() {
  int i, j;
  double time_spent;
  clock_t begin, end;

  int array[MAX_ARRAY_SIZE];

  srand(time(NULL));

  // initialize array with random values
  for (i = 0; i < MAX_ARRAY_SIZE; i++) {
    array[i] = rand() % 1000;
  }

  // bubble sort
  printf("Bubble Sort:\n");
  begin = clock();
  for (i = 0; i < MAX_ARRAY_SIZE; i++) {
    for (j = 0; j < MAX_ARRAY_SIZE-i-1; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  end = clock();
  time_spent = ((double)(end - begin) / CLOCKS_PER_SEC);
  printf("Time taken: %f seconds\n", time_spent);

  // selection sort
  printf("Selection Sort:\n");
  begin = clock();
  for (i = 0; i < MAX_ARRAY_SIZE-1; i++) {
    int min_idx = i;
    for (j = i+1; j < MAX_ARRAY_SIZE; j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }
    int temp = array[i];
    array[i] = array[min_idx];
    array[min_idx] = temp;
  }
  end = clock();
  time_spent = ((double)(end - begin) / CLOCKS_PER_SEC);
  printf("Time taken: %f seconds\n", time_spent);

  // insertion sort
  printf("Insertion Sort:\n");
  begin = clock();
  for (i = 1; i < MAX_ARRAY_SIZE; i++) {
    int key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      j = j - 1;
    }
    array[j+1] = key;
  }
  end = clock();
  time_spent = ((double)(end - begin) / CLOCKS_PER_SEC);
  printf("Time taken: %f seconds\n", time_spent);

  return 0;
}