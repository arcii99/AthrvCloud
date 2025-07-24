//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_LENGTH 64

void sha256_hash(char *input, char *output) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);

    for (int i=0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[HASH_LENGTH] = '\0';
}

int main() {
    char input[] = "Hello World";
    char hash[HASH_LENGTH + 1];

    sha256_hash(input, hash);
    printf("Hash of '%s' = '%s'\n", input, hash);

    return 0;
}