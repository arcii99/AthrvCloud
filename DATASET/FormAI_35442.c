//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key);

int main() {
    char message[1000];
    int key;
    
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s", message);
    
    return 0;
}

void encrypt(char message[], int key) {
    int length = strlen(message);
    
    if (length <= 2) {
        return;
    }
    
    // Encrypt even index characters
    for (int i = 0; i < length; i += 2) {
        message[i] += key;
    }
    
    // Encrypt odd index characters
    for (int i = 1; i < length; i += 2) {
        message[i] -= key;
    }
    
    encrypt(message + 1, key - 1);
}