//FormAI DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 1000

struct Block {
    char data[BLOCK_SIZE];
};

struct FileSystem {
    struct Block blocks[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS];
    int num_free_blocks;
};

void init_file_system(struct FileSystem* fs) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fs->free_blocks[i] = i;
    }
    fs->num_free_blocks = MAX_BLOCKS;
}

int allocate_block(struct FileSystem* fs) {
    if (fs->num_free_blocks == 0) {
        return -1; // file system is full
    }
    int block_index = fs->free_blocks[fs->num_free_blocks - 1];
    fs->num_free_blocks--;
    return block_index;
}

void free_block(struct FileSystem* fs, int block_index) {
    fs->free_blocks[fs->num_free_blocks] = block_index;
    fs->num_free_blocks++;
}

void write_file(struct FileSystem* fs, const char* filename, const char* data, int size) {
    // find free block for file
    int block_index = allocate_block(fs);
    if (block_index == -1) {
        printf("Error: file system is full\n");
        return;
    }

    // write file data to block
    strncpy(fs->blocks[block_index].data, data, size);

    // create file entry
    printf("Created file: %s\n", filename);
    printf("File size: %d bytes\n", size);
    printf("Block index: %d\n", block_index);
    printf("Data: %s\n", data);
}

void read_file(struct FileSystem* fs, const char* filename) {
    // find block index for file
    int block_index = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(fs->blocks[i].data, filename) == 0) {
            block_index = i;
            break;
        }
    }

    // read file data from block
    if (block_index == -1) {
        printf("Error: file not found\n");
    } else {
        printf("Read file: %s\n", filename);
        printf("File size: %lu bytes\n", strlen(fs->blocks[block_index].data));
        printf("Block index: %d\n", block_index);
        printf("Data: %s\n", fs->blocks[block_index].data);
    }
}

int main() {
    struct FileSystem fs;
    init_file_system(&fs);

    // create and read files
    write_file(&fs, "file1.txt", "hello world", 11);
    read_file(&fs, "file1.txt");

    write_file(&fs, "file2.txt", "this is a test file", 20);
    read_file(&fs, "file2.txt");

    write_file(&fs, "file3.txt", "abcdefghijklmnopqrstuvwxyz", 26);
    read_file(&fs, "file3.txt");

    return 0;
}