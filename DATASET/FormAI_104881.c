//FormAI DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>

#define MAX_FILES 100
#define MAX_FILENAME 256

typedef struct {
    char fileName[MAX_FILENAME];
    int fileSize;
    char *fileData;
} File;

File files[MAX_FILES];
int numFiles = 0;

int createFile(char *fileName, int fileSize) {
    if (numFiles >= MAX_FILES) {
        printf("Error: Maximum file limit reached\n");
        return -1;
    }
    files[numFiles].fileSize = fileSize;
    files[numFiles].fileData = (char *) malloc(fileSize * sizeof(char));
    strcpy(files[numFiles].fileName, fileName);
    numFiles++;
    return 0;
}

int main() {
    if (createFile("example.txt", 100) == 0) {
        printf("File created successfully\n");
    }
    return 0;
}