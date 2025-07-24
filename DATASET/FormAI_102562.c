//FormAI DATASET v1.0 Category: Benchmarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int *arr, int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int i;
  int arr[ARRAY_SIZE];
  clock_t start, end;
  double cpu_time_used;

  // initialize array with random integers
  srand(time(NULL));  
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // start timing
  start = clock();

  // do bubble sort on the array
  bubble_sort(arr, ARRAY_SIZE);

  // end timing
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Sorting %d integers took %f seconds\n", ARRAY_SIZE, cpu_time_used);

  return 0;
}