//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdlib.h>

int main() {
  int *ptr = malloc(sizeof(int)); // allocate 4 bytes in memory
  if (!ptr) {
    // handle error if memory allocation failed
  }
  
  *ptr = 42; // assign value to allocated memory
  
  // some more code where the allocated memory is used...
  
  free(ptr); // release the memory
  
  return 0;
}