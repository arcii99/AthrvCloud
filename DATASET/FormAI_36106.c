//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 128

void encrypt(char *plaintext, const char *key);
void decrypt(char *ciphertext, const char *key);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <plaintext or ciphertext> <key>\n", argv[0]);
        exit(1);
    }

    char *input = argv[1];
    char *key = argv[2];

    if (strlen(key) != BLOCK_SIZE) {
        printf("Error: Invalid key size. Key must be %d bytes long.\n", BLOCK_SIZE);
        exit(1);
    }

    if (strncmp(input, "encrypted:", 10) == 0) {
        char *ciphertext = input + 10;
        decrypt(ciphertext, key);
        printf("Decrypted plaintext: %s\n", ciphertext);
    } else {
        encrypt(input, key);
        printf("Encrypted ciphertext: encrypted:%s\n", input);
    }

    return 0;
}

void encrypt(char *plaintext, const char *key) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] ^= key[i % BLOCK_SIZE];
    }
}

void decrypt(char *ciphertext, const char *key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] ^= key[i % BLOCK_SIZE];
    }
}