//FormAI DATASET v1.0 Category: File system simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining block size
#define BLOCK_SIZE 512

// Defining maximum number of blocks
#define MAX_BLOCKS_NUM 100

// Defining max file name size
#define MAX_FILE_NAME_SIZE 20

// Block structure
struct Block {
    int blockNum; // Block Number: 0, 1, 2...
    char data[BLOCK_SIZE]; // Actual block data
};

// File structure
struct File {
    char fileName[MAX_FILE_NAME_SIZE]; // File Name
    int blocks[MAX_BLOCKS_NUM]; // Blocks where file data exists
    int numBlocks; // Number of Blocks used by file
    int size; // Size of file
};

// Global Variables
struct Block blocks[MAX_BLOCKS_NUM]; // Blocks
struct File files[MAX_BLOCKS_NUM]; // Files list
int numBlocksUsed = 0; // Number of blocks currently used
int numFiles = 0; // Number of files currently stored

// Function to initialize file system
void initializeSystem() {
    int i;
    for(i = 0; i < MAX_BLOCKS_NUM; i++) {
        blocks[i].blockNum = i; // Set block number
        memset(blocks[i].data, 0, sizeof(blocks[i].data)); // Set block data to 0
    }
}

// Function to create a new file
void createFile(char* fileName, int size) {
    // Create new file object
    struct File newFile;
    strcpy(newFile.fileName, fileName);
    newFile.size = size;

    // Determine number of blocks required to store file data
    int numBlocksRequired = size/BLOCK_SIZE;
    if(size % BLOCK_SIZE != 0) {
        numBlocksRequired++;
    }

    // Check if enough blocks are available
    if(numBlocksUsed + numBlocksRequired > MAX_BLOCKS_NUM) {
        printf("Error: Not enough space available\n");
        return;
    }

    // Allocate required blocks to file
    newFile.numBlocks = numBlocksRequired;
    int i;
    for(i = 0; i < numBlocksRequired; i++) {
        newFile.blocks[i] = numBlocksUsed + i;
        numBlocksUsed++;
    }

    // Add file to files list
    files[numFiles++] = newFile;

    printf("File '%s' created successfully\n", fileName);
}

// Function to delete an existing file
void deleteFile(char* fileName) {
    int i, j;
    for(i = 0; i < numFiles; i++) {
        if(strcmp(files[i].fileName, fileName) == 0) {
            // Remove file blocks
            for(j = 0; j < files[i].numBlocks; j++) {
                blocks[files[i].blocks[j]].blockNum = -1;
                numBlocksUsed--;
            }

            // Remove file from files list
            for(j = i; j < numFiles - 1; j++) {
                files[j] = files[j+1];
            }
            numFiles--;

            printf("File '%s' deleted successfully\n", fileName);
            return;
        }
    }

    printf("Error: File '%s' not found.\n", fileName);
}

// Function to write data to a file
void writeFile(char* fileName, char* data) {
    int i, j;
    for(i = 0; i < numFiles; i++) {
        if(strcmp(files[i].fileName, fileName) == 0) {
            // Write data to file blocks
            int dataPos = 0;
            for(j = 0; j < files[i].numBlocks; j++) {
                memcpy(blocks[files[i].blocks[j]].data, &data[dataPos], sizeof(blocks[files[i].blocks[j]].data));
                dataPos += sizeof(blocks[files[i].blocks[j]].data);
            }

            printf("Data written successfully to file '%s'\n", fileName);
            return;
        }
    }

    printf("Error: File '%s' not found.\n", fileName);
}

// Function to read data from a file
void readFile(char* fileName) {
    int i, j;
    for(i = 0; i < numFiles; i++) {
        if(strcmp(files[i].fileName, fileName) == 0) {
            // Read data from file blocks
            int dataSize = files[i].size;
            char data[dataSize+1];
            int dataPos = 0;
            for(j = 0; j < files[i].numBlocks; j++) {
                memcpy(&data[dataPos], blocks[files[i].blocks[j]].data, sizeof(blocks[files[i].blocks[j]].data));
                dataPos += sizeof(blocks[files[i].blocks[j]].data);
            }
            data[dataSize] = '\0';
            printf("Data read successfully from file '%s': \n%s\n", fileName, data);
            return;
        }
    }

    printf("Error: File '%s' not found.\n", fileName);
}

int main() {
    // Initializing file system
    initializeSystem();

    // Testing filesystem operations
    createFile("test1.txt", 1025);
    writeFile("test1.txt", "This is a test file.\nThis is the second line.");
    readFile("test1.txt");
    deleteFile("test1.txt");

    return 0;
}