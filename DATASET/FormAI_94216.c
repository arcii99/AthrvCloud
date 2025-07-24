//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], char key[]) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < message_len; i++) {
        message[i] = message[i] ^ key[i % key_len];
    }
}

void decrypt(char message[], char key[]) {
    encrypt(message, key); // Same encryption and decryption algorithm
}

int main() {
    char message[50];
    char key[50];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);

    encrypt(message, key); // Encrypt the message using the key

    printf("\nEncrypted message: %s", message);

    decrypt(message, key); // Decrypt the message using the same key

    printf("\nDecrypted message: %s", message);

    return 0;
}