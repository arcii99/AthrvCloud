//FormAI DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char fileText[MAX_FILE_SIZE];
} File;

void createBackup(File* file) {
    char backupName[MAX_FILE_NAME_LENGTH + 5] = "~back";
    int i = 0;
    while (file->fileName[i] != '.') {
        backupName[i + 5] = file->fileName[i];
        i++;
    }
    FILE* backupFile = fopen(backupName, "w");
    if (backupFile == NULL) {
        printf("Error creating backup for %s\n", file->fileName);
        return;
    }
    fputs(file->fileText, backupFile);
    fclose(backupFile);
    printf("%s backed up successfully as %s\n", file->fileName, backupName);
}

int main() {
    File myFile;
    printf("Enter file name: ");
    fgets(myFile.fileName, MAX_FILE_NAME_LENGTH, stdin);
    printf("Enter text in the file: ");
    fgets(myFile.fileText, MAX_FILE_SIZE, stdin);
    
    createBackup(&myFile);
    
    return 0;
}