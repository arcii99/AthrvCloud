//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // Size of each block in bytes
#define NUM_BLOCKS 4096 // Number of blocks in the file system

typedef struct {
    char name[20];
    int size;
    int blockNum;
    int parent;
} File;

File fileList[50]; // Maximum of 50 files in the system
int numFiles = 0;
int freeBlocks[NUM_BLOCKS] = {0}; // Array of free blocks in the system

void initializeFileSystem() {
    // Set all blocks as free
    for (int i = 0; i < NUM_BLOCKS; i++) {
        freeBlocks[i] = 1;
    }
}

int allocateBlock() {
    // Find first free block and return its index
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (freeBlocks[i] == 1) {
            freeBlocks[i] = 0; // Mark block as used
            return i;
        }
    }
    return -1; // No free blocks available
}

int createFile(char name[], int size, int parent) {
    int blockNum = allocateBlock();
    if (blockNum == -1) {
        printf("Error: File system full\n");
        return -1;
    }
    File newFile;
    strcpy(newFile.name, name);
    newFile.size = size;
    newFile.blockNum = blockNum;
    newFile.parent = parent;
    fileList[numFiles++] = newFile; // Add new file to file list
    printf("File %s created with size %d in block %d\n", name, size, blockNum);
    return blockNum;
}

void deleteFile(int blockNum) {
    // Free block and remove file from file list
    freeBlocks[blockNum] = 1;
    int index = -1;
    for (int i = 0; i < numFiles; i++) {
        if (fileList[i].blockNum == blockNum) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < numFiles - 1; i++) {
            fileList[i] = fileList[i + 1];
        }
        numFiles--;
        printf("File in block %d deleted\n", blockNum);
    }
}

void displayFiles(int parent) {
    for (int i = 0; i < numFiles; i++) {
        if (fileList[i].parent == parent) {
            printf("%s (%d bytes)\n", fileList[i].name, fileList[i].size);
        }
    }
}

int main() {
    initializeFileSystem();

    // Create a root directory
    createFile("root", 0, -1);

    // Create some files in the root directory
    int file1 = createFile("file1", 1024, 0);
    int file2 = createFile("file2", 2048, 0);

    // Create a subdirectory
    int dir1 = createFile("dir1", 0, 0);

    // Create a file in the subdirectory
    int file3 = createFile("file3", 512, dir1);

    // Delete a file
    deleteFile(file2);

    // Display files in root directory
    printf("Files in root directory:\n");
    displayFiles(0);

    // Display files in subdirectory
    printf("Files in subdirectory:\n");
    displayFiles(dir1);

    return 0;
}