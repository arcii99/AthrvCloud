//FormAI DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key
const char *encryption_key = "SuperSecretKey";

// Encrypt function
void encrypt(char *plaintext, char *key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int i;

    // XOR each character of plaintext with the corresponding character in the key
    for(i = 0; i < plaintext_len; ++i) {
        plaintext[i] = plaintext[i] ^ key[i % key_len];
    }
}

// Decrypt function
void decrypt(char *ciphertext, char *key) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    int i;

    // XOR each character of ciphertext with the corresponding character in the key
    for(i = 0; i < ciphertext_len; ++i) {
        ciphertext[i] = ciphertext[i] ^ key[i % key_len];
    }
}

int main(void) {
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, 100, stdin);

    // Remove the newline character
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Encrypt the input plaintext using our encryption key
    encrypt(plaintext, encryption_key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", plaintext);

    // Decrypt the encrypted string using our encryption key
    decrypt(plaintext, encryption_key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", plaintext);

    return 0;
}