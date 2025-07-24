//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void recursive_malloc(int size, int depth) {
  if (depth == 0) {
    printf("Reached maximum depth of recursion.\n");
    return;
  }
  int* ptr = malloc(size * sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  printf("Allocated %d bytes of memory at address %p, depth=%d.\n", size, ptr, depth);
  recursive_malloc(size, depth-1);
  free(ptr);
  printf("Freed memory at address %p, depth=%d.\n", ptr, depth);
}

int main() {
  printf("Start of program.\n");
  recursive_malloc(10000, 5);
  printf("End of program.\n");
  return 0;
}