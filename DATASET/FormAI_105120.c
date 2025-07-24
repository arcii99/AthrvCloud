//FormAI DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given input string
void encrypt(char* input)
{
    // Key for encryption
    char key[] = "secret-key";

    // Obtain length of input string and key
    int len = strlen(input);
    int keyLen = strlen(key);

    // Modify length of input string to make it divisible by key length
    while (len % keyLen != 0)
        input[len++] = ' ';

    // Calculate number of key blocks
    int numKeyBlocks = len / keyLen;

    // Allocate memory to hold encrypted string
    char* encrypted = (char*)malloc(len * sizeof(char));

    // Encrypt each block of the input string using the key
    for (int i = 0; i < numKeyBlocks; i++) {
        for (int j = 0; j < keyLen; j++)
            encrypted[i * keyLen + j] = input[i * keyLen + j] ^ key[j];
    }

    // Print the encrypted string
    printf("Encrypted String: %s\n", encrypted);

    // Free allocated memory
    free(encrypted);
}

int main()
{
    // Input string to encrypt
    char input[] = "Hello, World!";

    // Encrypt the input string
    encrypt(input);

    return 0;
}