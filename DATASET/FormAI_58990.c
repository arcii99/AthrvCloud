//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 4096
#define MAX_FILES 16
#define MAX_FILE_NAME 64

typedef struct {
    char block[BLOCK_SIZE];
} Block;

typedef struct {
    int blockIndex[MAX_BLOCKS];
    int size;
} Inode;

typedef struct {
    char name[MAX_FILE_NAME];
    Inode inode;
} File;

typedef struct {
    File files[MAX_FILES];
} Directory;

Block fileSystem[MAX_BLOCKS];
Directory rootDir;

int findFreeBlock() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (fileSystem[i].block == NULL) {
            return i;
        }
    }
    return -1;
}

int findFreeInode() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (rootDir.files[i].name == NULL) {
            return i;
        }
    }
    return -1;
}

int storeBlock(char *data) {
    int blockIndex = findFreeBlock();
    if (blockIndex == -1) {
        printf("Error: file system full!\n");
        return -1;
    }
    strcpy(&fileSystem[blockIndex].block, data);
    return blockIndex;
}

void createFile(char *name) {
    int inodeIndex = findFreeInode();
    if (inodeIndex == -1) {
        printf("Error: maximum number of files reached!\n");
        return;
    }
    strcpy(&rootDir.files[inodeIndex].name, name);
}

void writeFile(char *name, char *data) {
    int inodeIndex = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(rootDir.files[i].name, name) == 0) {
            inodeIndex = i;
            break;
        }
    }
    if (inodeIndex == -1) {
        printf("Error: file not found!\n");
        return;
    }
    int blockIndex = storeBlock(data);
    if (blockIndex == -1) {
        return;
    }
    Inode *inode = &rootDir.files[inodeIndex].inode;
    inode->blockIndex[inode->size] = blockIndex;
    inode->size++;
}

void readFile(char *name) {
    int inodeIndex = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(rootDir.files[i].name, name) == 0) {
            inodeIndex = i;
            break;
        }
    }
    if (inodeIndex == -1) {
        printf("Error: file not found!\n");
        return;
    }
    Inode *inode = &rootDir.files[inodeIndex].inode;
    for (int i = 0; i < inode->size; i++) {
        printf("%s", &fileSystem[inode->blockIndex[i]].block);
    }
}

void initFileSystem() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fileSystem[i].block[0] = '\0';
    }
    for (int i = 0; i < MAX_FILES; i++) {
        rootDir.files[i].name[0] = '\0';
    }
}

int main() {
    initFileSystem();
    createFile("hello.txt");
    writeFile("hello.txt", "Hello World!\n");
    readFile("hello.txt");
    return 0;
}