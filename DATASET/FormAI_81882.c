//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char str[] = "Love is a hash function that encrypts two hearts into one.";
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)str, strlen(str), digest);
    char hash[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i*2], "%02x", (unsigned int)digest[i]);
    }
    printf("The SHA-256 hash of \"%s\" is:\n%s\n", str, hash);
    return 0;
}