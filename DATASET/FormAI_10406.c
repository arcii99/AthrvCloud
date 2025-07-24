//FormAI DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void backupFile(char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);
    
    backupFile(filename);
    
    return 0;
}

void backupFile(char *filename) {
    FILE *infile, *outfile;
    char backupFilename[MAX_FILENAME_LENGTH + 13];
    char buffer[1024];
    size_t bytesRead;

    infile = fopen(filename, "rb");
    if (infile == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    strcpy(backupFilename, filename);
    strcat(backupFilename, ".Backup");

    outfile = fopen(backupFilename, "wb");
    if (outfile == NULL) {
        printf("Unable to open backup file %s\n", backupFilename);
        exit(1);
    }

    printf("Backing up %s to %s...\n", filename, backupFilename);

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), infile)) > 0) {
        fwrite(buffer, 1, bytesRead, outfile);
    }

    fclose(infile);
    fclose(outfile);
}