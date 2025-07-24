//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {

  int *array;
  int i, n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  // Allocate memory dynamically
  array = (int*) malloc(n * sizeof(int));

  if (array == NULL) {  // Check if memory allocation was successful
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Take inputs for array elements
  printf("\nEnter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // Display array elements
  printf("Array elements are:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  // Deallocate the memory
  free(array);

  return 0;
}