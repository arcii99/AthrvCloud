//FormAI DATASET v1.0 Category: Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, size_t len, char key) {
    for (int i = 0; i < len; i++) {
        text[i] ^= key; // XOR with encryption key
    }
}

int main() {
    char *message = "This is a secret message!";
    char key = 0xF7;  // encryption key
    size_t len = strlen(message);
    char *encrypted = malloc(len+1);
    strcpy(encrypted, message);
    encrypt(encrypted, len, key);

    printf("Original message: '%s'\n", message);
    printf("Encrypted message: '%s'\n", encrypted);

    // decrypt back
    encrypt(encrypted, len, key);
    printf("Decrypted message: '%s'\n", encrypted);
    
    free(encrypted);
    return 0;
}