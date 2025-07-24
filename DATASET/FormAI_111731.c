//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM_SIZE 1024 // the maximum number of memory blocks that can be allocated

struct mem_block {
  int start_address;
  int end_address;
  int is_allocated;
};

struct mem_block mem_pool[MAX_MEM_SIZE]; //the memory pool array, this is where all the allocated memory blocks will be stored

//function prototypes
void init_mem_pool();
void print_mem_pool();
int allocate_mem_block(int);
int deallocate_mem_block(int);

int main() {

  init_mem_pool();

  //allocate some memory blocks
  int block1 = allocate_mem_block(200);
  printf("Block1 Address: %d\n", block1);

  int block2 = allocate_mem_block(500);
  printf("Block2 Address: %d\n", block2);

  //try allocating more than the maximum memory allowed
  int block3 = allocate_mem_block(600);
  if (block3 == -1) {
    printf("Cannot allocate memory beyond the maximum limit.\n");
  }

  //deallocate a memory block
  deallocate_mem_block(block1);
  printf("Block1 deallocated.\n");

  //try allocating a memory block again
  int block4 = allocate_mem_block(300);
  printf("Block4 Address: %d\n", block4);

  print_mem_pool();

  return 0;
}

//initialize the memory pool
void init_mem_pool() {
  for (int i=0; i<MAX_MEM_SIZE; i++) {
    mem_pool[i].start_address = i*10;
    mem_pool[i].end_address = (i*10) + 9;
    mem_pool[i].is_allocated = 0;
  }
}

//print the memory pool
void print_mem_pool() {
  printf("Memory Pool:\n");
  for (int i=0; i<MAX_MEM_SIZE; i++) {
    printf("%d - %d: %s\n", mem_pool[i].start_address, mem_pool[i].end_address, mem_pool[i].is_allocated ? "Allocated" : "Free");
  }
}

//allocate a memory block of given size
int allocate_mem_block(int size) {
  for (int i=0; i<MAX_MEM_SIZE; i++) {
    if (!mem_pool[i].is_allocated && (mem_pool[i].end_address - mem_pool[i].start_address + 1) >= size) {
      mem_pool[i].is_allocated = 1;
      return mem_pool[i].start_address;
    }
  }
  return -1; //cannot allocate more than the maximum limit
}

//deallocate a memory block of given address
int deallocate_mem_block(int address) {
  for (int i=0; i<MAX_MEM_SIZE; i++) {
    if (mem_pool[i].start_address == address) {
      mem_pool[i].is_allocated = 0;
      return 1;
    }
  }
  return 0;
}