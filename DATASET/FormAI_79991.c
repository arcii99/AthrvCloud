//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define SHIFT_AMOUNT 3

void encrypt(char* message) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] += SHIFT_AMOUNT;
        i++;
    }
}

void decrypt(char* message) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] -= SHIFT_AMOUNT;
        i++;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Remove trailing newline character from message
    int message_len = strlen(message);
    if (message[message_len - 1] == '\n') {
        message[message_len - 1] = '\0';
    }
    
    // Encrypt the message and print it
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message and print it
    decrypt(message);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}