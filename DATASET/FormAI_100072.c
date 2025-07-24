//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output)
{
    // Key to perform encryption
    char key[] = "my-secret-key";

    int input_length = strlen(input);
    int key_length = strlen(key);

    // Allocate memory to store the output
    char *encrypted = (char *)malloc(input_length + 1);
    memset(encrypted, 0, input_length + 1);

    // Loop through the input and perform encryption
    for(int i = 0; i < input_length; i++) {
        encrypted[i] = (input[i] ^ key[i % key_length]);
    }

    // Copy the encrypted data to the output buffer
    strncpy(output, encrypted, input_length);

    // Free the memory allocated
    free(encrypted);
}

int main()
{
    char input[] = "This is a secret message";
    char output[strlen(input) + 1];

    encrypt(input, output);

    printf("Original message: %s\n", input);
    printf("Encrypted message: %s\n", output);

    return 0;
}