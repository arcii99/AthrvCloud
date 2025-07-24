//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[100];
} File;

typedef struct {
    File files[MAX_FILES];
    int numFiles;
    int totalSize;
} FileSystem;

File createFile(char* name, int size, char* data) {
    File f;
    strcpy(f.name, name);
    f.size = size;
    strcpy(f.data, data);
    return f;
}

void addFile(FileSystem* fs, File f) {
    if (fs->numFiles >= MAX_FILES) {
        printf("Error: File system full\n");
        return;
    }
    fs->files[fs->numFiles] = f;
    fs->totalSize += f.size;
    fs->numFiles++;
}

void deleteFile(FileSystem* fs, char* name) {
    int indexToDelete = -1;
    for (int i = 0; i < fs->numFiles; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        printf("Error: File not found\n");
        return;
    }
    fs->totalSize -= fs->files[indexToDelete].size;
    for (int i = indexToDelete; i < fs->numFiles-1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->numFiles--;
}

void printFiles(FileSystem fs) {
    printf("%d files, %d bytes\n", fs.numFiles, fs.totalSize);
    for (int i = 0; i < fs.numFiles; i++) {
        printf("%s - %d bytes\n", fs.files[i].name, fs.files[i].size);
    }
}

int main() {
    FileSystem fs;
    fs.numFiles = 0;
    fs.totalSize = 0;

    addFile(&fs, createFile("file1.txt", 10, "Hello, world!"));
    addFile(&fs, createFile("file2.txt", 20, "This is a test file."));
    printFiles(fs);

    deleteFile(&fs, "file1.txt");
    printFiles(fs);

    return 0;
}