//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Allocate memory dynamically
  int *arr = (int *)malloc(n * sizeof(int));

  // Check if the memory allocation was successful
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("Enter the %d elements:\n", n);

  // Read in the elements of the array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Print out the elements of the array
  printf("The elements of the array are: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // Free the dynamically allocated memory
  free(arr);

  // Set the pointer to NULL after freeing
  arr = NULL;

  return 0;
}