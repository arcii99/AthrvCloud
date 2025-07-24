//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    int len = strlen(message);
    
    for(int i=0; i<len; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key) {
    int len = strlen(message);
    
    for(int i=0; i<len; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];
    int key;
    
    printf("Enter message: ");
    fgets(message, 100, stdin);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    printf("Original message: %s", message);
    
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s", message);
    
    return 0;
}