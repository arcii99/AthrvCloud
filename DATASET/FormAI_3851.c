//FormAI DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUM_BLOCKS 100

typedef struct {
    char fileName[MAX_NAME_LENGTH];
    int startBlock;
    int numBlocks;
} FileEntry;

FileEntry fileTable[MAX_NUM_BLOCKS];

/* Simulate the creation of a file */
void createFile(char *fileName, int numBlocks) {

    /* Set the start block of the file */
    int startBlock = -1;
    for (int i = 0; i < MAX_NUM_BLOCKS; i++) {
        if (fileTable[i].fileName[0] == '\0') {
            startBlock = i;
            break;
        }
    }

    if (startBlock != -1) {
        /* Update file table with new entry */
        strncpy(fileTable[startBlock].fileName, fileName, MAX_NAME_LENGTH);
        fileTable[startBlock].startBlock = startBlock;
        fileTable[startBlock].numBlocks = numBlocks;

        printf("File %s created with %d block(s) starting at block %d.\n",
               fileName, numBlocks, startBlock);
    } else {
        printf("File system is full. File creation failed.\n");
    }
}

/* Simulate the deletion of a file */
void deleteFile(char *fileName) {

    /* Search file table for matching file name */
    for (int i = 0; i < MAX_NUM_BLOCKS; i++) {
        if (strncmp(fileTable[i].fileName, fileName, MAX_NAME_LENGTH) == 0) {

            /* Clear the file entry in the file table */
            fileTable[i].fileName[0] = '\0';
            fileTable[i].startBlock = -1;
            fileTable[i].numBlocks = -1;

            printf("File %s deleted.\n", fileName);
            return;
        }
    }

    /* File name not found in file table */
    printf("File %s not found.\n", fileName);
}

int main() {

    /* Initialize file table entries */
    for (int i = 0; i < MAX_NUM_BLOCKS; i++) {
        fileTable[i].fileName[0] = '\0';
        fileTable[i].startBlock = -1;
        fileTable[i].numBlocks = -1;
    }

    /* Simulate creation of files */
    createFile("file1.txt", 5);
    createFile("file2.txt", 3);
    createFile("file3.txt", 2);

    /* Simulate deletion of a file */
    deleteFile("file1.txt");

    /* Print out file table */
    printf("File Table\n");
    printf("==========\n");
    printf("Start Block | Num Blocks | File Name\n");
    printf("------------------------------------\n");
    for (int i = 0; i < MAX_NUM_BLOCKS; i++) {
        if (fileTable[i].fileName[0] != '\0') {
            printf("%-12d | %-10d | %s\n",
                   fileTable[i].startBlock, fileTable[i].numBlocks, fileTable[i].fileName);
        }
    }

    return 0;
}