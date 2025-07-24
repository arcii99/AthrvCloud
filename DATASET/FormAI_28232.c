//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void hash(const char *str, char *result) {
    unsigned char md[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)str, strlen(str), md);

    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&result[i*2], "%02x", (unsigned int)md[i]);
    }
}

int main() {
    char *str = "This is a message to be hashed.";
    char result[33];
    hash(str, result);
    printf("Result: %s\n", result);
    return 0;
}