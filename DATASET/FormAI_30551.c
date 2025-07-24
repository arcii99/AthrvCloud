//FormAI DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 4096
#define FILENAME_SIZE 20

// File entry struct
typedef struct {
    char name[FILENAME_SIZE];
    int size;
    int block_start;
} FileEntry;

// File system struct
typedef struct {
    FileEntry entries[MAX_BLOCKS];
    char blocks[MAX_BLOCKS][BLOCK_SIZE];
    int free_blocks[MAX_BLOCKS];
    int num_free_blocks;
} FileSystem;

// Function to initialize the file system
void init_file_system(FileSystem *fs) {
    // Set all blocks as free
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fs->free_blocks[i] = i;
    }
    fs->num_free_blocks = MAX_BLOCKS;
}

// Function to create a file in the file system
int create_file(FileSystem *fs, char *name, int size) {
    // Check if there's enough space in the file system
    if (size > fs->num_free_blocks * BLOCK_SIZE) {
        printf("ERROR: Not enough space in the file system");
        return -1;
    }

    // Find the first free block
    int block = fs->free_blocks[--fs->num_free_blocks];

    // Update the file entry
    FileEntry entry;
    strncpy(entry.name, name, FILENAME_SIZE);
    entry.size = size;
    entry.block_start = block;
    fs->entries[block] = entry;

    // Update the file system
    memcpy(fs->blocks[block], "", BLOCK_SIZE);
    for (int i = 1; i < (size + BLOCK_SIZE - 1) / BLOCK_SIZE; i++) {
        int next_block = fs->free_blocks[--fs->num_free_blocks];
        memcpy(fs->blocks[block], "", BLOCK_SIZE);
    }

    return block;
}

// Function to write to a file in the file system
void write_file(FileSystem *fs, int block, char *data) {
    // Check if the file exists
    if (block < 0 || block >= MAX_BLOCKS || fs->entries[block].name[0] == '\0') {
        printf("ERROR: File does not exist");
        return;
    }

    // Write the data to the file
    int pos = 0;
    int size = fs->entries[block].size;
    int block_pos = fs->entries[block].block_start;
    while (pos < size) {
        memcpy(fs->blocks[block_pos], data + pos, BLOCK_SIZE);
        pos += BLOCK_SIZE;
        block_pos = -1;
        for (int i = 0; i < size / BLOCK_SIZE; i++) {
            if (fs->entries[i].block_start == block_pos + 1) {
                block_pos = i;
                break;
            }
        }
    }
}

// Function to read from a file in the file system
void read_file(FileSystem *fs, int block, char *data) {
    // Check if the file exists
    if (block < 0 || block >= MAX_BLOCKS || fs->entries[block].name[0] == '\0') {
        printf("ERROR: File does not exist");
        return;
    }

    // Read the data from the file
    int pos = 0;
    int size = fs->entries[block].size;
    int block_pos = fs->entries[block].block_start;
    while (pos < size) {
        memcpy(data + pos, fs->blocks[block_pos], BLOCK_SIZE);
        pos += BLOCK_SIZE;
        block_pos = -1;
        for (int i = 0; i < size / BLOCK_SIZE; i++) {
            if (fs->entries[i].block_start == block_pos + 1) {
                block_pos = i;
                break;
            }
        }
    }
}

int main() {
    // Initialize the file system
    FileSystem fs;
    init_file_system(&fs);

    // Create a file
    int block = create_file(&fs, "test.txt", 1024);

    // Write to the file
    char data[1024] = "Hello world!";
    write_file(&fs, block, data);

    // Read from the file
    char read_data[1024];
    read_file(&fs, block, read_data);
    printf("Read data: %s", read_data);

    return 0;
}