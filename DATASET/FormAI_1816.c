//FormAI DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    int size;
    int isDeleted;
};

struct file_system {
    struct file files[MAX_FILES];
    int numFiles;
};

void createFile(struct file_system *fs, char *name, char *data, int size) {
    if (fs->numFiles >= MAX_FILES) {
        printf("File system is full. Cannot create file.\n");
        return;
    }
    struct file *f = &fs->files[fs->numFiles];
    strcpy(f->name, name);
    memcpy(f->data, data, size);
    f->size = size;
    f->isDeleted = 0;
    fs->numFiles++;
    printf("File %s created.\n", name);
}

void deleteFile(struct file_system *fs, char *name) {
    for (int i = 0; i < fs->numFiles; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->files[i].isDeleted = 1;
            printf("File %s deleted.\n", name);
            return;
        }
    }
    printf("Could not find file %s.\n", name);
}

void readFile(struct file_system *fs, char *name) {
    for (int i = 0; i < fs->numFiles; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File %s contents:\n%s\n", name, fs->files[i].data);
            return;
        }
    }
    printf("Could not find file %s.\n", name);
}

int main() {
    struct file_system fs;
    fs.numFiles = 0;
    
    createFile(&fs, "file1.txt", "This is the contents of file 1.\n", 33);
    createFile(&fs, "file2.txt", "This is the contents of file 2.\n", 33);
    
    readFile(&fs, "file1.txt");
    deleteFile(&fs, "file1.txt");
    readFile(&fs, "file1.txt");
    
    return 0;
}