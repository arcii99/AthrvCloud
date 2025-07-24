//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX 100

void encrypt(char message[]) {
    int i, key = 5;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
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

void decrypt(char message[]) {
    int i, key = 5;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
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
    char message[MAX];

    printf("Enter message to encrypt: ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = 0;

    encrypt(message);

    printf("Encrypted message: %s\n", message);

    decrypt(message);

    printf("Decrypted message: %s\n", message);

    return 0;
}