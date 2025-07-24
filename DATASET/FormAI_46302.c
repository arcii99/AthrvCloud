//FormAI DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100               // Maximum number of files in the file system
#define MAX_FILENAME_SIZE 20        // Maximum length of a file name
#define BLOCK_SIZE 1024             // Size of each block in bytes
#define NUM_BLOCKS 1024             // Total number of blocks in the file system
#define DISK_SIZE (BLOCK_SIZE * NUM_BLOCKS)   // Size of the disk in bytes

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int start_block;
    int end_block;
    int num_blocks;
} File;

File files[MAX_FILES];              // Global array to store information about files
char disk[DISK_SIZE];               // Global array representing the disk

// Initialize the file system by marking all blocks as free
void initialize() {
    memset(disk, 0, DISK_SIZE);
}

// Create a new file and allocate blocks to it
// Returns 1 on success, 0 on failure
int create_file(char *filename, int size) {
    int i, j;
    int num_blocks_needed = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (i = 0; i < MAX_FILES; i++) {
        if (files[i].filename[0] == '\0') {
            // Found an empty slot in the file table
            strncpy(files[i].filename, filename, MAX_FILENAME_SIZE);
            files[i].num_blocks = num_blocks_needed;
            for (j = 0; j < NUM_BLOCKS - num_blocks_needed; j++) {
                if (disk[j] == 0) {
                    // Found a block that is free
                    files[i].start_block = j;
                    files[i].end_block = j + num_blocks_needed - 1;
                    for (int k = 0; k < num_blocks_needed; k++) {
                        disk[j + k] = 1;
                    }
                    return 1;
                }
            }
            // No free blocks found
            printf("Error: Disk is full\n");
            files[i].filename[0] = '\0';
            return 0;
        }
    }
    // File table is full
    printf("Error: Max number of open files exceeded\n");
    return 0;
}

// Write data to a file
// Returns the number of bytes written
int write_file(char *filename, char *data, int size) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strncmp(files[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
            // Found the file we want to write to
            int start_block = files[i].start_block;
            int end_block = files[i].end_block;
            int remaining_bytes = size;
            int bytes_written = 0;
            for (int j = start_block; j <= end_block; j++) {
                if (remaining_bytes <= 0) {
                    // Finished writing all the bytes
                    break;
                }
                if (disk[j] == 0) {
                    // Error: Attempting to write to an unallocated block
                    printf("Error: Attempting to write to an unallocated block\n");
                    return bytes_written;
                }
                int block_start = j * BLOCK_SIZE;
                int block_remaining = BLOCK_SIZE;
                if (j == start_block) {
                    block_start += files[i].num_blocks % BLOCK_SIZE;
                    block_remaining -= block_start;
                }
                if (j == end_block) {
                    block_remaining -= (BLOCK_SIZE - ((files[i].num_blocks + files[i].start_block) % BLOCK_SIZE));
                }
                if (block_remaining > remaining_bytes) {
                    block_remaining = remaining_bytes;
                }
                memcpy(disk + block_start, data + bytes_written, block_remaining);
                remaining_bytes -= block_remaining;
                bytes_written += block_remaining;
            }
            return bytes_written;
        }
    }
    // File not found
    printf("Error: File not found\n");
    return 0;
}

// Read data from a file
// Returns the number of bytes read
int read_file(char *filename, char *buffer, int size) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strncmp(files[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
            // Found the file we want to read from
            int start_block = files[i].start_block;
            int end_block = files[i].end_block;
            int remaining_bytes = size;
            int bytes_read = 0;
            for (int j = start_block; j <= end_block; j++) {
                if (remaining_bytes <= 0) {
                    // Finished reading all the bytes
                    break;
                }
                if (disk[j] == 0) {
                    // Error: Attempting to read from an unallocated block
                    printf("Error: Attempting to read from an unallocated block\n");
                    return bytes_read;
                }
                int block_start = j * BLOCK_SIZE;
                int block_remaining = BLOCK_SIZE;
                if (j == start_block) {
                    block_start += files[i].num_blocks % BLOCK_SIZE;
                    block_remaining -= block_start;
                }
                if (j == end_block) {
                    block_remaining -= (BLOCK_SIZE - ((files[i].num_blocks + files[i].start_block) % BLOCK_SIZE));
                }
                if (block_remaining > remaining_bytes) {
                    block_remaining = remaining_bytes;
                }
                memcpy(buffer + bytes_read, disk + block_start, block_remaining);
                remaining_bytes -= block_remaining;
                bytes_read += block_remaining;
            }
            return bytes_read;
        }
    }
    // File not found
    printf("Error: File not found\n");
    return 0;
}

int main() {
    initialize();
    create_file("test.txt", 4096);
    write_file("test.txt", "Hello, world!", 13);
    char buffer[1024];
    read_file("test.txt", buffer, 13);
    printf("Content of test.txt: %s\n", buffer);
    return 0;
}