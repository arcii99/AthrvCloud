//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Encryption key
const char KEY = 'x';

// Function to encode a message
void encode(char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] ^ KEY;
    }
}

// Function to decode an encoded message
void decode(char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] ^ KEY;
    }
}

int main() {
    char message[MAX_LEN];

    // Get message from user
    printf("Enter message to encode: ");
    fgets(message, MAX_LEN, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;

    // Encode message
    encode(message);
    printf("Encoded message: %s\n", message);

    // Decode message
    decode(message);
    printf("Decoded message: %s\n", message);

    return 0;
}