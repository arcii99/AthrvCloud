//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fitness Tracker structure
struct FitnessTracker {
    char username[50];
    int age;
    float weight;
    float height;
    float bmi;
};

// Blockchain structure
struct Block {
    int index;
    int timestamp;
    struct FitnessTracker tracker;
    unsigned char previousHash[32];
    unsigned char hash[32];
};

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to generate hash
void generateHash(unsigned char* data, int dataSize, unsigned char* hash) {
    // Implementation of hash algorithm goes here
    // For the sake of simplicity, we are not implementing the hash algorithm here
    // Instead, we will use a random hash
    for (int i = 0; i < 32; i++) {
        hash[i] = rand() % 256;
    }
}

// Function to add block to blockchain
void addBlock(struct Block* block, struct Block* previousBlock) {
    block->index = previousBlock->index + 1;
    block->timestamp = (int)time(NULL);
    generateHash((unsigned char*)&block->tracker, sizeof(block->tracker), block->hash);
    memcpy(block->previousHash, previousBlock->hash, sizeof(block->hash));
}

// Main function to run the program
int main() {
    // Initialize blockchain with the genesis block
    struct Block genesisBlock;
    genesisBlock.index = 0;
    genesisBlock.timestamp = (int)time(NULL);
    strcpy(genesisBlock.tracker.username, "JohnDoe");
    genesisBlock.tracker.age = 25;
    genesisBlock.tracker.weight = 70.5;
    genesisBlock.tracker.height = 1.75;
    genesisBlock.tracker.bmi = calculateBMI(genesisBlock.tracker.weight, genesisBlock.tracker.height);
    generateHash((unsigned char*)&genesisBlock.tracker, sizeof(genesisBlock.tracker), genesisBlock.hash);

    // Add genesis block to blockchain
    struct Block blockchain[10];
    memcpy(&blockchain[0], &genesisBlock, sizeof(struct Block));

    // Add blocks to blockchain
    for (int i = 1; i < 10; i++) {
        struct Block block;
        addBlock(&block, &blockchain[i - 1]);
        memcpy(&blockchain[i], &block, sizeof(struct Block));
    }

    // Print the blockchain
    for (int i = 0; i < 10; i++) {
        printf("Block %d:\n", blockchain[i].index);
        printf("Username: %s\n", blockchain[i].tracker.username);
        printf("Age: %d\n", blockchain[i].tracker.age);
        printf("Weight: %f\n", blockchain[i].tracker.weight);
        printf("Height: %f\n", blockchain[i].tracker.height);
        printf("BMI: %f\n", blockchain[i].tracker.bmi);
        printf("Hash: ");
        for (int j = 0; j < 32; j++) {
            printf("%02x", blockchain[i].hash[j]);
        }
        printf("\n\n");
    }

    return 0;
}