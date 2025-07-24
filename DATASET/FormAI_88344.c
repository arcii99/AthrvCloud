//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 1000000

void sort(int *arr, int size) {
  int i, j, temp;
  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int arr[NUM_ELEMENTS];
  int i;

  // Fill array with random numbers
  srand(time(NULL));
  for (i = 0; i < NUM_ELEMENTS; i++) {
    arr[i] = rand() % 1000;
  }

  // Sort array
  sort(arr, NUM_ELEMENTS);

  // Print sorted array
  for (i = 0; i < NUM_ELEMENTS; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}