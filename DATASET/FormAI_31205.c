//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key)
{
    int message_len = strlen(message);
    int key_len = strlen(key);
    int key_index = 0;
    
    for (int i = 0; i < message_len; i++) {
        message[i] = message[i] ^ key[key_index];
        key_index = (key_index + 1) % key_len;
    }
}

void decrypt(char *message, char *key)
{
    encrypt(message, key);
}

int main()
{
    char message[100];
    char key[100];
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    
    printf("Enter key: ");
    fgets(key, 100, stdin);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}