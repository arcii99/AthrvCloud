//FormAI DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
// Welcome to our amazing encryption program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char key[MAX_LENGTH]; 
    int key_length, input_length, i, j;

    printf("Welcome to C Modern Encryption!\n");
    printf("Enter your message to encrypt (up to 100 characters): \n");
    fgets(input, MAX_LENGTH, stdin);

    printf("Enter your encryption key (up to 100 characters): \n");
    fgets(key, MAX_LENGTH, stdin);

    key_length = strlen(key);
    input_length = strlen(input);

    // Remove new line characters
    key[key_length-1] = '\0';
    input[input_length-1] = '\0';

    printf("\nEncrypting message...\n");

    // XOR encryption
    for (i = 0, j = 0; i < input_length; ++i) {
        // Reset key index if end of key is reached
        if (j == key_length) {
            j = 0;
        }

        input[i] ^= key[j];
        j++;
    }

    printf("Encryption complete!\n");
    printf("Encrypted message: %s\n", input);

    return 0;
}