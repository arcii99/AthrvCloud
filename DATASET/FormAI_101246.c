//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

extern void encrypt(char *message, int key);
extern void decrypt(char *message, int key);

int main(void) {
    srand(time(NULL)); // to ensure random key on each run

    char message[MAX_LENGTH];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key) {
    int i, random;
    for (i = 0; message[i] != '\0'; i++) {
        random = rand() % 256; // random number between 0 and 255
        message[i] = message[i] ^ key ^ random;
    }
}

void decrypt(char *message, int key) {
    encrypt(message, key); // decryption is the same as encryption with the same key
}