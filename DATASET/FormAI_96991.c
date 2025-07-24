//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>

#define LENGTH 16 // define signal length
#define BLOCK_SIZE 4 // define block size
#define NUM_BLOCKS LENGTH / BLOCK_SIZE // calculate number of blocks

void decentralized_dsp(int signal[], int block_size, int num_blocks);

int main() {
    int signal[LENGTH] = {1, 2, 3, -4, 5, 6, -7, 8, 9, -10, 11, 12, -13, 14, 15, -16};
    decentralized_dsp(signal, BLOCK_SIZE, NUM_BLOCKS);
    return 0;
}

void decentralized_dsp(int signal[], int block_size, int num_blocks) {
    
    int sum = 0;
    int block_sum = 0;
    
    // calculate sum of entire signal
    for(int i = 0; i < LENGTH; i++) {
        sum += signal[i];
    }
    printf("Sum of entire signal: %d\n", sum);
    
    // calculate sum of each block
    for(int i = 0; i < num_blocks; i++) {
        for(int j = 0; j < block_size; j++) {
            block_sum += signal[(i*block_size)+j];
        }
        printf("Sum of block %d: %d\n", i+1, block_sum);
        block_sum = 0;
    }
}