//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt a message using Caesar cipher
void caesarCipherEncrypt(char* message, int key) {
    int i;
    char ch;

    for(i=0; message[i] != '\0'; i++) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

// Function to decrypt a message using Caesar cipher
void caesarCipherDecrypt(char* message, int key) {
    int i;
    char ch;

    for(i=0; message[i] != '\0'; i++) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int choice, key;

    while(1) {
        printf("\nEnter your message: ");
        fgets(message, 100, stdin);

        printf("\nChoose the type of encryption/decryption:");
        printf("\n1. Caesar Cipher");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\nEnter the key: ");
        scanf("%d", &key);

        switch(choice) {
            case 1:
                caesarCipherEncrypt(message, key);
                printf("\nEncrypted message: %s", message);

                caesarCipherDecrypt(message, key);
                printf("\nDecrypted message: %s", message);
                break;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}