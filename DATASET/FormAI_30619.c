//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory and store values in the array
int* createArray(int size) {
  int *array = (int*) malloc (size * sizeof(int));
  for(int i = 0; i < size; i++) {
    array[i] = i+1;
  }
  return array;
}

// Function to print the array
void printArray(int *array, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  // Allocate memory for the array
  int *array = createArray(10);

  // Print the contents of the array
  printf("Initial array: ");
  printArray(array, 10);

  // Reallocate memory for the array
  array = (int*) realloc (array, 20 * sizeof(int));

  // Add more values to the array
  for(int i = 10; i < 20; i++) {
    array[i] = i+1;
  }

  // Print the contents of the new larger array
  printf("New array with added elements: ");
  printArray(array, 20);

  // Deallocate memory for the array
  free(array);

  return 0;
}