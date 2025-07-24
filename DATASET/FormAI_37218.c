//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main() {
    const char *input = "Hello World!";
    unsigned char output[MD5_DIGEST_LENGTH];
    char md5string[33];

    MD5((const unsigned char*)input, strlen(input), output);

    for(int i = 0; i < 16; i++) {
        sprintf(&md5string[i*2], "%02x", (unsigned int)output[i]);
    }

    printf("Input: %s\n", input);
    printf("Hash: %s\n", md5string);

    return 0;
}