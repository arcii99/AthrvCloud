//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr;
  int size, i;

  printf("Enter the size of the integer array: ");
  scanf("%d", &size);

  // Allocate memory for the integer array
  ptr = (int*)malloc(size * sizeof(int));

  // If allocation fails
  if (ptr == NULL) {
    printf("Memory allocation failed!");
    exit(1);
  }

  // Get input from user for the integer array
  printf("Enter %d integers: ", size);
  for (i = 0; i < size; ++i) {
     scanf("%d", ptr + i);
  }

  // Display all the integers entered
  printf("The entered integers are: ");
  for (i = 0; i < size; ++i) {
     printf("%d ", *(ptr + i));
  }

  // Free the dynamically allocated memory
  free(ptr);

  return 0;
}