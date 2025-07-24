//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 255
#define MAX_FILES 50

typedef struct {
    char name[MAX_PATH_LENGTH];
    int size;
} File;

void readFileList(char *path, File fileList[], int *count) {
    FILE *fp;
    char command[MAX_PATH_LENGTH];

    sprintf(command, "dir /s %s > .fileList.tmp", path);
    system(command);

    fp = fopen(".fileList.tmp", "r");
    if (fp == NULL) {
        printf("Error: unable to open file list\n");
        exit(1);
    }

    char buf[MAX_PATH_LENGTH+20];
    char *pos;
    char *name;
    *count = 0;

    while (fgets(buf, MAX_PATH_LENGTH+20, fp)) {
        if ((pos=strstr(buf, "bytes")) != NULL) {
            int size = atoi(buf);
            fileList[*count].size = size;
            name = strtok(buf," ");
            name = strtok(NULL," ");
            while (name != NULL) {
                sprintf(fileList[*count].name, "%s/%s", path, name);
                name = strtok(NULL, " ");
            }
            (*count)++;
        }
    }
    fclose(fp);
}

void sortFilesBySize(File fileList[], int count) {
    for (int i=0; i<count-1; i++) {
        for (int j=i+1; j<count; j++) {
            if (fileList[j].size > fileList[i].size) {
                File tmp = fileList[i];
                fileList[i] = fileList[j];
                fileList[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH_LENGTH];
    strncpy(path, argv[1], MAX_PATH_LENGTH);
    int count;
    File fileList[MAX_FILES];
    readFileList(path, fileList, &count);
    sortFilesBySize(fileList, count);

    printf("Size of folder %s:\n", path);
    printf("---------------------------------\n");
    printf("%-60s %10s\n", "File Name", "Size (bytes)");
    printf("---------------------------------\n");
    int totalSize = 0;
    for (int i=0; i<count; i++) {
        printf("%-60s %10d\n", fileList[i].name, fileList[i].size);
        totalSize += fileList[i].size;
    }
    printf("---------------------------------\n");
    printf("%-60s %10d\n", "Total Size (bytes)", totalSize);

    return 0;
}