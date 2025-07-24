//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define key for encryption and decryption
const int KEY = 3;

// Function to encrypt a string
void encrypt(char message[]) {
    int message_length = strlen(message);

    // Loop over each character in the string and encrypt it using the key
    for (int i = 0; i < message_length; i++) {
        char character = message[i];
        if (character >= 'a' && character <= 'z') {
            message[i] = ((character - 'a') + KEY) % 26 + 'a';
        }
        else if (character >= 'A' && character <= 'Z') {
            message[i] = ((character - 'A') + KEY) % 26 + 'A';
        }
    }
}

// Function to decrypt a string
void decrypt(char message[]) {
    int message_length = strlen(message);

    // Loop over each character in the string and decrypt it using the key
    for (int i = 0; i < message_length; i++) {
        char character = message[i];
        if (character >= 'a' && character <= 'z') {
            message[i] = ((character - 'a') - KEY + 26) % 26 + 'a';
        }
        else if (character >= 'A' && character <= 'Z') {
            message[i] = ((character - 'A') - KEY + 26) % 26 + 'A';
        }
    }
}

// Main function
int main() {
    char message[100];

    // Get the message input from the user
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character

    // Encrypt the message and print the result
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message and print the result
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}