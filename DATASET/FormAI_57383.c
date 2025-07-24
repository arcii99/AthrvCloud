//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define FILE_NAME_LENGTH 20
#define BLOCK_SIZE 1024
#define MAX_BLOCKS 100

// File structure
typedef struct File {
    char name[FILE_NAME_LENGTH];
    int size;
    int block_count;
    int blocks[MAX_BLOCKS];
} File;

// File System structure
typedef struct FileSystem {
    int total_blocks;
    int free_blocks;
    int file_count;
    File files[MAX_FILES];
    char block[BLOCK_SIZE * MAX_BLOCKS];
} FileSystem;

// Function to initialize the file system
void init_filesystem(FileSystem* fs) {
    fs->total_blocks = MAX_BLOCKS;
    fs->free_blocks = MAX_BLOCKS;
    for(int i = 0; i < MAX_FILES; i++) {
        fs->files[i].name[0] = '\0';
        fs->files[i].size = 0;
        fs->files[i].block_count = 0;
        for(int j = 0; j < MAX_BLOCKS; j++) {
            fs->files[i].blocks[j] = -1;
        }
    }
    memset(fs->block, 0, sizeof(fs->block));
}

// Function to find the next available block
int find_free_block(FileSystem* fs) {
    for(int i = 0; i < fs->total_blocks; i++) {
        if(fs->block[i * BLOCK_SIZE] == '\0') {
            return i;
        }
    }
    return -1;
}

// Function to create a new file
void create_file(FileSystem* fs, const char* name, int size) {
    if(fs->free_blocks == 0) {
        printf("Error: No free space available\n");
        return;
    }
    for(int i = 0; i < MAX_FILES; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File with name '%s' already exists\n", name);
            return;
        }
    }
    int block_count = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    if(block_count > fs->free_blocks) {
        printf("Error: Not enough free space available\n");
        return;
    }
    int file_index = fs->file_count;
    fs->file_count++;
    strcpy(fs->files[file_index].name, name);
    fs->files[file_index].size = size;
    fs->files[file_index].block_count = block_count;
    for(int i = 0; i < block_count; i++) {
        int block = find_free_block(fs);
        if(block == -1) {
            printf("Error: No free space available\n");
            return;
        }
        fs->block[block * BLOCK_SIZE] = '1';
        fs->files[file_index].blocks[i] = block;
        fs->free_blocks--;
    }
    printf("File %s created\n", name);
}

// Function to delete a file
void delete_file(FileSystem* fs, const char* name) {
    int file_index = -1;
    for(int i = 0; i < fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if(file_index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    for(int i = 0; i < fs->files[file_index].block_count; i++) {
        int block = fs->files[file_index].blocks[i];
        fs->block[block * BLOCK_SIZE] = '\0';
        fs->free_blocks++;
    }
    fs->files[file_index] = fs->files[fs->file_count - 1];
    fs->files[fs->file_count - 1].name[0] = '\0';
    fs->files[fs->file_count - 1].size = 0;
    fs->files[fs->file_count - 1].block_count = 0;
    for(int i = 0; i < MAX_BLOCKS; i++) {
        fs->files[fs->file_count - 1].blocks[i] = -1;
    }
    fs->file_count--;
    printf("File %s deleted\n", name);
}

// Function to read from a file
void read_file(FileSystem* fs, const char* name, int offset, int size) {
    int file_index = -1;
    for(int i = 0; i < fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if(file_index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    if(offset + size > fs->files[file_index].size) {
        printf("Error: Invalid read operation\n");
        return;
    }
    char* data = malloc(size);
    int start_block = offset / BLOCK_SIZE;
    int end_block = (offset + size - 1) / BLOCK_SIZE;
    int data_offset = 0;
    for(int i = start_block; i <= end_block; i++) {
        int block = fs->files[file_index].blocks[i];
        int block_offset = offset % BLOCK_SIZE;
        int block_size = (i == end_block ? offset + size - i * BLOCK_SIZE : BLOCK_SIZE - block_offset);
        memcpy(data + data_offset, fs->block + block * BLOCK_SIZE + block_offset, block_size);
        offset += block_size;
        data_offset += block_size;
    }
    printf("Read from file %s: %.*s\n", name, size, data);
    free(data);
}

// Function to write to a file
void write_file(FileSystem* fs, const char* name, int offset, const char* data, int size) {
    int file_index = -1;
    for(int i = 0; i < fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if(file_index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    if(offset + size > fs->files[file_index].size) {
        printf("Error: Invalid write operation\n");
        return;
    }
    int start_block = offset / BLOCK_SIZE;
    int end_block = (offset + size - 1) / BLOCK_SIZE;
    int data_offset = 0;
    for(int i = start_block; i <= end_block; i++) {
        int block = fs->files[file_index].blocks[i];
        int block_offset = offset % BLOCK_SIZE;
        int block_size = (i == end_block ? offset + size - i * BLOCK_SIZE : BLOCK_SIZE - block_offset);
        memcpy(fs->block + block * BLOCK_SIZE + block_offset, data + data_offset, block_size);
        offset += block_size;
        data_offset += block_size;
    }
    printf("Write to file %s successful\n", name);
}

int main() {
    FileSystem fs;
    init_filesystem(&fs);
    create_file(&fs, "file1", 1500);
    create_file(&fs, "file2", 500);
    read_file(&fs, "file1", 1000, 500);
    write_file(&fs, "file2", 100, "Hello world", 11);
    delete_file(&fs, "file1");
    delete_file(&fs, "file2");
    return 0;
}