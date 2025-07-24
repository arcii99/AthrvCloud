//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(0);
    }

    unsigned char md5_result[MD5_DIGEST_LENGTH];
    char* str = argv[1];
    int len = strlen(str);

    MD5((unsigned char*) str, len, md5_result);

    printf("MD5 Hash for string '%s' is: ", str);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md5_result[i]);
    }
    printf("\n");

    return 0;
}