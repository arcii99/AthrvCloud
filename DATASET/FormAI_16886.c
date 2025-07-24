//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Encryption key
const char key[27] = "QWERTYUIOPSDFGHJKLZXCVBNM";

// Encryption function
char* encrypt(char* message) {
    int length = strlen(message);
    char* encrypted = calloc(length, sizeof(char));
    if (!encrypted) {
        printf("Memory allocation for encrypted message failed.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);
        if (c < 'A' || c > 'Z') {
            encrypted[i] = c;
            continue;
        }
        encrypted[i] = key[c - 'A'];
    }

    return encrypted;
}

int main() {
    char message[MAX_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strlen(message) - 1] = '\0';

    char* encrypted = encrypt(message);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted);

    return 0;
}