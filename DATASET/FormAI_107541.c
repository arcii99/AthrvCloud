//FormAI DATASET v1.0 Category: File system simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // Size of a block in bytes
#define MAX_BLOCKS 1000 // Maximum number of blocks in the file system
#define FILENAME_LENGTH 20 // Maximum length of a file name

typedef struct {
    char name[FILENAME_LENGTH]; // Name of the file
    unsigned int start_block; // Index (starting from 0) of the first block of the file
    unsigned int num_blocks; // Number of blocks occupied by the file
} File;

typedef struct {
    unsigned char data[BLOCK_SIZE]; // Data stored in a block
    unsigned int next_block; // Index (starting from 0) of the next block in the file
} Block;

int num_files = 0; // Number of files in the file system
File files[MAX_BLOCKS]; // Array of files
int num_free_blocks = MAX_BLOCKS; // Number of free blocks in the file system
Block blocks[MAX_BLOCKS]; // Array of blocks
int next_free_block = 0; // Index (starting from 0) of the next free block in the array

/**
 * This function initializes the file system by setting up the array of blocks and
 * making all blocks free. It also initializes the array of files by setting the start
 * block and number of blocks for each file to 0.
 */
void initialize_file_system() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        memset(blocks[i].data, 0, BLOCK_SIZE);
        blocks[i].next_block = -1;
    }
    for (i = 0; i < MAX_BLOCKS; i++) {
        files[i].start_block = -1;
        files[i].num_blocks = 0;
    }
}

/**
 * This function allocates a block for a file. If no free blocks are available,
 * it returns -1.
 */
int allocate_block() {
    if (num_free_blocks == 0) {
        return -1;
    }
    int block_idx = next_free_block;
    next_free_block = blocks[block_idx].next_block;
    blocks[block_idx].next_block = -1;
    num_free_blocks--;
    return block_idx;
}

/**
 * This function releases a block that was previously allocated for a file.
 */
void release_block(unsigned int block_idx) {
    blocks[block_idx].next_block = next_free_block;
    next_free_block = block_idx;
    num_free_blocks++;
}

/**
 * This function adds a new file to the file system. It allocates the required number
 * of blocks for the file and updates the corresponding fields in the File struct.
 * If the file cannot be added (because there are not enough free blocks), it returns -1.
 */
int add_file(char* name, int size) {
    if (size > num_free_blocks * BLOCK_SIZE) {
        return -1;
    }
    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int start_block = allocate_block();
    int i;
    for (i = 1; i < num_blocks; i++) {
        int block_idx = allocate_block();
        blocks[start_block].next_block = block_idx;
        start_block = block_idx;
    }
    strncpy(files[num_files].name, name, FILENAME_LENGTH - 1);
    files[num_files].start_block = start_block;
    files[num_files].num_blocks = num_blocks;
    num_files++;
    return 0;
}

/**
 * This function deletes a file from the file system. It releases all blocks used
 * by the file and updates the corresponding fields in the File struct. If the file
 * does not exist, it returns -1.
 */
int delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int block_idx = files[i].start_block;
            while (block_idx != -1) {
                int next_block_idx = blocks[block_idx].next_block;
                release_block(block_idx);
                block_idx = next_block_idx;
            }
            files[i].start_block = -1;
            files[i].num_blocks = 0;
            num_files--;
            files[i] = files[num_files];
            return 0;
        }
    }
    return -1;
}

/**
 * This function reads data from a file in the file system. If the file does not
 * exist, it returns -1. If the offset is past the end of the file, it returns 0.
 * Otherwise, it returns the number of bytes read.
 */
int read_file(char* name, int offset, int size, char* buffer) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int start_block = files[i].start_block;
            int start_byte = offset % BLOCK_SIZE;
            int block_offset = offset / BLOCK_SIZE;
            int bytes_read = 0;
            while (start_block != -1 && bytes_read < size) {
                int bytes_to_read = BLOCK_SIZE - start_byte;
                if (bytes_to_read > size - bytes_read) {
                    bytes_to_read = size - bytes_read;
                }
                memcpy(buffer + bytes_read, blocks[start_block].data + start_byte, bytes_to_read);
                bytes_read += bytes_to_read;
                start_byte = 0;
                block_offset++;
                start_block = blocks[start_block].next_block;
            }
            return bytes_read;
        }
    }
    return -1;
}

/**
 * This function writes data to a file in the file system. If the file does not
 * exist, it returns -1. If the offset is past the end of the file, it returns -2.
 * If there is not enough space in the file system to write the data, it returns -3.
 * Otherwise, it returns the number of bytes written.
 */
int write_file(char* name, int offset, int size, char* buffer) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int start_block = files[i].start_block;
            int start_byte = offset % BLOCK_SIZE;
            int block_offset = offset / BLOCK_SIZE;
            int bytes_written = 0;
            while (start_block != -1 && bytes_written < size) {
                int bytes_to_write = BLOCK_SIZE - start_byte;
                if (bytes_to_write > size - bytes_written) {
                    bytes_to_write = size - bytes_written;
                }
                memcpy(blocks[start_block].data + start_byte, buffer + bytes_written, bytes_to_write);
                bytes_written += bytes_to_write;
                start_byte = 0;
                block_offset++;
                start_block = blocks[start_block].next_block;
            }
            if (bytes_written < size) {
                int num_extra_blocks = (size - bytes_written + BLOCK_SIZE - 1) / BLOCK_SIZE;
                if (num_extra_blocks > num_free_blocks) {
                    return -3;
                }
                int block_idx = allocate_block();
                if (block_idx == -1) {
                    return -3;
                }
                files[i].num_blocks += num_extra_blocks;
                if (files[i].start_block == -1) {
                    files[i].start_block = block_idx;
                } else {
                    int last_block_idx = files[i].start_block;
                    while (blocks[last_block_idx].next_block != -1) {
                        last_block_idx = blocks[last_block_idx].next_block;
                    }
                    blocks[last_block_idx].next_block = block_idx;
                }
                start_byte = 0;
                while (bytes_written < size) {
                    int bytes_to_write = BLOCK_SIZE - start_byte;
                    if (bytes_to_write > size - bytes_written) {
                        bytes_to_write = size - bytes_written;
                    }
                    memcpy(blocks[block_idx].data + start_byte, buffer + bytes_written, bytes_to_write);
                    bytes_written += bytes_to_write;
                    start_byte = 0;
                    block_idx = blocks[block_idx].next_block;
                }
            }
            return bytes_written;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    initialize_file_system();
    add_file("test1.txt", 10);
    add_file("test2.txt", 20);
    printf("%d\n", read_file("test1.txt", 0, 10, NULL));
    printf("%d\n", read_file("test2.txt", 0, 20, NULL));
    char buffer[100];
    memset(buffer, 'a', 100);
    printf("%d\n", write_file("test1.txt", 5, 5, buffer));
    printf("%d\n", read_file("test1.txt", 0, 10, buffer));
    printf("%d\n", write_file("test2.txt", 25, 5, buffer));
    printf("%d\n", read_file("test2.txt", 0, 20, buffer));
    delete_file("test1.txt");
    printf("%d\n", read_file("test1.txt", 0, 10, buffer));
    return 0;
}