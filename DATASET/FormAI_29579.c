//FormAI DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <time.h>

int main() {
  int array_size = 1000000;
  int* array = malloc(array_size * sizeof(int));

  clock_t start, end;
  double cpu_time_used;

  // Benchmarking loop
  for(int i = 0; i < 10; i++) {

    // Randomize array values
    for(int j = 0; j < array_size; j++) {
      array[j] = rand();
    }

    // Bubble Sort
    start = clock();

    for(int j = 0; j < array_size; j++) {
      for(int k = 0; k < array_size - j - 1; k++) {
        if(array[k] > array[k + 1]) {
          int temp = array[k];
          array[k] = array[k + 1];
          array[k + 1] = temp;
        }
      }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort run %d:\n", i);
    printf("Array size: %d\n", array_size);
    printf("Time taken: %f seconds\n\n", cpu_time_used);
  }

  free(array);
  return 0;
}