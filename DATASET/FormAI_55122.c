//FormAI DATASET v1.0 Category: File system simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// define constants
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024

// define structs
typedef struct {
    unsigned short int magic_number; // magic number to check if file system is valid
    unsigned short int block_size; // block size in bytes
    unsigned short int num_blocks; // number of blocks in file system
    unsigned short int free_blocks[NUM_BLOCKS]; // array of free blocks
} superblock_t;

typedef struct {
    char data[BLOCK_SIZE]; // data stored in block
    unsigned short int next_block; // index of next block in file chain
} block_t;

// helper function to initialize superblock
void init_superblock(superblock_t *sb) {
    sb->magic_number = 0xADAD;
    sb->block_size = BLOCK_SIZE;
    sb->num_blocks = NUM_BLOCKS;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        sb->free_blocks[i] = 1;
    }
}

// helper function to find first free block in superblock
int find_free_block(superblock_t *sb) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (sb->free_blocks[i] == 1) {
            sb->free_blocks[i] = 0;
            return i;
        }
    }
    return -1; // error - no free blocks available
}

int main() {
    // initialize superblock and write to disk
    superblock_t sb;
    init_superblock(&sb);
    FILE *disk = fopen("my_file_system.txt", "w+b");
    fwrite(&sb, sizeof(superblock_t), 1, disk);
    
    // write some data to disk
    char data[] = "Hello, world!";
    int data_size = sizeof(data);
    int num_blocks_needed = data_size / BLOCK_SIZE + (data_size % BLOCK_SIZE != 0);
    int data_block_ptrs[num_blocks_needed];
    for (int i = 0; i < num_blocks_needed; i++) {
        data_block_ptrs[i] = find_free_block(&sb);
        block_t data_block;
        if (i == num_blocks_needed - 1) {
            // last block - fill with remaining bytes and set next_block to -1
            int bytes_remaining = data_size % BLOCK_SIZE;
            for (int j = 0; j < bytes_remaining; j++) {
                data_block.data[j] = data[i*BLOCK_SIZE + j];
            }
            data_block.next_block = -1;
        } else {
            // not last block - fill with BLOCK_SIZE bytes and set next_block pointer
            for (int j = 0; j < BLOCK_SIZE; j++) {
                data_block.data[j] = data[i*BLOCK_SIZE + j];
            }
            data_block.next_block = data_block_ptrs[i+1];
        }
        fseek(disk, data_block_ptrs[i]*BLOCK_SIZE, SEEK_SET);
        fwrite(&data_block, sizeof(block_t), 1, disk);
    }
    
    // read data from disk
    fseek(disk, data_block_ptrs[0]*BLOCK_SIZE, SEEK_SET);
    int bytes_read = 0;
    char buffer[data_size];
    while (bytes_read < data_size) {
        block_t data_block;
        fread(&data_block, sizeof(block_t), 1, disk);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            buffer[bytes_read++] = data_block.data[j];
        }
        if (data_block.next_block == -1) {
            break;
        }
        fseek(disk, data_block.next_block*BLOCK_SIZE, SEEK_SET);
    }
    printf("%s\n", buffer);
    
    fclose(disk);
    return 0;
}