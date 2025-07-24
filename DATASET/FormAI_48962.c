//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 100

typedef struct {
  char name[MAX_FILENAME_LENGTH];
  int start_block;
  int size;
}file;

int file_count = 0;
file files[MAX_FILE_COUNT];
int disk[1000];

void initialize_disk() {
  int i;
  for(i=0;i<1000;i++) {
    disk[i] = 0;
  }
}

void create_file() {
  char name[MAX_FILENAME_LENGTH];
  printf("Enter file name: ");
  scanf("%s", name);

  int size, start_block;
  printf("Enter file size in blocks: ");
  scanf("%d", &size);

  if(file_count+size > MAX_FILE_COUNT) {
    printf("Not enough space for file\n");
    return;
  }

  int i,j;
  for(i=0;i<=1000-size;i++) {
    for(j=0;j<size;j++) {
      if(disk[i+j] == 1) {
        break;
      }
    }
    if(j == size) {
      start_block = i;
      break;
    }
  }

  if(i > 1000-size) {
    printf("Not enough space for file\n");
    return;
  }

  strcpy(files[file_count].name, name);
  files[file_count].start_block = start_block;
  files[file_count].size = size;

  for(i=start_block;i<start_block+size;i++) {
    disk[i] = 1;
  }

  printf("File created successfully\n");
  file_count++;
}

void delete_file() {
  char name[MAX_FILENAME_LENGTH];
  printf("Enter file name to be deleted: ");
  scanf("%s", name);

  int i;
  for(i=0;i<file_count;i++) {
    if(strcmp(files[i].name, name) == 0) {
      int j;
      for(j=files[i].start_block;j<files[i].start_block+files[i].size;j++) {
        disk[j] = 0;
      }
      for(j=i;j<file_count-1;j++) {
        strcpy(files[j].name, files[j+1].name);
        files[j].start_block = files[j+1].start_block;
        files[j].size = files[j+1].size;
      }
      file_count--;
      printf("File deleted successfully\n");
      return;
    }
  }
  printf("File not found\n");
}

void display_file_allocation() {
  printf("Disk Space\tFile Allocation\n");
  int i,j;
  for(i=0;i<100;i++) {
    printf("%d-%d\t\t", i*10, (i+1)*10-1);
    for(j=0;j<10;j++) {
      if(disk[i*10+j] == 0) {
        printf("- ");
      } else {
        int k;
        for(k=0;k<file_count;k++) {
          if(files[k].start_block == i*10+j) {
            printf("%s ", files[k].name);
            break;
          }
        }
        if(k == file_count) {
          printf("M ");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  initialize_disk();
  int choice;
  do {
    printf("\nFile System Simulation\n");
    printf("1. Create a file\n");
    printf("2. Delete a file\n");
    printf("3. Display file allocation on disk\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        create_file();
        break;
      case 2:
        delete_file();
        break;
      case 3:
        display_file_allocation();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice. Try again\n");
    }
  } while(choice != 4);

  return 0;
}