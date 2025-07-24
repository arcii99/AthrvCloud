//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char *plaintext, int key) {
    int i;
    for(i = 0; i < strlen(plaintext); ++i) {
        // Shift each character by the key value
        plaintext[i] = (plaintext[i] + key) % 127;
    }
}

void decrypt(char *ciphertext, int key) {
    int i;
    for(i = 0; i < strlen(ciphertext); ++i) {
        // Shift each character back by the key value
        ciphertext[i] = (ciphertext[i] - key + 127) % 127;
    }
}

int main() {
    char message[MAX_SIZE];
    int key;

    // Read input from the user
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter an integer key value: ");
    scanf("%d", &key);

    // Ensure key value is between 0 - 126
    key = key % 127;

    // Encrypt the message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the same key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}