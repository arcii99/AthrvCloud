//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    printf("Enter the input to be hashed (maximum %d characters): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from input if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Compute SHA256 hash of input
    SHA256(input, strlen(input), hash);

    // Print the hash in hexadecimal format
    printf("SHA256 hash of \"%s\" is: ", input);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}