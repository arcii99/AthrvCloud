//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: ./hash-test [string]\n");
        return -1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    char *raw_str = argv[1];
    SHA256(raw_str, strlen(raw_str), hash);

    printf("String: %s\n", raw_str);
    printf("Hash Value: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}