//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int arr[100000];
  int sum = 0;
  
  // Populate array with random values
  srand(time(NULL));
  for(int i = 0; i < 100000; i++) {
    arr[i] = rand() % 1000;
  }

  // Benchmarking using clock_t
  clock_t start = clock();

  // Loop through array and sum the values
  for(int i = 0; i < 100000; i++) {
    sum += arr[i];
  }

  double time_taken = ((double)(clock() - start))/CLOCKS_PER_SEC;
  
  printf("Sum of array: %d\n", sum);
  printf("Time taken: %f seconds\n", time_taken);

  return 0;
}