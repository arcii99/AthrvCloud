//FormAI DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_BLOCKS 100
#define BLOCK_SIZE 512

// define struct for files
typedef struct {
    char* name;
    int start_block;
    int size;
} File;

// declare global variables
char* file_system[MAX_BLOCKS];
int blocks_taken = 0;
File* files[MAX_BLOCKS];

/*
 * Creates a new file in the file system
 */
void create_file(char* name, int size) {
    // check if there is enough space in the file system
    if (blocks_taken + ((size + BLOCK_SIZE - 1) / BLOCK_SIZE) > MAX_BLOCKS) {
        printf("Error: file system full\n");
        return;
    }
    // find a free block big enough to store the file
    int start_block = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file_system[i] == NULL) {
            int blocks_needed = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
            int j = i;
            for (; j < i + blocks_needed && j < MAX_BLOCKS; j++) {
                if (file_system[j] != NULL) {
                    break;
                }
            }
            if (j == i + blocks_needed) {
                start_block = i;
                break;
            }
        }
    }
    if (start_block == -1) {
        printf("Error: no free block large enough to store file\n");
        return;
    }
    // allocate blocks to the file
    int blocks_needed = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (int i = start_block; i < start_block + blocks_needed; i++) {
        file_system[i] = (char*) malloc(BLOCK_SIZE);
    }
    // create file struct and add to files array
    File* new_file = (File*) malloc(sizeof(File));
    new_file->name = strdup(name);
    new_file->start_block = start_block;
    new_file->size = size;
    files[blocks_taken] = new_file;
    blocks_taken += blocks_needed;
    printf("File %s created successfully\n", name);
}

/*
 * Reads from a file in the file system
 */
void read_file(char* name, int offset, int length) {
    // find the file in the files array
    File* file = NULL;
    for (int i = 0; i < blocks_taken; i++) {
        if (files[i] != NULL && strcmp(files[i]->name, name) == 0) {
            file = files[i];
            break;
        }
    }
    if (file == NULL) {
        printf("Error: file not found\n");
        return;
    }
    // read from the file
    int start = offset;
    int end = offset + length;
    if (start < 0) {
        start = 0;
    }
    if (end > file->size) {
        end = file->size;
    }
    int block_offset = start / BLOCK_SIZE;
    int byte_offset = start % BLOCK_SIZE;
    int bytes_read = 0;
    for (int i = block_offset; i < blocks_taken; i++) {
        if (files[i] != NULL && files[i] == file) {
            char* block = file_system[i];
            int bytes_to_read = BLOCK_SIZE - byte_offset;
            if (i == block_offset + (end - start - bytes_read - 1) / BLOCK_SIZE) {
                bytes_to_read = (end - start) - bytes_read;
            }
            for (int j = byte_offset; j < byte_offset + bytes_to_read; j++) {
                printf("%c", block[j]);
            }
            bytes_read += bytes_to_read;
            byte_offset = 0;
            if (bytes_read >= end - start) {
                break;
            }
        }
    }
}

// main function
int main() {
    // initialize the file system with empty blocks
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file_system[i] = NULL;
    }
    // create some test files
    create_file("file1", 1000);
    create_file("file2", 2000);
    create_file("file3", 3000);
    // read from one of the files
    read_file("file2", 500, 1000);
    return 0;
}