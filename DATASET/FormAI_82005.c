//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_FILES 5

int main(void) {

  // Define variables
  char filename[MAX_FILENAME_LENGTH];
  char command[100];
  int numBackupFiles = 0;
  char backupFileNames[MAX_BACKUP_FILES][MAX_FILENAME_LENGTH];
  
  // Welcome message
  printf("Welcome to the C File Backup System!\n");

  // Main loop
  while(1) {
    
    // Get user input
    printf("\nEnter a filename to backup (or type 'q' to quit): ");
    scanf("%s", filename);
    
    // Check if user wants to quit
    if(strcmp(filename, "q") == 0 || strcmp(filename, "Q") == 0) {
      printf("\nThanks for using the C File Backup System!\n");
      break;
    }

    // Check if file exists
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
      printf("File %s not found.\n", filename);
      continue;
    }
    fclose(file);

    // Check if maximum backup files reached
    if(numBackupFiles == MAX_BACKUP_FILES) {
      printf("Maximum number of backup files reached.\n");
      printf("Do you want to delete the oldest backup file to make space? (y/n) ");
      char choice;
      scanf(" %c", &choice);
      if(choice == 'y' || choice == 'Y') {
        // Delete oldest backup file
        sprintf(command, "rm %s", backupFileNames[0]);
        system(command);
        // Shift backup file names to the left
        for(int i=0; i<numBackupFiles-1; i++) {
          strcpy(backupFileNames[i], backupFileNames[i+1]);
        }
        numBackupFiles--;
      }
      else {
        continue; // User does not want to delete oldest backup file
      }
    }

    // Create backup file name with timestamp
    time_t now = time(NULL);
    char timestamp[MAX_FILENAME_LENGTH];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", localtime(&now)); // Format: YYYYMMDDHHMMSS
    sprintf(backupFileNames[numBackupFiles], "%s.%s.bak", filename, timestamp);
    
    // Create backup file
    sprintf(command, "cp %s %s", filename, backupFileNames[numBackupFiles]);
    system(command);
    numBackupFiles++;

    printf("Backup created: %s\n", backupFileNames[numBackupFiles-1]);
  }

  return 0;
}