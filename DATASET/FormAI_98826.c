//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t start, end;
  double cpu_time_used;

  int N = 1000000;
  int *array = malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    array[i] = rand() % 1000;
  }

  start = clock();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (array[i] < array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Time taken to execute sorting algorithm: %f seconds", cpu_time_used);

  free(array);
  return 0;
}