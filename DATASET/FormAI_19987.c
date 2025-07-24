//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_NAME_LENGTH 50
#define BACKUP_DIR "backup/"
#define ERROR_FILE "error.log"

char filesList[MAX_FILES][MAX_NAME_LENGTH];
int numOfFiles = 0;

void createBackupDirectory() {
    int status = system("mkdir backup");
    if(status != 0) {
        FILE *errorFile = fopen(ERROR_FILE, "a");
        time_t now = time(NULL);
        fprintf(errorFile, "%s : An error occurred while creating backup directory\n", ctime(&now));
        fclose(errorFile);
    }
}

void backupFiles() {
    FILE *errorFile = fopen(ERROR_FILE, "a");
    time_t now = time(NULL);
    char backupCommand[100];
    sprintf(backupCommand, "cp %s* %s%d/", BACKUP_DIR, BACKUP_DIR, (int)now);
    int status = system(backupCommand);
    if(status != 0) {
        fprintf(errorFile, "%s : An error occurred while backing up files\n", ctime(&now));
    }
    fclose(errorFile);
}

int main() {
    printf("Welcome to the Unique Backup System!\n");

    // Get all the files in the directory
    FILE *filesPipe = popen("ls", "r");
    if(!filesPipe) {
        printf("Error: Could not open pipe to ls command\n");
        exit(1);
    }
    char tempFileName[MAX_NAME_LENGTH];
    while(fgets(tempFileName, MAX_NAME_LENGTH, filesPipe)) {
        tempFileName[strcspn(tempFileName, "\n")] = 0; // Remove newline character
        strcpy(filesList[numOfFiles], tempFileName);
        numOfFiles++;
    }
    pclose(filesPipe);

    // Create backup directory if it doesn't exist
    if(system("test -d backup") != 0) {
        createBackupDirectory();
    }

    // Copy all the files in the directory to the backup directory
    for(int i = 0; i < numOfFiles; i++) {
        char copyCommand[100];
        sprintf(copyCommand, "cp %s%s %s", filesList[i], BACKUP_DIR, filesList[i]);
        int status = system(copyCommand);
        if(status != 0) {
            FILE *errorFile = fopen(ERROR_FILE, "a");
            time_t now = time(NULL);
            fprintf(errorFile, "%s : An error occurred while backing up %s\n", ctime(&now), filesList[i]);
            fclose(errorFile);
        }
    }

    // Backup all files every 24 hours
    while(1) {
        backupFiles();
        sleep(86400);
    }

    return 0;
}