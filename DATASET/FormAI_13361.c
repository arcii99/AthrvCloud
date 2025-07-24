//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_FILE_CONTENT_SIZE 1000

typedef struct {
  char name[MAX_FILENAME_SIZE];
  char content[MAX_FILE_CONTENT_SIZE];
  int size;
} file;

typedef struct {
  file *files;
  int num_files;
  int capacity;
} file_system;

file_system *init_file_system(int capacity) {
  file_system *fs = (file_system*)malloc(sizeof(file_system));
  fs->files = (file*)malloc(sizeof(file) * capacity);
  fs->num_files = 0;
  fs->capacity = capacity;
  return fs;
}

void add_file(file_system *fs, char *name, char *content, int size) {
  if (fs->num_files == fs->capacity) {
    printf("File system full, cannot add new file.\n");
    return;
  }
  file new_file;
  strncpy(new_file.name, name, MAX_FILENAME_SIZE);
  strncpy(new_file.content, content, MAX_FILE_CONTENT_SIZE);
  new_file.size = size;
  fs->files[fs->num_files++] = new_file;
}

void print_file_system(file_system *fs) {
  printf("File system contents:\n");
  for (int i = 0; i < fs->num_files; i++) {
    printf("(%d) %s - %d bytes\n", i+1, fs->files[i].name, fs->files[i].size);
  }
  printf("End of file system contents.\n");
}

void delete_file(file_system *fs, char *name) {
  int index = -1;
  for (int i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("File not found.\n");
    return;
  }
  for (int i = index; i < fs->num_files - 1; i++) {
    fs->files[i] = fs->files[i+1];
  }
  fs->num_files--;
  printf("File %s deleted.\n", name);
}

int main() {
  file_system *fs = init_file_system(10);
  add_file(fs, "file1.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.", 50);
  add_file(fs, "file2.txt", "Nullam non magna in tellus elementum accumsan eu quis dui.", 63);
  add_file(fs, "file3.txt", "Fusce feugiat fringilla leo, et vestibulum metus rhoncus eu.", 58);
  print_file_system(fs);
  delete_file(fs, "file2.txt");
  print_file_system(fs);
  free(fs->files);
  free(fs);
  return 0;
}