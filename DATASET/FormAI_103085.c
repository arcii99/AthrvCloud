//FormAI DATASET v1.0 Category: Encryption ; Style: curious
/* Welcome to the curious world of encryption! Let's have some fun with our secret message. */
#include <stdio.h>
#include <string.h>

// For encoding our message
void encode(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = message[i] + key;
        i++;
    }
}

// For decoding our message
void decode(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = message[i] - key;
        i++;
    }
}

int main() {
    printf("Enter your message: ");
    char message[100];
    fgets(message, 100, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = '\0';

    printf("Enter your encryption key: ");
    int key;
    scanf("%d", &key);

    printf("\n---Encoding your message with key %d---\n", key);
    encode(message, key);
    printf("Encoded message: %s\n", message);

    printf("\n---Decoding your message with key %d---\n", key);
    decode(message, key);
    printf("Decoded message: %s\n", message);

    return 0;
}