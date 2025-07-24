//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

void backupFile(char *filename);

int main() {
    printf("Welcome to the Shocked C File Backup System!\n");
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter a filename to backup: ");
    scanf("%s", filename);
    backupFile(filename);
    printf("File backup complete! Your file %s is now safe and sound.\n", filename);
    return 0;
}

void backupFile(char *filename) {
    FILE *originalFile, *backupFile;
    char backupFilename[MAX_FILENAME_LENGTH+4];
    // add ".bak" extension to filename
    strcpy(backupFilename, filename);
    strcat(backupFilename, ".bak");
    originalFile = fopen(filename, "r");
    backupFile = fopen(backupFilename, "w");
    if (originalFile == NULL) {
        printf("Error opening file %s. Backup failed.\n", filename);
        exit(1);
    }
    if (backupFile == NULL) {
        printf("Error creating backup file %s. Backup failed.\n", backupFilename);
        exit(1);
    }
    int c;
    while ((c = fgetc(originalFile)) != EOF) {
        fputc(c, backupFile);
    }
    fclose(originalFile);
    fclose(backupFile);
}