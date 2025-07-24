//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

/**
 * This function takes a string as input and returns an SHA-256 hash of the string.
 * The hash is stored in a static buffer, so it must be used or copied before calling
 * this function again.
 */
char* peaceful_hash(const char* input) {
    static unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);

    char *output = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    int i;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[SHA256_DIGEST_LENGTH * 2] = '\0';

    return output;
}

/**
 * This is a sample program that uses the peaceful_hash function.
 * It prompts the user for a string and prints out the SHA-256 hash of that string.
 */
int main() {
    char input[100];
    printf("Please enter a string to hash: ");
    scanf("%s", input);

    char* hash = peaceful_hash(input);
    printf("The SHA-256 hash of \"%s\" is: %s\n", input, hash);

    free(hash);
    return 0;
}