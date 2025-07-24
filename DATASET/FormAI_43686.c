//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define MAX_BLOCKS 1000

// Define the data structure for the simulated file system.
typedef struct {
    int blockNumber; // the block number for this file.
    char* data; // a pointer to the data for this file.
} FCB;

// Define an array to hold the blocks of memory for the file system.
char* blocks[MAX_BLOCKS];

// Define an array to hold the file control blocks (FCBs) for files on the system.
FCB files[MAX_BLOCKS];

// Initialize the file system.
void initFileSystem() {
    int i;

    // Allocate memory for each block in the file system.
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = (char*) malloc(sizeof(char) * BLOCK_SIZE);
    }
    
    // Initialize the FCBs for each block in the file system.
    for (i = 0; i < MAX_BLOCKS; i++) {
        files[i].blockNumber = -1;
        files[i].data = NULL;
    }
}

// Allocate a new block for a file.
int allocateBlock(int blockNumber) {
    int i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (files[i].blockNumber == -1) {
            files[i].blockNumber = blockNumber;
            files[i].data = blocks[blockNumber];
            return i; // return the index of the allocated block.
        }
    }

    return -1; // return -1 if no block was allocated.
}

// Free a block used by a file.
void freeBlock(int blockNumber) {
    int i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (files[i].blockNumber == blockNumber) {
            files[i].blockNumber = -1;
            files[i].data = NULL;
            return;
        }
    }
}

// Display the contents of a file.
void displayFile(char* fileName) {
    int i;
    int found = 0;

    // Search for the specified file.
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (files[i].blockNumber != -1 && strstr(files[i].data, fileName) != NULL) {
            printf("%s\n", files[i].data);
            found = 1;
        }
    }

    if (!found) {
        printf("File not found.\n");
    }
}

int main() {
    char input[256];
    char* token;
    char* fileName;
    char* fileContents;
    int blockNumber;

    initFileSystem(); // Initialize the file system.

    // Begin the main loop.
    while (1) {

        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);

        token = strtok(input, " ");

        if (strcmp(token, "exit") == 0) {
            break;
        }

        else if (strcmp(token, "create") == 0) {
            fileName = strtok(NULL, " ");
            fileContents = strtok(NULL, "");

            // Allocate a new block for the file, and copy the contents into it.
            blockNumber = allocateBlock(rand() % MAX_BLOCKS);
            strcpy(blocks[blockNumber], fileContents);

            printf("File created: %s\n", fileName);
        }

        else if (strcmp(token, "delete") == 0) {
            fileName = strtok(NULL, " ");

            // Free the block used by the file.
            for (int i = 0; i < MAX_BLOCKS; i++) {
                if (files[i].blockNumber != -1 && strstr(files[i].data, fileName) != NULL) {
                    freeBlock(files[i].blockNumber);
                    printf("File deleted: %s\n", fileName);
                    break;
                }
            }
        }

        else if (strcmp(token, "display") == 0) {
            fileName = strtok(NULL, " ");

            // Display the contents of the file.
            displayFile(fileName);
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}