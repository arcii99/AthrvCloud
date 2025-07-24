//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encode(char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] + key;
    }
    printf("The encoded message is: %s\n", message);
}

void decode(char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] - key;
    }
    printf("The decoded message is: %s\n", message);
}

int main() {
    srand(time(NULL));
    int key = rand() % 100;
    printf("Surprise! We are going to encrypt your message using a unique encryption algorithm.\n");
    printf("Your encryption key is: %d\n", key);

    char message[100];
    printf("Please enter the message you want to encrypt (max 100 characters): ");
    fgets(message, 100, stdin);

    // remove trailing newline character
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    printf("Original message: %s\n", message);

    encode(message, key);

    printf("Do you want to decrypt the message? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        decode(message, key);
    }

    return 0;
}