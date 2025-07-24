//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory dynamically
  int* arr = (int*) malloc(5 * sizeof(int));

  // Check if allocation was successful
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Populate array with values
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  // Print original array
  printf("Original array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Resize array dynamically
  int* newarr = (int*) realloc(arr, 10 * sizeof(int));

  // Check if reallocation was successful
  if (newarr == NULL) {
    printf("Memory reallocation failed.\n");
    free(arr);
    return 1;
  }

  // Populate new elements of array
  newarr[5] = 60;
  newarr[6] = 70;
  newarr[7] = 80;
  newarr[8] = 90;
  newarr[9] = 100;

  // Print resized array
  printf("Resized array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", newarr[i]);
  }
  printf("\n");

  // Free allocated memory
  free(newarr);

  return 0;
}