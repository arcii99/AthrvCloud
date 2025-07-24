//FormAI DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BLOCKS 1000

// Structure to define a file
struct File {
    char name[20];
    int size;
    int blocks[10]; // Maximum 10 blocks for each file
    int block_count; // Number of blocks occupied by the file
};

// Structure to define a block
struct Block {
    int occupied; // 0 - free, 1 - occupied
    int next_block; // -1 if not occupied, else index of the next block
};

// Global variables
struct Block blocks[MAX_BLOCKS];
struct File files[MAX_BLOCKS];
int file_count = 0;

// Initializes the file system
void initFileSystem() {
    printf("Initializing the file system...\n");
    for(int i=0; i<MAX_BLOCKS; i++) {
        blocks[i].occupied = 0;
        blocks[i].next_block = -1;
    }
    printf("File system initialized successfully!\n");
}

// Function to allocate a new block
int allocateBlock() {
    for(int i=0; i<MAX_BLOCKS; i++) {
        if(blocks[i].occupied == 0) {
            blocks[i].occupied = 1;
            blocks[i].next_block = -1;
            return i;
        }
    }
    return -1;
}

// Function to create a new file
void createFile(char* name, int size) {
    int blocks_required = (size+3)/4; // Each block can hold 4 bytes
    int blocks[blocks_required];

    for(int i=0; i<blocks_required; i++) {
        int block_index = allocateBlock();
        if(block_index == -1) {
            printf("Not enough space to create the file!\n");
            return;
        }
        blocks[i] = block_index;
    }

    struct File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.block_count = blocks_required;
    for(int i=0; i<blocks_required; i++) {
        new_file.blocks[i] = blocks[i];
    }

    files[file_count++] = new_file;
    printf("File created successfully!\n");
}

// Function to delete a file
void deleteFile(char* name) {
    int index = -1;
    for(int i=0; i<file_count; i++) {
        if(strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("File not found!\n");
        return;
    }

    for(int i=0; i<files[index].block_count; i++) {
        blocks[files[index].blocks[i]].occupied = 0;
        blocks[files[index].blocks[i]].next_block = -1;
    }

    for(int i=index; i<file_count-1; i++) {
        files[i] = files[i+1];
    }
    file_count--;

    printf("File deleted! \n");
}

// Function to display the contents of the file system
void displayFileSystem() {
    printf("Displaying file system state...\n");
    for(int i=0; i<MAX_BLOCKS; i++) {
        if(blocks[i].occupied == 1) {
            printf("Block %d is occupied ", i);
            if(blocks[i].next_block == -1) {
                printf("by a file\n");
            }
            else {
                printf("by a file, next block is %d\n", blocks[i].next_block);
            }
        }
    }

    printf("\nList of files:\n");
    for(int i=0; i<file_count; i++) {
        printf("%s - size: %d bytes, blocks occupied: ", files[i].name, files[i].size);
        for(int j=0; j<files[i].block_count; j++) {
            printf("%d ", files[i].blocks[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    initFileSystem();

    createFile("file1", 1024);
    createFile("file2", 2048);
    createFile("file3", 512);
    deleteFile("file2");
    createFile("file4", 4096);
    deleteFile("file1");
    createFile("file5", 8192);
    displayFileSystem();

    return 0;
}