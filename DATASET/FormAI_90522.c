//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 128

void printByteArray(char *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%02x ", arr[i]);
    }
    printf("\n");
}

void generateKey(char *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 256;
    }
}

void xor(char *a, char *b, int len) {
    for (int i = 0; i < len; i++) {
        a[i] ^= b[i];
    }
}

void encrypt(char *plainText, char *cipherText, char *key, int len) {
    char block[BLOCK_SIZE];
    memcpy(block, key, BLOCK_SIZE);
    memcpy(cipherText, plainText, len);
    int numBlocks = len / BLOCK_SIZE;
    for (int i = 0; i < numBlocks; i++) {
        int blockStart = i * BLOCK_SIZE;
        int blockEnd = blockStart + BLOCK_SIZE;
        xor(cipherText + blockStart, block, BLOCK_SIZE);
        memcpy(block, cipherText + blockStart, BLOCK_SIZE);
    }
}

void decrypt(char *cipherText, char *plainText, char *key, int len) {
    char block[BLOCK_SIZE];
    memcpy(block, key, BLOCK_SIZE);
    memcpy(plainText, cipherText, len);
    int numBlocks = len / BLOCK_SIZE;
    for (int i = numBlocks - 1; i >= 0; i--) {
        int blockStart = i * BLOCK_SIZE;
        int blockEnd = blockStart + BLOCK_SIZE;
        xor(plainText + blockStart, block, BLOCK_SIZE);
        memcpy(block, cipherText + blockStart, BLOCK_SIZE);
        printByteArray(block, BLOCK_SIZE);
    }
}

int main() {
    char plainText[] = "Hello, world! This is a test string.";
    char cipherText[sizeof(plainText)];
    char decryptedText[sizeof(plainText)];
    int len = strlen(plainText) + 1;

    char key[BLOCK_SIZE];
    generateKey(key, BLOCK_SIZE);
    printf("Key: ");
    printByteArray(key, BLOCK_SIZE);

    encrypt(plainText, cipherText, key, len);
    printf("Cipher text: ");
    printByteArray(cipherText, len);

    decrypt(cipherText, decryptedText, key, len);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}