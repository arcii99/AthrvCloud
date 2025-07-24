//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Number of bits in the hash output
#define HASH_SIZE 256

// Initial seed value for the hash function
#define SEED 0xdeadbeef

// Number of 32-bit words in the hash output
#define WORDS HASH_SIZE / 32

// Bitwise rotate left function
#define ROTL(x,n) ((x << n) | (x >> (32-n)))

// Modular addition function
#define ADD(x,y) (x + y) % 0x100000000

// Hash function
void hash(char *input, uint32_t *output) {
    // Initialize hash state
    uint32_t state[WORDS];
    for (int i = 0; i < WORDS; i++) {
        state[i] = SEED;
    }
    
    // Pad input string to a multiple of 64 bytes
    int input_length = strlen(input);
    int padded_length = ((input_length + 8) / 64 + 1) * 64;
    char *padded_input = malloc(padded_length);
    memcpy(padded_input, input, input_length);
    padded_input[input_length] = 0x80;
    for (int i = input_length+1; i < padded_length-8; i++) {
        padded_input[i] = 0x00;
    }
    
    // Add length of input in bits to the end
    uint64_t bits = input_length * 8;
    memcpy(&padded_input[padded_length-8], &bits, 8);
    
    // Process each 64-byte block of padded input
    for (int block = 0; block < padded_length/64; block++) {
        // Break block into 16 32-bit words
        uint32_t words[16];
        for (int i = 0; i < 16; i++) {
            int offset = block*64 + i*4;
            words[i] = (padded_input[offset] << 24) | (padded_input[offset+1] << 16) |
                       (padded_input[offset+2] << 8) | padded_input[offset+3];
        }
        
        // Perform 64 rounds of mixing operations
        for (int round = 0; round < 64; round++) {
            // Compute function specific constants
            uint32_t K, f;
            if (round < 16) {
                K = 0x5a827999;
                f = (state[1] & state[2]) | ((~state[1]) & state[3]);
            } else if (round < 32) {
                K = 0x6ed9eba1;
                f = state[1] ^ state[2] ^ state[3];
            } else if (round < 48) {
                K = 0x8f1bbcdc;
                f = (state[1] & state[2]) | (state[1] & state[3]) | (state[2] & state[3]);
            } else {
                K = 0xca62c1d6;
                f = state[1] ^ state[2] ^ state[3];
            }
            
            // Perform mixing operations
            uint32_t temp = ADD(ADD(ADD(state[0], f), words[round % 16]), K);
            state[0] = ADD(state[3], ROTL(temp, 5));
            state[3] = state[2];
            state[2] = state[1];
            state[1] = state[0];
        }
        
        // Update output hash with mixing results
        for (int i = 0; i < WORDS; i++) {
            output[i] = ADD(output[i], state[i]);
        }
    }
    
    // Free dynamically allocated memory
    free(padded_input);
}

// Test program
int main(int argc, char **argv) {
    // Hash each command line argument and print result
    uint32_t output[WORDS];
    for (int i = 1; i < argc; i++) {
        hash(argv[i], output);
        printf("Hash of \"%s\": 0x", argv[i]);
        for (int j = 0; j < WORDS; j++) {
            printf("%08x", output[j]);
        }
        printf("\n");
    }
    
    return 0;
}