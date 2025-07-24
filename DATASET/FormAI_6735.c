//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 100

/* Structure to hold file information */
typedef struct {
  char name[20];
  char type[5];
  int size;
} File;

/* Structure to hold directory information */
typedef struct {
  char name[20];
  int num_files;
  File files[MAXSIZE];
} Directory;

/* Structure to hold filesystem information */
typedef struct {
  int num_directories;
  Directory directories[MAXSIZE];
} FileSystem;

/* Function to create a new directory */
void create_directory(FileSystem *fs, char directory_name[]) {
  Directory new_directory;
  strcpy(new_directory.name, directory_name);
  new_directory.num_files = 0;
  fs->directories[fs->num_directories] = new_directory;
  fs->num_directories++;
}

/* Function to create a new file */
void create_file(FileSystem *fs, char directory_name[], char file_name[], char file_type[], int file_size) {
  int directory_index = -1;
  /* Find the directory index */
  for (int i=0; i<fs->num_directories; i++) {
    if (strcmp(fs->directories[i].name, directory_name) == 0) {
      directory_index = i;
      break;
    }
  }
  /* If directory exists */
  if (directory_index != -1) {
    /* Create new file */
    File new_file;
    strcpy(new_file.name, file_name);
    strcpy(new_file.type, file_type);
    new_file.size = file_size;
    /* Add file to directory */
    fs->directories[directory_index].files[fs->directories[directory_index].num_files] = new_file;
    fs->directories[directory_index].num_files++;
  } else {
    printf("Directory not found!\n");
  }
}

/* Function to display filesystem information */
void display_filesystem(FileSystem *fs) {
  printf("FileSystem Information:\n");
  printf("-----------------------\n");
  for (int i=0; i<fs->num_directories; i++) {
    printf("\nDirectory: %s\n", fs->directories[i].name);
    for (int j=0; j<fs->directories[i].num_files; j++) {
      printf("  %s.%s (%d bytes)\n", fs->directories[i].files[j].name, fs->directories[i].files[j].type, fs->directories[i].files[j].size);
    }
  }
}

/* Main function */
int main() {
  FileSystem fs;
  fs.num_directories = 0;
  printf("Creating Directories...\n");
  create_directory(&fs, "Documents");
  create_directory(&fs, "Pictures");
  create_directory(&fs, "Videos");
  printf("Creating Files...\n");
  create_file(&fs, "Documents", "report", "txt", 2048);
  create_file(&fs, "Pictures", "family", "jpeg", 10240);
  create_file(&fs, "Videos", "tutorial", "mp4", 409600);
  printf("Displaying Filesystem Information...\n");
  display_filesystem(&fs);
  return 0;
}