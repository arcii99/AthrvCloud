//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hash_sha256(char* input, unsigned char* hash);

int main() {
    char* input = "Hello, world!";
    unsigned char hash[SHA256_DIGEST_LENGTH];

    hash_sha256(input, hash);

    printf("Input: %s\n", input);
    printf("Output: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

void hash_sha256(char* input, unsigned char* hash) {
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, input, strlen(input));
    SHA256_Final(hash, &context);
}