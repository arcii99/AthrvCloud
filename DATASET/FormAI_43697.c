//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define NUM_BLOCKS 100

// Structure for simulating hard disk blocks
typedef struct Block {
    int id;
    int data;
} Block;

// Function to simulate data recovery from hard disk blocks
void data_recovery(Block *blocks, int num_blocks) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].id != i) {
            // If block id doesn't match expected id, recover data
            blocks[i].data = i;
        }
    }
}

int main() {
    Block blocks[NUM_BLOCKS];
    int i;

    // Initialize hard disk blocks
    for (i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].id = i;
        blocks[i].data = rand();
    }

    // Simulate data corruption
    blocks[5].data = 0;
    blocks[10].id = 12;

    // Recover data
    data_recovery(blocks, NUM_BLOCKS);

    // Print recovered data
    for (i = 0; i < NUM_BLOCKS; i++) {
        printf("Block %d: %d\n", i, blocks[i].data);
    }

    return 0;
}