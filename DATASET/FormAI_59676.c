//FormAI DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char *cipher_text = malloc(sizeof(char) * (message_length + key_length));
    
    for(int i = 0; i < message_length; i++) {
        cipher_text[i] = message[i] ^ key[i % key_length];
    }
    
    printf("Encrypted message: %s\n", cipher_text);
    free(cipher_text);
}

int main() {
    char *message = "Hello World!";
    printf("Original message: %s\n", message);
    
    char *key = "secret";
    printf("Key: %s\n", key);
    
    encrypt(message, key);
    return 0;
}