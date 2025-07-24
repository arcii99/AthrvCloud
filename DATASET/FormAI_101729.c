//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

int main() {

    char fileName[MAX_FILE_NAME_LENGTH];
    char backupFileName[MAX_FILE_NAME_LENGTH + 4];
    char fileContent[10000];
    FILE *filePtr;
    FILE *backupPtr;
    int bytesRead;

    printf("Enter the name of the file to be backed up: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);

    fileName[strcspn(fileName, "\n")] = 0; // remove trailing newline character

    filePtr = fopen(fileName, "r");

    if (filePtr == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    backupFileName[0] = '\0';
    strcat(backupFileName, fileName);
    strcat(backupFileName, ".bak");

    backupPtr = fopen(backupFileName, "w");

    if (backupPtr == NULL) {
        printf("Error: Unable to create backup file.\n");
        fclose(filePtr);
        return 1;
    }

    while ((bytesRead = fread(fileContent, 1, 10000, filePtr)) > 0) {
        fwrite(fileContent, 1, bytesRead, backupPtr);
    }

    fclose(filePtr);
    fclose(backupPtr);

    printf("Backup created successfully.\n");
    return 0;
}