//FormAI DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random key
void generate_key(char *key, int key_length) {
    int i;
    for(i=0; i<key_length; i++) {
        key[i] = (rand() % 26) + 'A';
    }
    key[i] = '\0';
}

// Function to encrypt a message
void encrypt(char *message, char *key, int key_length) {
    int i, j;
    for(i=0, j=0; message[i]; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + key[j] - 2*'A') % 26 + 'A';
            j = (j+1) % key_length;
        }
    }
}

// Function to decrypt a message
void decrypt(char *message, char *key, int key_length) {
    int i, j;
    for(i=0, j=0; message[i]; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - key[j] + 26) % 26 + 'A';
            j = (j+1) % key_length;
        }
    }
}

// Main program
int main() {
    char message[1000], key[100];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the message from input
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = 0;

    // Generate a random key of length equal to the message
    generate_key(key, strlen(message));

    // Print the key
    printf("Generated key: %s\n", key);

    // Encrypt the message using the key
    encrypt(message, key, strlen(key));

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key, strlen(key));

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}