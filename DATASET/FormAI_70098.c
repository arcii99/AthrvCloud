//FormAI DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char filename[BUFFER_SIZE];
    char backupFilename[BUFFER_SIZE + 5];
    char command[BUFFER_SIZE + 50];
    FILE *srcFile, *backupFile;
    int fileSize, ch;

    printf("Enter the name of the file to backup: ");
    fgets(filename, BUFFER_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    srcFile = fopen(filename, "rb");
    if (srcFile == NULL)
    {
        printf("Error: Could not open source file.\n");
        exit(EXIT_FAILURE);
    }

    // Generate backup filename
    strcpy(backupFilename, filename);
    strcat(backupFilename, ".bak");

    // Create or open backup file
    backupFile = fopen(backupFilename, "wb");
    if (backupFile == NULL)
    {
        printf("Error: Could not create or open backup file.\n");
        fclose(srcFile); // Close the source file before exiting
        exit(EXIT_FAILURE);
    }

    // Copy data from srcFile to backupFile
    fileSize = 0;
    while ((ch = fgetc(srcFile)) != EOF)
    {
        fputc(ch, backupFile);
        fileSize++;
    }

    // Close both files
    fclose(srcFile);
    fclose(backupFile);

    // Print success message
    printf("Backup of '%s' (%d bytes) created as '%s'\n", filename, fileSize, backupFilename);

    // Optional: compress the backup file using gzip
    sprintf(command, "gzip %s", backupFilename);
    system(command);

    return 0;
}