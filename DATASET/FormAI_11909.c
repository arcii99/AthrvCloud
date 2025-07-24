//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = (int*) malloc(5 * sizeof(int));

  if (!ptr) {
    printf("Memory allocation failed!");
    exit(1);
  }

  for (int i = 0; i < 5; i++) {
    *(ptr + i) = i;
    printf("Value %d stored at address %p\n", *(ptr + i), (ptr + i));
  }

  printf("\n");

  // Reallocating Memory
  ptr = realloc(ptr, 10 * sizeof(int));
  
  if (!ptr) {
    printf("Memory reallocation failed!");
    exit(1);
  }

  for (int i = 5; i < 10; i++) {
    *(ptr + i) = i;
    printf("Value %d stored at address %p\n", *(ptr + i), (ptr + i));
  }

  free(ptr);
  ptr = NULL;

  return 0;
}