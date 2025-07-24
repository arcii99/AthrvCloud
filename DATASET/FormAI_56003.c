//FormAI DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* function to encrypt message */
void encrypt(char *message, int key) {
    while (*message) {
        *message = (*message + key) % 128;
        message++;
    }
}

/* function to decrypt message */
void decrypt(char *message, int key) {
    while (*message) {
        *message = (*message - key + 128) % 128;
        message++;
    }
}

/* main function */
int main() {
    char message[100];
    int key;

    /* get message and encryption key from user */
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    /* encrypt message */
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    /* decrypt message */
    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}