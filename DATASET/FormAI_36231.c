//FormAI DATASET v1.0 Category: File system simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 1000
#define BLOCK_SIZE 4096

typedef struct {
    int id;
    int size;
    char* data;
} block;

int num_blocks = 0;
block blocks[MAX_BLOCKS];
int disk[MAX_BLOCKS*BLOCK_SIZE];

void format_disk() {
    memset(disk, 0, MAX_BLOCKS*BLOCK_SIZE);
}

int get_next_block() {
    int block_num = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i].id == -1) {
            block_num = i;
            break;
        }
    }
    return block_num;
}

int create_block(int size) {
    int block_num = get_next_block();
    if (block_num != -1) {
        block new_block;
        new_block.id = block_num;
        new_block.size = size;
        new_block.data = (char*) malloc(size);
        blocks[block_num] = new_block;
    }
    return block_num;
}

void write_block(int block_num, char* data) {
    if (block_num >= 0 && block_num < MAX_BLOCKS) {
        block* b = &blocks[block_num];
        memcpy(b->data, data, b->size);
        memcpy(&disk[block_num*BLOCK_SIZE], b->data, b->size);
    }
}

void read_block(int block_num) {
    if (block_num >= 0 && block_num < MAX_BLOCKS) {
        block* b = &blocks[block_num];
        memcpy(&disk[block_num*BLOCK_SIZE], b->data, b->size);
        printf("Block %d:\n", block_num);
        printf("%s", b->data);
        printf("\n");
    }
}

void delete_block(int block_num) {
    if (block_num >= 0 && block_num < MAX_BLOCKS) {
        block* b = &blocks[block_num];
        free(b->data);
        b->id = -1;
        b->size = -1;
    }
}

int main(void) {
    format_disk();

    int block_num1 = create_block(10);
    int block_num2 = create_block(20);

    char* data1 = "Hello World!";
    char* data2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

    write_block(block_num1, data1);
    write_block(block_num2, data2);

    printf("Reading Block %d:\n", block_num1);
    read_block(block_num1);

    delete_block(block_num1);

    printf("Reading Block %d:\n", block_num1);
    read_block(block_num1);

    return 0;
}