//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int i, messageLen = strlen(message), keyLen = strlen(key);
    
    for(i = 0; i < messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}

void decrypt(char* message, char* key) {
    int i, messageLen = strlen(message), keyLen = strlen(key);
    
    for(i = 0; i < messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}

int main() {
    char message[100], key[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    
    // remove newline characters
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    
    printf("Message before encryption: %s\n", message);
    printf("Key: %s\n", key);
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("Message after decryption: %s\n", message);
    
    return 0;
}