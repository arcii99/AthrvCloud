//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char **argv) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char input[256];
    int i;

    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);

    SHA256(input, strlen(input), hash);

    printf("Hash output:\n");
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}