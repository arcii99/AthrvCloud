//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    char* message = argv[1];
    size_t message_len = strlen(message);

    SHA256((unsigned char*)message, message_len, hash);

    printf("SHA-256 hash of \"%s\":\n", message);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}