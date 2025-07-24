//FormAI DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20

typedef struct file{
  char name[MAX_FILE_NAME];
  int size;
  char *content;
}File;

typedef struct file_system{
  File files[MAX_FILES];
  int used_files;
  int max_size;
}FileSystem;

void init_file_system(FileSystem *fs, int max_size){
  fs->used_files = 0;
  fs->max_size = max_size;
}

void create_file(FileSystem *fs, char *name, int size){
  if(fs->used_files >= MAX_FILES){
    printf("Cannot create file. Maximum number of files reached!\n");
    return;
  }

  if((fs->max_size-size) < 0){
    printf("Cannot create file. Not enough space left in file system!\n");
    return;
  }

  File f;
  strcpy(f.name, name);
  f.size = size;
  f.content = (char*)malloc(sizeof(char)*size);

  fs->files[fs->used_files] = f;
  fs->used_files++;
  fs->max_size -= size;
  printf("File created successfully\n");
}

void delete_file(FileSystem *fs, char *name){
  int i;
  for(i=0;i<fs->used_files;i++){
    if(strcmp(fs->files[i].name, name) == 0){
      fs->max_size += fs->files[i].size;
      free(fs->files[i].content);
      fs->files[i] = fs->files[fs->used_files-1];
      fs->used_files--;
      printf("File deleted successfully\n");
      return;
    }
  }

  printf("Cannot delete file. File not found in file system!\n");
}

void update_file(FileSystem *fs, char *name, char *new_content){
  int i;
  for(i=0;i<fs->used_files;i++){
    if(strcmp(fs->files[i].name, name) == 0){
      if(strlen(new_content) > fs->files[i].size){
        printf("Cannot update file. New content is larger than the file size!\n");
        return;
      }
      strcpy(fs->files[i].content, new_content);
      printf("File updated successfully\n");
      return;
    }
  }

  printf("Cannot update file. File not found in file system!\n");
}

void display_file_system(FileSystem fs){
  printf("File System Status:\n");
  printf("Total space: %dKB\n", fs.max_size);
  printf("Used space: %dKB\n", MAX_FILES - fs.used_files);

  int i;
  for(i=0;i<fs.used_files;i++){
    printf("\nFile Name: %s\n", fs.files[i].name);
    printf("File Size: %dKB\n", fs.files[i].size);
    printf("File Content: %s\n", fs.files[i].content);
  }
}

int main(){
  FileSystem fs;
  init_file_system(&fs, 100);

  create_file(&fs, "file1", 20);
  create_file(&fs, "file2", 30);
  create_file(&fs, "file3", 10);
  create_file(&fs, "file4", 50);
  create_file(&fs, "file5", 15);

  display_file_system(fs);
  printf("\n");

  delete_file(&fs, "file2");

  display_file_system(fs);
  printf("\n");

  update_file(&fs, "file3", "This is the new content of file3");

  display_file_system(fs);
  printf("\n");

  create_file(&fs, "file6", 80);

  display_file_system(fs);
  printf("\n");

  delete_file(&fs, "file5");
  delete_file(&fs, "file7");

  return 0;
}