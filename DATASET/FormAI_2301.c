//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100000

int main() {
  int arr[ARR_SIZE], i, j, temp;

  srand(time(NULL)); // Seed random number generator with current time
  for (i = 0; i < ARR_SIZE; i++) {
    arr[i] = rand() % 100000; // Fill array with random numbers between 0 and 99999
  }

  clock_t start = clock(); // Start timing the program execution

  // Perform bubble sort algorithm
  for (i = 0; i < ARR_SIZE-1; i++) {
    for (j = 0; j < ARR_SIZE-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j]; // Swap the two elements
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  clock_t end = clock(); // End timing the program execution

  double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the time taken in seconds

  // Print the sorted array
  printf("Sorted array:\n");
  for (i = 0; i < ARR_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Print the program execution time
  printf("Time taken by program: %f seconds\n", time_taken);

  return 0;
}