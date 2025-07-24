//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plainText, int key) {
    int length = strlen(plainText);
    char* cipherText = (char*) malloc(length + 1);
    // Copy the plaintext to ciphertext string
    strcpy(cipherText, plainText);
    // Use XOR operation for encryption
    for (int i = 0; i < length; i++) {
        cipherText[i] = cipherText[i] ^ key;
    }
    // Null terminate the string
    cipherText[length] = '\0';
    return cipherText;
}

int main() {
    char* plaintext = "This is a sample plaintext";
    int key = 17;
    char* ciphertext = encrypt(plaintext, key);
    printf("Plain text is: %s\n", plaintext);
    printf("Key is: %d\n", key);
    printf("Encrypted text is: %s\n", ciphertext);
    return 0;
}