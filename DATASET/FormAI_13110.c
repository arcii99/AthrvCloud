//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 13 // ROT13 Cipher

int main()
{
    char message[100];
    int i;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from message
    if (message[strlen(message)-1] == '\n') {
        message[strlen(message)-1] = '\0';
    }

    // Encrypt message
    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + ENCRYPT_KEY) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + ENCRYPT_KEY) % 26 + 'A';
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}