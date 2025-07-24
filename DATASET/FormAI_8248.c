//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  clock_t start = clock(); // start measuring time
  int *array = (int *) malloc(ARRAY_SIZE * sizeof(int));
  
  // initialize array with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }
  
  // sort array using bubble sort algorithm
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  
  // print sorted array
  printf("Sorted array:\n");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  
  free(array); // free memory allocated for array
  
  clock_t end = clock(); // end measuring time
  double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
  
  printf("\n\nTime taken by program is %f seconds\n", time_taken);
  
  return 0;
}