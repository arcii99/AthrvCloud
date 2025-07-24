//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LENGTH 100

struct FileInfo {
    char* name;
    char* content;
    int length;
    time_t timestamp;
};

struct Backup {
    struct FileInfo* files[MAX_FILES];
    int fileCount;
};

void backupFile(struct Backup* backup, char* fileName) {
    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Error: failed to open file %s for backup.\n", fileName);
        return;
    }

    struct FileInfo* fileInfo = (struct FileInfo*) malloc(sizeof(struct FileInfo));
    fileInfo->name = (char*) malloc(sizeof(char) * MAX_FILE_NAME_LENGTH);
    strcpy(fileInfo->name, fileName);

    fseek(file, 0, SEEK_END);
    fileInfo->length = ftell(file);
    rewind(file);

    fileInfo->content = (char*) malloc(sizeof(char) * (fileInfo->length + 1));
    fread(fileInfo->content, sizeof(char), fileInfo->length, file);
    fileInfo->content[fileInfo->length] = '\0';

    fileInfo->timestamp = time(NULL);

    backup->files[backup->fileCount++] = fileInfo;

    fclose(file);
}

void printFileInfo(struct FileInfo* fileInfo) {
    printf("File: %s\nTimestamp: %dContent: %s\n\n", fileInfo->name, (int)fileInfo->timestamp, fileInfo->content);
}

void printBackup(struct Backup* backup) {
    printf("Backup:\n");
    for(int i = 0; i < backup->fileCount; i++) {
        printFileInfo(backup->files[i]);
    }
}

int main() {
    struct Backup backup;
    backup.fileCount = 0;

    backupFile(&backup, "file1.txt");
    backupFile(&backup, "file2.txt");
    backupFile(&backup, "file3.txt");

    printBackup(&backup);

    return 0;
}