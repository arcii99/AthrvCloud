//FormAI DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // disk block size
#define BLOCKS_PER_DISK 1000 // total number of blocks in disk
#define MAX_FILE_SIZE 5120 // maximum size of a file in blocks

typedef struct {
    char name[20]; // file name
    int size; // file size in blocks
    int block_ptr[5]; // pointer to disk block # containing file data
} File;

int disk[BLOCKS_PER_DISK][BLOCK_SIZE]; // simulated disk
File file_table[50]; // file table to keep track of files

int get_free_block() {
    // function to return a free block number for data storage

    for (int i = 0; i < BLOCKS_PER_DISK; i++) {
        int free = 1;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (disk[i][j] != 0) {
                free = 0;
                break;
            }
        }
        if (free) {
            return i;
        }
    }
    return -1;
}

void create_file(char* name, int size) {
    // function to create a new file and allocate disk blocks for it

    // check if file already exists
    for (int i = 0; i < 50; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            printf("Error: File already exists!\n");
            return;
        }
    }

    // check if there is enough space on disk
    if (size > MAX_FILE_SIZE) {
        printf("Error: File size too large!\n");
        return;
    }
    int num_blocks_needed = size / BLOCK_SIZE + (size % BLOCK_SIZE ? 1 : 0);
    int free_blocks = 0;
    for (int i = 0; i < BLOCKS_PER_DISK; i++) {
        int free = 1;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (disk[i][j] != 0) {
                free = 0;
                break;
            }
        }
        if (free) {
            free_blocks++;
            if (free_blocks == num_blocks_needed) {
                break;
            }
        }
    }
    if (free_blocks < num_blocks_needed) {
        printf("Error: Not enough space on disk!\n");
        return;
    }

    // allocate disk blocks for file data
    int block_ptrs[5];
    for (int i = 0; i < num_blocks_needed; i++) {
        int block_num = get_free_block();
        block_ptrs[i] = block_num;
        memcpy(&disk[block_num], "Sample Data", 11);
    }

    // add file entry to file table
    for (int i = 0; i < 50; i++) {
        if (file_table[i].size == 0) {
            strcpy(file_table[i].name, name);
            file_table[i].size = size;
            memcpy(file_table[i].block_ptr, block_ptrs, sizeof(block_ptrs));
            break;
        }
    }
    printf("File %s created successfully!\n", name);
}

void delete_file(char* name) {
    // function to delete a file and free up disk blocks allocated to it

    // check if file exists
    File* file = NULL;
    for (int i = 0; i < 50; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            file = &file_table[i];
            break;
        }
    }
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    // delete file data from disk
    for (int i = 0; i < 5; i++) {
        if (file->block_ptr[i] == -1) break;
        memset(&disk[file->block_ptr[i]], 0, BLOCK_SIZE);
    }

    // remove file entry from file table
    memset(file, 0, sizeof(File));
    printf("File %s deleted successfully!\n", name);
}

void display_file(char* name) {
    // function to display the contents of a file

    // check if file exists
    File* file = NULL;
    for (int i = 0; i < 50; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            file = &file_table[i];
            break;
        }
    }
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    // display file data
    printf("Name: %s\nSize: %d\nData:\n", file->name, file->size);
    for (int i = 0; i < 5; i++) {
        if (file->block_ptr[i] == -1) break;
        printf("Block %d: %s\n", file->block_ptr[i], disk[file->block_ptr[i]]);
    }
}

int main() {
    // initialize disk
    for (int i = 0; i < BLOCKS_PER_DISK; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            disk[i][j] = 0;
        }
    }
    // initialize file table with empty entries
    for (int i = 0; i < 50; i++) {
        memset(&file_table[i], 0, sizeof(File));
    }

    // simulate file system operations
    create_file("file1", 2048);
    create_file("file2", 4096);
    display_file("file1");
    display_file("file2");
    delete_file("file1");
    display_file("file1");
    delete_file("file2");
    display_file("file2");

    return 0;
}