//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a Caesar cipher with a given key
char *encrypt(char *message, int key) {
    int i;
    char ch;
    char *encrypted = (char *) malloc(strlen(message) + 1);

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }

        encrypted[i] = ch;
    }
    encrypted[i] = '\0';

    return encrypted;
}

int main() {
    char message[100];
    int key;
    char *encrypted;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter key to encrypt the message (1-25): ");
    scanf("%d", &key);

    encrypted = encrypt(message, key);

    printf("Encrypted message: %s", encrypted);

    free(encrypted);
    return 0;
}