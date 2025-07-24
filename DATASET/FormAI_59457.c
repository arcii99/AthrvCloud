//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    int j = 0;
    for (int i = 0; i < text_length; i++) {
        text[i] = text[i] ^ key[j];
        j = (j + 1) % key_length;
    }
}

void decrypt(char *text, char *key) {
    encrypt(text, key); // XOR encryption is symmetric
}

int main() {
    char text[1000], key[1000];
    printf("Enter text to encrypt: ");
    fgets(text, 1000, stdin);
    printf("Enter key: ");
    fgets(key, 1000, stdin);
    
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    
    return 0;
}