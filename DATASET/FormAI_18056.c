//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define BLOCK_SIZE 512

void print_hash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// A custom hash function that uses SHA-256 to generate the hash
unsigned char* custom_hash(unsigned char *input) {
    SHA256_CTX context;
    unsigned char *hash = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
    SHA256_Init(&context);
    SHA256_Update(&context, input, strlen(input));
    SHA256_Final(hash, &context);
    return hash;
}

int main() {
    char input[BLOCK_SIZE];
    unsigned char* digest;
    int len;

    printf("Enter input string:\n");
    fgets(input, BLOCK_SIZE, stdin);
    len = strlen(input);
    // Remove newline character from input
    if (input[len-1] == '\n') input[len-1] = '\0';

    digest = custom_hash((unsigned char*)input);
    printf("Hash of input string: ");
    print_hash(digest);

    free(digest);
    return 0;
}