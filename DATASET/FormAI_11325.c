//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    for(i=0; i<strlen(message); i++) {
        message[i] = ((message[i] - 'a' + key) % 26) + 'a';
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i=0; i<strlen(message); i++) {
        message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key to encrypt with: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}