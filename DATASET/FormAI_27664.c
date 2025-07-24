//FormAI DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    char* encrypted = (char*) malloc(strlen(message) * sizeof(char));
    for(int i=0; i<strlen(message); i++) {
        // Apply key to each character
        encrypted[i] = message[i] + key;
    }
    return encrypted;
}

char* decrypt(char* message, int key) {
    char* decrypted = (char*) malloc(strlen(message) * sizeof(char));
    for(int i=0; i<strlen(message); i++) {
        // Apply negative key to each character
        decrypted[i] = message[i] - key;
    }
    return decrypted;
}

int main() {
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("Enter a key (integer value): ");
    scanf("%d", &key);
    
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    return 0;
}