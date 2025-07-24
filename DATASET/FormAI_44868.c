//FormAI DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_FILE_COUNT 10
#define BLOCK_SIZE 512
#define DISK_SIZE 20*1024

typedef struct {
  char filename[MAX_FILENAME_SIZE];
  int block_count;
  int blocks[10];
} fcb_t;

fcb_t fs[MAX_FILE_COUNT];
int disk[DISK_SIZE/BLOCK_SIZE];

int find_free_block() {
  for (int i = 0; i < DISK_SIZE/BLOCK_SIZE; i++) {
    if (disk[i] == 0) {
      return i;
    }
  }
  return -1;
}

void create_file(char* filename) {
  if (strnlen(filename, MAX_FILENAME_SIZE) >= MAX_FILENAME_SIZE) {
    printf("Filename too long\n");
    return;
  }
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
    if (strncmp(fs[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
      printf("File already exists\n");
      return;
    }
  }
  int block_count = 0;
  int blocks[10];
  int free_block;
  do {
    free_block = find_free_block();
    if (free_block >= 0) {
      blocks[block_count] = free_block;
      disk[free_block] = 1;
      block_count++;
    }
  } while (free_block >= 0 && block_count < 10);
  if (block_count == 0) {
    printf("Not enough disk space\n");
    return;
  }
  fcb_t new_file;
  strncpy(new_file.filename, filename, MAX_FILENAME_SIZE);
  new_file.block_count = block_count;
  for (int i = 0; i < block_count; i++) {
    new_file.blocks[i] = blocks[i];
  }
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
    if (strlen(fs[i].filename) == 0) {
      fs[i] = new_file;
      printf("File created successfully\n");
      return;
    }
  }
  printf("Maximum number of files reached\n");
}

void delete_file(char* filename) {
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
    if (strncmp(fs[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
      for (int j = 0; j < fs[i].block_count; j++) {
        disk[fs[i].blocks[j]] = 0;
      }
      memset(&fs[i], 0, sizeof(fcb_t));
      printf("File deleted successfully\n");
      return;
    }
  }
  printf("File not found\n");
}

void list_files() {
  printf("Filename\tBlock count\n");
  for (int i = 0; i < MAX_FILE_COUNT; i++) {
    if (strlen(fs[i].filename) > 0) {
      printf("%s\t\t%d\n", fs[i].filename, fs[i].block_count);
    }
  }
}

int main() {
  memset(fs, 0, sizeof(fs));
  memset(disk, 0, sizeof(disk));
  char input[100];
  while (1) {
    printf("Enter a command (create, delete, list, exit):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    if (strncmp(input, "create", 6) == 0) {
      char filename[MAX_FILENAME_SIZE];
      printf("Enter filename:\n");
      fgets(filename, sizeof(filename), stdin);
      filename[strcspn(filename, "\n")] = 0;
      create_file(filename);
    } else if (strncmp(input, "delete", 6) == 0) {
      char filename[MAX_FILENAME_SIZE];
      printf("Enter filename:\n");
      fgets(filename, sizeof(filename), stdin);
      filename[strcspn(filename, "\n")] = 0;
      delete_file(filename);
    } else if (strncmp(input, "list", 4) == 0) {
      list_files();
    } else if (strncmp(input, "exit", 4) == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }
  return 0;
}