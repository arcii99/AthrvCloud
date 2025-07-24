//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCK_NUM 1024
#define MAX_FILE_NUM 512
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char* buffer;
    int index;
} Block;

typedef struct {
    char* name;
    int blocks[MAX_BLOCK_NUM];
    int block_count;
    int size;  // bytes
} File;

typedef struct {
    Block blocks[MAX_BLOCK_NUM];
    int block_count;
} Disk;

File files[MAX_FILE_NUM];
int file_count = 0;

void format_disk(Disk* disk) {
    for (int i = 0; i < MAX_BLOCK_NUM; i++) {
        disk->blocks[i].buffer = malloc(BLOCK_SIZE);
        disk->blocks[i].index = i;
    }
    disk->block_count = MAX_BLOCK_NUM;
}

int allocate_block(Disk* disk) {
    for (int i = 0; i < disk->block_count; i++) {
        if (disk->blocks[i].index == -1) {
            disk->blocks[i].index = i;
            disk->blocks[i].buffer = malloc(BLOCK_SIZE);
            return i;
        }
    }
    return -1;  // no available block
}

void clear_block(Block* block) {
    memset(block->buffer, 0, BLOCK_SIZE);
}

void write_block(Block* block, char* buffer) {
    strncpy(block->buffer, buffer, BLOCK_SIZE);
}

void read_block(Block* block, char* buffer) {
    strncpy(buffer, block->buffer, BLOCK_SIZE);
}

int create_file(Disk* disk, char* name, int size) {
    if (file_count == MAX_FILE_NUM) {
        return -1;  // max file count exceeded
    }

    File file;
    file.name = malloc(MAX_FILENAME_LENGTH);
    strncpy(file.name, name, MAX_FILENAME_LENGTH);
    file.size = size;

    // allocate blocks
    int block_index;
    int remaining_size = size;
    while (remaining_size > 0) {
        block_index = allocate_block(disk);
        if (block_index == -1) {
            return -2;  // no available block
        }
        file.blocks[file.block_count] = block_index;
        file.block_count++;
        remaining_size -= BLOCK_SIZE;
    }

    files[file_count] = file;
    file_count++;
    return 0;  // success
}

File* find_file(char* name) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return &files[i];
        }
    }
    return NULL;  // file not found
}

void delete_file(Disk* disk, char* name) {
    File* file = find_file(name);
    if (file == NULL) {
        return;  // file not found
    }

    // free allocated blocks
    for (int i = 0; i < file->block_count; i++) {
        int block_index = file->blocks[i];
        clear_block(&disk->blocks[block_index]);
        disk->blocks[block_index].index = -1;
    }

    // remove file from list
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            for (int j = i; j < file_count - 1; j++) {
                files[j] = files[j+1];
            }
            file_count--;
            return;
        }
    }
}

int main() {
    Disk disk;
    format_disk(&disk);

    // Test create_file and find_file
    create_file(&disk, "test.txt", 2048);
    File* file = find_file("test.txt");
    printf("File name: %s\n", file->name);
    printf("File size: %d bytes\n", file->size);
    printf("Block count: %d\n", file->block_count);
    for (int i = 0; i < file->block_count; i++) {
        printf("Block %d index: %d\n", i, file->blocks[i]);
    }

    // Test delete_file
    delete_file(&disk, "test.txt");
    printf("File count: %d\n", file_count);

    return 0;
}