//FormAI DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME_LENGTH 100

void backupFiles(char filenameList[][MAX_FILENAME_LENGTH], int nFiles);

int main() {
    char filenameList[MAX_FILES][MAX_FILENAME_LENGTH];
    int nFiles = 0;

    // Get file names from user input
    printf("Enter up to %d file names to backup:\n", MAX_FILES);
    printf("(Enter an empty line to end input)\n");
    while (nFiles < MAX_FILES) {
        char input[MAX_FILENAME_LENGTH];
        printf("File %d: ", nFiles+1);
        fgets(input, sizeof(input), stdin);

        // Check if user entered an empty line
        if (input[0] == '\n') {
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check if filename is already in list
        int duplicate = 0;
        for (int i = 0; i < nFiles; i++) {
            if (strcmp(filenameList[i], input) == 0) {
                printf("File already in list.\n");
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            continue;
        }

        // Copy filename into list
        strcpy(filenameList[nFiles], input);
        nFiles++;
    }

    // Check if user entered too many files
    if (nFiles == MAX_FILES) {
        printf("Maximum number of files reached (%d).\n", MAX_FILES);
    }

    // Backup files
    printf("\nBacking up %d files...\n", nFiles);
    backupFiles(filenameList, nFiles);
    printf("Backup complete.\n");

    return 0;
}

void backupFiles(char filenameList[][MAX_FILENAME_LENGTH], int nFiles) {
    // Create backups directory
    system("mkdir backups");

    // Backup each file
    for (int i = 0; i < nFiles; i++) {
        printf("Backing up %s...\n", filenameList[i]);

        // Create backup filename
        char backupName[MAX_FILENAME_LENGTH+8];
        sprintf(backupName, "./backups/%s.bak", filenameList[i]);

        // Open original file for reading
        FILE *originalFile = fopen(filenameList[i], "r");
        if (originalFile == NULL) {
            printf("Error: Unable to open %s for reading.\n", filenameList[i]);
            continue;
        }

        // Open backup file for writing
        FILE *backupFile = fopen(backupName, "w");
        if (backupFile == NULL) {
            printf("Error: Unable to open %s for writing.\n", backupName);
            fclose(originalFile);
            continue;
        }

        // Copy original file contents to backup file
        char buffer[4096];
        size_t n;
        while ((n = fread(buffer, 1, sizeof(buffer), originalFile)) > 0) {
            fwrite(buffer, 1, n, backupFile);
        }

        // Close files
        fclose(originalFile);
        fclose(backupFile);
    }
}