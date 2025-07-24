//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // maximum length of each file name

int main() {
  char fileNames[10][MAX_LENGTH]; // array to store file names
  int numFiles; // number of files to be backed up
  int i;

  printf("Welcome to the C File Backup System\n");
  
  // ask user for number of files to be backed up
  printf("\nEnter the number of files you want to backup: ");
  scanf("%d", &numFiles);

  // ask user to enter file names
  for (i = 0; i < numFiles; i++) {
    printf("\nEnter name of file %d: ", i+1);
    scanf("%s", fileNames[i]);
  }

  // creating a new folder for backup files
  char command[100];
  strcpy(command, "mkdir backup");
  system(command);

  // backing up files
  for (i = 0; i < numFiles; i++) {
    char backupFile[MAX_LENGTH + 7]; // maximum length of file name + 7 (for backup folder and extension)
    strcpy(backupFile, "backup/");
    strcat(backupFile, fileNames[i]);
    strcat(backupFile, ".bak");

    printf("\nBacking up file %s\n", fileNames[i]);
    
    // copying file to backup folder
    char command[1000];
    sprintf(command, "cp %s %s", fileNames[i], backupFile);
    system(command);

    printf("Backup of %s complete\n", fileNames[i]);
  }

  printf("\nAll files have been successfully backed up!");
  
  return 0;
}