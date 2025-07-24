//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 10000
#define NUM_ITERATIONS 100000

void fill_random_data(char* data, size_t size) {
    for(size_t i = 0; i < size; i++) {
        data[i] = 'A' + rand() % 26;
    }
}

void perform_operation(char* block) {
    for(size_t i = 0; i < BLOCK_SIZE; i++) {
        block[i] = 'a' + rand() % 26;
    }
}

int main() {
    srand(time(NULL));
    char* data[NUM_BLOCKS];

    for(size_t i = 0; i < NUM_BLOCKS; i++) {
        data[i] = (char*)malloc(BLOCK_SIZE);
        if(!data[i]) {
            printf("Error: Failed to allocate memory for block %zu\n", i);
            return -1;
        }
        fill_random_data(data[i], BLOCK_SIZE);
    }

    for(size_t i = 0; i < NUM_ITERATIONS; i++) {
        size_t rand_block = rand() % NUM_BLOCKS;
        perform_operation(data[rand_block]);
    }

    for(size_t i = 0; i < NUM_BLOCKS; i++) {
        free(data[i]);
    }

    return 0;
}