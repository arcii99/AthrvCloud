//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
/*
This program demonstrates a simple encryption and decryption method
using the Caesar Cipher algorithm. The algorithm works by shifting all
letters of a given message by a fixed number of positions.

Author: John Doe
Date: September 28, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to encrypt the message */
void encrypt(char message[], int key) {
    int i;

    for (i = 0; i < strlen(message); ++i) {
        /* Shift letters by key positions */
        if (message[i] >= 'a' && message[i] <= 'z') {
            /* Handle lowercase letters */
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            /* Handle uppercase letters */
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }

    printf("Encrypted message: %s\n", message);
}

/* Function to decrypt the message */
void decrypt(char message[], int key) {
    int i;

    for (i = 0; i < strlen(message); ++i) {
        /* Shift letters by key positions */
        if (message[i] >= 'a' && message[i] <= 'z') {
            /* Handle lowercase letters */
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            /* Handle uppercase letters */
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
    }

    printf("Decrypted message: %s\n", message);
}

/* Main function */
int main() {
    char message[100];
    int key = 3;

    /* Get message from user */
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    /* Encrypt message */
    encrypt(message, key);

    /* Decrypt message */
    decrypt(message, key);

    return 0;
}