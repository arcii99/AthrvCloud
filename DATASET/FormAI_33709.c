//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This function encrypts the given message using a modern encryption algorithm.
 * 
 * @param message The message to be encrypted.
 * 
 * @return The encrypted message.
 */
char* encryptMessage(char* message) {
    int len = strlen(message);
    char* encrypted = (char*) malloc(sizeof(char) * len);

    int i;
    for (i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            int diff = message[i] - 'a';
            encrypted[i] = (char) ('z' - diff);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            int diff = message[i] - 'A';
            encrypted[i] = (char) ('Z' - diff);
        } else {
            encrypted[i] = message[i];
        }
    }

    return encrypted;
}

int main() {
    char message[256];
    printf("Enter the message to be encrypted: ");
    fgets(message, 256, stdin);
    message[strcspn(message, "\r\n")] = 0; // strip newline character

    char* encrypted = encryptMessage(message);
    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);
    return 0;
}