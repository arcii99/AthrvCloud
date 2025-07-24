//FormAI DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024
#define NUM_FILES 128

typedef struct {
  int size; // size of file
  int start_block; // starting block of file
} file;

char disk[NUM_BLOCKS][BLOCK_SIZE]; // simulated disk blocks
file files[NUM_FILES]; // array of simulated files
int free_blocks = NUM_BLOCKS; // count of free blocks on disk
int root_dir_size = 0; // total size of directory
int file_count = 0; // count of files in directory

// helper function to find free blocks on disk
int find_free_blocks(int num_blocks) {
  int i, j;
  for (i = 0; i < NUM_BLOCKS - num_blocks; i++) {
    for (j = i; j < i + num_blocks; j++) {
      if (disk[j][0] != 0) {
        break;
      }
    }
    if (j == i + num_blocks) {
      return i;
    }
  }
  return -1; // couldn't find free blocks
}

// helper function to print disk contents
void print_disk() {
  int i;
  for (i = 0; i < NUM_BLOCKS; i++) {
    printf("%s\n", disk[i]);
  }
}

// helper function to print directory contents
void print_directory() {
  int i;
  for (i = 0; i < file_count; i++) {
    printf("File: %d\tSize: %d\tStart Block: %d\n", i, files[i].size, files[i].start_block);
  }
}

// helper function to create a new file
void create_file(char* filename, int size) {
  int start_block = find_free_blocks(size);
  if (start_block == -1) {
    printf("Error: not enough free blocks.\n");
    return;
  }
  int i;
  for (i = start_block; i < start_block + size; i++) {
    disk[i][0] = '1'; // mark blocks as used
  }
  files[file_count].size = size;
  files[file_count].start_block = start_block;
  file_count++;
  root_dir_size += size;
  printf("File %s created.\n", filename);
}

// helper function to delete a file
void delete_file(char* filename) {
  int i, j, flag = 0;
  for (i = 0; i < file_count; i++) {
    if (strcmp(filename, disk[files[i].start_block + 1]) == 0) {
      flag = 1;
      for (j = files[i].start_block; j < files[i].start_block + files[i].size; j++) {
        disk[j][0] = '0'; // mark blocks as free
      }
      root_dir_size -= files[i].size;
      printf("File %s deleted.\n", filename);
      break;
    }
  }
  if (!flag) {
    printf("Error: %s not found.\n", filename);
  }
}

int main() {
  memset(disk, 0, sizeof(disk)); // initialize disk to zeros
  int choice, size, i;
  char filename[20];
  while (1) {
    printf("\n1. Create file\n2. Delete file\n3. Print directory\n4. Print disk\n5. Quit\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter filename: ");
        scanf("%s", filename);
        printf("Enter file size: ");
        scanf("%d", &size);
        create_file(filename, size);
        break;
      case 2:
        printf("Enter filename: ");
        scanf("%s", filename);
        delete_file(filename);
        break;
      case 3:
        print_directory();
        break;
      case 4:
        print_disk();
        break;
      case 5:
        printf("Quitting...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}