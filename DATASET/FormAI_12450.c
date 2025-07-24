//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void compute_sha256_hash(unsigned char *data, size_t dataSize, unsigned char *digest) {
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, data, dataSize);
    SHA256_Final(digest, &context);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *inputStr = argv[1];
    size_t inputStrSize = strlen(inputStr);

    unsigned char digest[SHA256_DIGEST_LENGTH];
    compute_sha256_hash((unsigned char *)inputStr, inputStrSize, digest);

    printf("Input String: %s\n", inputStr);
    printf("Hash Digest: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}