//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    for (int i = 0; i < message_len; i++) {
        message[i] ^= key[i % key_len];
    }
}

void decrypt(char* message, char* key) {
    encrypt(message, key);
}

int main() {
    char message[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char key[] = "secretkey";
    
    printf("Original message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}