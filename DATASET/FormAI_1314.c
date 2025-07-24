//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 500000

int main() {
  clock_t start, end;
  double cpu_time_used;
  int i, j, tmp;
  int arr[ARRAY_SIZE];

  // Fill the array with random numbers
  srand(time(NULL));
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // Print the unsorted array
  printf("Unsorted array:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  // Start the timer
  start = clock();

  // Perform a bubble sort
  for (i = 0; i < ARRAY_SIZE - 1; i++) {
    for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap the two elements
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }

  // Stop the timer
  end = clock();

  // Calculate the CPU time used
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Print the sorted array
  printf("Sorted array:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }

  // Print the CPU time used
  printf("\n\nSorting took %f seconds.\n", cpu_time_used);

  // Exit the program
  return 0;
}