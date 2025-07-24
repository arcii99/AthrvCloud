//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3 // Define the key used to encrypt/decrypt

// Function to encrypt a message
void encrypt(char *msg) {
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + KEY;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + KEY;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}

// Function to decrypt a message
void decrypt(char *msg) {
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - KEY;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - KEY;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
}

int main() {
    char msg[100];
    int choice;

    printf("Enter a message to encrypt/decrypt: ");
    fgets(msg, sizeof(msg), stdin);

    printf("Enter your choice:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice) {
    case 1:
        encrypt(msg);
        printf("Encrypted message: %s", msg);
        break;
    case 2:
        decrypt(msg);
        printf("Decrypted message: %s", msg);
        break;
    default:
        printf("Invalid choice!");
    }

    return 0;
}