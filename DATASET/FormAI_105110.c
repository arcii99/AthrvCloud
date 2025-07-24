//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#define MEM_SIZE 1024

int main() {
  char* mem_block = (char*) malloc(MEM_SIZE * sizeof(char));  // allocate memory of size MEM_SIZE
  if (mem_block == NULL) {
    printf("Error allocating memory");
    return 1;
  }

  int count = 0;
  for (int i = 0; i < MEM_SIZE; i++) {
    mem_block[i] = 'a';
    count++;
    if (count == 64) {
      count = 0;
      int usage = (i + 1) * 100 / MEM_SIZE;   // calculate the percentage of memory used
      printf("Memory usage: %d%%\n", usage);
    }
  }

  free(mem_block);    // free the allocated memory
  return 0;
}