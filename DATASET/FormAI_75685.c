//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants for file system
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_COUNT 1000
#define BLOCK_SIZE 512

// define a file
typedef struct {
  char name[MAX_FILENAME_LENGTH];
  int size;
  int blocks[10];
} File;

// define a block
typedef struct {
  char data[BLOCK_SIZE];
  int next_block;
} Block;

// define the file system
typedef struct {
  File files[MAX_FILE_COUNT];
  int file_count;
  Block blocks[1000];
  int block_count;
} FileSystem;

// function prototypes
void init_file_system(FileSystem* fs);
void create_file(FileSystem* fs, char* name, int size);
void delete_file(FileSystem* fs, char* name);
void list_files(FileSystem* fs);
void read_file(FileSystem* fs, char* name);
void write_file(FileSystem* fs, char* name, char* data, int length);

// initialize the file system
void init_file_system(FileSystem* fs) {
  fs->file_count = 0;
  fs->block_count = 0;
}

// create a new file
void create_file(FileSystem* fs, char* name, int size) {
  // check if file limit has been reached
  if (fs->file_count == MAX_FILE_COUNT) {
    printf("Error: maximum file limit reached\n");
    return;
  }

  // check if file name already exists
  for (int i = 0; i < fs->file_count; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      printf("Error: file name already exists\n");
      return;
    }
  }

  // calculate number of blocks needed for file
  int num_blocks = size / BLOCK_SIZE;
  if (size % BLOCK_SIZE != 0) {
    num_blocks++;
  }

  // check if enough blocks are available
  if (fs->block_count + num_blocks > 1000) {
    printf("Error: not enough space on file system\n");
    return;
  }

  // create new file
  File new_file;
  strncpy(new_file.name, name, MAX_FILENAME_LENGTH);
  new_file.size = size;

  // allocate blocks to file
  int blocks_allocated = 0;
  for (int i = 0; i < num_blocks; i++) {
    new_file.blocks[i] = fs->block_count + i;
    fs->block_count++;
    blocks_allocated++;
  }

  // add file to file system
  fs->files[fs->file_count] = new_file;
  fs->file_count++;

  printf("File %s created successfully with %d bytes and %d blocks allocated\n", name, size, blocks_allocated);
}

// delete a file
void delete_file(FileSystem* fs, char* name) {
  int file_index = -1;
  for (int i = 0; i < fs->file_count; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      file_index = i;
      break;
    }
  }

  if (file_index != -1) {
    // free blocks allocated to file
    for (int i = 0; i < 10; i++) {
      if (fs->files[file_index].blocks[i] != -1) {
        fs->blocks[fs->files[file_index].blocks[i]].next_block = -1;
        memset(fs->blocks[fs->files[file_index].blocks[i]].data, 0, BLOCK_SIZE);
        fs->block_count--;
      }
    }

    // remove file from file system
    for (int i = file_index; i < fs->file_count - 1; i++) {
      fs->files[i] = fs->files[i+1];
    }
    fs->file_count--;

    printf("File %s deleted successfully\n", name);
  }
  else {
    printf("Error: file not found\n");
  }
}

// list all files
void list_files(FileSystem* fs) {
  if (fs->file_count == 0) {
    printf("No files found\n");
  }
  else {
    printf("List of files in file system:\n");
    for (int i = 0; i < fs->file_count; i++) {
      printf("- %s (%d bytes, %d blocks)\n", fs->files[i].name, fs->files[i].size, (fs->files[i].size / BLOCK_SIZE) + 1);
    }
  }
}

// read file data
void read_file(FileSystem* fs, char* name) {
  int file_index = -1;
  for (int i = 0; i < fs->file_count; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      file_index = i;
      break;
    }
  }

  if (file_index != -1) {
    printf("File content of %s:\n", name);
    for (int i = 0; i < 10; i++) {
      if (fs->files[file_index].blocks[i] != -1) {
        printf("%s", fs->blocks[fs->files[file_index].blocks[i]].data);
      }
    }
  }
  else {
    printf("Error: file not found\n");
  }
}

// write to a file
void write_file(FileSystem* fs, char* name, char* data, int length) {
  int file_index = -1;
  for (int i = 0; i < fs->file_count; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      file_index = i;
      break;
    }
  }

  if (file_index != -1) {
    int remaining_length = fs->files[file_index].size;
    int data_index = 0;
    for (int i = 0; i < 10; i++) {
      if (fs->files[file_index].blocks[i] != -1) {
        int block_length = (remaining_length >= BLOCK_SIZE) ? BLOCK_SIZE : remaining_length;
        strncpy(fs->blocks[fs->files[file_index].blocks[i]].data, &data[data_index], block_length);
        remaining_length -= block_length;
        data_index += block_length;
      }
    }
    printf("Data written successfully to %s\n", name);
  }
  else {
    printf("Error: file not found\n");
  }
}

// main function
int main(int argc, char** argv) {
  FileSystem fs;
  init_file_system(&fs);

  // usage instructions
  printf("File System Simulation Example Program\n");
  printf("Usage:\n");
  printf("- create <filename> <size>\n");
  printf("- delete <filename>\n");
  printf("- list\n");
  printf("- read <filename>\n");
  printf("- write <filename> <data>\n");
  printf("- exit\n");

  char input[256];
  char* command;
  char* file_name;
  char* data;
  int file_size;

  // command loop
  while (1) {
    printf("File System> ");
    fgets(input, 256, stdin);

    // remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // parse command
    command = strtok(input, " ");

    if (strcmp(command, "create") == 0) {
      // parse filename and size
      file_name = strtok(NULL, " ");
      file_size = atoi(strtok(NULL, " "));
      create_file(&fs, file_name, file_size);
    }
    else if (strcmp(command, "delete") == 0) {
      // parse filename
      file_name = strtok(NULL, " ");
      delete_file(&fs, file_name);
    }
    else if (strcmp(command, "list") == 0) {
      list_files(&fs);
    }
    else if (strcmp(command, "read") == 0) {
      // parse filename
      file_name = strtok(NULL, " ");
      read_file(&fs, file_name);
    }
    else if (strcmp(command, "write") == 0) {
      // parse filename and data
      file_name = strtok(NULL, " ");

      // check if data provided
      if (file_name == NULL) {
        printf("Error: missing arguments\n");
        continue;
      }

      data = strtok(NULL, "");
      write_file(&fs, file_name, data, strlen(data));
    }
    else if (strcmp(command, "exit") == 0) {
      break;
    }
    else {
      printf("Error: invalid command\n");
    }
  }

  return 0;
}