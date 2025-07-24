//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 20
#define BLOCK_SIZE 4096
#define TOTAL_BLOCKS 256
#define SIZE_OF_BITMAP 8

typedef struct {
  char name[MAX_FILE_NAME_LENGTH];
  int inode_num;
  int size;
  int blocks[10];
  bool is_free; // if the file was deleted or not
} File;

File files[MAX_FILES];
bool bitmap[TOTAL_BLOCKS / SIZE_OF_BITMAP]; // To keep track of which blocks are free or not

int create_file(char *name, int size) {
  int i, j = 0;
  int blocks_needed = size / BLOCK_SIZE + 1;
  for(i = 0; i < MAX_FILES; i++) {
    if(files[i].is_free == true) {
      files[i].is_free = false;
      files[i].inode_num = i;
      files[i].size = size;
      strcpy(files[i].name, name);
      while(j < blocks_needed && j < 10) {
        int block_num = get_next_free_block(); // implemented below
        files[i].blocks[j] = block_num;
        j++;
      }
      // if all blocks were assigned
      if(j == blocks_needed) {
        return i; // returning inode number of the file
      } else {
        // free up the partially assigned blocks
        for(int k = 0; k < j; k++) {
          free_block(files[i].blocks[k]);
        }
        files[i].is_free = true;
      }
    }
  }
  // If the control reaches here, it means that no free inode was found
  printf("Cannot create file. Max limit for files reached.\n");
  return -1;
}

void delete_file(char* name) {
  for(int i = 0; i < MAX_FILES; i++) {
    if(strcmp(files[i].name, name) == 0 && files[i].is_free == false) {
      files[i].is_free = true;
      for(int j = 0; j < 10; j++) {
        free_block(files[i].blocks[j]);
        files[i].blocks[j] = -1;
      }
      printf("Deleted file: %s\n", name);
      return;
    }
  }
  printf("File not found: %s\n", name);
}

int get_next_free_block() {
  for(int i = 0; i < TOTAL_BLOCKS / SIZE_OF_BITMAP; i++) {
    if(bitmap[i] != 0xFF) { // if this byte is not full
      for(int j = 0; j < 8; j++) {
        if((bitmap[i] & (1 << j)) == 0) { // check unused bits
          bitmap[i] |= (1 << j); // mark as used
          return i * SIZE_OF_BITMAP + j;
        }
      }
    }
  }
  printf("No free blocks available\n");
  return -1;
}

void free_block(int block_num) {
  int i = block_num / SIZE_OF_BITMAP;
  int j = block_num % SIZE_OF_BITMAP;
  bitmap[i] &= ~(1 << j); // * bitwise NOT
}

int main() {
  // initialize bitmap with all zeros
  memset(bitmap, 0, sizeof(bitmap));
  // set first block as reserved
  bitmap[0] |= 1;

  // Example usage
  int inode_num = create_file("example.txt", 8192);
  printf("Created file with inode number: %d\n", inode_num);
  delete_file("example.txt");

  return 0;
}