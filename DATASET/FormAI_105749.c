//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

struct file {
  char name[20];
  int size;
  char* data;
};

struct file_system {
  struct file files[MAX_FILES];
  int num_files;
};

// Function to print all files in the file system
void print_files(struct file_system* fs) {
  printf("Files in File System:\n");
  for (int i = 0; i < fs->num_files; i++) {
    printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
  }
  printf("\n");
}

// Function to initialize the file system
void init_file_system(struct file_system* fs) {
  fs->num_files = 0;
}

// Function to add a file to the file system
void add_file(struct file_system* fs, char* name, int size, char* data) {
  if (fs->num_files < MAX_FILES) {
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.data = (char*) malloc(size);
    memcpy(new_file.data, data, size);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    printf("File '%s' added to file system.\n\n", name);
  }
  else {
    printf("File system is full. Cannot add file.\n\n");
  }
}

// Function to remove a file from the file system
void remove_file(struct file_system* fs, char* name) {
  int index = -1;
  for (int i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index >= 0) {
    free(fs->files[index].data);
    for (int i = index; i < fs->num_files - 1; i++) {
      fs->files[i] = fs->files[i+1];
    }
    fs->num_files--;
    printf("File '%s' removed from file system.\n\n", name);
  }
  else {
    printf("File '%s' not found in file system.\n\n", name);
  }
}

int main() {
  struct file_system fs;
  init_file_system(&fs);

  add_file(&fs, "hello.txt", 12, "Hello, world!");
  add_file(&fs, "data.bin", 8, "\xFF\xEE\xDD\xCC\xBB\xAA\x99\x88");
  add_file(&fs, "image.jpg", 59524, "<JPEG data>");
  print_files(&fs);

  remove_file(&fs, "data.bin");
  remove_file(&fs, "not_found.txt");
  print_files(&fs);

  return 0;
}