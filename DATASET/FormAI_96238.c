//FormAI DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
  // allocate memory for an array of 5 integers
  int *ptr = (int*) malloc(5 * sizeof(int));

  // check if allocation was successful
  if(ptr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // assign values to array
  for(int i = 0; i < 5; i++) {
    ptr[i] = i * 2;
  }

  // print values in array
  printf("Values in array: ");
  for(int i = 0; i < 5; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");

  // deallocate memory
  free(ptr);
  ptr = NULL;

  // check if deallocation was successful
  if(ptr == NULL) {
    printf("Memory deallocation successful.\n");
  }

  return 0;
}