//FormAI DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20 //Maximum file name length
#define MAX_FILE_COUNT 10 //Maximum number of files that can be stored
#define MAX_FILE_SIZE 1024 //Maximum size of file in bytes
#define BLOCK_SIZE 512 //Block size in bytes
#define MAX_BLOCKS MAX_FILE_SIZE / BLOCK_SIZE //Maximum number of blocks

//File structure
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int block_count;
    int* block_pointers;
} File;

//File system structure
typedef struct {
    int block_map[MAX_BLOCKS]; //Array to represent used and free blocks
    File files[MAX_FILE_COUNT]; //Array to store files in file system
} FileSystem;

//Function to initialize file system
void initialize(FileSystem* fs) {
    int i;
    for(i = 0; i < MAX_BLOCKS; i++) {
        fs->block_map[i] = 0; //Initially all blocks are free
    }
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        strcpy(fs->files[i].name, ""); //Initially file names are empty
    }
}

//Function to allocate a block for file
int allocateBlock(FileSystem* fs) {
    int i;
    for(i = 0; i < MAX_BLOCKS; i++) {
        if(fs->block_map[i] == 0) { //If block is free
            fs->block_map[i] = 1; //Allocate block
            return i;
        }
    }
    return -1; //Return -1 if no block is free
}

//Function to free a block
void freeBlock(FileSystem* fs, int blockNumber) {
    fs->block_map[blockNumber] = 0; //Mark block as free
}

//Function to create a file
int createFile(FileSystem* fs, char name[], int size) {
    int i, j, block_number;
    //Check if file already exists
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            return -1; //Return -1 if file already exists
        }
    }
    //Find free file slot
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        if(strcmp(fs->files[i].name, "") == 0) {
            //Allocate required number of blocks
            int* block_pointers = (int*) malloc(MAX_BLOCKS * sizeof(int));
            for(j = 0; j < MAX_BLOCKS; j++) {
                block_pointers[j] = -1; //Initialize block pointers as -1
            }
            int block_count = 0;
            for(j = 0; j < size; j += BLOCK_SIZE) {
                block_number = allocateBlock(fs); //Allocate block for file
                if(block_number >= 0) { //If block is successfully allocated
                    block_pointers[block_count] = block_number; //Store block pointer in file struct
                    block_count++;
                } else {
                    //Free the already allocated blocks
                    for(j = 0; j < block_count; j++) {
                        freeBlock(fs, block_pointers[j]);
                    }
                    free(block_pointers);
                    return -2; //Return -2 if no free block is available
                }
            }
            //Store file details in file system
            strcpy(fs->files[i].name, name);
            fs->files[i].size = size;
            fs->files[i].block_pointers = block_pointers;
            fs->files[i].block_count = block_count;
            return 1; //Return 1 if file is successfully created
        }
    }
    return -3; //Return -3 if no free file slot is available
}

//Function to read a block
void readBlock(FileSystem* fs, int blockNumber, char* data) {
    //Copy block to buffer
    memcpy(data, fs->block_map + (blockNumber * BLOCK_SIZE), BLOCK_SIZE * sizeof(char));
}

//Function to write a block
void writeBlock(FileSystem* fs, int blockNumber, char* data) {
    //Copy buffer to block
    memcpy(fs->block_map + (blockNumber * BLOCK_SIZE), data, BLOCK_SIZE * sizeof(char));
}

//Function to read data from file
int readFile(FileSystem* fs, char name[], int offset, int size, char* data) {
    int i, j, block_number;
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            if(offset >= fs->files[i].size) {
                return -1; //Return -1 if offset is invalid
            }
            if(offset + size > fs->files[i].size) {
                size = fs->files[i].size - offset; //Read only till end of file
            }
            int start_block = offset / BLOCK_SIZE;
            int end_block = (offset + size - 1) / BLOCK_SIZE;
            int start_offset = offset % BLOCK_SIZE;
            int end_offset = (offset + size - 1) % BLOCK_SIZE;
            int data_index = 0;
            char buffer[BLOCK_SIZE];
            for(j = start_block; j <= end_block; j++) {
                block_number = fs->files[i].block_pointers[j];
                if(block_number < 0) {
                    return -2; //Return -2 if block is not allocated
                }
                readBlock(fs, block_number, buffer); //Read block from disk
                if(j == start_block && j == end_block) {
                    //Block is only partially read
                    for(int k = start_offset; k <= end_offset; k++) {
                        data[data_index++] = buffer[k];
                    }
                } else if(j == start_block) {
                    //First block is partially read
                    for(int k = start_offset; k < BLOCK_SIZE; k++) {
                        data[data_index++] = buffer[k];
                    }
                } else if(j == end_block) {
                    //Last block is partially read
                    for(int k = 0; k <= end_offset; k++) {
                        data[data_index++] = buffer[k];
                    }
                } else {
                    //Block is completely read
                    for(int k = 0; k < BLOCK_SIZE; k++) {
                        data[data_index++] = buffer[k];
                    }
                }
            }
            return size; //Return size of data read
        }
    }
    return -3; //Return -3 if file not found
}

