//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int arr[ARRAY_SIZE];
  
  // initialize array with random values
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % ARRAY_SIZE;
  }
  
  // print unsorted array
  printf("Unsorted Array:\n");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  
  // measure execution time of bubble sort algorithm
  clock_t start = clock();
  bubbleSort(arr, ARRAY_SIZE);
  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
   
  // print sorted array and execution time
  printf("Sorted Array:\n");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  printf("Execution Time: %f seconds\n", time_taken);
  
  return 0;
}