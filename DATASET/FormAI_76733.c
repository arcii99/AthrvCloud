//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

void backupFile(FILE *srcFile, FILE *destFile);

int main(int argc, char *argv[]) {
    // Make sure correct amount of arguments were passed
    if (argc != 3) {
        printf("Usage: ./backup [sourceFile] [destinationFile]\n");
        return 1;
    }

    // Open the source file for reading
    FILE *srcFile = fopen(argv[1], "r");
    if (srcFile == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Open the destination file for writing
    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        return 1;
    }

    // Backup the file
    backupFile(srcFile, destFile);

    // Close the file pointers
    fclose(srcFile);
    fclose(destFile);

    return 0;
}

void backupFile(FILE *srcFile, FILE *destFile) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, srcFile) != NULL) {
        fputs(line, destFile);
    }
}