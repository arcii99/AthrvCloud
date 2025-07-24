//FormAI DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 100
#define FILE_NAME_SIZE 20

typedef struct file_metadata {
    char file_name[FILE_NAME_SIZE];
    int start_block;
    int num_blocks;
} file_md;

int free_blocks[NUM_BLOCKS];
char file_system[NUM_BLOCKS * BLOCK_SIZE];

void initialize() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free_blocks[i] = 1;
    }
}

int allocate_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (free_blocks[i]) {
            free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

void free_block(int block_num) {
    free_blocks[block_num] = 1;
}

void create_file(char* file_name, int file_size) {
    if (strlen(file_name) > FILE_NAME_SIZE) {
        printf("File name too long!\n");
        return;
    }

    int num_blocks = file_size % BLOCK_SIZE == 0 ? file_size / BLOCK_SIZE : file_size / BLOCK_SIZE + 1;

    int start_block = allocate_block();
    if (start_block == -1) {
        printf("Not enough space!\n");
        return;
    }

    file_md metadata;
    strcpy(metadata.file_name, file_name);
    metadata.start_block = start_block;
    metadata.num_blocks = num_blocks;

    memcpy(&file_system[start_block * BLOCK_SIZE], &metadata, sizeof(file_md));

    for (int i = start_block + 1; i < start_block + num_blocks; i++) {
        int block = allocate_block();
        if (block == -1) {
            printf("Not enough space!\n");
            return;
        }
        memcpy(&file_system[i * BLOCK_SIZE], &block, sizeof(int));
    }

    printf("File created successfully!\n");
}

void list_files() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (!free_blocks[i]) {
            file_md metadata;
            memcpy(&metadata, &file_system[i * BLOCK_SIZE], sizeof(file_md));
            printf("%s (%d bytes)\n", metadata.file_name, metadata.num_blocks * BLOCK_SIZE);
        }
    }
}

void delete_file(char* file_name) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (!free_blocks[i]) {
            file_md metadata;
            memcpy(&metadata, &file_system[i * BLOCK_SIZE], sizeof(file_md));
            if (strcmp(metadata.file_name, file_name) == 0) {
                free_block(i);
                for (int j = metadata.start_block + 1; j < metadata.start_block + metadata.num_blocks; j++) {
                    int block;
                    memcpy(&block, &file_system[j * BLOCK_SIZE], sizeof(int));
                    free_block(block);
                }
                printf("File deleted successfully!\n");
                return;
            }
        }
    }
    printf("File not found!\n");
}

int main() {
    initialize();

    create_file("example.txt", 2048);
    create_file("notes.doc", 1024);

    list_files();

    delete_file("example.txt");

    list_files();

    return 0;
}