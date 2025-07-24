//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000000 // Length of the array

int main() {
  int a[LENGTH]; // Array for benchmarking
  double elapsed_time; // Elapsed time in seconds
  clock_t start_time, end_time; // Start and end time

  // Fill the array with random integers
  for (int i = 0; i < LENGTH; i++) {
    a[i] = rand();
  }

  // Benchmarking of linear search
  start_time = clock();
  for (int i = 0; i < LENGTH; i++) {
    if (a[i] == a[LENGTH-1]) { // Search for the last element
      break;
    }
  }
  end_time = clock();

  elapsed_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

  printf("Linear search elapsed time: %lf seconds\n", elapsed_time);

  // Benchmarking of binary search
  start_time = clock();
  int low = 0;
  int high = LENGTH-1;
  int mid;
  while (low <= high) {
    mid = (low+high)/2;
    if (a[mid] == a[LENGTH-1]) { // Search for the last element
      break;
    } else if (a[mid] < a[LENGTH-1]) {
      low = mid+1;
    } else {
      high = mid-1;
    }
  }
  end_time = clock();

  elapsed_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

  printf("Binary search elapsed time: %lf seconds\n", elapsed_time);

  return 0;
}