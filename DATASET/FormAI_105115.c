//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

/* Function declaration */
void sha256_hash(char *string, unsigned char *hash);

int main() {
    char input[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    printf("Enter a string to hash: ");
    fgets(input, 256, stdin);

    sha256_hash(input, hash);

    printf("\nSHA256 hash of the string is: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

/* Function definition */
void sha256_hash(char *string, unsigned char *hash) {
    SHA256_CTX context;

    SHA256_Init(&context);
    SHA256_Update(&context, string, strlen(string));
    SHA256_Final(hash, &context);
}