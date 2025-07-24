//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 1000000

int main() {
  int i, j, temp;
  int array[ARRAY_SIZE];

  // Randomly populate the array with integers between 1 and 10
  for (i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 10 + 1;
  }

  // Print unsorted array
  printf("Unsorted array:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }

  // Perform bubble sort to sort the array in ascending order
  for (i = 0; i < ARRAY_SIZE - 1; i++) {
    for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        // Swap the two elements
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  // Print sorted array
  printf("\nSorted array:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  
  return 0;
}