//Function to write data to file
int writeFile(FileSystem* fs, char name[], int offset, int size, char* data) {
    int i, j, block_number;
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            if(offset >= fs->files[i].size) {
                return -1; //Return -1 if offset is invalid
            }
            if(offset + size > fs->files[i].size) {
                size = fs->files[i].size - offset; //Write only till end of file
            }
            int start_block = offset / BLOCK_SIZE;
            int end_block = (offset + size - 1) / BLOCK_SIZE;
            int start_offset = offset % BLOCK_SIZE;
            int end_offset = (offset + size - 1) % BLOCK_SIZE;
            int data_index = 0;
            char buffer[BLOCK_SIZE];
            for(j = start_block; j <= end_block; j++) {
                block_number = fs->files[i].block_pointers[j];
                if(block_number < 0) {
                    return -2; //Return -2 if block is not allocated
                }
                readBlock(fs, block_number, buffer); //Read block from disk
                if(j == start_block && j == end_block) {
                    //Data is only partially written in block
                    for(int k = start_offset; k <= end_offset; k++) {
                        buffer[k] = data[data_index++];
                    }
                } else if(j == start_block) {
                    //First block is partially written
                    for(int k = start_offset; k < BLOCK_SIZE; k++) {
                        buffer[k] = data[data_index++];
                    }
                } else if(j == end_block) {
                    //Last block is partially written
                    for(int k = 0; k <= end_offset; k++) {
                        buffer[k] = data[data_index++];
                    }
                } else {
                    //Block is completely written
                    for(int k = 0; k < BLOCK_SIZE; k++) {
                        buffer[k] = data[data_index++];
                    }
                }
                writeBlock(fs, block_number, buffer); //Write block to disk
            }
            return size; //Return size of data written
        }
    }
    return -3; //Return -3 if file not found
}

//Function to delete a file
int deleteFile(FileSystem* fs, char name[]) {
    int i, j, block_number;
    for(i = 0; i < MAX_FILE_COUNT; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            //Free allocated blocks
            for(j = 0; j < fs->files[i].block_count; j++) {
                block_number = fs->files[i].block_pointers[j];
                freeBlock(fs, block_number);
            }
            free(fs->files[i].block_pointers);
            strcpy(fs->files[i].name, ""); //Mark file as deleted
            fs->files[i].size = 0;
            fs->files[i].block_count = 0;
            return 1; //Return 1 if file is successfully deleted
        }
    }
    return -1; //Return -1 if file not found
}

int main() {
    FileSystem fs;
    initialize(&fs); //Initialize file system
    int status = createFile(&fs, "file1", 1024); //Create a file named "file1" with 1024 bytes size
    switch(status) {
        case 1:
            printf("File created successfully!\n");
            break;
        case -1:
            printf("File already exists!\n");
            break;
        case -2:
            printf("No free block is available!\n");
            break;
        case -3:
            printf("No free file slot is available!\n");
            break;
    }
    char data[1024];
    memset(data, 'A', 1024); //Initialize data buffer with 'A'
    status = writeFile(&fs, "file1", 0, 512, data); //Write first 512 bytes of data in file "file1"
    switch(status) {
        case 512:
            printf("Data written successfully!\n");
            break;
        case -1:
            printf("Offset is invalid!\n");
            break;
        case -2:
            printf("Block is not allocated!\n");
            break;
        case -3:
            printf("File not found!\n");
            break;
    }
    char buffer[512];
    status = readFile(&fs, "file1", 0, 512, buffer); //Read first 512 bytes of data from file "file1"
    switch(status) {
        case 512:
            printf("Data read successfully!\n");
            break;
        case -1:
            printf("Offset is invalid!\n");
            break;
        case -2:
            printf("Block is not allocated!\n");
            break;
        case -3:
            printf("File not found!\n");
            break;
    }
    status = deleteFile(&fs, "file1"); //Delete file "file1"
    switch(status) {
        case 1:
            printf("File deleted successfully!\n");
            break;
        case -1:
            printf("File not found!\n");
            break;
    }
    return 0;
}