//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#define BLOCK_SIZE 32

// Define the Block structure
typedef struct {
    unsigned int index;
    unsigned int timestamp;
    unsigned char hash[BLOCK_SIZE];
    unsigned char prevHash[BLOCK_SIZE];
    unsigned int nonce;
} Block;

// The main function
int main() {
    // Initialize some variables
    Block block;
    unsigned int difficulty = 4; // Difficulty of the proof-of-work algorithm
    unsigned int nonce = 0; // Nonce value
    int i; // Index of the loop

    // Generate a genesis block
    block.index = 0;
    block.timestamp = 0;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block.hash[i] = 0;
        block.prevHash[i] = 0;
    }
    block.nonce = 0;

    // Print the genesis block
    printf("Block %d (%d) [%02x%02x%02x%02x...]\n", block.index, block.timestamp, block.hash[0], block.hash[1], block.hash[2], block.hash[3]);

    // Generate a new block
    block.index = 1;
    block.timestamp = (unsigned int) time(NULL);
    for (i = 0; i < BLOCK_SIZE; i++) {
        block.prevHash[i] = block.hash[i];
    }
    while (1) {
        nonce++;
        block.nonce = nonce;
        // Calculate the hash value using the proof-of-work algorithm
        calcHash(block.hash, block.prevHash, block.timestamp, nonce, difficulty);

        // If the calculated hash starts with the specified number of zeros, break out of the loop
        if (isValidHash(block.hash, difficulty)) {
            break;
        }
    }

    // Print the new block
    printf("Block %d (%d) [%02x%02x%02x%02x...]\n", block.index, block.timestamp, block.hash[0], block.hash[1], block.hash[2], block.hash[3]);
    return 0;
}

// Function to calculate the hash value
void calcHash(unsigned char* hash, unsigned char* prevHash, unsigned int timestamp, unsigned int nonce, unsigned int difficulty) {
    int i; // Loop index
    unsigned char buffer[4 + BLOCK_SIZE + BLOCK_SIZE + sizeof(unsigned int)]; // Buffer to store the input values
    memcpy(buffer, &timestamp, sizeof(unsigned int)); // Copy the timestamp
    memcpy(buffer + sizeof(unsigned int), prevHash, BLOCK_SIZE); // Copy the previous hash
    memcpy(buffer + sizeof(unsigned int) + BLOCK_SIZE, &nonce, sizeof(unsigned int)); // Copy the nonce
    SHA256(buffer, 4 + BLOCK_SIZE + BLOCK_SIZE + sizeof(unsigned int), hash); // Compute the hash using the SHA256 algorithm
    for (i = 0; i < difficulty; i++) {
        if (hash[i / 8] & (1 << (7 - i % 8))) { // Check if the specified bit is set to 1
            return; // The hash value is not valid
        }
    }
}

// Function to validate the hash value
int isValidHash(unsigned char* hash, unsigned int difficulty) {
    int i; // Loop index
    for (i = 0; i < difficulty; i++) {
        if (hash[i / 8] & (1 << (7 - i % 8))) { // Check if the specified bit is set to 1
            return 0; // The hash value is not valid
        }
    }
    return 1; // The hash value is valid
}