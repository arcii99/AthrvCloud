//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_KEY_LENGTH 16

void xor_encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i;
    for(i = 0; i < message_length; i++) {
        message[i] ^= key[i % key_length];
    }
}

int main() {
    char message[MAX_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    xor_encrypt(message, key);
    printf("The encrypted message is: %s\n", message);
    xor_encrypt(message, key);
    printf("The decrypted message is: %s\n", message);
    return 0;
}