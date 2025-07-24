//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int len = strlen(message);
    
    // Apply key to each character in message
    for (int i = 0; i < len; i++) {
        message[i] = message[i] ^ key;
    }
}

void decrypt(char message[], int key) {
    encrypt(message, key); // To decrypt message, just apply key again
}

int main() {
    char message[100];
    int key;
    
    printf("Enter message to encrypt:\n");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character from message
    
    printf("Enter encryption key (must be a positive integer):\n");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}