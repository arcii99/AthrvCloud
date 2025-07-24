//FormAI DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_VERSIONS 10
#define MAX_FILE_SIZE 1024

typedef struct FileBackup {
    char filename[MAX_FILENAME_LENGTH];
    char backupVersions[MAX_BACKUP_VERSIONS][MAX_FILE_SIZE];
    int backupCount;
} FileBackup;

void backupFile(char *filename, FileBackup *fb) {
    printf("Backing up file %s...\n", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file %s does not exist.\n", filename);
        return;
    }

    // Read file contents
    char fileContents[MAX_FILE_SIZE];
    char c;
    int i = 0;
    while ((c = getc(file)) != EOF && i < MAX_FILE_SIZE) {
        fileContents[i] = c;
        i++;
    }
    fclose(file);

    // Create file backup
    if (fb->backupCount == MAX_BACKUP_VERSIONS) {
        // Remove oldest backup to make room for new one
        for (int j = 1; j < MAX_BACKUP_VERSIONS; j++) {
            strcpy(fb->backupVersions[j-1], fb->backupVersions[j]);
        }
        fb->backupCount--;
    }
    strcpy(fb->backupVersions[fb->backupCount], fileContents);
    fb->backupCount++;

}

void restoreFile(char *filename, FileBackup *fb, int version) {
    printf("Restoring file %s to version %d...\n", filename, version);

    if (version < 0 || version >= fb->backupCount) {
        printf("Error: invalid version number.\n");
        return;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file %s.\n", filename);
        return;
    }
    fwrite(fb->backupVersions[version], sizeof(char), strlen(fb->backupVersions[version]), file);
    fclose(file);
}

void printBackupVersions(FileBackup *fb) {
    printf("Backup versions for file %s:\n", fb->filename);
    for (int i = 0; i < fb->backupCount; i++) {
        printf("%d. ", i);
        printf("%s\n", fb->backupVersions[i]);
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize file backup system
    FileBackup fb;
    fb.backupCount = 0;

    // Perform backup of example file
    backupFile("example.txt", &fb);

    // Perform backup of example file 5 more times (for a total of 6)
    for (int i = 0; i < 5; i++) {
        int version = rand() % fb.backupCount;
        restoreFile("example.txt", &fb, version);
        backupFile("example.txt", &fb);
    }

    // Print backup versions for example file
    printBackupVersions(&fb);

    return 0;
}