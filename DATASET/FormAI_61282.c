//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 17 // The encryption key

void encrypt(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = (str[i] + KEY) % 127; // Add the key and wrap around if necessary
    }
}

void decrypt(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = (str[i] - KEY + 127) % 127; // Subtract the key and wrap around if necessary
    }
}

int main() {
    char input[100];
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character from input
    printf("Original: %s\n", input);
    
    encrypt(input);
    printf("Encrypted: %s\n", input);
    
    decrypt(input);
    printf("Decrypted: %s\n", input);

    return 0;
}