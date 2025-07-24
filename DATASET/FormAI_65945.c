//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define BLOCK_SIZE 1024

typedef struct {
    char filename[20];
    int blocks;
    int size;
    int start_block;
} file;

typedef struct {
    int block_id;
    char data[BLOCK_SIZE];
} block;

file fat[MAX_FILES];
block disk[50];

int num_files = 0;
int num_blocks = 50;

void init_disk() {
    for (int i = 0; i < num_blocks; i++) {
        disk[i].block_id = i;
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
}

void format_disk() {
    for (int i = 0; i < num_blocks; i++) {
        disk[i].block_id = i;
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
    num_files = 0;
}

int find_free_block() {
    for (int i = 0; i < num_blocks; i++) {
        if (strlen(disk[i].data) == 0) {
            return i;
        }
    }
    return -1;
}

void add_file(char* filename, int size) {
    int blocks_needed = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        blocks_needed++;
    }
    int start_block = find_free_block();
    if (start_block == -1) {
        printf("Error: not enough space on disk\n");
        return;
    }
    fat[num_files].start_block = start_block;
    fat[num_files].size = size;
    fat[num_files].blocks = blocks_needed;
    strcpy(fat[num_files].filename, filename);
    for (int i = start_block; i < start_block + blocks_needed; i++) {
        sprintf(disk[i].data, "data %s block %d", filename, i);
    }
    num_files++;
}

void delete_file(char* filename) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(fat[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }
    int start_block = fat[file_index].start_block;
    int blocks = fat[file_index].blocks;
    for (int i = start_block; i < start_block + blocks; i++) {
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
    fat[file_index].start_block = -1;
    fat[file_index].size = 0;
    fat[file_index].blocks = 0;
    strcpy(fat[file_index].filename, "");
}

void print_disk() {
    for (int i = 0; i < num_blocks; i++) {
        if (strlen(disk[i].data) != 0) {
            printf("Block %d: %s\n", disk[i].block_id, disk[i].data);
        }
    }
}

void print_fat() {
    for (int i = 0; i < num_files; i++) {
        printf("File %d: name=%s, size=%d, blocks=%d, start_block=%d\n", 
            i, fat[i].filename, fat[i].size, fat[i].blocks, fat[i].start_block);
    }
}

int main() {
    init_disk();
    add_file("file1", 2048);
    add_file("file2", 4096);
    add_file("file3", 10240);
    print_fat();
    print_disk();
    delete_file("file2");
    print_fat();
    print_disk();
    format_disk();
    return 0;
}