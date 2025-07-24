//FormAI DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>

int main()
{
    // Define file paths to be backed up
    char* filePath1 = "/home/user/Documents/file1.txt";
    char* filePath2 = "/home/user/Documents/file2.txt";
    char* filePath3 = "/home/user/Documents/file3.txt";
    
    // Define backup directory path
    char* backupDirPath = "/home/user/Backups/";
    
    // Create backup directory if it does not exist
    char createBackupDirCommand[1000];
    sprintf(createBackupDirCommand, "mkdir -p %s", backupDirPath);
    system(createBackupDirCommand);
    
    // Get current date and time for backup folder name
    char dateCommand[1000];
    sprintf(dateCommand, "date +\"%Y-%m-%d_%H-%M-%S\"");
    FILE* dateProcess = popen(dateCommand, "r");
    char backupFolderName[1000];
    fgets(backupFolderName, 1000, dateProcess);
    pclose(dateProcess);
    backupFolderName[strlen(backupFolderName)-1] = '\0'; // Remove newline character from string
    
    // Create backup directory with current date and time as folder name
    char createFolderCommand[1000];
    sprintf(createFolderCommand, "mkdir %s%s/", backupDirPath, backupFolderName);
    system(createFolderCommand);
    
    // Copy files to backup directory
    char copyFileCommand[1000];
    sprintf(copyFileCommand, "cp %s %s%s/", filePath1, backupDirPath, backupFolderName);
    system(copyFileCommand);
    sprintf(copyFileCommand, "cp %s %s%s/", filePath2, backupDirPath, backupFolderName);
    system(copyFileCommand);
    sprintf(copyFileCommand, "cp %s %s%s/", filePath3, backupDirPath, backupFolderName);
    system(copyFileCommand);
    
    printf("Backup completed successfully!\n");
    
    return 0;
}