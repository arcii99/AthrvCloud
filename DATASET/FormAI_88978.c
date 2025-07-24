//FormAI DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Encryption Key
const int key = 10;

// Define the Encryption Function
void encrypt(char *message, int key) {

    // Loop through each character in the message
    int i = 0;
    while (message[i] != '\0') {

        // Encrypt each character by adding the key
        message[i] += key;

        // Move to the next character
        i++;
    }
}

// Define the Decryption Function
void decrypt(char *message, int key) {

    // Loop through each character in the message
    int i = 0;
    while (message[i] != '\0') {

        // Decrypt each character by subtracting the key
        message[i] -= key;

        // Move to the next character
        i++;
    }
}

int main() {

    // Define the message
    char message[100];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = 0;

    // Print the original message
    printf("Original Message: %s\n", message);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted Message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted Message: %s\n", message);

    // Exit the program
    return 0;
}