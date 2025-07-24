//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void print_hex(unsigned char *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%02x", array[i]);
    }
    printf("\n");
}

unsigned char *encrypt(unsigned char *plaintext, unsigned char *key) {
    unsigned char *ciphertext = (unsigned char*) malloc(strlen(plaintext));
    unsigned char block[BLOCK_SIZE], iv[BLOCK_SIZE];
    int i, j;

    // Initialize IV
    for (i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = rand() % 256;
    }

    // Copy IV to ciphertext
    memcpy(ciphertext, iv, BLOCK_SIZE);

    // Copy IV to block
    memcpy(block, iv, BLOCK_SIZE);

    for (i = BLOCK_SIZE; i < strlen(plaintext); i += BLOCK_SIZE) {
        // XOR block with plaintext
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= plaintext[i + j];
        }

        // Encrypt block with key
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= key[j];
        }

        // Copy block to ciphertext
        memcpy(ciphertext + i, block, BLOCK_SIZE);
    }

    return ciphertext;
}

unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key) {
    unsigned char *plaintext = (unsigned char*) malloc(strlen(ciphertext) - BLOCK_SIZE);
    unsigned char block[BLOCK_SIZE], iv[BLOCK_SIZE];
    int i, j;

    // Copy IV from ciphertext
    memcpy(iv, ciphertext, BLOCK_SIZE);

    // Copy IV to block
    memcpy(block, iv, BLOCK_SIZE);

    for (i = BLOCK_SIZE; i < strlen(ciphertext); i += BLOCK_SIZE) {
        // Decrypt block with key
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= key[j];
        }

        // XOR block with previous block or IV
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= ciphertext[i - BLOCK_SIZE + j];
        }

        // Copy block to plaintext
        memcpy(plaintext + i - BLOCK_SIZE, block, BLOCK_SIZE);

        // Copy ciphertext block to block
        memcpy(block, ciphertext + i, BLOCK_SIZE);
    }

    return plaintext;
}

int main() {
    unsigned char plaintext[] = "This is a secret message";
    unsigned char key[BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
                                     0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    unsigned char *ciphertext, *recovered_plaintext;

    ciphertext = encrypt(plaintext, key);
    printf("Encrypted message: ");
    print_hex(ciphertext, strlen(plaintext));

    recovered_plaintext = decrypt(ciphertext, key);
    printf("Recovered message: %s\n", recovered_plaintext);

    free(ciphertext);
    free(recovered_plaintext);

    return 0;
}