//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // maximum number of files to backup
#define MAX_FILENAME_LENGTH 50 // maximum length of a filename
#define BUFFER_SIZE 1024 // size of the backup buffer

// function to copy file contents from source to destination
int copyFile(const char *source, const char *destination) {
    FILE *fsrc, *fdst;
    int bytesCopied = 0;
    
    // open the source file in read mode
    fsrc = fopen(source, "rb");
    if (fsrc == NULL) {
        return -1; // error opening source file
    }
    
    // open the destination file in write mode
    fdst = fopen(destination, "wb");
    if (fdst == NULL) {
        fclose(fsrc);
        return -2; // error opening destination file
    }
    
    // copy contents from source to destination
    char buffer[BUFFER_SIZE];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fsrc)) > 0) {
        fwrite(buffer, 1, bytesRead, fdst);
        bytesCopied += bytesRead;
    }
    
    // close the files
    fclose(fsrc);
    fclose(fdst);
    
    return bytesCopied;
}

int main() {
    char filenames[MAX_FILES][MAX_FILENAME_LENGTH]; // array to store filenames
    int numFiles = 0; // number of files to backup
    char backupDir[MAX_FILENAME_LENGTH]; // backup directory name
    
    // read backup directory name from user
    printf("Enter backup directory name: ");
    fgets(backupDir, MAX_FILENAME_LENGTH, stdin);
    backupDir[strcspn(backupDir, "\n")] = 0; // remove newline character from input
    
    // ensure backup directory exists
    
    // read filenames from user
    char filename[MAX_FILENAME_LENGTH];
    do {
        printf("Enter filename (blank to stop): ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        if (strcmp(filename, "\n") != 0) { // filename not blank
            filename[strcspn(filename, "\n")] = 0; // remove newline character from input
            strcpy(filenames[numFiles], filename);
            numFiles++;
        }
    } while (strcmp(filename, "\n") != 0 && numFiles < MAX_FILES);
    
    // backup each file
    int i;
    char backupFilename[MAX_FILENAME_LENGTH];
    for (i = 0; i < numFiles; i++) {
        // generate backup filename
        sprintf(backupFilename, "%s/%s.bak", backupDir, filenames[i]);
        
        // copy file to backup directory
        int bytesCopied = copyFile(filenames[i], backupFilename);
        if (bytesCopied == -1) {
            printf("Error: Could not open file %s\n", filenames[i]);
        } else if (bytesCopied == -2) {
            printf("Error: Could not create backup file for %s\n", filenames[i]);
        } else {
            printf("File %s backed up to %s (%d bytes copied)\n", filenames[i], backupFilename, bytesCopied);
        }
    }
    
    return 0;
}