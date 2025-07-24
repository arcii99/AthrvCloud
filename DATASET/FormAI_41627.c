//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare an array to hold the key for encryption
char key[] = "surreality";

// Function to encrypt the message using the key
char* encrypt(char* message) {
    int i, j = 0, k;
    int key_length = strlen(key);

    // Allocate memory for the encrypted message string
    char *encrypted_message = malloc(strlen(message));

    // Loop through each character in the message
    for (i = 0; i < strlen(message); i++) {
        // Get the corresponding character in the key
        char key_char = key[j % key_length];

        // XOR the message character with the key character
        encrypted_message[i] = message[i] ^ key_char;

        // Increment the key index
        j++;
    }

    // Return the encrypted message
    return encrypted_message;
}

int main() {
    char message[] = "This is a surrealist encryption program!";

    // Encrypt the message
    char *encrypted_message = encrypt(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Free the memory allocated for the encrypted message
    free(encrypted_message);

    return 0;
}