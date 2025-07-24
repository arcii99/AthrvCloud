//FormAI DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define DISK_BLOCKS 1024
#define FILE_NAME_SIZE 20
#define MAX_FILES 10

typedef struct {
    char name[FILE_NAME_SIZE];
    int size;
    int blockPtrs[10];
} file;

typedef struct {
    char freeBlockList[DISK_BLOCKS];
    file fileTable[MAX_FILES];
} disk;

disk hardDisk;

int getFreeBlock() {
    for (int i = 0; i < DISK_BLOCKS; i++) {
        if (hardDisk.freeBlockList[i] == 0) {
            hardDisk.freeBlockList[i] = 1;
            return i;
        }
    }
    return -1;
}

void freeBlock(int block) {
    hardDisk.freeBlockList[block] = 0;
}

void createFile(char* fileName, int size) {
    file newFile;
    strcpy(newFile.name, fileName);
    newFile.size = size;
    for (int i = 0; i < size; i++) {
        int block = getFreeBlock();
        if (block == -1) {
            printf("Error: not enough free blocks\n");
            return;
        }
        newFile.blockPtrs[i] = block;
    }
    for (int i = size; i < 10; i++) {
        newFile.blockPtrs[i] = -1;
    }
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(hardDisk.fileTable[i].name, "") == 0) {
            hardDisk.fileTable[i] = newFile;
            return;
        }
    }
    printf("Error: too many files\n");
}

void deleteFile(char* fileName) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(hardDisk.fileTable[i].name, fileName) == 0) {
            for (int j = 0; j < hardDisk.fileTable[i].size; j++) {
                freeBlock(hardDisk.fileTable[i].blockPtrs[j]);
            }
            hardDisk.fileTable[i].size = 0;
            strcpy(hardDisk.fileTable[i].name, "");
            return;
        }
    }
    printf("Error: file not found\n");
}

void readBlock(int block) {
    printf("Reading block %d\n", block);
}

void writeBlock(int block) {
    printf("Writing block %d\n", block);
}

void readFile(char* fileName) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(hardDisk.fileTable[i].name, fileName) == 0) {
            for (int j = 0; j < hardDisk.fileTable[i].size; j++) {
                readBlock(hardDisk.fileTable[i].blockPtrs[j]);
            }
            return;
        }
    }
    printf("Error: file not found\n");
}

void writeFile(char* fileName) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(hardDisk.fileTable[i].name, fileName) == 0) {
            for (int j = 0; j < hardDisk.fileTable[i].size; j++) {
                writeBlock(hardDisk.fileTable[i].blockPtrs[j]);
            }
            return;
        }
    }
    printf("Error: file not found\n");
}

int main() {
    // Initialize the free block list
    for (int i = 0; i < DISK_BLOCKS; i++) {
        hardDisk.freeBlockList[i] = 0;
    }

    createFile("file1", 3);
    createFile("file2", 5);
    createFile("file3", 2);
    readFile("file1");
    writeFile("file2");
    deleteFile("file3");

    return 0;
}