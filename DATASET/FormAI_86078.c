//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILES 100

const char* backupDir = "backup/";

struct File {
    char name[256];
    char path[1024];
    unsigned long size;
};

void backupFiles(int argc, char* argv[]);
int getFiles(char* directory, struct File fileArr[]);
void copyFile(char* source, char* destination);
char* generateBackupFileName(char* fileName);
int checkIfFileExists(char* filePath);

int main(int argc, char* argv[]) {
    printf("Welcome to the file backup program!\n");

    backupFiles(argc, argv);

    printf("\nAll files backed up successfully!\n");

    return 0;
}

void backupFiles(int argc, char* argv[]) {
    struct File fileArr[MAXFILES];
    int fileCount = 0;

    for(int i = 1; i < argc; i++) {
        fileCount += getFiles(argv[i], fileArr);
    }

    for(int i = 0; i < fileCount; i++) {
        char* backupFilePath = generateBackupFileName(fileArr[i].path);
        copyFile(fileArr[i].path, backupFilePath);
        printf("Backed up file \"%s\" successfully as \"%s\"\n", fileArr[i].name, backupFilePath);
        free(backupFilePath);
    }
}

int getFiles(char* directory, struct File fileArr[]) {
    int fileCount = 0;
    FILE* fp;
    char filename[256];

    sprintf(filename, "ls -p \"%s\" | grep -v /", directory);

    fp = popen(filename, "r");

    if (fp == NULL) {
        printf("Failed to open directory \"%s\"\n", directory);
        return 0;
    }

    while(fgets(filename, sizeof(filename), fp) != NULL) {
        filename[strcspn(filename, "\n")] = 0;
        char filePath[1024];
        sprintf(filePath, "%s/%s", directory, filename);
        struct File file;
        strcpy(file.name, filename);
        strcpy(file.path, filePath);
        file.size = checkIfFileExists(filePath);
        fileArr[fileCount] = file;
        fileCount++;
    }

    pclose(fp);

    return fileCount;
}

void copyFile(char* source, char* destination) {
    FILE *f1, *f2;
    char buf[4096];

    f1 = fopen(source, "rb");
    f2 = fopen(destination, "wb");

    while(!feof(f1)) {
        size_t sz = fread(buf, 1, sizeof(buf), f1);
        fwrite(buf, 1, sz, f2);
    }

    fclose(f1);
    fclose(f2);
}

char* generateBackupFileName(char* fileName) {
    char* backupFilePath = (char*) malloc(sizeof(char) * 1024);
    sprintf(backupFilePath, "%s%s.backup", backupDir, fileName);
    return backupFilePath;
}

int checkIfFileExists(char* filePath) {
    FILE* fp = fopen(filePath, "rb");
    if(fp == NULL) {
        printf("File \"%s\" does not exist\n", filePath);
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fclose(fp);
    return fileSize;
}