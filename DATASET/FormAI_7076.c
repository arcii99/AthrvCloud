//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ENCRYPTION_KEY 1234
#define BLOCK_SIZE 16

void encrypt(char* plaintext, unsigned int size) {
    srand(time(NULL));
    char key[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        key[i] = (char) (rand() % 255);
    }
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            plaintext[i+j] ^= key[j];
        }
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[size+i] = key[i];
    }
}

void decrypt(char* ciphertext, unsigned int size) {
    char key[BLOCK_SIZE];
    for (int i = size-BLOCK_SIZE; i < size; i++) {
        key[i-(size-BLOCK_SIZE)] = ciphertext[i];
    }
    for (int i = size-BLOCK_SIZE; i >= 0; i -= BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i+j] ^= key[j];
        }
    }
}

int main() {
    char plaintext[] = "Hello, world! This is a message to be encrypted.";
    unsigned int size = sizeof(plaintext);
    encrypt(plaintext, size);
    printf("Encrypted message: %s\n", plaintext);
    decrypt(plaintext, size);
    printf("Decrypted message: %s\n", plaintext);
    return 0;
}