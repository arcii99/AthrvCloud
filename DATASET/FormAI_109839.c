//FormAI DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_COUNT 100

// Structure to represent a backup file
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t createTime;
} BackupFile;

// Global array to store backup files
BackupFile backupFiles[MAX_FILE_COUNT];
int fileCount = 0;

// Function to create a new backup file
void createBackup(char* filename) {
    // Check if backup files limit reached
    if (fileCount >= MAX_FILE_COUNT) {
        printf("Error: Maximum backup files limit reached. Delete old backups to create new ones.\n");
        return;
    }

    // Create new backup file
    BackupFile newFile;
    strcpy(newFile.filename, filename);
    newFile.createTime = time(NULL);
    backupFiles[fileCount] = newFile;
    fileCount++;

    printf("Backup created successfully: %s\n", newFile.filename);
}

// Function to delete a backup file
void deleteBackup(char* filename) {
    int i;
    for (i = 0; i < fileCount; i++) {
        BackupFile file = backupFiles[i];
        if (strcmp(file.filename, filename) == 0) {
            // Delete file from array by shifting elements
            int j;
            for (j = i; j < fileCount - 1; j++) {
                backupFiles[j] = backupFiles[j+1];
            }
            fileCount--;
            printf("Backup deleted successfully: %s\n", filename);
            return;
        }
    }
    printf("Error: Backup file not found.\n");
}

int main() {
    // Test createBackup() function
    createBackup("file1.txt");
    createBackup("file2.txt");
    createBackup("file3.txt");
    createBackup("file4.txt");

    // Test deleteBackup() function
    deleteBackup("file2.txt");
    deleteBackup("file5.txt");

    return 0;
}