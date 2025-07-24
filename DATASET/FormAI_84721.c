//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, keyLen = strlen(key), plaintextLen = strlen(plaintext);
    for (i = 0; i < plaintextLen; ++i) {
        ciphertext[i] = (plaintext[i] + key[i % keyLen]) % 26 + 'a';
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, keyLen = strlen(key), ciphertextLen = strlen(ciphertext);
    for (i = 0; i < ciphertextLen; ++i) {
        plaintext[i] = (ciphertext[i] - key[i % keyLen] + 26) % 26 + 'a';
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[] = "hello";
    char key[] = "cipher";
    char ciphertext[strlen(plaintext)];

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    char decryptedPlaintext[strlen(plaintext)];
    decrypt(ciphertext, key, decryptedPlaintext);
    printf("Decrypted message: %s\n", decryptedPlaintext);

    return 0;
}