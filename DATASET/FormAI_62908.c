//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], const char *string) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, string, strlen(string));
    SHA256_Final(hash, &ctx);
}

void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s string_to_hash\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    hash_string(hash, string);
    printf("Hash of \"%s\":\n", string);
    print_hash(hash);
    return 0;
}