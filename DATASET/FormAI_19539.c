//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for an integer
  int *num = (int *) malloc(sizeof(int));

  // Check if allocation was successful
  if (num == NULL) {
    printf("Error allocating memory!\n");
    exit(1);
  }

  // Initialize the integer
  *num = 10;

  // Print the integer
  printf("The value of num is %d\n", *num);

  // Reallocate memory for an array of integers
  int *arr = (int *) realloc(num, 3 * sizeof(int));

  // Check if reallocation was successful
  if (arr == NULL) {
    printf("Error reallocating memory!\n");
    exit(1);
  }

  // Initialize the array
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  // Print the array
  printf("The values of arr are %d, %d, %d\n", arr[0], arr[1], arr[2]);

  // Free memory
  free(arr);

  return 0;
}