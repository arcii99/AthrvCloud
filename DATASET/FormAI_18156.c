//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 4096

char disk[NUM_BLOCKS][BLOCK_SIZE];

int allocate_block() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (disk[i][0] == 0) {
            disk[i][0] = 1;
            return i;
        }
    }
    return -1;
}

void free_block(int block_num) {
    disk[block_num][0] = 0;
}

int write_block(int block_num, char* data) {
    if (block_num < 0 || block_num >= NUM_BLOCKS) {
        return -1;
    }
    if (data == NULL) {
        return -1;
    }
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        disk[block_num][i] = data[i];
    }
    return 0;
}

char* read_block(int block_num) {
    if (block_num < 0 || block_num >= NUM_BLOCKS) {
        return NULL;
    }
    char* data = malloc(BLOCK_SIZE * sizeof(char));
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        data[i] = disk[block_num][i];
    }
    return data;
}

void format_disk() {
    int i, j;
    for (i = 0; i < NUM_BLOCKS; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            disk[i][j] = 0;
        }
        disk[i][0] = -1;
    }
}

int main() {
    format_disk();
    int block_num = allocate_block();
    char data[BLOCK_SIZE] = "Hello, World!";
    write_block(block_num, data);
    char* read_data = read_block(block_num);
    printf("Block %d contains: %s\n", block_num, read_data);
    free_block(block_num);
    return 0;
}