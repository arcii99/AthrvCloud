//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    int length = strlen(message);
    
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

void decrypt(char* message, int key) {
    int length = strlen(message);
    
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[50];
    int key = 5;
    
    printf("Enter the message to be encrypted: ");
    fgets(message, 50, stdin);
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}