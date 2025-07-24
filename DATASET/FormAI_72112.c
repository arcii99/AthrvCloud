//FormAI DATASET v1.0 Category: modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000 // Maximum character limit for input

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main() {
    char message[MAX];
    int key;

    // Get message and key from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX, stdin);

    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);
    while (key < 1 || key > 25) {
        printf("Invalid key. Enter encryption key (1-25): ");
        scanf("%d", &key);
    }

    // Encrypt the message
    encrypt(message, key);

    printf("\nEncrypted message: %s", message);

    // Decrypt the message
    decrypt(message, key);

    printf("Decrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Encrypt lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        // Encrypt uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char *message, int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Decrypt lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }

        // Decrypt uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}