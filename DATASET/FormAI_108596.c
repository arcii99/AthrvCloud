//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include <stdlib.h>

#define MAX_SIZE 1000000

int main() {
  char *ptr = NULL; // Setting pointer to NULL to avoid pointer pointing to some random location
  ptr = malloc(MAX_SIZE); // Allocating memory using malloc to store some data

  if (ptr == NULL) { // Checking if memory allocation successful 
    printf("Memory allocation failed");
  } else {
    memset(ptr, 0, MAX_SIZE); // Clearing allocated memory before usage
  }

  // Perform operations on the allocated memory here

  free(ptr); // Freeing the allocated memory to avoid memory leaks
  ptr = NULL; // Setting pointer to NULL after freeing memory to avoid dangling pointer
  return 0;
}