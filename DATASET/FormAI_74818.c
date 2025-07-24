//FormAI DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  int arr[ARRAY_SIZE];
  srand(time(NULL));
  clock_t start, end;
  double cpu_time_used;

  for (int i = 0; i < ARRAY_SIZE; ++i) {
    arr[i] = rand() % 100; // initialize array with random integers from 0 to 99
  }

  // Benchmarking using bubble sort algorithm
  start = clock();

  for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; ++j) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  printf("Sorting took %lf seconds\n", cpu_time_used);
  
  return 0;
}