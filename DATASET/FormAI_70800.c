//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
  // Declare variables/arrays
  int arr[SIZE];
  int temp;
  int i, j;
  clock_t start, end;
  
  // Randomly initialize array
  srand(time(NULL));
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % SIZE;
  }
  
  // Bubble sort
  start = clock();
  for (i = 0; i < SIZE - 1; i++) {
    for (j = 0; j < SIZE - 1 - i; j++) {
      if (arr[j] > arr[j+1]) {
        // Swap elements
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  end = clock();
  
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Bubble sort took %f seconds to execute.\n", time_taken);
  
  return 0;
}