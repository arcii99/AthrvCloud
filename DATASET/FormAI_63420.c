//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void sha256(char* string, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, string, strlen(string));
    SHA256_Final(hash, &sha256_ctx);
}

int main() {
    char string[] = "Hello, World!";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256(string, hash);

    printf("SHA256 hash of \"%s\":\n", string);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}