//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_FILE_SIZE 1000

typedef struct {
  char name[MAX_FILENAME];
  int size;
  char content[MAX_FILE_SIZE];
} file_t;

file_t file_system[MAX_FILES];
int num_files = 0;

/**
 * Function to create a new file in the file system
 */
void create_file(char* name, char* content) {
  if (num_files == MAX_FILES) {
    printf("ERROR: File system full\n");
    return;
  }

  if (strlen(name) > MAX_FILENAME) {
    printf("ERROR: File name is too long\n");
    return;
  }

  file_t new_file;
  strcpy(new_file.name, name);
  strcpy(new_file.content, content);
  new_file.size = strlen(content);

  file_system[num_files] = new_file;
  num_files++;

  printf("File created: %s\n", name);
}

/**
 * Function to delete a file from the file system
 */
void delete_file(char* name) {
  int i, index = -1;

  for (i = 0; i < num_files; i++) {
    if (!strcmp(name, file_system[i].name)) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("File not found: %s\n", name);
    return;
  }

  for (i = index; i < num_files - 1; i++) {
    file_system[i] = file_system[i+1];
  }

  num_files--;

  printf("File deleted: %s\n", name);
}

/**
 * Function to read the contents of a file
 */
void read_file(char* name) {
  int i, index = -1;

  for (i = 0; i < num_files; i++) {
    if (!strcmp(name, file_system[i].name)) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("File not found: %s\n", name);
    return;
  }

  printf("File contents:\n%s\n", file_system[index].content);
}

int main() {
  printf("File system simulation\n\n");

  create_file("file1", "This is file 1");
  create_file("file2", "This is file 2");
  read_file("file1");
  delete_file("file1");
  read_file("file1");

  return 0;
}