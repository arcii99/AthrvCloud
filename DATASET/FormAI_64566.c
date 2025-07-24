//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 4096 // 4KB block size
#define MAX_BLOCKS 500000 // Max number of blocks in our simulated storage

typedef struct {
    int block_number;
    char data[BLOCK_SIZE];
} block_t;

typedef struct {
    int n_blocks;
    int current_write_block;
    block_t *blocks[MAX_BLOCKS];
} storage_t;

void initialize_storage(storage_t *storage) {
    storage->n_blocks = 0;
    storage->current_write_block = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        storage->blocks[i] = NULL;
    }
}

int write_block(storage_t *storage, char *data) {
    if (storage->n_blocks >= MAX_BLOCKS) {
        return -1; // Error: storage full
    }
    block_t *block = (block_t*) malloc(sizeof(block_t));
    block->block_number = storage->n_blocks;
    memcpy(block->data, data, BLOCK_SIZE);
    storage->blocks[storage->current_write_block++] = block;
    storage->n_blocks++;
    return block->block_number;
}

int read_block(storage_t *storage, int block_number, char *data) {
    if (block_number < 0 || block_number >= storage->n_blocks) {
        return -1; // Error: block not found
    }
    block_t *block = storage->blocks[block_number];
    memcpy(data, block->data, BLOCK_SIZE);
    return 0;
}

void free_storage(storage_t *storage) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (storage->blocks[i] != NULL) {
            free(storage->blocks[i]);
            storage->blocks[i] = NULL;
        }
    }
}

int main() {
    storage_t storage;
    initialize_storage(&storage);

    srand(time(NULL));
    char data[BLOCK_SIZE];
    for (int i = 0; i < 1000000; i++) {
        // Generate random data to simulate write
        for (int j = 0; j < BLOCK_SIZE; j++) {
            data[j] = rand() % 256;
        }
        int block_number = write_block(&storage, data);

        // Read back the data to simulate read
        char data_read[BLOCK_SIZE];
        read_block(&storage, block_number, data_read);

        // Compare the data to ensure it was written and read correctly
        if (memcmp(data, data_read, BLOCK_SIZE) != 0) {
            printf("Error: data mismatch after write/read\n");
            break;
        }

        // Free the storage to simulate free
        if (i % 100 == 99) {
            free_storage(&storage);
            initialize_storage(&storage);
        }
    }

    free_storage(&storage);
    return 0;
}