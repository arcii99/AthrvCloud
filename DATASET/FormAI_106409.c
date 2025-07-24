//FormAI DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // allocate memory for an integer
  int *ptr = (int *) malloc(sizeof(int));
  if (ptr == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  // assign a value to the integer
  *ptr = 42;

  // print the value of the integer
  printf("The value of the integer is %d\n", *ptr);

  // deallocate the memory
  free(ptr);
  
  return 0;
}