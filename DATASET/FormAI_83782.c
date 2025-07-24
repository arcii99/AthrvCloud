//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 20
#define MAX_FILE_CONTENT 50

typedef struct {
    char filename[MAX_FILENAME_LEN];
    char content[MAX_FILE_CONTENT];
    int size;
} File;

File filesystem[MAX_FILES];
int numFiles = 0;

void createFile(char *filename) {
    if (numFiles >= MAX_FILES) {
        printf("Maximum number of files exceeded\n");
        return;
    }
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(filesystem[i].filename, filename) == 0) {
            printf("File with the same name already exists\n");
            return;
        }
    }
    File newFile;
    strcpy(newFile.filename, filename);
    newFile.size = 0;
    filesystem[numFiles++] = newFile;
    printf("File %s created successfully\n", filename);
}

void deleteFile(char *filename) {
    int found = 0;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(filesystem[i].filename, filename) == 0) {
            found = 1;
            for (int j = i; j < numFiles - 1; j++) {
                filesystem[j] = filesystem[j+1];
            }
            numFiles--;
            printf("File %s deleted successfully\n", filename);
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
    }
}

void readFile(char *filename) {
    int found = 0;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(filesystem[i].filename, filename) == 0) {
            found = 1;
            printf("%s\n", filesystem[i].content);
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
    }
}

void writeFile(char *filename, char *content) {
    int found = 0;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(filesystem[i].filename, filename) == 0) {
            found = 1;
            strcpy(filesystem[i].content, content);
            filesystem[i].size = strlen(content);
            printf("File %s updated successfully\n", filename);
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
    }
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");
    writeFile("file1.txt", "hello world");
    readFile("file1.txt");
    deleteFile("file2.txt");
    return 0;
}