//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for an integer
  int *ptr = (int*)malloc(sizeof(int));
  
  if (ptr == NULL) {
    printf("Memory allocation failed. Exiting program.");
    exit(1);
  }
  
  // Set the integer value to 42
  *ptr = 42;
  
  // Print the value before freeing the memory
  printf("Value of ptr: %d\n", *ptr);
  
  // Free the memory
  free(ptr);
  
  // Attempt to set the value again
  *ptr = 84;
  
  // This will cause a segmentation fault, as the memory has been freed
  printf("Value of ptr after free: %d\n", *ptr);
  
  return 0;
}