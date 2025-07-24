//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM_SIZE 1024

char memory[MAX_MEM_SIZE]; // Our memory pool
int free_mem = MAX_MEM_SIZE; // Amount of free memory

int allocate(int size) {
  if (size <= free_mem) {
    int addr = MAX_MEM_SIZE - free_mem;
    free_mem -= size;
    return addr;
  } else {
    return -1; // Return -1 to indicate error
  }
}

void deallocate(int addr, int size) {
  int new_free_mem = free_mem + size;
  if (addr + size == MAX_MEM_SIZE) {
    // If block is at the end of memory, just expand the free memory
    free_mem = new_free_mem;
  } else {
    // Otherwise, merge the free memory with the block
    memory[addr] = new_free_mem & 0xFF; // Lower byte of new free memory size
    memory[addr + 1] = (new_free_mem >> 8) & 0xFF; // Higher byte of new free memory size
    free_mem = new_free_mem;
  }
}

int main() {
  // Allocate a block of 100 bytes
  int addr1 = allocate(100);

  // Check if allocation was successful
  if (addr1 == -1) {
    printf("Error: Not enough memory\n");
    return 1;
  }

  // Fill the block with some data
  for (int i = 0; i < 100; i++) {
    memory[addr1 + i] = i + 1;
  }

  // Deallocate the block
  deallocate(addr1, 100);

  // Allocate another two blocks
  int addr2 = allocate(50);
  int addr3 = allocate(25);

  // Check for errors
  if (addr2 == -1 || addr3 == -1) {
    printf("Error: Not enough memory\n");
    return 1;
  }

  // Fill the blocks with some data
  for (int i = 0; i < 50; i++) {
    memory[addr2 + i] = i + 1;
  }
  for (int i = 0; i < 25; i++) {
    memory[addr3 + i] = i + 1;
  }

  // Print the contents of the memory
  printf("Memory contents:\n");
  for (int i = 0; i < MAX_MEM_SIZE; i++) {
    printf("%d ", memory[i]);
    if (i % 16 == 15) {
      printf("\n");
    }
  }

  // Deallocate the blocks
  deallocate(addr2, 50);
  deallocate(addr3, 25);

  return 0; // Success
}