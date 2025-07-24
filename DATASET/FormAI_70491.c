//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3 // Arbitary key value for encryption

void encrypt(char *message); // Function prototype

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    encrypt(message); // Call the encryption function

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message) {
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + KEY;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + KEY;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}