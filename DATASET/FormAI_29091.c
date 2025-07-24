//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPT_KEY 7 // Encryption key

void encrypt(char* message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] += key; // Add encryption key to each character
    }
}

void decrypt(char* message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] -= key; // Subtract encryption key from each character
    }
}

int main() {
    srand(time(NULL)); // Set random seed based on current time

    char message[100]; // Message to be encrypted
    printf("Hello! What do you want to encrypt today? (Max 100 characters)\n");
    fgets(message, 100, stdin);

    printf("\nOriginal message: %s\n\n", message);

    encrypt(message, ENCRYPT_KEY); // Encrypt message
    printf("Encrypted message: %s\n\n", message);

    decrypt(message, ENCRYPT_KEY); // Decrypt message
    printf("Decrypted message: %s\n\n", message);

    printf("Hope you enjoyed encrypting and decrypting your message with me!\n");

    return 0;
}