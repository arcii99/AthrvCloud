//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

int main() {
    char input[256];
    char output[256];
    char decoded[256];
    int i, j;
    int key_len = strlen(KEY);

    printf("Enter your message: ");
    fgets(input, 256, stdin);

    // Encrypt the message
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        output[i] = input[i] ^ KEY[j];
    }
    output[i] = '\0';

    printf("Encrypted message: %s\n", output);

    // Decrypt the message
    for (i = 0, j = 0; i < strlen(output); i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        decoded[i] = output[i] ^ KEY[j];
    }
    decoded[i] = '\0';

    printf("Decoded message: %s\n", decoded);

    return 0;
}