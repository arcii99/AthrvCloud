//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

// function to allocate memory in a chunk of 64 bytes
void* my_malloc(size_t size) {
  void* pointer = malloc(size + 64);
  *((size_t*)pointer) = size;
  return (void*)((size_t)pointer + 64);
}

// function to deallocate memory allocated by my_malloc
void my_free(void* pointer) {
  void* real_pointer = (void*)((size_t)pointer - 64);
  free(real_pointer);
}

int main() {
  int* ptr = (int*) my_malloc(sizeof(int));   // allocating memory of 4 bytes
  *ptr = 10;   // storing value in allocated memory
  printf("Value stored in allocated memory: %d\n", *ptr);
  my_free(ptr);   // deallocating memory
  return 0;
}