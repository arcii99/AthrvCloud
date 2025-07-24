//FormAI DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256
#define BLOCK_NUMBERS 4096

typedef struct inode {
  int size;
  int block_used[BLOCK_NUMBERS];
} inode;

char blocks[BLOCK_NUMBERS][BLOCK_SIZE];
inode inodes[BLOCK_NUMBERS];

void writeFile(int inode_number, char* data) {
  int size = strlen(data);
  int used_blocks = size / BLOCK_SIZE + 1;
  inodes[inode_number].size = size;
  int block_pointer = 0;
  for(int i=0; i<BLOCK_NUMBERS && block_pointer<used_blocks; i++) {
    if(inodes[inode_number].block_used[i] == 0) {
      inodes[inode_number].block_used[i] = 1;
      strncpy(blocks[i], data + BLOCK_SIZE * block_pointer, BLOCK_SIZE);
      block_pointer++;
    }
  }
}

char* readFile(int inode_number) {
  char* data = malloc(inodes[inode_number].size + 1);
  int block_pointer = 0;
  for(int i=0; i<BLOCK_NUMBERS && block_pointer<inodes[inode_number].size/BLOCK_SIZE+1; i++) {
    if(inodes[inode_number].block_used[i] == 1) {
      strncpy(data + BLOCK_SIZE * block_pointer, blocks[i], BLOCK_SIZE);
      block_pointer++;
    }
  }
  return data;
}

int main() {
  memset(blocks, 0, BLOCK_NUMBERS*BLOCK_SIZE);
  memset(inodes, 0, BLOCK_NUMBERS*sizeof(inode));

  char* data_to_write = "Hello, C File System Simulation";
  int inode_number = 0;

  writeFile(inode_number, data_to_write);

  char* data_read = readFile(inode_number);

  printf("Data read: %s\n", data_read);

  free(data_read);

  return 0;
}