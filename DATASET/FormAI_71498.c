//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
  // Allocate space for an array of integers
  int *arr = (int*) malloc(SIZE * sizeof(int));
  
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  
  // Fill the array with random values
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }
  
  // Print the array
  printf("Array before sorting:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // Sort the array using bubble sort
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  // Print the sorted array
  printf("Array after sorting:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // Deallocate the memory used by the array
  free(arr);
  
  return 0;
}