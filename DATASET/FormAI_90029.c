//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void allocate(int **ptr, int size, int level) {
  printf("Level %d: Allocating %d bytes of memory...\n", level, size);
  *ptr = malloc(size);
  
  if (level == 1) {
    return;
  } else {
    allocate(ptr, size/2, level-1);
  }
}

int main() {
  int level;
  printf("Enter the level of recursion: ");
  scanf("%d", &level);

  int *ptr;
  allocate(&ptr, 1000, level);

  printf("\nMemory successfully allocated and deallocated!");
  free(ptr);
  return 0;
}