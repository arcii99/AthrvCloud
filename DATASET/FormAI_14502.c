//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>

// Artistic encryption algorithm
void artistic_encrypt(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = (message[i] + key) % 126;
        if(message[i] < 32) message[i] += 32;
    }
}

// Artistic decryption algorithm
void artistic_decrypt(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = (message[i] - key) % 126;
        if(message[i] < 32) message[i] += 94;
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    artistic_encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    artistic_decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}