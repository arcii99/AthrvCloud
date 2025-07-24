//FormAI DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void backupFile(char *, char *);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Error: incorrect number of arguments.\n");
        printf("Usage: %s [file-to-backup] [backup-directory]\n", argv[0]);
        exit(1);
    }

    char *fileToBackup = argv[1];
    char *backupDirectory = argv[2];

    backupFile(fileToBackup, backupDirectory);

    printf("Backup successful! (%s -> %s)\n", fileToBackup, backupDirectory);

    return 0;
}

void backupFile(char *fileName, char *backupDir) {
    char backupFileName[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *inputFile, *outputFile;

    // Create backup file name by appending ".bak" to original file name
    snprintf(backupFileName, sizeof(backupFileName), "%s/%s.bak", backupDir, fileName);

    // Open input file and backup file
    inputFile = fopen(fileName, "rb");
    if(inputFile == NULL) {
        printf("Error: could not open file '%s'\n", fileName);
        exit(1);
    }

    outputFile = fopen(backupFileName, "wb");
    if(outputFile == NULL) {
        printf("Error: could not create backup file '%s'\n", backupFileName);
        fclose(inputFile);
        exit(1);
    }

    // Copy contents of input file to output file
    while(fread(buffer, sizeof(char), sizeof(buffer), inputFile)) {
        fwrite(buffer, sizeof(char), sizeof(buffer), outputFile);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);
}