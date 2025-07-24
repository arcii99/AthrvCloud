//FormAI DATASET v1.0 Category: Encryption ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

//Function to encrypt the message
void encrypt(char *message, char *key) {
    for(int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

int main() {
    char message[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    
    printf("Enter the message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    
    printf("Enter the encryption key: ");
    fgets(key, BUFFER_SIZE, stdin);
    
    //Remove the newline character from input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    //Encrypt the message using the key
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    //Decrypt the message using the key
    encrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}