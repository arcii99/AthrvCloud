//FormAI DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20
#define MAX_FILE_NAME 30

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    int location;
} File;

File files[MAX_FILES];
int numFiles = 0;
int nextLocation = 0;

void createFile(char *name, int size) {
    if (numFiles >= MAX_FILES) {
        printf("File system full. Cannot create new file.\n");
        return;
    }
    
    File newFile;
    newFile.size = size;
    newFile.location = nextLocation;
    
    for (int i = 0; i < MAX_FILE_NAME; i++) {
        newFile.name[i] = name[i];
        if (name[i] == '\0') {
            break;
        }
    }
    
    files[numFiles++] = newFile;
    nextLocation += size;
}

void deleteFile(char *name) {
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            for (int j = i; j < numFiles - 1; j++) {
                files[j] = files[j+1];
            }
            numFiles--;
            nextLocation = files[numFiles-1].location + files[numFiles-1].size;
            printf("File %s deleted.\n", name);
            return;
        }
    }
    printf("File %s not found.\n", name);
}

void printFiles() {
    printf("Files in File System:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s\t%d\t%d\n", files[i].name, files[i].size, files[i].location);
    }
}

int main() {
    createFile("file1.txt", 100);
    createFile("file2.txt", 50);
    createFile("file3.txt", 75);
    
    printFiles();
    
    deleteFile("file1.txt");
    deleteFile("file4.txt");
    
    printFiles();
    
    return 0;
}