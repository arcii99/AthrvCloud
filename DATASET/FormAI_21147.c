//FormAI DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_EXTENSION_LEN 10

typedef struct File {
    char filename[MAX_FILENAME_LEN];
    char extension[MAX_FILE_EXTENSION_LEN];
    time_t lastModified;
} File;

void backupFile(File *file) {
    // Create backup filename
    char backupFilename[MAX_FILENAME_LEN + MAX_FILE_EXTENSION_LEN + 20]; // Add additional space for timestamp
    time_t rawTime;
    struct tm *timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    strftime(backupFilename, sizeof(backupFilename), "%Y-%m-%d_%H-%M-%S", timeInfo);
    strcat(backupFilename, "_backup_");
    strcat(backupFilename, file->filename);
    strcat(backupFilename, ".");
    strcat(backupFilename, file->extension);
    
    // Open original file and backup file
    FILE *originalFile = fopen(file->filename, "rb");
    FILE *backupFile = fopen(backupFilename, "wb");
    
    // Copy original file to backup file
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), originalFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }
    
    // Close files
    fclose(originalFile);
    fclose(backupFile);
    
    // Update last modified timestamp
    file->lastModified = rawTime;
}

int main() {
    // Initialize file
    File myFile = {"example", "txt", time(NULL)};
    
    // Backup file
    backupFile(&myFile);
    
    // Wait a few seconds
    printf("Waiting for 3 seconds...\n");
    sleep(3);
    
    // Backup file again
    backupFile(&myFile);
    
    // Print success message
    printf("File backup successful!\n");
    
    return 0;
}