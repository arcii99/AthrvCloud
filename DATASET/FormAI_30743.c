//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main() {
  int arr[ARRAY_SIZE];
  clock_t start, end;
  double cpu_time_used;

  // Fill the array with random integers
  srand(time(NULL));
  for(int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 100;
  }

  // Bubble sort algorithm
  start = clock();
  for(int i = 0; i < ARRAY_SIZE - 1; i++) {
    for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  end = clock();

  // Calculate the CPU time used in sorting the array
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Array of size %d sorted in %f seconds.\n", ARRAY_SIZE, cpu_time_used);

  return 0;
}