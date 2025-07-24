//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message recursively
void encrypt(char* message, int key, int depth) {
    // Base case: if the message length is zero or depth is zero
    if(strlen(message) == 0 || depth == 0) {
        return;
    }

    // Loop through each character of the message
    for(int i = 0; i < strlen(message); i++) {
        // Shift the character by the key value
        message[i] = (((message[i] - 'a') + key) % 26) + 'a';
    }

    // Encrypt the message recursively again with the same key and depth reduced by 1
    encrypt(message, key, depth-1);
}

int main() {
    // Get the message and key from user
    char message[100];
    int key, depth;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("Enter encryption depth: ");
    scanf("%d", &depth);

    // Encrypt the message recursively
    encrypt(message, key, depth);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}