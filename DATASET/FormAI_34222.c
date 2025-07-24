//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretkey"

void encrypt(char *input, int length) {
    int i;
    for(i=0; i<length; i++) {
        input[i] ^= KEY[i % strlen(KEY)];
    }
}

void decrypt(char *input, int length) {
    encrypt(input, length);
}

int main() {
    char plaintext[1024];
    printf("Enter plaintext message:\n");
    fgets(plaintext, 1024, stdin);
    printf("Original Message: %s", plaintext);

    int length = strlen(plaintext);

    // Pad plaintext to be a multiple of 16 bytes
    int remainder = length % 16;
    if(remainder > 0) {
        int padding = 16 - remainder;
        int i;
        for(i=0; i<padding; i++) {
            plaintext[length+i] = '\0';
        }
        length += padding;
    }

    // Encryption
    encrypt(plaintext, length);
    printf("Encrypted Message: %s", plaintext);

    // Decryption
    decrypt(plaintext, length);
    printf("Decrypted Message: %s", plaintext);

    return 0;
}