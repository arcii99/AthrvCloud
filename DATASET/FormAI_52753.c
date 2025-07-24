//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
// Romeo and Juliet's C Cryptography Implementation Example Program

#include <stdio.h>
#include <string.h>

// Encryption function
void encrypt(char *message, int key) {
    int i;
    char ch;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

// Decryption function
void decrypt(char *message, int key) {
    int i;
    char ch;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int key, choice;

    // Introduction
    printf("Welcome to Romeo and Juliet's Cryptography Implementation Program\n");
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    do {
        printf("Enter the key (1-25): ");
        scanf("%d", &key);
    } while (key < 1 || key > 25);

    printf("Choose from the following options:\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    scanf("%d", &choice);

    // Encrypt or decrypt the message
    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}