//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given string
void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] + key;
    }
}

// Function to decrypt the given string
void decrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] - key;
    }
}

int main() {
    char str[100];
    int key;

    printf("Enter the string to be encrypted: ");
    scanf("%s", str);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the string
    encrypt(str, key);

    printf("Encrypted string: %s\n", str);

    // Decrypt the string
    decrypt(str, key);

    printf("Decrypted string: %s\n", str);

    return 0;
}