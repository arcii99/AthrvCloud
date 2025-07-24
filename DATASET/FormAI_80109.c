//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void print_hash(unsigned char *hash) {
    printf("Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string to hash>\n", argv[0]);
        return 1;
    }

    unsigned char *input = (unsigned char *) argv[1];
    unsigned char *hash = (unsigned char *) malloc(MD5_DIGEST_LENGTH);
    MD5(input, strlen(input), hash);

    print_hash(hash);

    free(hash);

    return 0;
}