//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 256
#define NUM_BLOCKS 1024

typedef struct {
  char data[BLOCK_SIZE];
} Block;

Block disk[NUM_BLOCKS];
int free_blocks[NUM_BLOCKS], num_free_blocks = NUM_BLOCKS;

void initialize_blocks() {
  for (int i = 0; i < NUM_BLOCKS; i++) {
    free_blocks[i] = 1;
  }
}

int allocate_block() {
  if (num_free_blocks == 0) {
    return -1;
  }

  int block_num = rand() % NUM_BLOCKS;

  while (!free_blocks[block_num]) {
    block_num = rand() % NUM_BLOCKS;
  }

  free_blocks[block_num] = 0;
  num_free_blocks--;

  return block_num;
}

void free_block(int block_num) {
  if (free_blocks[block_num]) {
    printf("Error: Block already free.\n");
    return;
  }

  free_blocks[block_num] = 1;
  num_free_blocks++;
}

void write_block(int block_num, char *data) {
  if (block_num < 0 || block_num >= NUM_BLOCKS) {
    printf("Error: Invalid block number.\n");
    return;
  }

  for (int i = 0; i < BLOCK_SIZE; i++) {
    disk[block_num].data[i] = data[i];
  }
}

void read_block(int block_num, char *buffer) {
  if (block_num < 0 || block_num >= NUM_BLOCKS) {
    printf("Error: Invalid block number.\n");
    return;
  }

  for (int i = 0; i < BLOCK_SIZE; i++) {
    buffer[i] = disk[block_num].data[i];
  }
}

int main() {
  initialize_blocks();

  int block_num = allocate_block();
  char data[BLOCK_SIZE] = "Hello, world!";
  write_block(block_num, data);

  char buffer[BLOCK_SIZE];
  read_block(block_num, buffer);
  printf("%s\n", buffer);

  free_block(block_num);

  return 0;
}