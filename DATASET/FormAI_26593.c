//FormAI DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10 // maximum number of files to be backed up
#define MAX_LENGTH 100 // maximum file name length

// structure to hold information about a file
struct file_info {
  char name[MAX_LENGTH];
  char location[MAX_LENGTH];
};

// function to backup files from a given location
void backup_files(struct file_info files[], int num_files, char backup_dir[]) {
  char command[MAX_LENGTH];
  for(int i=0; i<num_files; i++) {
    // create backup command
    sprintf(command, "cp %s/%s %s/%s.bak", files[i].location, files[i].name, backup_dir, files[i].name);
    // execute the backup command
    system(command);
  }
  printf("Backup completed!\n");
}

int main() {
  struct file_info files[MAX_FILES];
  int num_files;
  char backup_dir[MAX_LENGTH];

  // get input from user
  printf("Enter the number of files to backup (max %d): ", MAX_FILES);
  scanf("%d", &num_files);

  printf("Enter the backup directory: ");
  scanf("%s", backup_dir);

  for(int i=0; i<num_files; i++) {
    printf("Enter the name of file %d: ", i+1);
    scanf("%s", files[i].name);
    printf("Enter the location of file %d: ", i+1);
    scanf("%s", files[i].location);
  }

  // call the backup function
  backup_files(files, num_files, backup_dir);

  return 0;
}