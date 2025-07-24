//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    printf("Enter a string to hash: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline char from input

    SHA256((const unsigned char*)input, strlen(input), hash);

    printf("Sha256 hash of input '%s':\n", input);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}