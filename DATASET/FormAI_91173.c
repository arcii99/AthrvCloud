//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Block {
    int prevHash;
    char message[100];
    int nonce;
    int hash;
};

int main() {
    int numBlocks, prevHash = 0;
    printf("Enter number of blocks: ");
    scanf("%d", &numBlocks);

    struct Block blockChain[numBlocks];

    // Generate random seed
    srand(time(NULL));

    for (int i=0; i<numBlocks; i++) {
        // Collect message to be watermarked
        printf("Enter message for block %d: ", i+1);
        scanf("%s", blockChain[i].message);

        // Generate a random nonce value
        blockChain[i].nonce = rand() % 10000 + 1;

        // Calculate hash of current block
        blockChain[i].hash = prevHash + blockChain[i].nonce + strlen(blockChain[i].message);

        // Assign current block's hash to previous block's hash
        prevHash = blockChain[i].hash;
    }

    // Print out block chain with watermarked messages
    printf("\nBlockchain with watermarked messages:\n\n");

    for (int i=0; i<numBlocks; i++) {
        printf("Block %d:\n", i+1);
        printf("     Prev Hash: %d\n", blockChain[i].prevHash);
        printf("     Nonce: %d\n", blockChain[i].nonce);
        printf("     Hash: %d\n", blockChain[i].hash);
        printf("     Message: %s [watermarked]\n\n", blockChain[i].message);
    }

    return 0;
}