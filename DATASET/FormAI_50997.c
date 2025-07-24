//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to represent data block
struct data_block {
    int id;
    char* data;
};

// Function to recover data from block with given ID
char* recover_data(struct data_block* blocks, int num_blocks, int id) {
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i].id == id) {
            return blocks[i].data;
        }
    }
    return NULL;
}

int main() {
    // Example usage
    struct data_block blocks[4];

    // Initialize blocks with dummy data
    char* data1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char* data2 = "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char* data3 = "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    char* data4 = "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.";

    blocks[0].id = 1;
    blocks[0].data = data1;

    blocks[1].id = 2;
    blocks[1].data = data2;

    blocks[2].id = 3;
    blocks[2].data = data3;

    blocks[3].id = 4;
    blocks[3].data = data4;

    // Recover data from block 1 and print
    char* recovered_data = recover_data(blocks, 4, 1);
    printf("Recovered data: %s\n", recovered_data);

    return 0;
}