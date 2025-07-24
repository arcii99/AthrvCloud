//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUP_FILES 10
#define MAX_FILENAME_LENGTH 256

/* Function to get current time */
char* getCurrentTime() {
    time_t raw_time;
    struct tm* time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    return asctime(time_info);
}

/* Function to add a new backup file */
void addBackupFile(char* fileName, char* backupFiles[]) {
    int i;
    char* currentTime = getCurrentTime();

    /* Check if backup file already exists */
    for(i=0; i<MAX_BACKUP_FILES; i++) {
        if(strcmp(backupFiles[i], fileName) == 0) {
            printf("Backup file already exists!\n");
            return;
        }
    }

    /* Add new backup file */
    for(i=MAX_BACKUP_FILES-1; i>0; i--) {
        strcpy(backupFiles[i], backupFiles[i-1]);
    }

    strcpy(backupFiles[0], fileName);

    printf("Backup file %s added at %s", fileName, currentTime);
}

/* Function to remove a backup file */
void removeBackupFile(char* fileName, char* backupFiles[]) {
    int i;

    /* Check if backup file exists */
    for(i=0; i<MAX_BACKUP_FILES; i++) {
        if(strcmp(backupFiles[i], fileName) == 0) {
            break;
        }
    }

    if(i == MAX_BACKUP_FILES) {
        printf("Backup file does not exist!\n");
        return;
    }

    /* Remove backup file */
    for(; i<MAX_BACKUP_FILES-1; i++) {
        strcpy(backupFiles[i], backupFiles[i+1]);
    }

    strcpy(backupFiles[MAX_BACKUP_FILES-1], "");

    printf("Backup file %s removed.\n", fileName);
}

/* Function to list backup files */
void listBackupFiles(char* backupFiles[]) {
    int i;

    printf("List of backup files:\n");

    for(i=0; i<MAX_BACKUP_FILES; i++) {
        if(backupFiles[i][0] != '\0') {
            printf("%s\n", backupFiles[i]);
        }
    }
}

/* Function to backup a file */
void backupFile(char* fileName, char* backupFiles[]) {
    char command[MAX_FILENAME_LENGTH+50];
    char* currentTime = getCurrentTime();

    /* Check if file exists */
    FILE* file = fopen(fileName,"r");

    if(file == NULL) {
        printf("File %s does not exist!\n", fileName);
        return;
    }

    fclose(file);

    /* Backup file */
    sprintf(command, "cp %s backup/%s_%s", fileName, fileName, currentTime);
    system(command);

    addBackupFile(fileName, backupFiles);
}

int main() {
    char backupFiles[MAX_BACKUP_FILES][MAX_FILENAME_LENGTH] = {""};
    char input[MAX_FILENAME_LENGTH];
    char fileName[MAX_FILENAME_LENGTH];

    system("mkdir backup");

    while(1) {
        printf("Enter command (backup, add, remove, list, quit): ");
        fgets(input, MAX_FILENAME_LENGTH, stdin);

        /* Remove newline character from input */
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if(strcmp(input, "list") == 0) {
            listBackupFiles(backupFiles);
        }

        if(strcmp(input, "add") == 0) {
            printf("Enter file name: ");
            fgets(fileName, MAX_FILENAME_LENGTH, stdin);
            fileName[strcspn(fileName, "\n")] = 0;

            addBackupFile(fileName, backupFiles);
        }

        if(strcmp(input, "remove") == 0) {
            printf("Enter file name: ");
            fgets(fileName, MAX_FILENAME_LENGTH, stdin);
            fileName[strcspn(fileName, "\n")] = 0;

            removeBackupFile(fileName, backupFiles);
        }

        if(strcmp(input, "backup") == 0) {
            printf("Enter file name: ");
            fgets(fileName, MAX_FILENAME_LENGTH, stdin);
            fileName[strcspn(fileName, "\n")] = 0;

            backupFile(fileName, backupFiles);
        }
    }

    return 0;
}