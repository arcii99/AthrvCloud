//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: active
#include <stdio.h>
#include <openssl/sha.h>

void compute_sha256_hash(unsigned char *input, unsigned char *output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final(output, &ctx);
}

int main() {
    char input[] = "Hello, world!";
    unsigned char output[SHA256_DIGEST_LENGTH];

    compute_sha256_hash(input, output);

    printf("Hash value computed using SHA-256: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}