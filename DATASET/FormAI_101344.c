//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char *encrypt(char *message);

int main(void) {
    char message[MAX_LENGTH], *encrypted_message;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    encrypted_message = encrypt(message);

    printf("Encrypted message: %s\n", encrypted_message);

    free(encrypted_message);

    return 0;
}

char *encrypt(char *message) {
    char *encrypted = (char *) malloc((strlen(message) + 1) * sizeof(char));

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = 'z' - (message[i] - 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = 'Z' - (message[i] - 'A');
        } else {
            encrypted[i] = message[i];
        }
    }

    return encrypted;
}