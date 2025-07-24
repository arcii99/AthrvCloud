//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
  // Declare variables
  int i, j;
  int temp;
  int array[MAX_SIZE];
  clock_t start, end;
  double cpu_time_used;

  // Generate random numbers and fill the array
  srand(time(NULL));
  for(i = 0; i < MAX_SIZE; i++) {
    array[i] = rand() % MAX_SIZE;
  }

  // Print the initial array
  printf("Initial array:\n");
  for(i = 0; i < MAX_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Start the clock
  start = clock();

  // Sort the array in ascending order using bubble sort
  for(i = 0; i < MAX_SIZE - 1; i++) {
    for(j = 0; j < MAX_SIZE - i - 1; j++) {
      if(array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  // Stop the clock
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Print the sorted array
  printf("Sorted array:\n");
  for(i = 0; i < MAX_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Print the CPU time used
  printf("CPU time used: %f seconds.\n", cpu_time_used);

  return 0;
}