//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int plaintext_len = strlen(plaintext), key_len = strlen(key), i;
    for (i = 0; i < plaintext_len; i++) {
        ciphertext[i] = (plaintext[i] + key[i % key_len]) % 26 + 'A';
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int ciphertext_len = strlen(ciphertext), key_len = strlen(key), i;
    for (i = 0; i < ciphertext_len; i++) {
        plaintext[i] = (ciphertext[i] - key[i % key_len] + 26) % 26 + 'A';
    }
    plaintext[i] = '\0';
}

int main() {
    char *plaintext = "HELLO", *key = "KEY", ciphertext[100], decrypted[100];
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    decrypt(ciphertext, key, decrypted);
    printf("Decrypted text: %s\n", decrypted);
    return 0;
}