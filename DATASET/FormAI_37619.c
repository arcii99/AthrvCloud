//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key;
    }
}

void decrypt(char* message, char key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key;
    }
}

int main() {
    printf("Welcome to the Fun Encryption Program!\n");

    char message[100];
    char key;
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    printf("Enter a key: ");
    scanf(" %c", &key);

    printf("\nEncrypting message with key '%c':\n", key);
    encrypt(message, key);
    printf("%s\n", message);

    printf("\nDecrypting message with key '%c':\n", key);
    decrypt(message, key);
    printf("%s\n", message);

    printf("\nWow! Your message is now SAFE and SECURE!\n");
    
    return 0;
}