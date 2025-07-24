//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(char* plaintext, char* key, char* ciphertext) {
    while (*plaintext) {
        // Get the next block of plaintext
        char block[BLOCK_SIZE+1];
        int i;
        for (i = 0; i < BLOCK_SIZE && *plaintext; i++, plaintext++) {
            block[i] = *plaintext;
        }
        // Pad the block with zeros if necessary
        for (; i < BLOCK_SIZE; i++) {
            block[i] = 0;
        }
        block[BLOCK_SIZE] = '\0';
        // XOR the block with the key
        for (i = 0; i < BLOCK_SIZE; i++) {
            block[i] ^= key[i];
        }
        // Write the encrypted block to the ciphertext buffer
        strcat(ciphertext, block);
    }
}

int main(int argc, char** argv) {
    // Parse command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <plaintext> <key> <ciphertext>\n", argv[0]);
        exit(1);
    }
    char* plaintext = argv[1];
    char* key = argv[2];
    char* ciphertext = argv[3];
    // Encrypt the plaintext with the key
    encrypt(plaintext, key, ciphertext);
    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}