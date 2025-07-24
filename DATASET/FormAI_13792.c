//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 1000000
#define NUM_QUERIES 100

int main(int argc, char *argv[]) {
  int *arr = (int*)malloc(NUM_ELEMENTS * sizeof(int));
  if (!arr) {
    printf("Error: failed to allocate memory!\n");
    return 1;
  }

  srand(42);

  // Fill array with random integers
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    arr[i] = rand() % NUM_ELEMENTS;
  }

  // Perform queries on the array
  for (int i = 0; i < NUM_QUERIES; i++) {
    int index = rand() % NUM_ELEMENTS;
    int value = arr[index];
    printf("Index %d: %d\n", index, value);
  }

  free(arr);
  return 0;
}