//FormAI DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // maximum number of files in the file system
#define MAX_FILENAME_LEN 20 // maximum length of a filename
#define BLOCK_SIZE 512 // size of each block in bytes
#define MAX_BLOCKS 1000 // maximum number of blocks in the file system

// struct to represent a file
typedef struct file {
    char name[MAX_FILENAME_LEN];
    int size;
    int start_block;
} File;

// struct to represent a block
typedef struct block {
    char data[BLOCK_SIZE];
    int next_block;
} Block;

// global variables
File files[MAX_FILES];
Block blocks[MAX_BLOCKS];
int free_block;
int num_files;

// function to initialize the file system
void init_filesystem() {
    num_files = 0;
    free_block = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].next_block = i + 1;
    }
    blocks[MAX_BLOCKS - 1].next_block = -1;
}

// function to create a new file
void create_file(char *name, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: maximum number of files reached\n");
        return;
    }
    if (free_block == -1) {
        printf("Error: file system full\n");
        return;
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.start_block = free_block;
    files[num_files] = new_file;
    num_files++;
    free_block = blocks[free_block].next_block;
}

// function to write data to a file
void write_file(char *name, char *data) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }
    int block_index = files[file_index].start_block;
    int data_index = 0;
    while (data_index < files[file_index].size) {
        strncpy(blocks[block_index].data, data + data_index, BLOCK_SIZE);
        data_index += BLOCK_SIZE;
        if (data_index < files[file_index].size) {
            if (blocks[block_index].next_block == -1) {
                printf("Error: file too large for file system\n");
                return;
            }
            block_index = blocks[block_index].next_block;
        }
    }
}

// function to read data from a file
void read_file(char *name, char *data) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }
    int block_index = files[file_index].start_block;
    int data_index = 0;
    while (data_index < files[file_index].size) {
        strncat(data, blocks[block_index].data, BLOCK_SIZE);
        data_index += BLOCK_SIZE;
        block_index = blocks[block_index].next_block;
    }
}

int main() {
    init_filesystem();
    create_file("example.txt", 1024);
    char data[1024] = "This is an example file.";
    write_file("example.txt", data);
    char read_data[1024] = "";
    read_file("example.txt", read_data);
    printf("%s\n", read_data);
    return 0;
}