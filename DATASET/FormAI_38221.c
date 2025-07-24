//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *, int);
void decrypt(char *, int);

int main() {
	char message[1000];
    int key = 5;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character from input
    printf("\n");

    printf("Original message: %s\n", message);

    // Encrypt message using key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt message using key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key) {
    int i = 0;
    char c;
    while (message[i]) {
        // Shift each character by the key value
        c = message[i] + key;

        // Handle wrap-around for ASCII values
        if (c > 'z') {
            c = 'a' + (c - 'z') - 1;
        } else if (c < 'a') {
            c = 'z' - ('a' - c) + 1;
        }
        message[i] = c;
        i++;
    }
}

void decrypt(char *message, int key) {
    int i = 0;
    char c;
    while (message[i]) {
        // Shift each character back by the key value
        c = message[i] - key;

        // Handle wrap-around for ASCII values
        if (c > 'z') {
            c = 'a' + (c - 'z') - 1;
        }
        else if (c < 'a') {
            c = 'z' - ('a' - c) + 1;
        }
        message[i] = c;
        i++;
    }
}