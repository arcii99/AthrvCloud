//FormAI DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ENCRYPTION FUNCTION
 * Takes in a string and a key, and returns a string encrypted with the given key using XOR operation.
 */
char* encrypt(char* str, char* key) {
    int len = strlen(str);
    int klen = strlen(key);
    char* result = (char*)malloc(len + 1);
    for(int i = 0; i < len; i++) {
        result[i] = str[i] ^ key[i % klen]; // XOR operation
        if(i % klen == klen-1) result[i+1] = '\0'; // Add null terminator after each block
    }
    return result;
}

/*
 * MAIN FUNCTION
 * Takes in a message and a key from the user and encrypts the message using the given key.
 */
int main() {
    char message[100];
    char key[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    fgets(key, 100, stdin);
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted); // Free allocated memory
    return 0;
}