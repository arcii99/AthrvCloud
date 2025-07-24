//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program encrypts a message using a custom algorithm

int main() {
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin); // Get input from user

    int key;
    printf("Enter a key (1-26): ");
    scanf("%d", &key); // Get encryption key from user

    // Convert all characters to uppercase
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 32;
        }
    }

    // Encrypt the message using the custom algorithm
    char encryptedMessage[1000];
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = ((message[i] - 'A' + key) % 26) + 'A'; // Shift character by key
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encryptedMessage); // Print encrypted message

    return 0;
}