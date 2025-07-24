//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
  // Allocate memory dynamically for an integer array
  int *arr = (int*) malloc(sizeof(int) * SIZE);
  
  // Check if memory allocation was successful
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  // Initialize the array with random values
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }
  
  // Print the array elements
  printf("Array elements: ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  
  // Calculate the sum of all array elements
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    sum += arr[i];
  }
  
  // Print the sum of all array elements
  printf("\nSum of all array elements: %d\n", sum);
  
  // Free the allocated memory
  free(arr);
  
  // Set the pointer to NULL after freeing memory
  arr = NULL;
  
  return 0;
}