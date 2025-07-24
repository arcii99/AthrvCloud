//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_KEY_LENGTH 128

void encrypt(char *input, char *key);
void decrypt(char *input, char *key);

int main() {
    char input[MAX_INPUT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Please enter the input you want to encrypt: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);  // Get input from user

    printf("Please enter the key for encryption (must be a multiple of 8): ");
    fgets(key, MAX_KEY_LENGTH, stdin);  //Get encryption key

    while(strlen(key) % 8 != 0) {
        printf("Error: Key length must be a multiple of 8.\n"); 
        printf("Please enter the key for encryption (must be a multiple of 8): ");
        fgets(key, MAX_KEY_LENGTH, stdin);
    }

    printf("\nProcessing...\n\n");

    // Encrypt the input
    encrypt(input, key);

    printf("Encrypted message: %s\n", input);

    // Decrypt the message
    decrypt(input, key);

    printf("\nDecrypted message: %s\n", input);

    return 0;
}

// Encrypt function
void encrypt(char *input, char *key) {
    for(int i = 0, k = 0; i < strlen(input); i++, k++) {
        if(k == strlen(key) - 1) {
            k = 0;
        }
        input[i] = input[i] ^ key[k];
    }
}

// Decrypt function
void decrypt(char *input, char *key) {
    for(int i = 0, k = 0; i < strlen(input); i++, k++) {
        if(k == strlen(key) - 1) {
            k = 0;
        }
        input[i] = input[i] ^ key[k];
    }
}