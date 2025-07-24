//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 20
#define MAX_FILESIZE 100

typedef struct {
  char name[MAX_FILENAME];
  char contents[MAX_FILESIZE];
  int size;
} File;

typedef struct {
  File files[MAX_FILES];
  int num_files;
} FileSystem;

void initialize_fs(FileSystem *fs) {
  fs->num_files = 0;
}

void create_file(FileSystem *fs, char* filename, char* contents) {
  if(fs->num_files >= MAX_FILES) {
    printf("Maximum number of files reached\n");
  } else {
    File* new_file = &fs->files[fs->num_files];
    strcpy(new_file->name, filename);
    strcpy(new_file->contents, contents);
    new_file->size = strlen(contents);
    fs->num_files++;
  }
}

void delete_file(FileSystem *fs, char* filename) {
  int i;
  for(i=0; i<fs->num_files; i++) {
    if(strcmp(fs->files[i].name, filename) == 0) {
      fs->num_files--;
      fs->files[i] = fs->files[fs->num_files];
      printf("File %s deleted\n", filename);
      return;
    }
  }
  printf("File %s not found\n", filename);
}

void list_files(FileSystem *fs) {
  int i;
  printf("Listing %d files:\n", fs->num_files);
  for(i=0; i<fs->num_files; i++) {
    printf("  %s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
  }
}

int main() {
  FileSystem fs;
  initialize_fs(&fs);
  
  printf("Creating new files...\n");
  create_file(&fs, "file1.txt", "This is file 1");
  create_file(&fs, "file2.txt", "This is file 2");
  create_file(&fs, "file3.txt", "This is file 3");

  list_files(&fs);

  printf("Deleting file2.txt...\n");
  delete_file(&fs, "file2.txt");

  list_files(&fs);

  return 0;
}