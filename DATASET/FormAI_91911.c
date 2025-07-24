//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed for random number generation
  int arr[100000];
  clock_t start, end;
  double cpu_time_used;

  // Generate random numbers and fill the array
  for(int i=0; i<100000; i++) {
    arr[i] = rand() % 1000 + 1;
  }

  // Bubble sort implementation
  start = clock();
  for(int i=0; i<100000-1; i++) {
    for(int j=0; j<100000-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // CPU time used in seconds

  printf("Sorted array: ");
  for(int i=0; i<100000; i++) {
    printf("%d ", arr[i]);
  }

  printf("\nTime taken by Bubble Sort: %f seconds", cpu_time_used);

  return 0;
}