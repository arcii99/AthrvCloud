//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Modern Encryption
void modern_encrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = ((int)input[i] + key) % 127;
    }
    output[len] = '\0';
}

// Function to perform Modern Decryption
void modern_decrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = ((int)input[i] - key + 127) % 127;
    }
    output[len] = '\0';
}

int main() {
    char input[1000], output[1000], decrypted[1000];
    int key;

    printf("Welcome to the Modern Encryption Program\n");
    printf("Please enter the string to encrypt:\n");
    fgets(input, 1000, stdin);

    printf("\nPlease enter a key for encryption:\n");
    scanf("%d", &key);

    modern_encrypt(input, output, key);
    printf("\nEncrypted String: %s\n", output);

    printf("\nTo decrypt the string, enter the decryption key:\n");
    scanf("%d", &key);
    modern_decrypt(output, decrypted, key);
    printf("\nDecrypted String: %s\n", decrypted);

    return 0;
}