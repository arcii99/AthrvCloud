//FormAI DATASET v1.0 Category: File system simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000
#define FILENAME_SIZE 20

typedef struct block {
    char data[BLOCK_SIZE];
} Block;

typedef struct file {
    char name[FILENAME_SIZE];
    int start_block;
    int num_blocks;
} File;

void initialize_disk(Block disk[]) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
}

int find_free_block(Block disk[]) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strlen(disk[i].data) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(Block disk[], File* file, char* data) {
    int start_block = find_free_block(disk);
    if (start_block != -1) {
        strcpy(file->name, "example.txt");
        file->start_block = start_block;
        int num_blocks = strlen(data) / BLOCK_SIZE + 1;
        file->num_blocks = num_blocks;
        int i;
        for (i = 0; i < num_blocks; i++) {
            int block_index = start_block + i;
            strncpy(disk[block_index].data, data + i * BLOCK_SIZE, BLOCK_SIZE);
        }
    } else {
        printf("Error: Disk is full!\n");
    }
}

void read_file(Block disk[], File file) {
    int i;
    for (i = 0; i < file.num_blocks; i++) {
        int block_index = file.start_block + i;
        printf("%s", disk[block_index].data);
    }
}

int main() {
    Block disk[NUM_BLOCKS];
    initialize_disk(disk);

    char data[] = "This is an example file.";
    File file;
    create_file(disk, &file, data);

    read_file(disk, file);

    return 0;
}