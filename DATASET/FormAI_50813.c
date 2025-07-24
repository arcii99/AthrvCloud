//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plainText, char* key) {
    int plainTextLength = strlen(plainText);
    int keyLength = strlen(key);

    for (int i = 0; i < plainTextLength; i++) {
        plainText[i] ^= key[i % keyLength];
    }
}

void decrypt(char* plainText, char* key) {
    int plainTextLength = strlen(plainText);
    int keyLength = strlen(key);

    for (int i = 0; i < plainTextLength; i++) {
        plainText[i] ^= key[i % keyLength];
    }
}

int main() {
    char plainText[100];
    printf("Enter the plain text: ");
    scanf("%s", plainText);

    char key[100];
    printf("Enter the key for encryption: ");
    scanf("%s", key);

    encrypt(plainText, key);
    printf("The encrypted text is: %s\n", plainText);

    decrypt(plainText, key);
    printf("The decrypted text is: %s\n", plainText);

    return 0;
}