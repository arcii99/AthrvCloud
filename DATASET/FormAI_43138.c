//FormAI DATASET v1.0 Category: modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256

void encrypt(char message[], char key[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = (message[i] + key[j]) % 256;
    }
}

void decrypt(char message[], char key[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = (message[i] - key[j] + 256) % 256;
    }
}

int main(void) {
    char message[1024];
    char key[MAX_KEY_SIZE];
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; //remove newline from input
    
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; //remove newline from input
    
    printf("\nOriginal message: %s\n", message);
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}