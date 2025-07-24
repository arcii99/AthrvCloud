//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 256
#define MAX_FILES 1024

typedef struct {
    char name[MAX_PATH];
    double size;
} File;

int countFiles(char *dir);
double getSize(char *dir, char *name);

int main() {
    char dir[MAX_PATH];
    File files[MAX_FILES];
    int numFiles = 0;
    double totalSize = 0.0;

    printf("Welcome to Retro Disk Analyzer!\n");
    printf("Please enter the directory path: ");
    fgets(dir, MAX_PATH, stdin);
    dir[strcspn(dir, "\n")] = '\0';

    numFiles = countFiles(dir);

    if (numFiles == 0) {
        printf("No files found in directory %s\n", dir);
        return 0;
    }

    for (int i = 0; i < numFiles; i++) {
        double size = getSize(dir, files[i].name);
        files[i].size = size;
        totalSize += size;
    }

    printf("\n---------------------------------------------\n");
    printf("Disk space usage report for directory %s\n", dir);
    printf("---------------------------------------------\n");
    printf("%-50s %10s\n", "File Name", "Size");
    printf("---------------------------------------------\n");

    for (int i = 0; i < numFiles; i++) {
        printf("%-50s %10.2fKB\n", files[i].name, files[i].size / 1024.0);
    }

    printf("---------------------------------------------\n");
    printf("%-50s %10.2fKB\n", "Total Size", totalSize / 1024.0);
    printf("---------------------------------------------\n");

    return 0;
}

int countFiles(char *dir) {
    int count = 0;
    char path[MAX_PATH];
    sprintf(path, "dir /b /s %s", dir);

    FILE *fp = popen(path, "r");
    if (!fp) {
        printf("Error executing command.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(path, MAX_PATH, fp) != NULL) {
        count++;
    }

    pclose(fp);
    return count;
}

double getSize(char *dir, char *name) {
    char path[MAX_PATH];
    sprintf(path, "%s\\%s", dir, name);

    FILE *fp = fopen(path, "rb");
    if (!fp) {
        printf("Error opening file %s\n", name);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    double size = ftell(fp);

    fclose(fp);
    return size;
}