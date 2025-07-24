//FormAI DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILES 10

// Define a backup file structure
typedef struct BackupFile {
    char filename[MAX_FILENAME_LENGTH];
    char contents[MAX_FILENAME_LENGTH*10];
} BackupFile;

// Define a backup system structure
typedef struct BackupSystem {
    int num_files;
    BackupFile files[MAX_BACKUP_FILES];
} BackupSystem;

// Function to create a new backup file
void createBackupFile(BackupSystem* bs, char* filename, char* contents) {
    BackupFile bf;
    strcpy(bf.filename, filename);
    strcpy(bf.contents, contents);
    if (bs->num_files == MAX_BACKUP_FILES) {
        printf("Error: maximum number of backup files reached.\n");
    }
    else {
        bs->files[bs->num_files] = bf;
        bs->num_files++;
    }
}

// Function to print all backup files in the system
void printBackupFiles(BackupSystem* bs) {
    printf("Backup files:\n");
    for (int i=0; i<bs->num_files; i++) {
        printf("  %d: %s\n", i+1, bs->files[i].filename);
    }
}

// Function to print the contents of a specific backup file
void printBackupFileContents(BackupSystem* bs, int index) {
    if (index < 1 || index > bs->num_files) {
        printf("Error: invalid file index.\n");
    }
    else {
        printf("Backup file contents:\n");
        printf("%s\n", bs->files[index-1].contents);
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char contents[MAX_FILENAME_LENGTH*10];
    BackupSystem bs;
    bs.num_files = 0;

    // Example usage of backup system
    printf("Creating backup files...\n");
    strcpy(filename, "file1.txt");
    strcpy(contents, "This is the contents of file1.");
    createBackupFile(&bs, filename, contents);
    strcpy(filename, "file2.txt");
    strcpy(contents, "This is the contents of file2.");
    createBackupFile(&bs, filename, contents);
    printBackupFiles(&bs);
    printBackupFileContents(&bs, 1);
    printBackupFileContents(&bs, 2);

    return 0;
}