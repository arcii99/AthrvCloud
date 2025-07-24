//FormAI DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTION_KEY 5

void encrypt(char *input, char *output) {
    int input_len = strlen(input);
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = input[i] + ENCRYPTION_KEY;
    }
    output[i] = '\0'; // add null terminator to output string
}

void decrypt(char *input, char *output) {
    int input_len = strlen(input);
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = input[i] - ENCRYPTION_KEY;
    }
    output[i] = '\0'; // add null terminator to output string
}

int main() {
    char message[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    encrypt(message, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    decrypt(encrypted, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}